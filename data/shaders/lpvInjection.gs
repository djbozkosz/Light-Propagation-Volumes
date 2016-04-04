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
  int cascade = x / int(tiles.x);

  vec2 tex = vec2(float(x), float(y)) * geomTexSize.zw + gl_in[0].gl_Position.xy; // zeros
  vec3 light = texture(geomColorTex, tex).xyz;

  if(length(light) > 0.0)
  {
    vec3 pos = texture(geomPosTex, tex).xyz;
    vec3 lpvPos = vec3(pos.xy / (lpvTexSize.xy * 0.5), pos.z + lpvTexSize.z * 0.5);

    if((lpvPos.x > -1.0) && (lpvPos.x < 1.0) &&
       (lpvPos.y > -1.0) && (lpvPos.y < 1.0) &&
       (lpvPos.z > 0.0) && (lpvPos.z < lpvTexSize.z))
    {
      lpvPos.x = ((lpvPos.x * 0.5 + 0.5 + float(cascade)) / float(tiles.x)) * 2.0 - 1.0; // place X into correct lpv cascade: ndc -> 0..1 -> shift, normalize -> ndc
      texPos = vec2(float(x), float(y));
      gl_Layer = int(lpvPos.z);
      gl_Position = vec4(lpvPos.xy, 0.0, 1.0);
      EmitVertex();
    }
  }

  EndPrimitive();

  /*texPos = vec2(0.0, 0.0);
  gl_Layer = 16;
  gl_Position = gl_in[0].gl_Position + vec4(float(vertexID[0]) * geomTexSize.z * 2.0 - 1.0, 0.0, 0.0, 1.0); EmitVertex();
  //gl_Position = vec4(-1.0,  1.0, 0.5, 1.0); EmitVertex();
  //gl_Position = vec4( 1.0,  1.0, 0.5, 1.0); EmitVertex();
  //gl_Position = vec4(-1.0, -1.0, 0.5, 1.0); EmitVertex();
  //gl_Position = vec4( 1.0, -1.0, 0.5, 1.0); EmitVertex();
  EndPrimitive();*/
}
