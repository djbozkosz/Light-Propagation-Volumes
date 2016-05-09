#version 150
precision lowp float;

in vec3 _vertexPosition;
#ifdef DIF_TEX
in vec2 _vertexTexCoord;
#endif

uniform mat4 mvp;

#ifdef DIF_TEX
out vec2 texCoord;
#endif

void main()
{
#ifdef DIF_TEX
  texCoord = _vertexTexCoord;
#endif

  gl_Position = mvp * vec4(_vertexPosition, 1.0);
}
