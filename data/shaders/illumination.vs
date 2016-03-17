#version 150
precision lowp float;

#define SHADOW_CASCADES_COUNT 1

in vec3 _vertexPosition;
in vec3 _vertexNormal;
#ifdef NOR_TEX
in vec3 _vertexNormalTangent;
//in vec3 _vertexNormalBitangent;
#endif
in vec2 _vertexTexCoord;
in vec4 _vertexColor;

uniform mat4 mw;
#ifdef NOR_TEX
uniform mat3 mwnit;
#endif
uniform mat4 mvp;
#ifdef SHAD_TEX
uniform mat4 mvpsb[SHADOW_CASCADES_COUNT];
#endif

out vec3 positionWorld;
#ifndef NOR_TEX
out vec3 normal;
#endif
out vec2 texCoord;
out vec4 color;
#ifdef SHAD_TEX
out vec3 shadowCoord[SHADOW_CASCADES_COUNT];
#endif
#ifdef NOR_TEX
out mat3 mtbnt;
#endif

void main()
{
  positionWorld = vec4(mw * vec4(_vertexPosition, 1.0)).xyz;
#ifndef NOR_TEX
  normal = _vertexNormal;
#endif
  texCoord = _vertexTexCoord;
  color = _vertexColor;
#ifdef SHAD_TEX
  shadowCoord[0] = vec4(mvpsb[0] * vec4(_vertexPosition, 1.0)).xyz;
#endif
#ifdef NOR_TEX
  mtbnt = transpose(mat3(normalize(mwnit * _vertexNormalTangent), normalize(mwnit * /*_vertexNormalBitangent*/cross(_vertexNormal, _vertexNormalTangent)), normalize(mwnit * _vertexNormal)));
#endif
  gl_Position = mvp * vec4(_vertexPosition, 1.0);
}
