#version 150
precision lowp float;

layout(points) in;
layout(points, max_vertices = 1) out;
//layout(triangle_strip, max_vertices = 4) out;

flat in int vertexID[];

void main()
{
#ifndef LPV_SCATTERING
#else
#endif
  gl_Position = gl_in[0].gl_Position;
  EmitVertex();
  EndPrimitive();
}
