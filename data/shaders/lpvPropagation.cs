#version 430
precision lowp float;

layout(local_size_x = 32, local_size_y = 1, local_size_z = 1) in;

layout(r32i) uniform image3D lpv0ImgR;
layout(r32i) uniform image3D lpv0ImgG;
layout(r32i) uniform image3D lpv0ImgB;
layout(r32i) uniform image3D lpv1ImgR;
layout(r32i) uniform image3D lpv1ImgG;
layout(r32i) uniform image3D lpv1ImgB;
layout(r32i) uniform image3D gvImgA0;
layout(r32i) uniform image3D lpvOutImgR;
layout(r32i) uniform image3D lpvOutImgG;
layout(r32i) uniform image3D lpvOutImgB;

uniform vec4 lpvPos;
uniform vec3 lpvTexSize;
uniform vec3 lpvCellSize;

void main()
{
#ifndef LPV_SCATTERING
#else
#endif

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

  const uint x = gl_GlobalInvocationID.x;
  const uint y = gl_GlobalInvocationID.y;
  const uvec3 s = uvec3(lpvTexSize);

  if((x < (s.x * s.y)) && (y < s.z))
  {
    ivec3 i = ivec3(x / s.x, x % s.x, y);
    vec4 shR0 = vec4(0.0);
    vec4 shG0 = vec4(0.0);
    vec4 shB0 = vec4(0.0);

    for(uint n = 0; n < 6; n++)
    {
      mat3 nMat = nm[n];
      vec3 nVec = nMat * vec3(0.0, 0.0, 1.0);
      ivec3 p = i - ivec3(nVec);
      vec4 lpvShR0 = imageLoad(lpvImgR0, p);
      vec4 lpvShG0 = imageLoad(lpvImgG0, p);
      vec4 lpvShB0 = imageLoad(lpvImgB0, p);

      vec4 shccl = vec4(0.8862, -1.0233 * nVec.y, 1.0233 * nVec.z, -1.0233 * nVec.x);
      vec4 sh = vec4(0.2821, -0.4886 * nVec.y, 0.4886 * nVec.z, -0.4886 * nVec.x);
      shR0 += 0.1275 * dot(lpvShR0, sh) * shccl;
      shG0 += 0.1275 * dot(lpvShG0, sh) * shccl;
      shB0 += 0.1275 * dot(lpvShB0, sh) * shccl;

      for(uint w = 0; w < 4; w++)
      {
        vec2 s = sv[w];
        vec3 rep = nMat * vec3(0.1275, 0.1347, 0.0);
        vec3 dir = nMat * vec3(0.057, 0.0602, 0.8944);

        vec4 repShccl = vec4(0.8862, -1.0233 * rep.y, 1.0233 * rep.z, -1.0233 * rep.x);
        vec4 dirSh = vec4(0.2821, -0.4886 * dir.y, 0.4886 * dir.z, -0.4886 * dir.x);

        shR0 += 0.1347 * dot(lpvShR0, dirSh) * repShccl;
        shG0 += 0.1347 * dot(lpvShG0, dirSh) * repShccl;
        shB0 += 0.1347 * dot(lpvShB0, dirSh) * repShccl;
      }
    }

    imageStore(lpvImgR0, i, shR0 + imageLoad(lpvImgR0, i));
    imageStore(lpvImgG0, i, shG0 + imageLoad(lpvImgG0, i));
    imageStore(lpvImgB0, i, shB0 + imageLoad(lpvImgB0, i));
  }
}