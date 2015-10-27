#version 130
precision lowp float;

in vec3 vertexPosition;
in vec2 vertexTexCoord;
in vec4 vertexColor;

uniform vec4 pos;
uniform vec2 texPos;

out vec2 texCoord;
out vec4 color;

void main()
{
  vec2 pos = (vertexPosition.xy * pos.zw + pos.xy) * 2.0 - 1.0;

  texCoord = vertexTexCoord + texPos;
  color = vertexColor;
  gl_Position = vec4(pos.x, pos.y, 0.0, 1.0);
}
