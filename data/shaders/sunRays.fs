#version 150
precision lowp float;

in vec2 texCoord;

uniform sampler2D difTex;

uniform vec3 lightAmb;

out vec4 glFragColor;

void main()
{
  vec2 lightDir = (texCoord - lightAmb.xy);
  vec2 coord = texCoord;
  vec2 offset = lightDir / 50.0 * 0.95;
  vec3 color = vec3(0.0, 0.0, 0.0);

  for(int i = 0; i < 50; i++)
  {
    coord -= offset;
    color += texture(difTex, coord).rgb / 50.0;
  }

  glFragColor = vec4(color * max(0.0, lightAmb.z), 1.0);
}
