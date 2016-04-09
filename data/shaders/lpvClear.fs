#version 150
precision lowp float;

out vec4 glFragColor0LpvR;
out vec4 glFragColor1LpvG;
out vec4 glFragColor2LpvB;
out vec4 glFragColor3LpvAccumR;
out vec4 glFragColor4LpvAccumG;
out vec4 glFragColor5LpvAccumB;
out vec4 glFragColor6Gv;

void main()
{
  glFragColor0LpvR = vec4(0.0);
  glFragColor1LpvG = vec4(0.0);
  glFragColor2LpvB = vec4(0.0);
  glFragColor3LpvAccumR = vec4(0.0);
  glFragColor4LpvAccumG = vec4(0.0);
  glFragColor5LpvAccumB = vec4(0.0);
  glFragColor6Gv = vec4(0.0);
}
