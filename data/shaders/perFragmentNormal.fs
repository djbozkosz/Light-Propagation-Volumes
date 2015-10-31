#version 130
precision lowp float;

in vec3 positionWorld;
in vec2 texCoord;
in vec4 color;
in vec3 depthCoord;
in mat3 mtbnt;

uniform vec3 cam;

uniform sampler2D difTex;
uniform sampler2D speTex;
uniform sampler2D norTex;
uniform sampler2DShadow depthTex;

uniform int type;
uniform vec3 depthTexelSize;

uniform vec3 lightAmb;
uniform vec3 lightPos;
uniform vec2 lightRange;
uniform vec3 lightColor;
uniform vec4 lightSpeColor;
uniform vec2 fogRange;
uniform vec3 fogColor;

out vec4 glFragColor;

const vec2 poissonDisk[16] = vec2[]
(
  vec2(-0.94201624, -0.39906216),
  vec2(0.94558609, -0.76890725),
  vec2(-0.094184101, -0.92938870),
  vec2(0.34495938, 0.29387760),
  vec2(-0.91588581, 0.45771432),
  vec2(-0.81544232, -0.87912464),
  vec2(-0.38277543, 0.27676845),
  vec2(0.97484398, 0.75648379),
  vec2(0.44323325, -0.97511554),
  vec2(0.53742981, -0.47373420),
  vec2(-0.26496911, -0.41893023),
  vec2(0.79197514, 0.19090188),
  vec2(-0.24188840, 0.99706507),
  vec2(-0.81409955, 0.91437590),
  vec2(0.19984126, 0.78641367),
  vec2(0.14383161, -0.14100790)
);

void main()
{
  vec4 fragDif = texture(difTex, texCoord);

  if(((type & 0x20000000) != 0) && (fragDif.a < 0.8))
    discard;

  float depthVis = 0.0;
  // one sample
  //float depthVis = texture(depthTex, depthCoord);
  // for sample
  /*for(float y = -depthTexelSize.y * 2.0; y <= depthTexelSize.y * 2.0; y += depthTexelSize.y * 2.0)
    for(float x = -depthTexelSize.x * 2.0; x <= depthTexelSize.x * 2.0; x += depthTexelSize.x * 2.0)
      depthVis += 0.11111 * texture(depthTex, depthCoord + vec3(x, y, 0.0));*/
  // 4 samples
  /*depthVis += 0.25 * texture(depthTex, depthCoord + vec3(depthTexelSize.x, depthTexelSize.y, 0.0));
  depthVis += 0.25 * texture(depthTex, depthCoord + vec3(depthTexelSize.x, -depthTexelSize.y, 0.0));
  depthVis += 0.25 * texture(depthTex, depthCoord + vec3(-depthTexelSize.x, depthTexelSize.y, 0.0));
  depthVis += 0.25 * texture(depthTex, depthCoord + vec3(-depthTexelSize.x, -depthTexelSize.y, 0.0));*/
  // for jittering
  /*const int jitterSamples = 4;
  const float jitterVisStep = 1.0 / float(jitterSamples);
  for(int i = 0; i < jitterSamples; i++)
  {
    float rnd = fract(sin(dot(vec4(texCoord.x, texCoord.y, depthCoord.z, float(i)), vec4(12.9898, 78.233, 45.164, 94.673))) * 43758.5453);
    int j = int(16.0 * rnd) % 16;
    depthVis += jitterVisStep * texture(depthTex, vec3(depthCoord.xy + poissonDisk[j] * depthTexelSize.xy * depthTexelSize.z, depthCoord.z));
  }*/
  // 4 jittering
  depthVis += 0.25 * texture(depthTex, vec3(depthCoord.xy + poissonDisk[int(16.0 * fract(sin(dot(vec4(texCoord.x, texCoord.y, depthCoord.z, 0.0), vec4(12.9898, 78.233, 45.164, 94.673))) * 43758.5453)) % 16] * depthTexelSize.xy * depthTexelSize.z, depthCoord.z));
  depthVis += 0.25 * texture(depthTex, vec3(depthCoord.xy + poissonDisk[int(16.0 * fract(sin(dot(vec4(texCoord.x, texCoord.y, depthCoord.z, 1.0), vec4(12.9898, 78.233, 45.164, 94.673))) * 43758.5453)) % 16] * depthTexelSize.xy * depthTexelSize.z, depthCoord.z));
  depthVis += 0.25 * texture(depthTex, vec3(depthCoord.xy + poissonDisk[int(16.0 * fract(sin(dot(vec4(texCoord.x, texCoord.y, depthCoord.z, 2.0), vec4(12.9898, 78.233, 45.164, 94.673))) * 43758.5453)) % 16] * depthTexelSize.xy * depthTexelSize.z, depthCoord.z));
  depthVis += 0.25 * texture(depthTex, vec3(depthCoord.xy + poissonDisk[int(16.0 * fract(sin(dot(vec4(texCoord.x, texCoord.y, depthCoord.z, 3.0), vec4(12.9898, 78.233, 45.164, 94.673))) * 43758.5453)) % 16] * depthTexelSize.xy * depthTexelSize.z, depthCoord.z));

  vec3 fragSpe = texture(speTex, texCoord).rgb;

  float fragDist = distance(cam, positionWorld);
  vec3 viewDirCam = normalize(cam - positionWorld);
  vec3 viewDir = normalize(mtbnt * viewDirCam);
  vec3 normalDir = normalize(texture(norTex, texCoord).rgb * 2.0 - 1.0) * vec3(-1.0, 1.0, 1.0);
  vec3 lightDir = lightPos - positionWorld;

  float lightDist = clamp((length(lightDir) - lightRange.x) / (lightRange.y - lightRange.x) * -1.0 + 1.0, 0.0, 1.0);
  lightDir = normalize(mtbnt * normalize(lightPos - positionWorld));
  float lightDot = max(0.0, dot(normalDir, lightDir)) * depthVis;

  vec3 colorDif = lightColor * lightDot * lightDist + lightAmb;
  vec3 colorSpe = lightSpeColor.rgb * pow(max(0.0, dot(viewDir, reflect(-lightDir, normalDir))), lightSpeColor.a) * lightDot * lightDist;

  float fogDist = clamp((fragDist - fogRange.x) / (fogRange.y - fogRange.x), 0.0, 1.0);
  /*float fogDot = pow(max(0.0, dot(normalize(cam - lightPos), viewDirCam)), 16.0);
  float fresPow = clamp(pow(1.0 - dot(viewDir, normalDir) * 0.5, 8.0), 0.0, 1.0) * 1.0;*/

  glFragColor = vec4(mix(fragDif.rgb * color.rgb * colorDif + fragSpe * colorSpe/* + fresPow * fogColor*/, fogColor/* + fogDot * lightColor*/, fogDist), 1.0);
}
