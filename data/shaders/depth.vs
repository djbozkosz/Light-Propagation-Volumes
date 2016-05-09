#version 150
precision lowp float;

#define SHADOW_CASCADES_COUNT

in vec3 _vertexPosition;
#ifdef DIF_TEX
in vec2 _vertexTexCoord;
#endif

#ifndef CASCADE
uniform mat4 mvp;

#ifdef DIF_TEX
out vec2 texCoord;
#endif
#else
uniform mat4 mvp[SHADOW_CASCADES_COUNT];

uniform vec4 tiles;
uniform int tileInstances[SHADOW_CASCADES_COUNT];

#ifdef DIF_TEX
out vec2 texCoord;
#endif
#endif

void main()
{
#ifdef DIF_TEX
  texCoord = _vertexTexCoord;
#endif

#ifndef CASCADE
  gl_Position = mvp * vec4(_vertexPosition, 1.0);
#else
  int ti = tileInstances[gl_InstanceID];
  vec2 tileMin = vec2(float(ti % int(tiles.x)), float(ti / int(tiles.x))) * tiles.zw * 2.0 - 1.0;
  vec2 tileMax = tileMin + tiles.zw * 2.0;
  vec4 p = mvp[ti] * vec4(_vertexPosition, 1.0);

  gl_ClipDistance[0] = dot(vec4(1.0, 0.0, 0.0, -tileMin.x), p);
  gl_ClipDistance[1] = dot(vec4(-1.0, 0.0, 0.0, tileMax.x), p);
  gl_ClipDistance[2] = dot(vec4(0.0, -1.0, 0.0, -tileMin.y), p);
  gl_ClipDistance[3] = dot(vec4(0.0, 1.0, 0.0, tileMax.y), p);

  gl_Position = p;
#endif
}
