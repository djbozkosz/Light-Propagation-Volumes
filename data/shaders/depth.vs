#version 130
precision lowp float;

in vec3 _vertexPosition;
//in vec2 _vertexTexCoord;

uniform mat4 mvp;

//out vec2 texCoord;

void main()
{
  //texCoord = _vertexTexCoord;
  gl_Position = mvp * vec4(_vertexPosition, 1.0);
}
