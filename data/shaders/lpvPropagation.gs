#version 150
precision lowp float;

layout(points) in;
#ifdef LPV_GATHERING
//layout(triangle_strip, max_vertices = 4) out;
layout(points, max_vertices = 1) out;
#else
layout(points, max_vertices = 1) out;
#endif

flat in int vertexID[];

#ifdef LPV_GATHERING
out float texPos;
#else
#endif

void main()
{
#ifdef LPV_GATHERING
  gl_Layer = 16;// vertexID[0];
  texPos = float(vertexID[0]);
  gl_Position = gl_in[0].gl_Position; EmitVertex();
  /*gl_Position = vec4(-1.0,  1.0, 0.0, 1.0) + gl_in[0].gl_Position; EmitVertex();
  gl_Position = vec4( 1.0,  1.0, 0.0, 1.0); EmitVertex();
  gl_Position = vec4(-1.0, -1.0, 0.0, 1.0); EmitVertex();
  gl_Position = vec4( 1.0, -1.0, 0.0, 1.0); EmitVertex();*/
#else
  gl_Layer = 0;
  gl_Position = gl_in[0].gl_Position;
  EmitVertex();
#endif

  EndPrimitive();
}
