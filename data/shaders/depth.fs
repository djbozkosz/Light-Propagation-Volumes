#version 150
precision lowp float;

in vec2 texCoord;

out float glFragColor;

void main()
{
  vec2 t = texCoord; // unused
  glFragColor = gl_FragCoord.z;
}
