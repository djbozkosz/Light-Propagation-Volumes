#version 150
precision lowp float;

in vec3 _vertexPosition;
in vec3 _vertexNormal;
in vec3 _vertexNormalTangent;
//in vec3 _vertexNormalBitangent;
in vec2 _vertexTexCoord;
in vec4 _vertexColor;

uniform mat4 mw;
//uniform mat3 mwnit;
#ifndef GS_CASCADE
uniform mat4 mvp;

out vec3 positionWorld;
out vec3 normal;
out vec2 texCoord;
out vec4 color;
//out mat3 mtbnt;
#else
out vec3 _positionWorld;
out vec3 _normal;
out vec2 _texCoord;
out vec4 _color;
//out mat3 _mtbnt;
flat out int instanceID;
#endif

void main()
{
#ifndef GS_CASCADE
  positionWorld = vec4(mw * vec4(_vertexPosition, 1.0)).xyz;
  normal = _vertexNormal;
  texCoord = _vertexTexCoord;
  color = _vertexColor;
  //mtbnt = transpose(mat3(normalize(_vertexNormalTangent), normalize(/*_vertexNormalBitangent*/cross(_vertexNormal, _vertexNormalTangent)), normalize(_vertexNormal)));
  gl_Position = mvp * vec4(_vertexPosition, 1.0);
#else
  _positionWorld = vec4(mw * vec4(_vertexPosition, 1.0)).xyz;
  _normal = _vertexNormal;
  _texCoord = _vertexTexCoord;
  _color = _vertexColor;
  //_mtbnt = transpose(mat3(normalize(_vertexNormalTangent), normalize(/*_vertexNormalBitangent*/cross(_vertexNormal, _vertexNormalTangent)), normalize(_vertexNormal)));
  instanceID = gl_InstanceID;
  gl_Position = vec4(_vertexPosition, 1.0);
#endif
}
