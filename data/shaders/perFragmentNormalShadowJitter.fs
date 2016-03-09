#version 130
precision lowp float;

in vec3 positionWorld;
in vec3 normal;
in vec2 texCoord;
in vec4 color;
in vec3 depthCoord;
in mat3 mtbnt;

uniform mat3 mwnit;
uniform vec3 cam;

uniform sampler2D difTex;
uniform sampler2D speTex;
uniform sampler2D norTex;
uniform sampler2DShadow depthTex;
uniform sampler3D lpv0ImgR;
uniform sampler3D lpv0ImgG;
uniform sampler3D lpv0ImgB;

uniform int type;
uniform vec3 depthTexelSize;

uniform vec3 lightAmb;
uniform vec3 lightPos;
uniform vec2 lightRange;
uniform vec3 lightColor;
uniform vec4 lightSpeColor;
uniform vec2 fogRange;
uniform vec3 fogColor;

uniform vec4 lpvPos;
uniform vec3 lpvCellSize;

out vec4 glFragColor;

void main()
{
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

  vec4 fragDif = texture(difTex, texCoord);

  if(((type & 0x20000000) != 0) && (fragDif.a < 0.8))
    discard;

  vec3 n = normalize(mwnit * normalize(normal));
  vec4 sh = vec4(0.2821, -0.4886 * -n.y, 0.4886 * -n.z, -0.4886 * -n.x);
  vec3 p = (lpvPos.xyz + positionWorld) * lpvCellSize;
  vec4 lpvShR0 = texture(lpv0ImgR, p);
  vec4 lpvShG0 = texture(lpv0ImgG, p);
  vec4 lpvShB0 = texture(lpv0ImgB, p);
  vec3 lpvColor = vec3(dot(sh, lpvShR0), dot(sh, lpvShG0), dot(sh, lpvShB0)) * lpvPos.w;
  if((lpvColor.x < 0.0) || (lpvColor.y < 0.0) || (lpvColor.z < 0.0))
    lpvColor = vec3(0.0);

  vec3 fragSpe = texture(speTex, texCoord).rgb;

  float depthVis = 0.0;
  const int jitterSamples = 8;
  const float jitterVisStep = 1.0 / float(jitterSamples);
  for(int i = 0; i < jitterSamples; i++)
  {
    float rnd = fract(sin(dot(vec4(texCoord.x, texCoord.y, depthCoord.z, float(i)), vec4(12.9898, 78.233, 45.164, 94.673))) * 43758.5453);
    int j = int(16.0 * rnd) % 16;
    depthVis += jitterVisStep * texture(depthTex, vec3(depthCoord.xy + poissonDisk[j] * depthTexelSize.xy * depthTexelSize.z, depthCoord.z));
  }

  float fragDist = distance(cam, positionWorld);
  vec3 viewDirCam = normalize(cam - positionWorld);
  vec3 viewDir = normalize(mtbnt * viewDirCam);
  vec3 normalDir = normalize(texture(norTex, texCoord).rgb * 2.0 - 1.0);
  vec3 lightDir = lightPos - positionWorld;

  float lightDist = clamp((length(lightDir) - lightRange.x) / (lightRange.y - lightRange.x) * -1.0 + 1.0, 0.0, 1.0);
  lightDir = normalize(mtbnt * normalize(lightPos - positionWorld));
  float lightDot = max(0.0, dot(normalDir, lightDir)) * depthVis;

  vec3 colorDif = lightColor * lightDot * lightDist + lightAmb + lpvColor;
  vec3 colorSpe = lightSpeColor.rgb * pow(max(0.0, dot(viewDir, reflect(-lightDir, normalDir))), lightSpeColor.a) * lightDot * lightDist;

  float fogDist = clamp((fragDist - fogRange.x) / (fogRange.y - fogRange.x), 0.0, 1.0);
  /*float fogDot = pow(max(0.0, dot(normalize(cam - lightPos), viewDirCam)), 16.0);
  float fresPow = clamp(pow(1.0 - dot(viewDir, normalDir) * 0.5, 8.0), 0.0, 1.0) * 1.0;*/

  glFragColor = vec4(mix(fragDif.rgb * color.rgb * colorDif + fragSpe * colorSpe/* + fresPow * fogColor*/, fogColor/* + fogDot * lightColor*/, fogDist), 1.0);
}
