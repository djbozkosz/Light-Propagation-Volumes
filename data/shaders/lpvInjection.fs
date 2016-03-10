#version 150
precision lowp float;

out vec4 glFragColor0LpvR;
out vec4 glFragColor1LpvG;
out vec4 glFragColor2LpvB;
out vec4 glFragColor3Gv;

void main()
{
  glFragColor0LpvR = vec4(0.33, 0.0, 0.0, 1.0);
  glFragColor1LpvG = vec4(0.33, 0.0, 0.0, 1.0);
  glFragColor2LpvB = vec4(0.34, 0.0, 0.0, 1.0);
  glFragColor3Gv = vec4(0.0, 0.0, 0.0, 1.0);
}
