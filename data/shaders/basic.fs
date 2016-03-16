#version 150
precision lowp float;

in vec2 texCoord;
in vec4 color;

uniform sampler2D difTex;

out vec4 glFragColor;

void main()
{
  glFragColor = vec4(texture(difTex, texCoord).rgb * color.rgb, 1.0);
}
