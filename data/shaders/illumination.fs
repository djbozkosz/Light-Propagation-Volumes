#version 150
precision lowp float;

#define BLINN_PHONG

#define SHADOW_CASCADES_COUNT 1
#define LPV_CASCADES_COUNT 1

in vec3 positionWorld;
#ifndef NOR_TEX
in vec3 normal;
#endif
in vec2 texCoord;
in vec4 color;
#ifdef SHAD_TEX
in vec3 shadowCoord[SHADOW_CASCADES_COUNT];
#endif
#ifdef NOR_TEX
in mat3 mtbnt;
#endif

#ifndef NOR_TEX
uniform mat3 mwnit;
#endif
uniform vec3 cam;

uniform sampler2D difTex;
#ifdef ALP_TEX
uniform sampler2D alpTex;
#endif
uniform sampler2D speTex;
#ifdef NOR_TEX
uniform sampler2D norTex;
#endif
#ifdef SHAD_TEX
uniform sampler2DShadow shadTex;
uniform sampler3D lpvTexR;
uniform sampler3D lpvTexG;
uniform sampler3D lpvTexB;
#endif

uniform int type;
#ifdef ALP_TEX
uniform float opacity;
#endif
#ifdef SHADOW_JITTER
uniform vec3 shadowTexSize;
#endif

uniform vec3 lightAmb;
uniform vec3 lightPos;
uniform vec2 lightRange;
uniform vec3 lightColor;
uniform vec4 lightSpeColor;
uniform vec2 fogRange;
uniform vec3 fogColor;

#ifdef SHAD_TEX
uniform vec4 lpvPos[LPV_CASCADES_COUNT];
uniform vec3 lpvCellSize[LPV_CASCADES_COUNT];
uniform vec2 lpvParams;
#endif

out vec4 glFragColor;

void main()
{
#ifdef SHADOW_JITTER
  // old ati radeon fix
  vec2 poissonDisk[16];
  poissonDisk[0] = vec2(-0.94201624, -0.39906216);
  poissonDisk[1] = vec2(0.94558609, -0.76890725);
  poissonDisk[2] = vec2(-0.094184101, -0.92938870);
  poissonDisk[3] = vec2(0.34495938, 0.29387760);
  poissonDisk[4] = vec2(-0.91588581, 0.45771432);
  poissonDisk[5] = vec2(-0.81544232, -0.87912464);
  poissonDisk[6] = vec2(-0.38277543, 0.27676845);
  poissonDisk[7] = vec2(0.97484398, 0.75648379);
  poissonDisk[8] = vec2(0.44323325, -0.97511554);
  poissonDisk[9] = vec2(0.53742981, -0.47373420);
  poissonDisk[10] = vec2(-0.26496911, -0.41893023);
  poissonDisk[11] = vec2(0.79197514, 0.19090188);
  poissonDisk[12] = vec2(-0.24188840, 0.99706507);
  poissonDisk[13] = vec2(-0.81409955, 0.91437590);
  poissonDisk[14] = vec2(0.19984126, 0.78641367);
  poissonDisk[15] = vec2(0.14383161, -0.14100790);
#endif

  vec4 fragDif = texture(difTex, texCoord);

  if(((type & 0x20000000) != 0) && (fragDif.a < 0.8))
    discard;

#ifndef SHAD_TEX
  vec3 lpvColor = vec3(0.0, 0.0, 0.0);
#else
  vec3 n = vec3(0.0, 1.0, 0.0);//normalize(mwnit * normalize(normal));
  vec4 sh = vec4(0.2821, -0.4886 * -n.y, 0.4886 * -n.z, -0.4886 * -n.x);
  vec3 p = (lpvPos[0].xyz + positionWorld) * lpvCellSize[0];
  vec4 lpvShR0 = texture(lpvTexR, p);
  vec4 lpvShG0 = texture(lpvTexG, p);
  vec4 lpvShB0 = texture(lpvTexB, p);
  vec3 lpvColor = vec3(dot(sh, lpvShR0), dot(sh, lpvShG0), dot(sh, lpvShB0)) * lpvParams.y;
  if((lpvColor.x < 0.0) || (lpvColor.y < 0.0) || (lpvColor.z < 0.0))
    lpvColor = vec3(0.0);
#endif

#ifdef ALP_TEX
  vec3 fragAlp = texture(alpTex, texCoord).rgb;
#endif
  vec3 fragSpe = texture(speTex, texCoord).rgb;
#ifdef NOR_TEX
  vec3 fragNor = texture(norTex, texCoord).rgb;
#endif

#ifndef SHAD_TEX
  float depthVis = 1.0;
#else
//#ifndef SHADOW_JITTER
  float depthVis = texture(shadTex, shadowCoord[0]);
  depthVis = 1.0;
  // debug
/*#else
  float depthVis = 0.0;
  const int jitterSamples = 8;
  const float jitterVisStep = 1.0 / float(jitterSamples);
  for(int i = 0; i < jitterSamples; i++)
  {
    float rnd = fract(sin(dot(vec4(texCoord.x, texCoord.y, shadowCoord[0].z, float(i)), vec4(12.9898, 78.233, 45.164, 94.673))) * 43758.5453);
    int j = int(16.0 * rnd) % 16;
    depthVis += jitterVisStep * texture(shadTex, vec3(shadowCoord[0].xy + poissonDisk[j] * shadowTexSize.xy * shadowTexSize.z, shadowCoord[0].z));
  }
#endif*/
#endif

  float fragDist = distance(cam, positionWorld);
  vec3 viewDirCam = normalize(cam - positionWorld);
#ifndef NOR_TEX
  vec3 viewDir = viewDirCam;
  vec3 normalDir = normalize(mwnit * normalize(normal));
#else
  vec3 viewDir = normalize(mtbnt * viewDirCam);
  vec3 normalDir = normalize(fragNor * 2.0 - 1.0);
#endif
  vec3 lightDir = lightPos - positionWorld;

  float lightDist = clamp((length(lightDir) - lightRange.x) / (lightRange.y - lightRange.x) * -1.0 + 1.0, 0.0, 1.0);
#ifndef NOR_TEX
  lightDir = normalize(lightDir);
#else
  lightDir = normalize(mtbnt * normalize(lightDir));
#endif
  float lightDot = max(0.0, dot(normalDir, lightDir)) * depthVis;

  vec3 colorDif = lightColor * lightDot * lightDist + lightAmb + lpvColor;
#ifndef BLINN_PHONG
  float lightSpecDot = max(0.0, dot(viewDir, reflect(-lightDir, normalDir))); // phong
#else
  float lightSpecDot = max(0.0, dot(normalDir, normalize(lightDir + viewDir))); // blinn-phong
#endif
  vec3 colorSpe = lightSpeColor.rgb * pow(lightSpecDot, lightSpeColor.a) * lightDot * lightDist;

  float fogDist = clamp((fragDist - fogRange.x) / (fogRange.y - fogRange.x), 0.0, 1.0);
  /*float fogDot = pow(max(0.0, dot(normalize(cam - lightPos), viewDirCam)), 16.0);
  float fresPow = clamp(pow(1.0 - dot(viewDir, normalDir) * 0.5, 8.0), 0.0, 1.0) * 1.0;*/

#ifndef ALP_TEX
  float alpha = 1.0;
#else
  float alpha = (fragAlp.r + fragAlp.g + fragAlp.b) * 0.3333333334 * color.a * opacity + (colorSpe.r + colorSpe.g + colorSpe.b) * 0.3333333334;
#endif
  glFragColor = vec4(mix(fragDif.rgb * color.rgb * colorDif + fragSpe * colorSpe/* + fresPow * fogColor*/, fogColor/* + fogDot * lightColor*/, fogDist), alpha);
}
