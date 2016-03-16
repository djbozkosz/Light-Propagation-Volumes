#version 150
precision lowp float;

in vec3 _vertexPosition;
in vec2 _vertexTexCoord;
in vec4 _vertexColor;

uniform mat4 mvp;

out vec2 texCoord;
out vec4 color;

void main()
{
  texCoord = _vertexTexCoord;
  color = _vertexColor;
  gl_Position = mvp * vec4(_vertexPosition, 1.0);
}
