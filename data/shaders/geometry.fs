#version 150
precision lowp float;

in vec3 positionWorld;
in vec3 normal;
in vec2 texCoord;
in vec4 color;
in mat3 mtbnti;

//uniform vec3 cam;

uniform sampler2D difTex;
uniform sampler2D norTex;

uniform int type;

/*uniform vec3 lightPos;
uniform vec2 lightRange;
uniform vec3 lightColor;*/

out vec4 glFragColor0;
out vec4 glFragColor1Pos;
out vec4 glFragColor2Normal;
//out float glFragColor3Depth;

void main()
{
  vec4 fragDif = texture(difTex, texCoord);

  if(((type & 0x20000000) != 0) && (fragDif.a < 0.8))
    discard;

  vec3 fragNor = texture(norTex, texCoord).rgb;
  vec3 normalDir;

  if((fragNor.r == 0.0) && (fragNor.g == 0.0) && (fragNor.b == 0.0))
    normalDir = normalize(normal);
  else
    normalDir = normalize(mtbnti * normalize(fragNor * 2.0 - 1.0));

  //vec3 viewDir = normalize(cam - positionWorld);
  /*vec3 lightDir = lightPos - positionWorld;

  float lightDist = clamp((length(lightDir) - lightRange.x) / (lightRange.y - lightRange.x) * -1.0 + 1.0, 0.0, 1.0);
  lightDir = normalize(lightDir);
  float lightDot = max(0.0, dot(normalDir, lightDir));

  vec3 colorDif = lightColor * lightDot * lightDist;*/

  glFragColor0 = vec4(fragDif.rgb * color.rgb/* * colorDif*/, ((type & 0x00200000) != 0) ? 1.0 : 0.0);
  glFragColor1Pos = vec4(positionWorld, 1.0);
  glFragColor2Normal = vec4(normalDir, 1.0); //vec4(mtbnt * normalize(texture(norTex, texCoord).rgb), 1.0);
  //glFragColor3Depth = gl_FragCoord.z;
}
