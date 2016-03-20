#version 150
precision lowp float;

#define SHADOW_CASCADES_COUNT 1

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
uniform int tileInstances;

#ifdef DIF_TEX
out vec2 texCoord;
#endif
#endif

void main()
{
#ifndef CASCADE
#ifdef DIF_TEX
  texCoord = _vertexTexCoord;
#endif
  gl_Position = mvp * vec4(_vertexPosition, 1.0);
#else
#ifdef DIF_TEX
  texCoord = _vertexTexCoord;
#endif
  //int x = gl_InstanceID % int(tiles.x);
  //int y = gl_InstanceID / int(tiles.x);
  int t = tileInstances;
  int ti = 0;
  for(int i = 0; i < SHADOW_CASCADES_COUNT; i++, t >>= 1)
  {
    if((t & 1) != 0)
    {
      if(ti == gl_InstanceID)
        break;
      ti++;
    }
  }
  gl_ClipDistance[0] = _vertexPosition.x;
  gl_Position = mvp[ti] * vec4(_vertexPosition, 1.0);
#endif
}
