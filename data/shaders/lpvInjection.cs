#version 430
precision lowp float;

#define INJECT_SHIFT 1.0
#define GV_INJECT_SHIFT -2.0
#define SSLPV_INTENSITY 0.8
#define GV_BLOCKING_MUL 2.0
#define GS_CS_MUL 0.3

#define SH_F2I 1000.0
#define SH_I2F 0.001

#define LPV_CASCADES_COUNT
#define LPV_SUN_SKY_DIRS_COUNT
#define LPV_SH_COEFFS_COUNT 4
#define LPV_SAMPLE_SIZE 12

#define LPV_DATA_R_SH 0
#define LPV_DATA_G_SH 4
#define LPV_DATA_B_SH 8

layout(local_size_x = 32, local_size_y = 32, local_size_z = 1) in;

uniform layout(rgba32f) readonly image2D geomColorTex;
uniform layout(rgba32f) readonly image2D geomPosTex;
uniform layout(rgba32f) readonly image2D geomNormalTex;

uniform layout(r32i) coherent iimage3D lpv0Tex;
uniform layout(r32i) coherent iimage3D lpvAccumTex;
uniform layout(r32i) coherent iimage3D lpvNormalAccumTex;
uniform layout(r32i) coherent iimage3D gvTex;

uniform vec3 lightAmb[LPV_SUN_SKY_DIRS_COUNT];
uniform vec3 lightPos[LPV_SUN_SKY_DIRS_COUNT];
uniform vec4 tiles;
uniform vec4 geomTexSize;
uniform vec3 lpvPos[LPV_CASCADES_COUNT];
uniform vec3 lpvTexSize;
uniform vec3 lpvCellSize[LPV_CASCADES_COUNT];
uniform vec4 lpvParams;

vec4 imgLoad(in layout(r32i) readonly iimage3D img, in ivec3 pos, in float off)
{
  return vec4(
    float(imageLoad(img, pos + ivec3(off + 0, 0, 0)).x) * SH_I2F,
    float(imageLoad(img, pos + ivec3(off + 1, 0, 0)).x) * SH_I2F,
    float(imageLoad(img, pos + ivec3(off + 2, 0, 0)).x) * SH_I2F,
    float(imageLoad(img, pos + ivec3(off + 3, 0, 0)).x) * SH_I2F);
}

void imgStore(in layout(r32i) coherent iimage3D img, in ivec3 pos, in float off, in vec4 data)
{
  imageStore(img, pos + ivec3(off + 0, 0, 0), ivec4(data.x * SH_F2I, 0, 0, 0));
  imageStore(img, pos + ivec3(off + 1, 0, 0), ivec4(data.y * SH_F2I, 0, 0, 0));
  imageStore(img, pos + ivec3(off + 2, 0, 0), ivec4(data.z * SH_F2I, 0, 0, 0));
  imageStore(img, pos + ivec3(off + 3, 0, 0), ivec4(data.w * SH_F2I, 0, 0, 0));
}

void imgStoreAdd(in layout(r32i) coherent iimage3D img, in ivec3 pos, in float off, in vec4 data)
{
  imageAtomicAdd(img, pos + ivec3(off + 0, 0, 0), int(data.x * SH_F2I));
  imageAtomicAdd(img, pos + ivec3(off + 1, 0, 0), int(data.y * SH_F2I));
  imageAtomicAdd(img, pos + ivec3(off + 2, 0, 0), int(data.z * SH_F2I));
  imageAtomicAdd(img, pos + ivec3(off + 3, 0, 0), int(data.w * SH_F2I));
}

void imgStoreMax(in layout(r32i) coherent iimage3D img, in ivec3 pos, in float off, in vec4 data)
{
  imageAtomicMax(img, pos + ivec3(off + 0, 0, 0), int(data.x * SH_F2I));
  imageAtomicMax(img, pos + ivec3(off + 1, 0, 0), int(data.y * SH_F2I));
  imageAtomicMax(img, pos + ivec3(off + 2, 0, 0), int(data.z * SH_F2I));
  imageAtomicMax(img, pos + ivec3(off + 3, 0, 0), int(data.w * SH_F2I));
}

void main()
{
#ifndef LPV_SKY
  uint x = gl_GlobalInvocationID.x;
  uint y = gl_GlobalInvocationID.y;
  uint cascade = y / uint(geomTexSize.y * tiles.w);
  ivec2 tex = ivec2(x, uint(geomTexSize.y) - y);

  if((x < uint(geomTexSize.x)) && (y < uint(geomTexSize.y)))
  {
    vec4 light = imageLoad(geomColorTex, tex);

    if((length(light.rgb) > 0.0) && ((lpvParams.w > 0.0) || (light.a > 0.0)))
    {
      vec3 p = imageLoad(geomPosTex, tex).xyz;
      vec3 pos = p;
      vec3 lpvP;
      vec3 normal = normalize(imageLoad(geomNormalTex, tex).xyz) * ((lpvParams.w > 0.0) ? 1.0 : -1.0);

      vec4 cosineLobe = vec4(0.8862, -1.0233, 1.0233, -1.0233);
      vec4 shNormal = cosineLobe * vec4(1.0, normal.y, normal.z, normal.x);

#ifdef LPV_GV
      if(x < uint(geomTexSize.y * tiles.w))
      { // skin non light rsm fragments
#endif

        if(lpvParams.w > 0.0)
          pos += normal * lpvCellSize[cascade] * INJECT_SHIFT; // self illum shift

        lpvP = ((pos - lpvPos[cascade]) / (lpvTexSize.y * lpvCellSize[cascade] * 0.5)) * 0.5 + 0.5;

        if((lpvP.x >= 0.0) && (lpvP.x <= 1.0) &&
           (lpvP.y >= 0.0) && (lpvP.y <= 1.0) &&
           (lpvP.z >= 0.0) && (lpvP.z <= 1.0))
        { // clip
          lpvP.x = lpvP.x + float(cascade); // place X into correct lpv cascade
          lpvP *= lpvTexSize.y;
          ivec3 texPos = ivec3(lpvP) * ivec3(LPV_SAMPLE_SIZE, 1, 1);

          uint sunSkyLight = x / uint(geomTexSize.x * tiles.z);

          if(lpvParams.w > 0.0)
            light.rgb *= max(0.0, dot(normal, normalize(lightPos[sunSkyLight] - p)));

          vec4 shR = shNormal * light.r;
          vec4 shG = shNormal * light.g;
          vec4 shB = shNormal * light.b;

          if(lpvParams.w < 0.0)
          {
            shR *= SSLPV_INTENSITY;
            shG *= SSLPV_INTENSITY;
            shB *= SSLPV_INTENSITY;
          }

          imgStoreAdd(lpv0Tex, texPos, LPV_DATA_R_SH, shR);
          imgStoreAdd(lpv0Tex, texPos, LPV_DATA_G_SH, shG);
          imgStoreAdd(lpv0Tex, texPos, LPV_DATA_B_SH, shB);
          imgStoreAdd(lpvAccumTex, texPos, LPV_DATA_R_SH, shR);
          imgStoreAdd(lpvAccumTex, texPos, LPV_DATA_G_SH, shG);
          imgStoreAdd(lpvAccumTex, texPos, LPV_DATA_B_SH, shB);

          texPos = ivec3(lpvP) * ivec3(LPV_SH_COEFFS_COUNT * 2, 1, 1);
          imgStoreMax(lpvNormalAccumTex, texPos, 0, vec4(normal, 1.0));
        }

#ifdef LPV_GV
      }
#endif

      // gv
      pos = p;
      pos += lpvCellSize[cascade] * 0.5 + normal * lpvCellSize[cascade] * GV_INJECT_SHIFT;
      lpvP = ((pos - lpvPos[cascade]) / (lpvTexSize.y * lpvCellSize[cascade] * 0.5)) * 0.5 + 0.5;

      if((lpvP.x >= 0.0) && (lpvP.x <= 1.0) &&
         (lpvP.y >= 0.0) && (lpvP.y <= 1.0) &&
         (lpvP.z >= 0.0) && (lpvP.z <= 1.0))
      { // clip
        lpvP.x = lpvP.x + float(cascade); // place X into correct lpv cascade
        lpvP *= lpvTexSize.y;
        ivec3 texPos = ivec3(lpvP) * ivec3(LPV_SH_COEFFS_COUNT, 1, 1);

        shNormal *= GV_BLOCKING_MUL;

        imgStoreMax(gvTex, texPos, 0, shNormal);
      }
    }
  }

#else
  uint x = gl_GlobalInvocationID.x % uint(lpvTexSize.y);
  uint y = gl_GlobalInvocationID.y % uint(lpvTexSize.y);
  uint z = gl_GlobalInvocationID.y / uint(lpvTexSize.y);
  uint cascade = gl_GlobalInvocationID.x / uint(lpvTexSize.y);
  uint sunSkyLight = 1;

  if((cascade < LPV_CASCADES_COUNT) && (z < uint(lpvTexSize.z)))
  {
    ivec3 texPos = ivec3((cascade * uint(lpvTexSize.y) + x) * LPV_SAMPLE_SIZE, y, z);
    ivec2 tex = ivec2(float(x) / lpvTexSize.y * geomTexSize.x + geomTexSize.x, geomTexSize.y - (float(cascade) * geomTexSize.x + float(z) / lpvTexSize.y * geomTexSize.x));

    vec3 normal = vec3(0.0, 1.0, 0.0);
    vec4 cosineLobe = vec4(0.8862, -1.0233, 1.0233, -1.0233);
    vec4 shNormal = cosineLobe * vec4(1.0, -normal.y, -normal.z, -normal.x);
    vec3 pos = imageLoad(geomPosTex, tex).xyz;
    float posY = y * lpvCellSize[cascade].y - lpvTexSize.y * lpvCellSize[cascade].y * 0.5 + lpvPos[cascade].y;

    if(posY < pos.y)
      return;

    vec3 light = lightAmb[sunSkyLight];

    if(lpvParams.w > 0.0)
      light.rgb *= max(0.0, dot(normal, normalize(lightPos[sunSkyLight] - pos)));

    vec4 shR = shNormal * light.r;
    vec4 shG = shNormal * light.g;
    vec4 shB = shNormal * light.b;

    if(lpvParams.w < 0.0)
    {
      shR *= SSLPV_INTENSITY;
      shG *= SSLPV_INTENSITY;
      shB *= SSLPV_INTENSITY;
    }

    imgStoreAdd(lpv0Tex, texPos, LPV_DATA_R_SH, shR);
    imgStoreAdd(lpv0Tex, texPos, LPV_DATA_G_SH, shG);
    imgStoreAdd(lpv0Tex, texPos, LPV_DATA_B_SH, shB);
    imgStoreAdd(lpvAccumTex, texPos, LPV_DATA_R_SH, shR);
    imgStoreAdd(lpvAccumTex, texPos, LPV_DATA_G_SH, shG);
    imgStoreAdd(lpvAccumTex, texPos, LPV_DATA_B_SH, shB);
  }
#endif
}
