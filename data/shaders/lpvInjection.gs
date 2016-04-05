#version 150
precision lowp float;

#define LPV_CASCADES_COUNT
#define LPV_SUN_SKY_DIRS_COUNT

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

out vec2 texPos;

void main()
{
  int x = vertexID[0] % int(geomTexSize.x);
  int y = vertexID[0] / int(geomTexSize.x);
  int cascade = y / int(geomTexSize.y * tiles.w);
  vec2 tex = vec2(float(x), float(y)) * geomTexSize.zw;

  if(length(texture(geomColorTex, tex).rgb) > 0.0)
  {
    vec3 pos = texture(geomPosTex, tex).xyz;
    vec3 lpvPos = vec3(pos.xy / (lpvTexSize.y * 0.5), pos.z + lpvTexSize.z * 0.5);
    lpvPos.x = ((lpvPos.x * 0.5 + 0.5 + float(cascade)) * tiles.w) * 2.0 - 1.0; // place X into correct lpv cascade: ndc -> 0..1 -> shift, normalize -> ndc

    texPos = vec2(float(x), float(y));
    gl_Layer = int(lpvPos.z);
    gl_Position = gl_in[0].gl_Position + vec4(lpvPos.xy, 0.0, 1.0);
    EmitVertex();
  }

  EndPrimitive();

  /*int x = vertexID[0] % int(geomTexSize.x);
  int y = vertexID[0] / int(geomTexSize.y);
  texPos = texture(geomPosTex, vec2(float(x) * geomTexSize.z, float(y) * geomTexSize.w)).rg;
  gl_Layer = 16;
  gl_Position = gl_in[0].gl_Position + vec4(float(x) * geomTexSize.z * 2.0 - 1.0, float(y) * geomTexSize.w * 2.0 - 1.0, 0.0, 1.0) * vec4(1.0, 2.0, 0.0, 1.0);
  EmitVertex();
  EndPrimitive();*/

  /*gl_Layer = 16;
  texPos = vec2(-1.0, 1.0); gl_Position = vec4(-1.0, 1.0, 0.0, 1.0); EmitVertex();
  texPos = vec2(1.0, 1.0); gl_Position = vec4( 1.0,  1.0, 0.0, 1.0); EmitVertex();
  texPos = vec2(-1.0, -1.0); gl_Position = vec4(-1.0, -1.0, 0.0, 1.0); EmitVertex();
  texPos = vec2(1.0, -1.0); gl_Position = vec4( 1.0, -1.0, 0.0, 1.0); EmitVertex();
  EndPrimitive();*/
}
