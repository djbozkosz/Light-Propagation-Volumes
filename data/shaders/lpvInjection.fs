#version 150
precision lowp float;

#define LPV_CASCADES_COUNT
#define LPV_SUN_SKY_DIRS_COUNT

in vec2 texPos;

uniform sampler2D geomColorTex;
uniform sampler2D geomPosTex;
uniform sampler2D geomNormalTex;
//uniform sampler2D geomDepthTex;

uniform vec3 lightAmb[LPV_SUN_SKY_DIRS_COUNT];
uniform vec3 lightPos[LPV_SUN_SKY_DIRS_COUNT];

uniform vec4 tiles;
uniform vec4 geomTexSize;
uniform vec3 lpvPos[LPV_CASCADES_COUNT];
uniform vec3 lpvTexSize;
uniform vec3 lpvCellSize[LPV_CASCADES_COUNT];

out vec4 glFragColor0LpvR;
out vec4 glFragColor1LpvG;
out vec4 glFragColor2LpvB;
out vec4 glFragColor3Gv;

void main()
{
  int x = int(texPos.x) % int(geomTexSize.x);
  int y = int(texPos.y) / int(geomTexSize.x);
  int cascade = x / int(tiles.x);
  int sunSkyLight = y / int(tiles.y);

  glFragColor0LpvR = vec4(2.0, 0.0, 0.0, 1.0);
  glFragColor1LpvG = vec4(0.33, 0.0, 0.0, 1.0);
  glFragColor2LpvB = vec4(0.34, 0.0, 0.0, 1.0);
  glFragColor3Gv = vec4(0.0, 0.0, 0.0, 1.0);
}
