#version 430
precision lowp float;

#define INJECT_SHIFT 1.0
#define SH_F2I 0.25
#define SH_I2F 4.0

#define LPV_CASCADES_COUNT
#define LPV_SUN_SKY_DIRS_COUNT
#define LPV_SAMPLE_SIZE 3

#define LPV_DATA_R_SH 0
#define LPV_DATA_G_SH 1
#define LPV_DATA_B_SH 2

layout(local_size_x = 32, local_size_y = 32, local_size_z = 1) in;

uniform layout(rgba32f) readonly image2D geomColorTex;
uniform layout(rgba32f) readonly image2D geomPosTex;
uniform layout(rgba32f) readonly image2D geomNormalTex;

uniform layout(r32ui) coherent uimage3D lpv0Tex;
uniform layout(r32ui) coherent uimage3D lpvAccumTex;
uniform layout(r32ui) coherent uimage3D gvTex;

uniform vec3 lightAmb[LPV_SUN_SKY_DIRS_COUNT];
uniform vec3 lightPos[LPV_SUN_SKY_DIRS_COUNT];
uniform vec4 tiles;
uniform vec4 geomTexSize;
uniform vec3 lpvPos[LPV_CASCADES_COUNT];
uniform vec3 lpvTexSize;
uniform vec3 lpvCellSize[LPV_CASCADES_COUNT];

void main()
{
  uint x = gl_GlobalInvocationID.x;
  uint y = gl_GlobalInvocationID.y;
  uint cascade = y / uint(geomTexSize.y * tiles.w);

  if((x < uint(geomTexSize.x)) && (y < uint(geomTexSize.y)))
  {
    vec3 light = imageLoad(geomColorTex, ivec2(x, y)).rgb;

    if(length(light) > 0.0)
    {
      vec3 p = imageLoad(geomPosTex, ivec2(x, y)).xyz;
      vec3 pos = p;
      vec3 normal = normalize(imageLoad(geomNormalTex, ivec2(x, y)).xyz);
      pos += normal * lpvCellSize[cascade] * INJECT_SHIFT; // self illum shift

      vec3 lpvP = ((pos - lpvPos[cascade]) / (lpvTexSize.y * lpvCellSize[cascade] * 0.5)) * 0.5 + 0.5;

      if((lpvP.x >= 0.0) && (lpvP.x <= 1.0) &&
         (lpvP.y >= 0.0) && (lpvP.y <= 1.0) &&
         (lpvP.z >= 0.0) && (lpvP.z <= 1.0))
      { // clip
        lpvP.x = lpvP.x + float(cascade); // place X into correct lpv cascade
        lpvP *= lpvTexSize.y;
        ivec3 texPos = ivec3(lpvP) * ivec3(LPV_SAMPLE_SIZE, 1, 1);

        uint sunSkyLight = x / uint(geomTexSize.x * tiles.z);
        light *= max(0.0, dot(normal, normalize(lightPos[sunSkyLight] - p)));

        vec4 cosineLobe = vec4(0.8862, -1.0233, 1.0233, -1.0233);
        vec4 shNormal = cosineLobe * vec4(1.0, normal.y, normal.z, normal.x);

        uint shR = packSnorm4x8(shNormal * light.r * SH_F2I);
        uint shG = packSnorm4x8(shNormal * light.g * SH_F2I);
        uint shB = packSnorm4x8(shNormal * light.b * SH_F2I);

        imageAtomicAdd(lpv0Tex, texPos + ivec3(LPV_DATA_R_SH, 0, 0), shR);
        imageAtomicAdd(lpv0Tex, texPos + ivec3(LPV_DATA_G_SH, 0, 0), shG);
        imageAtomicAdd(lpv0Tex, texPos + ivec3(LPV_DATA_B_SH, 0, 0), shB);

        imageAtomicAdd(lpvAccumTex, texPos + ivec3(LPV_DATA_R_SH, 0, 0), shR);
        imageAtomicAdd(lpvAccumTex, texPos + ivec3(LPV_DATA_G_SH, 0, 0), shG);
        imageAtomicAdd(lpvAccumTex, texPos + ivec3(LPV_DATA_B_SH, 0, 0), shB);
      }

      lpvP = ((p - lpvPos[cascade]) / (lpvTexSize.y * lpvCellSize[cascade] * 0.5)) * 0.5 + 0.5;

      if((lpvP.x >= 0.0) && (lpvP.x <= 1.0) &&
         (lpvP.y >= 0.0) && (lpvP.y <= 1.0) &&
         (lpvP.z >= 0.0) && (lpvP.z <= 1.0))
      { // clip
        lpvP.x = lpvP.x + float(cascade); // place X into correct lpv cascade
        lpvP *= lpvTexSize.y;

        vec4 cosineLobe = vec4(0.8862, -1.0233, 1.0233, -1.0233);
        uint shNormal = packSnorm4x8(cosineLobe * vec4(1.0, normal.y, normal.z, normal.x) * SH_F2I);

        imageAtomicMax(gvTex, ivec3(lpvP), shNormal);
      }
    }
  }
}
