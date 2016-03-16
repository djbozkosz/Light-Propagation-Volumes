#version 150
precision lowp float;

in vec3 _vertexPosition;
in vec2 _vertexTexCoord;

out vec2 _texCoord;

void main()
{
  _texCoord = _vertexTexCoord;
  gl_Position = vec4(_vertexPosition, 1.0);
}
