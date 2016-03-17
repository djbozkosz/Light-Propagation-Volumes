#version 150
precision lowp float;

in vec3 _vertexPosition;
#ifdef DIF_TEX
in vec2 _vertexTexCoord;
#endif

#ifndef GS_CASCADE
uniform mat4 mvp;

out vec2 texCoord;
#else
out vec2 _texCoord;
flat out int instanceID;
#endif

void main()
{
#ifndef GS_CASCADE
#ifdef DIF_TEX
  texCoord = _vertexTexCoord;
#endif
  gl_Position = mvp * vec4(_vertexPosition, 1.0);
#else
#ifdef DIF_TEX
  _texCoord = _vertexTexCoord;
#endif
  instanceID = gl_InstanceID;
  gl_Position = vec4(_vertexPosition, 1.0);
#endif
}
