#version 430
precision lowp float;

#define INJECT_SHIFT 1.0
#define SH_F2I 1000.0
#define SH_I2F 0.001

#define LPV_CASCADES_COUNT
#define LPV_SUN_SKY_DIRS_COUNT
#define LPV_SH_COEFFS_COUNT 4
#define LPV_SAMPLE_SIZE 12
#define LPV_GV_SAMPLE_SIZE 8

#define LPV_DATA_R_SH0 0
#define LPV_DATA_R_SH1 1
#define LPV_DATA_R_SH2 2
#define LPV_DATA_R_SH3 3

#define LPV_DATA_G_SH0 4
#define LPV_DATA_G_SH1 5
#define LPV_DATA_G_SH2 6
#define LPV_DATA_G_SH3 7

#define LPV_DATA_B_SH0 8
#define LPV_DATA_B_SH1 9
#define LPV_DATA_B_SH2 10
#define LPV_DATA_B_SH3 11

layout(local_size_x = 32, local_size_y = 32, local_size_z = 1) in;

uniform layout(rgba32f) readonly image2D geomColorTex;
uniform layout(rgba32f) readonly image2D geomPosTex;
uniform layout(rgba32f) readonly image2D geomNormalTex;

uniform layout(r32i) coherent iimage3D lpv0Tex;
uniform layout(r32i) coherent iimage3D lpvAccumTex;
uniform layout(r32i) coherent iimage3D gvTex;

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

        vec4 shR = shNormal * light.r;
        vec4 shG = shNormal * light.g;
        vec4 shB = shNormal * light.b;

        imageAtomicAdd(lpv0Tex, texPos + ivec3(LPV_DATA_R_SH0, 0, 0), int(shR.x * SH_F2I));
        imageAtomicAdd(lpv0Tex, texPos + ivec3(LPV_DATA_R_SH1, 0, 0), int(shR.y * SH_F2I));
        imageAtomicAdd(lpv0Tex, texPos + ivec3(LPV_DATA_R_SH2, 0, 0), int(shR.z * SH_F2I));
        imageAtomicAdd(lpv0Tex, texPos + ivec3(LPV_DATA_R_SH3, 0, 0), int(shR.w * SH_F2I));

        imageAtomicAdd(lpv0Tex, texPos + ivec3(LPV_DATA_G_SH0, 0, 0), int(shG.x * SH_F2I));
        imageAtomicAdd(lpv0Tex, texPos + ivec3(LPV_DATA_G_SH1, 0, 0), int(shG.y * SH_F2I));
        imageAtomicAdd(lpv0Tex, texPos + ivec3(LPV_DATA_G_SH2, 0, 0), int(shG.z * SH_F2I));
        imageAtomicAdd(lpv0Tex, texPos + ivec3(LPV_DATA_G_SH3, 0, 0), int(shG.w * SH_F2I));

        imageAtomicAdd(lpv0Tex, texPos + ivec3(LPV_DATA_B_SH0, 0, 0), int(shB.x * SH_F2I));
        imageAtomicAdd(lpv0Tex, texPos + ivec3(LPV_DATA_B_SH1, 0, 0), int(shB.y * SH_F2I));
        imageAtomicAdd(lpv0Tex, texPos + ivec3(LPV_DATA_B_SH2, 0, 0), int(shB.z * SH_F2I));
        imageAtomicAdd(lpv0Tex, texPos + ivec3(LPV_DATA_B_SH3, 0, 0), int(shB.w * SH_F2I));

        imageAtomicAdd(lpvAccumTex, texPos + ivec3(LPV_DATA_R_SH0, 0, 0), int(shR.x * SH_F2I));
        imageAtomicAdd(lpvAccumTex, texPos + ivec3(LPV_DATA_R_SH1, 0, 0), int(shR.y * SH_F2I));
        imageAtomicAdd(lpvAccumTex, texPos + ivec3(LPV_DATA_R_SH2, 0, 0), int(shR.z * SH_F2I));
        imageAtomicAdd(lpvAccumTex, texPos + ivec3(LPV_DATA_R_SH3, 0, 0), int(shR.w * SH_F2I));

        imageAtomicAdd(lpvAccumTex, texPos + ivec3(LPV_DATA_G_SH0, 0, 0), int(shG.x * SH_F2I));
        imageAtomicAdd(lpvAccumTex, texPos + ivec3(LPV_DATA_G_SH1, 0, 0), int(shG.y * SH_F2I));
        imageAtomicAdd(lpvAccumTex, texPos + ivec3(LPV_DATA_G_SH2, 0, 0), int(shG.z * SH_F2I));
        imageAtomicAdd(lpvAccumTex, texPos + ivec3(LPV_DATA_G_SH3, 0, 0), int(shG.w * SH_F2I));

        imageAtomicAdd(lpvAccumTex, texPos + ivec3(LPV_DATA_B_SH0, 0, 0), int(shB.x * SH_F2I));
        imageAtomicAdd(lpvAccumTex, texPos + ivec3(LPV_DATA_B_SH1, 0, 0), int(shB.y * SH_F2I));
        imageAtomicAdd(lpvAccumTex, texPos + ivec3(LPV_DATA_B_SH2, 0, 0), int(shB.z * SH_F2I));
        imageAtomicAdd(lpvAccumTex, texPos + ivec3(LPV_DATA_B_SH3, 0, 0), int(shB.w * SH_F2I));
      }

      lpvP = ((p - lpvPos[cascade]) / (lpvTexSize.y * lpvCellSize[cascade] * 0.5)) * 0.5 + 0.5;

      if((lpvP.x >= 0.0) && (lpvP.x <= 1.0) &&
         (lpvP.y >= 0.0) && (lpvP.y <= 1.0) &&
         (lpvP.z >= 0.0) && (lpvP.z <= 1.0))
      { // clip
        lpvP.x = lpvP.x + float(cascade); // place X into correct lpv cascade
        lpvP *= lpvTexSize.y;
        ivec3 texPos = ivec3(lpvP) * ivec3(LPV_SH_COEFFS_COUNT, 1, 1);

        vec4 cosineLobe = vec4(0.8862, -1.0233, 1.0233, -1.0233);
        vec4 shNormal = cosineLobe * vec4(1.0, normal.y, normal.z, normal.x);

        imageAtomicMax(gvTex, texPos + ivec3(0, 0, 0), int(shNormal.x * SH_F2I));
        imageAtomicMax(gvTex, texPos + ivec3(1, 0, 0), int(shNormal.y * SH_F2I));
        imageAtomicMax(gvTex, texPos + ivec3(2, 0, 0), int(shNormal.z * SH_F2I));
        imageAtomicMax(gvTex, texPos + ivec3(3, 0, 0), int(shNormal.w * SH_F2I));

        imageAtomicMin(gvTex, texPos + ivec3(LPV_SH_COEFFS_COUNT + 0, 0, 0), int(shNormal.x * SH_F2I));
        imageAtomicMin(gvTex, texPos + ivec3(LPV_SH_COEFFS_COUNT + 1, 0, 0), int(shNormal.y * SH_F2I));
        imageAtomicMin(gvTex, texPos + ivec3(LPV_SH_COEFFS_COUNT + 2, 0, 0), int(shNormal.z * SH_F2I));
        imageAtomicMin(gvTex, texPos + ivec3(LPV_SH_COEFFS_COUNT + 3, 0, 0), int(shNormal.w * SH_F2I));
      }
    }
  }
}
