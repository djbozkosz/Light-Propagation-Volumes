#version 150
precision lowp float;

#define LPV_CASCADES_COUNT 1 // cascades * sun dirs * in
#define OUT_VERTICES 3 // cascades * sun dirs * in

layout(triangles) in;
layout(triangle_strip, max_vertices = OUT_VERTICES) out;

in vec3 _positionWorld[];
in vec3 _normal[];
in vec2 _texCoord[];
in vec4 _color[];
//in mat3 _mtbnt[];
flat in int instanceID[];

uniform mat4 mvp[LPV_CASCADES_COUNT];

out vec3 positionWorld;
out vec3 normal;
out vec2 texCoord;
out vec4 color;
//out mat3 mtbnt;

void main()
{
  int c = instanceID[0];
  gl_Layer = c;

  positionWorld = _positionWorld[0];
  normal = _normal[0];
  texCoord = _texCoord[0];
  color = _color[0];
  //mtbnt = _mtbnt[0];
  gl_Position = mvp[c] * gl_in[0].gl_Position;
  EmitVertex();

  positionWorld = _positionWorld[1];
  normal = _normal[1];
  texCoord = _texCoord[1];
  color = _color[1];
  //mtbnt = _mtbnt[1];
  gl_Position = mvp[c] * gl_in[1].gl_Position;
  EmitVertex();

  positionWorld = _positionWorld[2];
  normal = _normal[2];
  texCoord = _texCoord[2];
  color = _color[2];
  //mtbnt = _mtbnt[2];
  gl_Position = mvp[c] * gl_in[2].gl_Position;
  EmitVertex();

  EndPrimitive();
}
