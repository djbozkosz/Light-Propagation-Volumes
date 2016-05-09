#version 150
precision lowp float;

#ifndef LPV_GV
#define INJECT_SHIFT 1.0
#else
#define INJECT_SHIFT -2.0
#endif

#define LPV_CASCADES_COUNT
#define LPV_SUN_SKY_SPEC_DIRS_COUNT

layout(points) in;
layout(points, max_vertices = 1) out;
//layout(triangle_strip, max_vertices = 4) out;

flat in int vertexID[];

uniform sampler2D geomColorTex;
uniform sampler2D geomPosTex;
uniform sampler2D geomNormalTex;
//uniform sampler2D geomDepthTex;

uniform vec4 tiles;
uniform vec4 geomTexSize;
uniform vec3 lpvPos[LPV_CASCADES_COUNT];
uniform vec3 lpvTexSize;
uniform vec3 lpvCellSize[LPV_CASCADES_COUNT];
uniform vec4 lpvParams;

out vec2 texPos;

void main()
{
  int x = vertexID[0] % int(geomTexSize.x);
  int y = vertexID[0] / int(geomTexSize.x);
  int w = int(geomTexSize.x * tiles.z);
  int sunSkyLight = x / w;
  int cascade = y / int(geomTexSize.y * tiles.w);

/*#ifdef LPV_GV
  if(x >= 2*w)
  {
    EndPrimitive();
    return;
  }
#endif

  if(sunSkyLight >= LPV_SUN_SKY_SPEC_DIRS_COUNT)
  {
    x -= w;
    cascade++;
  }*/

  vec2 tex = vec2(float(x), geomTexSize.y - float(y)) * geomTexSize.zw;
  vec4 light = texture(geomColorTex, tex);

  if((length(light.rgb) > 0.0) && ((lpvParams.w > 0.0) || (light.a > 0.0)))
  {
    vec3 pos = texture(geomPosTex, tex).xyz;
    vec3 normal = normalize(texture(geomNormalTex, tex).xyz);

#ifndef LPV_GV
    if(lpvParams.w > 0.0)
      pos += normal * lpvCellSize[cascade] * INJECT_SHIFT; // self illum shift
#else
    pos += lpvCellSize[cascade] * 0.5 + normal * lpvCellSize[cascade] * INJECT_SHIFT; // shifted gv by half cell size
#endif

    vec3 lpvP = vec3((pos.xy - lpvPos[cascade].xy) / (lpvTexSize.y * lpvCellSize[cascade].xy * 0.5), ((pos.z - lpvPos[cascade].z) / (lpvTexSize.z * lpvCellSize[cascade].z * 0.5) * 0.5 + 0.5) * lpvTexSize.z);

    if((lpvP.x >= -1.0) && (lpvP.x <= 1.0) &&
       (lpvP.y >= -1.0) && (lpvP.y <= 1.0) &&
       (lpvP.z >= 0.0) && (lpvP.z < lpvTexSize.z))
    { // clip
      lpvP.x = ((lpvP.x * 0.5 + 0.5 + float(cascade)) * tiles.w) * 2.0 - 1.0; // place X into correct lpv cascade: ndc -> 0..1 -> shift, normalize -> ndc

      texPos = vec2(float(x), float(y));
      gl_Layer = int(lpvP.z);
      gl_Position = gl_in[0].gl_Position + vec4(lpvP.xy, 0.0, 1.0);
      EmitVertex();
    }
  }

  EndPrimitive();

  /*int x = vertexID[0] % int(geomTexSize.x);
  int y = vertexID[0] / int(geomTexSize.y);
  texPos = texture(geomPosTex, vec2(float(x) * geomTexSize.z, float(y) * geomTexSize.w)).rg;
  gl_Layer = 16;
  gl_Position = gl_in[0].gl_Position + vec4(float(x) * geomTexSize.z * 2.0 - 1.0, float(y) * geomTexSize.w * 2.0 - 1.0, 0.0, 1.0) * vec4(1.0, 2.0, 0.0, 1.0);
  EmitVertex();
  EndPrimitive();*/
}
