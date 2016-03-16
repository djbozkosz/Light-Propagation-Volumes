#version 150
precision lowp float;

#define SHADOW_CASCADES_COUNT 1
#define OUT_VERTICES 3 // cascades * in

layout(triangles) in;
layout(triangle_strip, max_vertices = OUT_VERTICES) out;

in vec2 _texCoord[];

uniform mat4 mvp[SHADOW_CASCADES_COUNT];

out vec2 texCoord;

void main()
{
  for(int c = 0; c < SHADOW_CASCADES_COUNT; c++)
  {
    gl_Layer = c;

    texCoord = _texCoord[0];
    gl_Position = mvp[c] * gl_in[0].gl_Position;
    EmitVertex();

    texCoord = _texCoord[1];
    gl_Position = mvp[c] * gl_in[1].gl_Position;
    EmitVertex();

    texCoord = _texCoord[2];
    gl_Position = mvp[c] * gl_in[2].gl_Position;
    EmitVertex();

    EndPrimitive();
  }
}
