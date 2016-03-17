#version 150
precision lowp float;

in vec3 _vertexPosition;
in vec2 _vertexTexCoord;

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
  texCoord = _vertexTexCoord;
  gl_Position = mvp * vec4(_vertexPosition, 1.0);
#else
  _texCoord = _vertexTexCoord;
  instanceID = gl_InstanceID;
  gl_Position = vec4(_vertexPosition, 1.0);
#endif
}
