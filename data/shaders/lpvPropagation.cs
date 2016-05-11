#version 430
precision lowp float;

#if defined(LPV_GATHERING) || defined(LPV_SCATTERING)
#ifdef LPV_GATHERING
#define LPV_PROPAGATION_INTENSITY3 1.0
#else
#define LPV_PROPAGATION_INTENSITY3 1.2
#endif
#ifndef LPV_LOBE
#define LPV_PROPAGATION_INTENSITY2 (1.0 * LPV_PROPAGATION_INTENSITY3)
#else
#define LPV_PROPAGATION_INTENSITY2 (2.2 * LPV_PROPAGATION_INTENSITY3)
#endif
#ifndef LPV_GV
#define LPV_PROPAGATION_INTENSITY (1.0 * LPV_PROPAGATION_INTENSITY2)
#else
#define LPV_PROPAGATION_INTENSITY (1.4 * LPV_PROPAGATION_INTENSITY2)
#endif
#else
#define LPV_PROPAGATION_INTENSITY 1.0
#endif
#define SSLPV_PROPAGATION_INTENSITY 0.3

#define INJECT_SHIFT 1.0
#define SH_F2I 1000.0
#define SH_I2F 0.001

#define LPV_CASCADES_COUNT
#define LPV_SH_COEFFS_COUNT 4
#define LPV_SAMPLE_SIZE 12

#define LPV_DATA_R_SH 0
#define LPV_DATA_G_SH 4
#define LPV_DATA_B_SH 8

layout(local_size_x = LOCAL_SIZE_X, local_size_y = LOCAL_SIZE_Y, local_size_z = LOCAL_SIZE_Z) in;

uniform layout(rgba32f) writeonly image3D lpvAccumTexR;
uniform layout(rgba32f) writeonly image3D lpvAccumTexG;
uniform layout(rgba32f) writeonly image3D lpvAccumTexB;
uniform layout(r32i) coherent iimage3D lpv0Tex;
uniform layout(r32i) coherent iimage3D lpv1Tex;
uniform layout(r32i) coherent iimage3D lpvAccumTex;
uniform layout(r32i) coherent iimage3D lpvNormalAccumTex;
uniform layout(r32i) readonly iimage3D gvTex;

uniform vec3 lpvTexSize;
uniform vec4 lpvParams;

#define imgLoad(img, pos, off) \
  vec4( \
    float(imageLoad(img, pos + ivec3(off + 0, 0, 0)).x) * SH_I2F, \
    float(imageLoad(img, pos + ivec3(off + 1, 0, 0)).x) * SH_I2F, \
    float(imageLoad(img, pos + ivec3(off + 2, 0, 0)).x) * SH_I2F, \
    float(imageLoad(img, pos + ivec3(off + 3, 0, 0)).x) * SH_I2F)

#define imgStore(img, pos, off, data) \
  imageStore(img, pos + ivec3(off + 0, 0, 0), ivec4(data.x * SH_F2I, 0, 0, 0)); \
  imageStore(img, pos + ivec3(off + 1, 0, 0), ivec4(data.y * SH_F2I, 0, 0, 0)); \
  imageStore(img, pos + ivec3(off + 2, 0, 0), ivec4(data.z * SH_F2I, 0, 0, 0)); \
  imageStore(img, pos + ivec3(off + 3, 0, 0), ivec4(data.w * SH_F2I, 0, 0, 0));

#define imgStoreAdd(img, pos, off, data) \
  imageAtomicAdd(img, pos + ivec3(off + 0, 0, 0), int(data.x * SH_F2I)); \
  imageAtomicAdd(img, pos + ivec3(off + 1, 0, 0), int(data.y * SH_F2I)); \
  imageAtomicAdd(img, pos + ivec3(off + 2, 0, 0), int(data.z * SH_F2I)); \
  imageAtomicAdd(img, pos + ivec3(off + 3, 0, 0), int(data.w * SH_F2I));

#define imgStoreMax(img, pos, off, data) \
  imageAtomicMax(img, pos + ivec3(off + 0, 0, 0), int(data.x * SH_F2I)); \
  imageAtomicMax(img, pos + ivec3(off + 1, 0, 0), int(data.y * SH_F2I)); \
  imageAtomicMax(img, pos + ivec3(off + 2, 0, 0), int(data.z * SH_F2I)); \
  imageAtomicMax(img, pos + ivec3(off + 3, 0, 0), int(data.w * SH_F2I));

void main()
{
  uint x = gl_GlobalInvocationID.x % uint(lpvTexSize.y);
  uint y = gl_GlobalInvocationID.y % uint(lpvTexSize.y);
  uint z = gl_GlobalInvocationID.y / uint(lpvTexSize.y);
  uint cascade = gl_GlobalInvocationID.x / uint(lpvTexSize.y);

  if((cascade < LPV_CASCADES_COUNT) && (z < uint(lpvTexSize.z)))
  {
    uint texX = cascade * uint(lpvTexSize.y) + x;
    uint lpvGlobTexX = texX * LPV_SAMPLE_SIZE;
    uint gvGlobTexX = texX * LPV_SH_COEFFS_COUNT;
    uint loveGlobTexX = texX * LPV_SH_COEFFS_COUNT * 2;
    ivec3 texGlobPos = ivec3(lpvGlobTexX, y, z);
    ivec3 gvTexGlobPos = ivec3(gvGlobTexX, y, z);
    ivec3 lobeTexGlobPos = ivec3(loveGlobTexX, y, z);
    ivec3 texPos = ivec3(texX, y, z);

    //uint swap = 0;
    uint swap = uint(lpvParams.x);
    int lobeCoeff = (swap == 0) ? 0 : LPV_SH_COEFFS_COUNT;

    vec4 cosineLobe = vec4(0.8862, -1.0233, 1.0233, -1.0233);
    vec4 shBase = vec4(0.2821, -0.4886, 0.4886, -0.4886);

    vec3 dirs[6];
    dirs[0] = vec3(0.0, 0.0, -1.0); dirs[1] = vec3(0.0, 0.0, 1.0);
    dirs[2] = vec3(0.0, -1.0, 0.0); dirs[3] = vec3(0.0, 1.0, 0.0);
    dirs[4] = vec3(-1.0, 0.0, 0.0); dirs[5] = vec3(1.0, 0.0, 0.0);

    //for(uint step = 0; step < uint(lpvParams.x); step++)
    //{
    // clean swap
#if defined(LPV_CLEAR)
    if(swap == 0)
      {
        imgStore(lpv1Tex, texGlobPos, LPV_DATA_R_SH, vec4(0.0));
        imgStore(lpv1Tex, texGlobPos, LPV_DATA_G_SH, vec4(0.0));
        imgStore(lpv1Tex, texGlobPos, LPV_DATA_B_SH, vec4(0.0));
      }
      else
      {
        imgStore(lpv0Tex, texGlobPos, LPV_DATA_R_SH, vec4(0.0));
        imgStore(lpv0Tex, texGlobPos, LPV_DATA_G_SH, vec4(0.0));
        imgStore(lpv0Tex, texGlobPos, LPV_DATA_B_SH, vec4(0.0));
      }

      //barrier();

#elif defined(LPV_LOBE_PROP)
#ifdef LPV_LOBE
      vec4 cellNormal = imgLoad(lpvNormalAccumTex, lobeTexGlobPos, lobeCoeff);

      if(length(cellNormal) == 0.0)
      {
        int ratio = 1;

        for(int cell = 1; cell < 6; cell++)
        {
          ivec3 p = lobeTexGlobPos + ivec3(dirs[cell]) * ivec3(LPV_SH_COEFFS_COUNT * 2, 1, 1);

          vec4 cNormal = imgLoad(lpvNormalAccumTex, p, lobeCoeff);

          if(length(cNormal) > 0.0)
          {
            cellNormal = mix(cellNormal, cNormal, 1.0 / float(ratio));
            ratio++;
          }
        }
      }

      imgStore(lpvNormalAccumTex, lobeTexGlobPos, lobeCoeff, cellNormal);

      if(length(cellNormal.xyz) > 0.01)
        cellNormal = normalize(cellNormal);
#endif
#else
    vec4 cellNormal = imgLoad(lpvNormalAccumTex, lobeTexGlobPos, lobeCoeff);

#ifdef LPV_GATHERING
      vec4 shR = vec4(0.0);
      vec4 shG = vec4(0.0);
      vec4 shB = vec4(0.0);

      for(uint cell = 0; cell < 6; cell++)
      {
        ivec3 p = ivec3((texX + int(dirs[cell].x)) * LPV_SAMPLE_SIZE, y, z) + ivec3(0, int(dirs[cell].y), int(dirs[cell].z));
        ivec3 pgv = ivec3((texX + int(dirs[cell].x)) * LPV_SH_COEFFS_COUNT, y, z) + ivec3(0, int(dirs[cell].y), int(dirs[cell].z));

        vec4 shCellR;
        vec4 shCellG;
        vec4 shCellB;

        if(swap == 0)
        {
          shCellR = imgLoad(lpv0Tex, p, LPV_DATA_R_SH);
          shCellG = imgLoad(lpv0Tex, p, LPV_DATA_G_SH);
          shCellB = imgLoad(lpv0Tex, p, LPV_DATA_B_SH);
        }
        else
        {
          shCellR = imgLoad(lpv1Tex, p, LPV_DATA_R_SH);
          shCellG = imgLoad(lpv1Tex, p, LPV_DATA_G_SH);
          shCellB = imgLoad(lpv1Tex, p, LPV_DATA_B_SH);
        }

        for(int face = 0; face < 6; face++)
        {
          vec3 faceDir = dirs[face] * 0.5 - dirs[cell];
          float faceLength = length(faceDir);

          if(faceLength < 0.6)
            continue;

          float solidAngle = (faceLength < 1.4) ? 0.12732 : 0.13477;
          vec3 normal = normalize(faceDir);
          vec4 shNormal = shBase * vec4(1.0, normal.y, normal.z, normal.x);
          vec4 shDir = cosineLobe * vec4(1.0, dirs[face].y, dirs[face].z, dirs[face].x);

#ifdef LPV_LOBE
          vec4 shOriginal = shBase * vec4(1.0, cellNormal.y, cellNormal.z, cellNormal.x);
          vec4 shLobeOriginal = cosineLobe * vec4(1.0, cellNormal.y, cellNormal.z, cellNormal.x);
          shDir = max(0.0, dot(shDir, shOriginal)) * shLobeOriginal;
#endif

          shDir *= LPV_PROPAGATION_INTENSITY;
          if(lpvParams.w < 0.0)
            shDir *= SSLPV_PROPAGATION_INTENSITY;
#ifdef LPV_GV
          vec4 shGv = (lpvParams.w < 0.0) ? vec4(0.0) : imgLoad(gvTex, pgv, 0); // todo pos
          shDir *= 1.0 - clamp(shGv.x * shNormal.x + abs(dot(shGv.yzw, shNormal.yzw)), 0.0, 1.0);
#endif

          shR += solidAngle * max(0.0, dot(shCellR, shNormal)) * shDir;
          shG += solidAngle * max(0.0, dot(shCellG, shNormal)) * shDir;
          shB += solidAngle * max(0.0, dot(shCellB, shNormal)) * shDir;
        }
      }

      if(swap == 0)
      {
        imgStoreAdd(lpv1Tex, texGlobPos, LPV_DATA_R_SH, shR);
        imgStoreAdd(lpv1Tex, texGlobPos, LPV_DATA_G_SH, shG);
        imgStoreAdd(lpv1Tex, texGlobPos, LPV_DATA_B_SH, shB);
      }
      else
      {
        imgStoreAdd(lpv0Tex, texGlobPos, LPV_DATA_R_SH, shR);
        imgStoreAdd(lpv0Tex, texGlobPos, LPV_DATA_G_SH, shG);
        imgStoreAdd(lpv0Tex, texGlobPos, LPV_DATA_B_SH, shB);
      }

      imgStoreAdd(lpvAccumTex, texGlobPos, LPV_DATA_R_SH, shR);
      imgStoreAdd(lpvAccumTex, texGlobPos, LPV_DATA_G_SH, shG);
      imgStoreAdd(lpvAccumTex, texGlobPos, LPV_DATA_B_SH, shB);
#else
      vec4 shCellR = vec4(0.0);
      vec4 shCellG = vec4(0.0);
      vec4 shCellB = vec4(0.0);

      if(swap == 0)
      {
        shCellR = imgLoad(lpv0Tex, texGlobPos, LPV_DATA_R_SH);
        shCellG = imgLoad(lpv0Tex, texGlobPos, LPV_DATA_G_SH);
        shCellB = imgLoad(lpv0Tex, texGlobPos, LPV_DATA_B_SH);
      }
      else
      {
        shCellR = imgLoad(lpv1Tex, texGlobPos, LPV_DATA_R_SH);
        shCellG = imgLoad(lpv1Tex, texGlobPos, LPV_DATA_G_SH);
        shCellB = imgLoad(lpv1Tex, texGlobPos, LPV_DATA_B_SH);
      }

      for(uint cell = 0; cell < 6; cell++)
      {
        ivec3 p = ivec3((texX + int(dirs[cell].x)) * LPV_SAMPLE_SIZE, y, z) + ivec3(0, int(dirs[cell].y), int(dirs[cell].z));
        ivec3 pgv = ivec3((texX + int(dirs[cell].x)) * LPV_SH_COEFFS_COUNT, y, z) + ivec3(0, int(dirs[cell].y), int(dirs[cell].z));

        vec4 shR = vec4(0.0);
        vec4 shG = vec4(0.0);
        vec4 shB = vec4(0.0);

        for(int face = 0; face < 6; face++)
        {
          vec3 faceDir = dirs[cell] + dirs[face] * 0.5;
          float faceLength = length(faceDir);

          if(faceLength > 0.6)
          {
            float solidAngle = 0.0;

            if(faceLength < 1.4)
              solidAngle = 0.12732;
            else
              solidAngle = 0.13477;

            vec3 normal = normalize(faceDir);
            vec4 shNormal = shBase * vec4(1.0, normal.y, normal.z, normal.x);
            vec4 shDir = cosineLobe * vec4(1.0, dirs[face].y, dirs[face].z, dirs[face].x);

#ifdef LPV_LOBE
            vec4 shOriginal = shBase * vec4(1.0, cellNormal.y, cellNormal.z, cellNormal.x);
            vec4 shLobeOriginal = cosineLobe * vec4(1.0, cellNormal.y, cellNormal.z, cellNormal.x);
            shDir = max(0.0, dot(shDir, shOriginal)) * shLobeOriginal;
#endif

            shDir *= LPV_PROPAGATION_INTENSITY;
            if(lpvParams.w < 0.0)
              shDir *= SSLPV_PROPAGATION_INTENSITY;
#ifdef LPV_GV
            vec4 shGv = (lpvParams.w < 0.0) ? vec4(0.0) : imgLoad(gvTex, pgv, 0); // todo pos
            shDir *= 1.0 - clamp(shGv.x * shNormal.x + abs(dot(shGv.yzw, shNormal.yzw)), 0.0, 1.0);
#endif

            shR += solidAngle * max(0.0, dot(shCellR, shNormal)) * shDir;
            shG += solidAngle * max(0.0, dot(shCellG, shNormal)) * shDir;
            shB += solidAngle * max(0.0, dot(shCellB, shNormal)) * shDir;
          }
        }

        if(swap == 0)
        {
          imgStoreAdd(lpv1Tex, p, LPV_DATA_R_SH, shR);
          imgStoreAdd(lpv1Tex, p, LPV_DATA_G_SH, shG);
          imgStoreAdd(lpv1Tex, p, LPV_DATA_B_SH, shB);
        }
        else
        {
          imgStoreAdd(lpv0Tex, p, LPV_DATA_R_SH, shR);
          imgStoreAdd(lpv0Tex, p, LPV_DATA_G_SH, shG);
          imgStoreAdd(lpv0Tex, p, LPV_DATA_B_SH, shB);
        }

        imgStoreAdd(lpvAccumTex, p, LPV_DATA_R_SH, shR);
        imgStoreAdd(lpvAccumTex, p, LPV_DATA_G_SH, shG);
        imgStoreAdd(lpvAccumTex, p, LPV_DATA_B_SH, shB);
      }
#endif

    //swap = (swap != 0) ? 0 : 1;
    //barrier();
    //}

#endif
#ifdef LPV_OUT
    imageStore(lpvAccumTexR, texPos, imgLoad(lpvAccumTex, texGlobPos, LPV_DATA_R_SH));
    imageStore(lpvAccumTexG, texPos, imgLoad(lpvAccumTex, texGlobPos, LPV_DATA_G_SH));
    imageStore(lpvAccumTexB, texPos, imgLoad(lpvAccumTex, texGlobPos, LPV_DATA_B_SH));
#endif
  }
}