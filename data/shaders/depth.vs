#version 130
precision lowp float;

in vec3 vertexPosition;
in vec2 vertexTexCoord;
in vec4 vertexColor;

uniform mat4 mvp;

out vec2 texCoord;
out vec4 color;

void main()
{
  texCoord = vertexTexCoord;
  color = vertexColor;
  gl_Position = mvp * vec4(vertexPosition, 1.0);
}
