#version 130
precision lowp float;

//in vec2 texCoord;
//in vec4 color;

//uniform sampler2D difTex;

out float glFragColor;

void main()
{
  glFragColor = gl_FragCoord.z;
}
