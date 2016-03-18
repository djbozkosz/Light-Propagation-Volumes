#version 150
precision lowp float;

#define SHADOW_CASCADES_COUNT 1
#define OUT_VERTICES 3 // cascades * in

layout(triangles) in;
layout(triangle_strip, max_vertices = OUT_VERTICES) out;

#ifdef DIF_TEX
in vec2 _texCoord[];
#endif
flat in int instanceID[];

uniform mat4 mvp[SHADOW_CASCADES_COUNT];

out vec2 texCoord;

void main()
{
  int c = instanceID[0];
  gl_Layer = c;

#ifdef DIF_TEX
  texCoord = _texCoord[0];
#endif
  gl_Position = mvp[c] * gl_in[0].gl_Position;
  EmitVertex();

#ifdef DIF_TEX
  texCoord = _texCoord[1];
#endif
  gl_Position = mvp[c] * gl_in[1].gl_Position;
  EmitVertex();

#ifdef DIF_TEX
  texCoord = _texCoord[2];
#endif
  gl_Position = mvp[c] * gl_in[2].gl_Position;
  EmitVertex();

  EndPrimitive();
}
