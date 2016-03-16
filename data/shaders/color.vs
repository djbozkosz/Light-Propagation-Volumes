#version 150
precision lowp float;

in vec3 _vertexPosition;
in vec2 _vertexTexCoord;

uniform mat4 mvp;

void main()
{
  vec2 t = _vertexTexCoord; // unused
  gl_Position = mvp * vec4(_vertexPosition, 1.0);
}
