#version 130
precision lowp float;

in vec3 vertexPosition;
in vec2 vertexTexCoord;

uniform mat4 mvp;
uniform vec4 pos;
uniform vec2 texPos;
uniform vec3 lightPos;
uniform vec4 lightSpeColor;

out vec2 texCoord;
out vec4 color;

void main()
{
  texCoord = vertexTexCoord;
  color = lightSpeColor;
  vec3 newPos = vertexPosition * lightPos;
  float angle = acos(dot(vec3(1.0, 0.0, 0.0), normalize(newPos)));
  if(newPos.y < 0.0)
    angle = 6.28 - angle;
  angle += pos.w;
  vec3 newPos2 = vec3(cos(angle), sin(angle), 0.0) * length(newPos) * vec3(texPos, 1.0);
  //gl_Position = mvp * vec4(pos.xyz, 1.0) + vec4(vertexPosition * pos.w * vec3(texPos, 1.0), 1.0);
  //gl_Position = mvp * vec4(0.0,0.0,0.0, 1.0) + vec4(vertexPosition * lightPos * vec3(texPos, 1.0), 1.0);
  gl_Position = mvp * vec4(0.0,0.0,0.0, 1.0) + vec4(newPos2, 1.0);
  //gl_Position = mvp * vec4(vertexPosition* lightPos, 1.0);// + vec4(vertexPosition * lightPos * vec3(texPos, 1.0), 1.0);
}
