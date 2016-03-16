#version 150
precision lowp float;

uniform vec3 lightAmb;

out vec4 glFragColor;

void main()
{
  glFragColor = vec4(lightAmb, 1.0);
}
