#version 130
precision lowp float;

in vec3 _vertexPosition;

uniform mat4 mvp;

void main()
{
  gl_Position = mvp * vec4(_vertexPosition, 1.0);
}
