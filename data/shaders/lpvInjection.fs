#version 150
precision lowp float;

#define SSLPV_INTENSITY 1.8
#ifndef LPV_LOBE
#ifdef LPV_GV
#define GV_BLOCKING_MUL 2.0
#endif

#define LPV_CASCADES_COUNT
#define LPV_SUN_SKY_DIRS_COUNT
#define LPV_SUN_SKY_SPEC_DIRS_COUNT
#endif

#if !defined(LPV_SKY) && !defined(LPV_LOBE)
in vec2 texPos;
#else
in float texPos;
#endif

#ifndef LPV_LOBE
uniform sampler2D geomColorTex;
uniform sampler2D geomPosTex;
uniform sampler2D geomNormalTex;
//uniform sampler2D geomDepthTex;
#else
uniform sampler3D lpvNormalTex;
#endif

#ifndef LPV_LOBE
uniform vec3 lightAmb[LPV_SUN_SKY_DIRS_COUNT];
uniform vec3 lightPos[LPV_SUN_SKY_DIRS_COUNT];

uniform vec4 tiles;
uniform vec4 geomTexSize;
#ifdef LPV_SKY
uniform vec3 lpvPos[LPV_CASCADES_COUNT];
uniform vec3 lpvCellSize[LPV_CASCADES_COUNT];
#endif
#endif
uniform vec3 lpvTexSize;
uniform vec4 lpvParams;

#ifndef LPV_LOBE
#ifndef LPV_GV
out vec4 glFragColor0LpvR;
out vec4 glFragColor1LpvG;
out vec4 glFragColor2LpvB;
out vec4 glFragColor3LpvAccumR;
out vec4 glFragColor4LpvAccumG;
out vec4 glFragColor5LpvAccumB;
out vec4 glFragColor6LpvNormal;
#else
out vec4 glFragColor0Gv;
#endif
#else
out vec4 glFragColor0LpvNormal;
#endif

void main()
{
  vec4 cosineLobe = vec4(0.8862, -1.0233, 1.0233, -1.0233);

#if defined(LPV_SKY)
  int x = int(gl_FragCoord.x) % int(lpvTexSize.y);
  int y = int(texPos);
  int sunSkyLight = 1;
  int cascade = int(gl_FragCoord.x) / int(lpvTexSize.y);
  vec2 tex = vec2(float(x) / lpvTexSize.y * geomTexSize.x + geomTexSize.x, geomTexSize.y - (float(cascade) * geomTexSize.x + float(y) / lpvTexSize.y * geomTexSize.x)) * geomTexSize.zw;

  vec3 normal = vec3(0.0, 1.0, 0.0);
  vec4 shNormal = cosineLobe * vec4(1.0, -normal.y, -normal.z, -normal.x);
  vec3 pos = texture(geomPosTex, tex).xyz;
  float posY = gl_FragCoord.y * lpvCellSize[cascade].y - lpvTexSize.y * lpvCellSize[cascade].y * 0.5 + lpvPos[cascade].y;

  if(posY < pos.y)
    discard;

  vec3 light = lightAmb[sunSkyLight];
#elif !defined(LPV_LOBE)
  int x = int(texPos.x);
  int y = int(texPos.y);
  int sunSkyLight = x / int(geomTexSize.x * tiles.z);
  vec2 tex = vec2(float(x), geomTexSize.y - float(y)) * geomTexSize.zw;

  vec3 normal = normalize(texture(geomNormalTex, tex).xyz) * ((lpvParams.w > 0.0) ? 1.0 : -1.0);
  vec4 shNormal = cosineLobe * vec4(1.0, normal.y, normal.z, normal.x);
  vec3 pos = texture(geomPosTex, tex).xyz;

  vec3 light = texture(geomColorTex, tex).rgb * lightAmb[sunSkyLight];
#endif
#if defined(LPV_SKY) || !defined(LPV_LOBE)
#ifndef LPV_GV
  if(lpvParams.w > 0.0)
    light *= max(0.0, dot(normal, normalize(lightPos[sunSkyLight] - pos)));

  vec4 shR = shNormal * light.r;
  vec4 shG = shNormal * light.g;
  vec4 shB = shNormal * light.b;

  if(lpvParams.w < 0.0)
  {
    shR *= SSLPV_INTENSITY;
    shG *= SSLPV_INTENSITY;
    shB *= SSLPV_INTENSITY;
  }

  glFragColor0LpvR = shR;
  glFragColor1LpvG = shG;
  glFragColor2LpvB = shB;
  glFragColor3LpvAccumR = shR;
  glFragColor4LpvAccumG = shG;
  glFragColor5LpvAccumB = shB;
  glFragColor6LpvNormal = vec4(normal, 0.0);
#else
  glFragColor0Gv = shNormal * GV_BLOCKING_MUL;
#endif
#else
  vec3 tex = 1.0 / lpvTexSize;
  vec3 pos = vec3(gl_FragCoord.xy, texPos) * tex;

  glFragColor0LpvNormal = texture(lpvNormalTex, pos);
#endif
}
