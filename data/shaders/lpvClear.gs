#version 150
precision lowp float;

layout(points) in;
layout(triangle_strip, max_vertices = 4) out;

flat in int vertexID[];

void main()
{
  gl_Layer = vertexID[0];
  gl_Position = vec4(-1.0,  1.0, 0.0, 1.0) + gl_in[0].gl_Position; EmitVertex();
  gl_Position = vec4( 1.0,  1.0, 0.0, 1.0); EmitVertex();
  gl_Position = vec4(-1.0, -1.0, 0.0, 1.0); EmitVertex();
  gl_Position = vec4( 1.0, -1.0, 0.0, 1.0); EmitVertex();

  EndPrimitive();
}
