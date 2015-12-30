#version 430
precision lowp float;

#extension GL_NV_shader_atomic_float : require

layout(local_size_x = 32, local_size_y = 32, local_size_z = 1) in;

layout(rgba32f) uniform readonly image2D fragColor;
layout(rgba32f) uniform readonly image2D fragPos;
layout(rgba32f) uniform readonly image2D fragNormal;
layout(rgba32f) uniform readonly image2D fragDepth;

layout(rgba32f) uniform image3D lpvImg;
layout(rgba32f) uniform image3D lpvGv;

uniform vec2 fragSize;
uniform vec3 lpvPos;
uniform vec3 lpvSize;
uniform vec3 lpvCellSize;

void main()
{
  const uint x = gl_GlobalInvocationID.x;
  const uint y = gl_GlobalInvocationID.y;

  if((x < uint(fragSize.x)) && (y < uint(fragSize.y)))
  {
    vec3 pos = imageLoad(fragPos, ivec2(x, y)).xyz;
    if((pos.x != 0.0) && (pos.y != 0.0) && (pos.z != 0.0))
    {
      pos += lpvSize * 0.5;
      imageStore(lpvImg, ivec3(pos), imageLoad(fragColor, ivec2(x, y)));
    }
  }
}
