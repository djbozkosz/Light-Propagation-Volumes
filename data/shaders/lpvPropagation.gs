#version 150
precision lowp float;

layout(points) in;
#ifdef LPV_GATHERING
layout(triangle_strip, max_vertices = 4) out;
#else
layout(points, max_vertices = 1) out;
#endif

flat in int vertexID[];

uniform vec3 lpvTexSize;
uniform vec2 lpvParams;

#ifdef LPV_GATHERING
out float texPos;
#else
out vec3 texPos;
#endif

void main()
{
#ifdef LPV_GATHERING
  texPos = vertexID[0];
  gl_Layer = vertexID[0];
  gl_Position = vec4(-1.0,  1.0, 0.0, 1.0) + gl_in[0].gl_Position; EmitVertex();
  gl_Position = vec4( 1.0,  1.0, 0.0, 1.0); EmitVertex();
  gl_Position = vec4(-1.0, -1.0, 0.0, 1.0); EmitVertex();
  gl_Position = vec4( 1.0, -1.0, 0.0, 1.0); EmitVertex();
#else
  int v = vertexID[0] + (int(lpvParams.x) * 65536);
  int x = v % int(lpvTexSize.x);
  int y = (v / int(lpvTexSize.x)) % int(lpvTexSize.y);
  int z = (v / int(lpvTexSize.x)) / int(lpvTexSize.y);

  texPos = vec3(float(x), float(y), float(z));
  gl_Layer = z;
  gl_Position = vec4(float(x) / lpvTexSize.x * 2.0 - 1.0, float(y) / lpvTexSize.y * 2.0 - 1.0, 0.0, 1.0) + gl_in[0].gl_Position; EmitVertex();
  EmitVertex();
#endif

  EndPrimitive();
}
