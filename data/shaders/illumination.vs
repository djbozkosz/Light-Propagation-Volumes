#version 150
precision lowp float;

#define SHADOW_CASCADES_COUNT 1

in vec3 _vertexPosition;
in vec3 _vertexNormal;
#ifdef NOR_TEX
in vec3 _vertexNormalTangent;
in vec3 _vertexNormalBitangent;
#endif
in vec2 _vertexTexCoord;
in vec4 _vertexColor;

uniform mat4 mw;
uniform mat3 mwnit;
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
out mat3 mtbnti;
#endif

#ifdef NOR_TEX
mat3 inv(mat3 m)
{
  float a00 = m[0][0], a01 = m[0][1], a02 = m[0][2];
  float a10 = m[1][0], a11 = m[1][1], a12 = m[1][2];
  float a20 = m[2][0], a21 = m[2][1], a22 = m[2][2];

  float b01 = a22 * a11 - a12 * a21;
  float b11 = -a22 * a10 + a12 * a20;
  float b21 = a21 * a10 - a11 * a20;

  float det = a00 * b01 + a01 * b11 + a02 * b21;

  return mat3(b01, (-a22 * a01 + a02 * a21), (a12 * a01 - a02 * a11),
              b11, (a22 * a00 - a02 * a20), (-a12 * a00 + a02 * a10),
              b21, (-a21 * a00 + a01 * a20), (a11 * a00 - a01 * a10)) / det;
}
#endif

void main()
{
  positionWorld = vec4(mw * vec4(_vertexPosition, 1.0)).xyz;
#ifndef NOR_TEX
  normal = mwnit * _vertexNormal;
#endif
  texCoord = _vertexTexCoord;
  color = _vertexColor;
#ifdef SHAD_TEX
  shadowCoord[0] = vec4(mvpsb[0] * vec4(_vertexPosition, 1.0)).xyz;
#endif
#ifdef NOR_TEX
  mtbnti = inv(transpose(mat3(normalize(mwnit * _vertexNormalTangent), normalize(mwnit * _vertexNormalBitangent), normalize(mwnit * _vertexNormal))));
#endif
  gl_Position = mvp * vec4(_vertexPosition, 1.0);
}
