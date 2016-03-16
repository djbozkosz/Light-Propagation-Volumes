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

out vec3 _positionWorld;
out vec3 _normal;
out vec2 _texCoord;
out vec4 _color;
//out mat3 _mtbnt;
flat out int instanceID;

void main()
{
  _positionWorld = vec4(mw * vec4(_vertexPosition, 1.0)).xyz;
  _normal = _vertexNormal;
  _texCoord = _vertexTexCoord;
  _color = _vertexColor;
  //mat3 m = mat3(normalize(_vertexNormalTangent), normalize(/*_vertexNormalBitangent*/cross(_vertexNormal, _vertexNormalTangent)), normalize(_vertexNormal));
  //_mtbnt = mat3(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2]);
  instanceID = gl_InstanceID;
  gl_Position = vec4(_vertexPosition, 1.0);
}
