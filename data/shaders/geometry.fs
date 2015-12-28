#version 130
precision lowp float;

in vec3 positionWorld;
in vec3 normal;
in vec2 texCoord;
in vec4 color;
//in mat3 mtbnt;

uniform sampler2D difTex;
uniform sampler2D norTex;

uniform int type;

out vec4 glFragColor;
out vec4 glFragColorPos;
out vec4 glFragColorNormal;
out float glFragColorDepth;

void main()
{
  vec4 fragDif = texture(difTex, texCoord);

  if(((type & 0x20000000) != 0) && (fragDif.a < 0.8))
    discard;

  glFragColor = vec4(texture(difTex, texCoord).rgb * color.rgb, 1.0);
  glFragColorPos = vec4(positionWorld, 1.0);
  glFragColorNormal = vec4(normal, 1.0); //vec4(mtbnt * normalize(texture(norTex, texCoord).rgb), 1.0);
  glFragColorDepth = gl_FragCoord.z;
}
