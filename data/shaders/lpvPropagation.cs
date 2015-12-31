#version 430
precision lowp float;

layout(local_size_x = 32, local_size_y = 1, local_size_z = 1) in;

layout(rgba32f) uniform image3D lpvImgR0;
layout(rgba32f) uniform image3D lpvImgG0;
layout(rgba32f) uniform image3D lpvImgB0;
layout(rgba32f) uniform image3D lpvGvA0;

uniform vec4 lpvPos;
uniform vec3 lpvSize;
uniform vec3 lpvCellSize;

void main()
{
  mat3 nm[6];
  nm[0] = mat3( 1, 0, 0, 0, 1, 0, 0, 0, 1);
  nm[1] = mat3(-1, 0, 0, 0, 1, 0, 0, 0,-1);
  nm[2] = mat3(0, 0, -1, 0, 1, 0, 1, 0, 0);
  nm[3] = mat3(0, 0, 1, 0, 1, 0, -1, 0, 0);
  nm[4] = mat3(1, 0, 0, 0, 0, -1, 0, 1, 0);
  nm[5] = mat3(1, 0, 0, 0, 0, 1, 0, -1, 0);

  vec2 sv[4]; 
  sv[0] = vec2( 1.0, 0.0); sv[1] = vec2( 0.0, 1.0);
  sv[2] = vec2(-1.0, 0.0); sv[3] = vec2(0.0, -1.0);

  vec2 sa = vec2(0.1275, 0.1347);
  vec2 c = vec2(0.4472, 0.8944);

  const uint x = gl_GlobalInvocationID.x;
  const uint y = gl_GlobalInvocationID.y;
  const uvec3 s = uvec3(lpvSize);

  if((x < (s.x * s.y)) && (y < s.z))
  {
    uvec3 i = uvec3(x / s.x, x % s.x, y);
    vec4 shR0 = vec4(0.0);
    vec4 shG0 = vec4(0.0);
    vec4 shB0 = vec4(0.0);

    for(uint n = 0; n < 6; n++)
    {
      mat3 nMat = nm[n];
      vec3 nVec = nMat * vec3(0.0, 0.0, 1.0);
      ivec3 p = ivec3(i) - ivec3(nVec);
      vec4 lpvShR0 = imageLoad(lpvImgR0, p);
      vec4 lpvShG0 = imageLoad(lpvImgG0, p);
      vec4 lpvShB0 = imageLoad(lpvImgB0, p);

      vec4 shccl = vec4(0.8862, -1.0233 * nVec.y, 1.0233 * nVec.z, -1.0233 * nVec.x);
      vec4 sh = vec4(0.2821, -0.4886 * nVec.y, 0.4886 * nVec.z, -0.4886 * nVec.x);
      shR0 += sa.x * dot(lpvShR0, sh) * shccl;
      shG0 += sa.x * dot(lpvShG0, sh) * shccl;
      shB0 += sa.x * dot(lpvShB0, sh) * shccl;

      for(uint w = 0; w < 4; w++)
      {
        vec2 s = sv[w];
        vec3 rep = nMat * vec3(s.x, s.y, 0.0);
        vec3 dir = nMat * vec3(s.x * c.x, s.y * c.x, c.y);

        vec4 repShccl = vec4(0.8862, -1.0233 * rep.y, 1.0233 * rep.z, -1.0233 * rep.x);
        vec4 dirSh = vec4(0.2821, -0.4886 * dir.y, 0.4886 * dir.z, -0.4886 * dir.x);

        shR0 += sa.y * dot(lpvShR0, dirSh) * repShccl;
        shG0 += sa.y * dot(lpvShG0, dirSh) * repShccl;
        shB0 += sa.y * dot(lpvShB0, dirSh) * repShccl;
      }
    }

    imageStore(lpvImgR0, ivec3(i.x, i.y, i.z), shR0);
    imageStore(lpvImgG0, ivec3(i.x, i.y, i.z), shG0);
    imageStore(lpvImgB0, ivec3(i.x, i.y, i.z), shB0);
  }
}