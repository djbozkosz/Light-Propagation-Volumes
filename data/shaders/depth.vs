#version 130
precision lowp float;

in vec3 vertexPosition;
//in vec2 vertexTexCoord;

uniform mat4 mvp;

//out vec2 texCoord;

void main()
{
  //texCoord = vertexTexCoord;
  gl_Position = mvp * vec4(vertexPosition, 1.0);
}
