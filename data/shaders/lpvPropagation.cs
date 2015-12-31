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
  const uint x = gl_GlobalInvocationID.x;
  const uint y = gl_GlobalInvocationID.y;
  const uint sx = uint(lpvSize.x);
  const uint sy = uint(lpvSize.y);
  const uint sz = uint(lpvSize.z);

  if((x < (sx * sy)) && (y < sz))
  {
  }
}