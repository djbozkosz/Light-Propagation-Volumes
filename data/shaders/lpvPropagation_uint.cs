#version 430
precision lowp float;

#define INJECT_SHIFT 1.0
#define SH_F2I 0.25
#define SH_I2F 4.0

#define LPV_CASCADES_COUNT
#define LPV_SAMPLE_SIZE 3

#define LPV_DATA_R_SH 0
#define LPV_DATA_G_SH 1
#define LPV_DATA_B_SH 2

layout(local_size_x = 32, local_size_y = 32, local_size_z = 1) in;

uniform layout(rgba32f) writeonly image3D lpvAccumTexR;
uniform layout(rgba32f) writeonly image3D lpvAccumTexG;
uniform layout(rgba32f) writeonly image3D lpvAccumTexB;
uniform layout(r32ui) coherent uimage3D lpv0Tex;
uniform layout(r32ui) coherent uimage3D lpv1Tex;
uniform layout(r32ui) coherent uimage3D lpvAccumTex;
uniform layout(r32ui) readonly uimage3D gvTex;

uniform vec3 lpvTexSize;
uniform vec2 lpvParams;

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
    ivec3 texGlobPos = ivec3(lpvGlobTexX, y, z);

    ivec3 texPos = ivec3(texX, y, z);
    uint swap = 0;

    vec4 cosineLobe = vec4(0.8862, -1.0233, 1.0233, -1.0233);
    vec4 shBase = vec4(0.2821, -0.4886, 0.4886, -0.4886);

    vec3 dirs[6];
    dirs[0] = vec3(0.0, 0.0, -1.0); dirs[1] = vec3(0.0, 0.0, 1.0);
    dirs[2] = vec3(0.0, -1.0, 0.0); dirs[3] = vec3(0.0, 1.0, 0.0);
    dirs[4] = vec3(-1.0, 0.0, 0.0); dirs[5] = vec3(1.0, 0.0, 0.0);

    for(uint step = 0; step < uint(lpvParams.x); step++)
    {
      // clean swap
      if(swap == 0)
      {
        for(int i = 0; i < LPV_SAMPLE_SIZE; i++)
          imageStore(lpv1Tex, ivec3(lpvGlobTexX + i, y, z), ivec4(0, 0, 0, 0));
      }
      else
      {
        for(int i = 0; i < LPV_SAMPLE_SIZE; i++)
          imageStore(lpv0Tex, ivec3(lpvGlobTexX + i, y, z), ivec4(0, 0, 0, 0));
      }

      barrier();

#ifdef LPV_GATHERING
      vec4 shR = vec4(0.0);
      vec4 shG = vec4(0.0);
      vec4 shB = vec4(0.0);

      for(uint cell = 0; cell < 6; cell++)
      {
        ivec3 p = ivec3((texX + int(dirs[cell].x)) * LPV_SAMPLE_SIZE, y, z) + ivec3(0, int(dirs[cell].y), int(dirs[cell].z));

        vec4 shCellR;
        vec4 shCellG;
        vec4 shCellB;

        if(swap == 0)
        {
          shCellR = unpackSnorm4x8(uint(imageLoad(lpv0Tex, p + ivec3(LPV_DATA_R_SH, 0, 0)).x)) * SH_I2F;
          shCellG = unpackSnorm4x8(uint(imageLoad(lpv0Tex, p + ivec3(LPV_DATA_G_SH, 0, 0)).x)) * SH_I2F;
          shCellB = unpackSnorm4x8(uint(imageLoad(lpv0Tex, p + ivec3(LPV_DATA_B_SH, 0, 0)).x)) * SH_I2F;
        }
        else
        {
          shCellR = unpackSnorm4x8(uint(imageLoad(lpv1Tex, p + ivec3(LPV_DATA_R_SH, 0, 0)).x)) * SH_I2F;
          shCellG = unpackSnorm4x8(uint(imageLoad(lpv1Tex, p + ivec3(LPV_DATA_G_SH, 0, 0)).x)) * SH_I2F;
          shCellB = unpackSnorm4x8(uint(imageLoad(lpv1Tex, p + ivec3(LPV_DATA_B_SH, 0, 0)).x)) * SH_I2F;
        }

        for(int face = 0; face < 6; face++)
        {
          vec3 faceDir = dirs[face] * 0.5 - dirs[cell];
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

            shR += solidAngle * max(0.0, dot(shCellR, shNormal)) * shDir;
            shG += solidAngle * max(0.0, dot(shCellG, shNormal)) * shDir;
            shB += solidAngle * max(0.0, dot(shCellB, shNormal)) * shDir;
          }
        }
      }

      uint shRu = packSnorm4x8(shR * SH_F2I);
      uint shGu = packSnorm4x8(shG * SH_F2I);
      uint shBu = packSnorm4x8(shB * SH_F2I);

      if(swap == 0)
      {
        imageAtomicAdd(lpv1Tex, texGlobPos + ivec3(LPV_DATA_R_SH, 0, 0), shRu);
        imageAtomicAdd(lpv1Tex, texGlobPos + ivec3(LPV_DATA_G_SH, 0, 0), shGu);
        imageAtomicAdd(lpv1Tex, texGlobPos + ivec3(LPV_DATA_B_SH, 0, 0), shBu);
      }
      else
      {
        imageAtomicAdd(lpv0Tex, texGlobPos + ivec3(LPV_DATA_R_SH, 0, 0), shRu);
        imageAtomicAdd(lpv0Tex, texGlobPos + ivec3(LPV_DATA_G_SH, 0, 0), shGu);
        imageAtomicAdd(lpv0Tex, texGlobPos + ivec3(LPV_DATA_B_SH, 0, 0), shBu);
      }

      imageAtomicAdd(lpvAccumTex, texGlobPos + ivec3(LPV_DATA_R_SH, 0, 0), shRu);
      imageAtomicAdd(lpvAccumTex, texGlobPos + ivec3(LPV_DATA_G_SH, 0, 0), shGu);
      imageAtomicAdd(lpvAccumTex, texGlobPos + ivec3(LPV_DATA_B_SH, 0, 0), shBu);
#else
      vec4 shCellR = vec4(0.0);
      vec4 shCellG = vec4(0.0);
      vec4 shCellB = vec4(0.0);

      if(swap == 0)
      {
        shCellR = unpackSnorm4x8(uint(imageLoad(lpv0Tex, texGlobPos + ivec3(LPV_DATA_R_SH, 0, 0)).x)) * SH_I2F;
        shCellG = unpackSnorm4x8(uint(imageLoad(lpv0Tex, texGlobPos + ivec3(LPV_DATA_G_SH, 0, 0)).x)) * SH_I2F;
        shCellB = unpackSnorm4x8(uint(imageLoad(lpv0Tex, texGlobPos + ivec3(LPV_DATA_B_SH, 0, 0)).x)) * SH_I2F;
      }
      else
      {
        shCellR = unpackSnorm4x8(uint(imageLoad(lpv1Tex, texGlobPos + ivec3(LPV_DATA_R_SH, 0, 0)).x)) * SH_I2F;
        shCellG = unpackSnorm4x8(uint(imageLoad(lpv1Tex, texGlobPos + ivec3(LPV_DATA_G_SH, 0, 0)).x)) * SH_I2F;
        shCellB = unpackSnorm4x8(uint(imageLoad(lpv1Tex, texGlobPos + ivec3(LPV_DATA_B_SH, 0, 0)).x)) * SH_I2F;
      }

      for(uint cell = 0; cell < 6; cell++)
      {
        ivec3 p = ivec3((texX + int(dirs[cell].x)) * LPV_SAMPLE_SIZE, y, z) + ivec3(0, int(dirs[cell].y), int(dirs[cell].z));

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

            shR += solidAngle * max(0.0, dot(shCellR, shNormal)) * shDir;
            shG += solidAngle * max(0.0, dot(shCellG, shNormal)) * shDir;
            shB += solidAngle * max(0.0, dot(shCellB, shNormal)) * shDir;
          }
        }

        uint shRu = packSnorm4x8(shR * SH_F2I);
        uint shGu = packSnorm4x8(shG * SH_F2I);
        uint shBu = packSnorm4x8(shB * SH_F2I);

        if(swap == 0)
        {
          imageAtomicAdd(lpv1Tex, p + ivec3(LPV_DATA_R_SH, 0, 0), shRu);
          imageAtomicAdd(lpv1Tex, p + ivec3(LPV_DATA_G_SH, 0, 0), shGu);
          imageAtomicAdd(lpv1Tex, p + ivec3(LPV_DATA_B_SH, 0, 0), shBu);
        }
        else
        {
          imageAtomicAdd(lpv0Tex, p + ivec3(LPV_DATA_R_SH, 0, 0), shRu);
          imageAtomicAdd(lpv0Tex, p + ivec3(LPV_DATA_G_SH, 0, 0), shGu);
          imageAtomicAdd(lpv0Tex, p + ivec3(LPV_DATA_B_SH, 0, 0), shBu);
        }

        imageAtomicAdd(lpvAccumTex, p + ivec3(LPV_DATA_R_SH, 0, 0), shRu);
        imageAtomicAdd(lpvAccumTex, p + ivec3(LPV_DATA_G_SH, 0, 0), shGu);
        imageAtomicAdd(lpvAccumTex, p + ivec3(LPV_DATA_B_SH, 0, 0), shBu);
      }
#endif

      swap = (swap != 0) ? 0 : 1;
      barrier();
    }

    imageStore(lpvAccumTexR, texPos, unpackSnorm4x8(uint(imageLoad(lpvAccumTex, texGlobPos + ivec3(LPV_DATA_R_SH, 0, 0)).x)) * SH_I2F);
    imageStore(lpvAccumTexG, texPos, unpackSnorm4x8(uint(imageLoad(lpvAccumTex, texGlobPos + ivec3(LPV_DATA_G_SH, 0, 0)).x)) * SH_I2F);
    imageStore(lpvAccumTexB, texPos, unpackSnorm4x8(uint(imageLoad(lpvAccumTex, texGlobPos + ivec3(LPV_DATA_B_SH, 0, 0)).x)) * SH_I2F);
  }
}