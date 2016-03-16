#version 150
precision lowp float;

in vec3 _vertexPosition;
in vec3 _vertexNormal;
in vec2 _vertexTexCoord;
in vec4 _vertexColor;

uniform mat4 mw;
uniform mat4 mvp;

out vec3 positionWorld;
out vec3 normal;
out vec2 texCoord;
out vec4 color;

void main()
{
  positionWorld = vec4(mw * vec4(_vertexPosition, 1.0)).xyz;
  normal = _vertexNormal;
  texCoord = _vertexTexCoord;
  color = _vertexColor;
  gl_Position = mvp * vec4(_vertexPosition, 1.0);
}
