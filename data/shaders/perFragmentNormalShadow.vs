#version 150
precision lowp float;

in vec3 _vertexPosition;
in vec3 _vertexNormal;
in vec3 _vertexNormalTangent;
//in vec3 _vertexNormalBitangent;
in vec2 _vertexTexCoord;
in vec4 _vertexColor;

uniform mat4 mw;
uniform mat3 mwnit;
uniform mat4 mvp;
uniform mat4 mvpdb;

out vec3 positionWorld;
out vec3 normal;
out vec2 texCoord;
out vec4 color;
out vec3 depthCoord;
out mat3 mtbnt;

void main()
{
  positionWorld = vec4(mw * vec4(_vertexPosition, 1.0)).xyz;
  normal = _vertexNormal;
  texCoord = _vertexTexCoord;
  color = _vertexColor;
  depthCoord = vec4(mvpdb * vec4(_vertexPosition, 1.0)).xyz * 0.5 + 0.5;
  mat3 m = mat3(normalize(mwnit * _vertexNormalTangent), normalize(mwnit * /*_vertexNormalBitangent*/cross(_vertexNormal, _vertexNormalTangent)), normalize(mwnit * _vertexNormal));
  mtbnt = mat3(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2]);
  gl_Position = mvp * vec4(_vertexPosition, 1.0);
}
