#version 150
precision lowp float;

layout(points) in;
#if defined(LPV_GATHERING) || defined(LPV_SKY) || defined(LPV_LOBE)
layout(triangle_strip, max_vertices = 4) out;
#else
layout(points, max_vertices = 7) out;
#endif

flat in int vertexID[];

#if !defined(LPV_GATHERING) && !defined(LPV_SKY) && !defined(LPV_LOBE)
uniform vec3 lpvTexSize;
uniform vec4 lpvParams;
#endif

#if defined(LPV_GATHERING) || defined(LPV_SKY) || defined(LPV_LOBE)
out float texPos;
#else
out vec3 texPos;
out vec3 dir;
#endif

void main()
{
#if defined(LPV_GATHERING) || defined(LPV_SKY) || defined(LPV_LOBE)
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

  vec3 dirs[6];
  dirs[0] = vec3(0.0, 0.0, -1.0); dirs[1] = vec3(0.0, 0.0, 1.0);
  dirs[2] = vec3(0.0, -1.0, 0.0); dirs[3] = vec3(0.0, 1.0, 0.0);
  dirs[4] = vec3(-1.0, 0.0, 0.0); dirs[5] = vec3(1.0, 0.0, 0.0);

  texPos = vec3(float(x), float(y), float(z));

  for(int cell = 0; cell < 6; cell++)
  {
    dir = dirs[cell];
    gl_Layer = z + int(dirs[cell].z);
    gl_Position = vec4((float(x) + dirs[cell].x) / lpvTexSize.x * 2.0 - 1.0, (float(y) + dirs[cell].y) / lpvTexSize.y * 2.0 - 1.0, 0.0, 1.0) + gl_in[0].gl_Position;
    EmitVertex();
  }

  // accum pass
  dir = vec3(0.0, 0.0, 0.0);
  gl_Layer = z;
  gl_Position = vec4(float(x) / lpvTexSize.x * 2.0 - 1.0, float(y) / lpvTexSize.y * 2.0 - 1.0, 0.0, 1.0) + gl_in[0].gl_Position;
  EmitVertex();
#endif

  EndPrimitive();
}
