#version 430
precision lowp float;

layout(local_size_x = 32, local_size_y = 32, local_size_z = 1) in;

/*layout(r32i) uniform image3D lpv0ImgR;
layout(r32i) uniform image3D lpv0ImgG;
layout(r32i) uniform image3D lpv0ImgB;
layout(r32i) uniform image3D lpv1ImgR;
layout(r32i) uniform image3D lpv1ImgG;
layout(r32i) uniform image3D lpv1ImgB;
layout(r32i) uniform image3D gvImgA0;

uniform vec3 lpvTexSize;*/

void main()
{
  /*const uint x = gl_GlobalInvocationID.x;
  const uint y = gl_GlobalInvocationID.y;
  const uvec3 s = uvec3(lpvTexSize);

  if((x < (s.x * s.y)) && (y < s.z))
  {
    imageStore(lpvImgR0, ivec3(x / s.x, x % s.x, y), vec4(0.0, 0.0, 0.0, 0.0));
    imageStore(lpvImgG0, ivec3(x / s.x, x % s.x, y), vec4(0.0, 0.0, 0.0, 0.0));
    imageStore(lpvImgB0, ivec3(x / s.x, x % s.x, y), vec4(0.0, 0.0, 0.0, 0.0));
    imageStore(gvImgA0, ivec3(x / s.x, x % s.x, y), vec4(0.0, 0.0, 0.0, 0.0));
  }*/
}
