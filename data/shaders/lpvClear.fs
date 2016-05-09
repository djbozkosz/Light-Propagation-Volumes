#version 150
precision lowp float;

#ifndef LPV_GV
#ifndef LPV_LOBE
out vec4 glFragColor0LpvR;
out vec4 glFragColor1LpvG;
out vec4 glFragColor2LpvB;
out vec4 glFragColor3LpvAccumR;
out vec4 glFragColor4LpvAccumG;
out vec4 glFragColor5LpvAccumB;
out vec4 glFragColor6LpvNormal;
#else
out vec4 glFragColor0LpvNormal;
#endif
#else
out vec4 glFragColor0Gv;
#endif

void main()
{
#ifndef LPV_GV
#ifndef LPV_LOBE
  glFragColor0LpvR = vec4(0.0);
  glFragColor1LpvG = vec4(0.0);
  glFragColor2LpvB = vec4(0.0);
  glFragColor3LpvAccumR = vec4(0.0);
  glFragColor4LpvAccumG = vec4(0.0);
  glFragColor5LpvAccumB = vec4(0.0);
  glFragColor6LpvNormal = vec4(0.0);
#else
  glFragColor0LpvNormal = vec4(0.0);
#endif
#else
  glFragColor0Gv = vec4(0.0);
#endif
}
