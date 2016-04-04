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
  vec2 tileMin = vec2(float(ti % int(tiles.x)), float(ti / int(tiles.x))) * tiles.zw;
  vec4 p = mvp[ti] * vec4(_vertexPosition, 1.0);
  vec2 clip = (p.xy * 0.5 + 0.5) * tiles.zw + tileMin;

  gl_ClipDistance[0] = clip.x - tileMin.x;
  gl_ClipDistance[1] = tiles.z - clip.x + tileMin.x;
  gl_ClipDistance[2] = clip.y - tileMin.y;
  gl_ClipDistance[3] = tiles.w - clip.y + tileMin.y;
  gl_Position = vec4(clip * 2.0 - 1.0, p.z, p.w);
#endif
}
