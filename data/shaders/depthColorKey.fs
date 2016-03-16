#version 150
precision lowp float;

in vec2 texCoord;

uniform sampler2D difTex;

out float glFragColor;

void main()
{
  if(texture(difTex, texCoord).a < 0.8)
    discard;

  glFragColor = gl_FragCoord.z;
}
