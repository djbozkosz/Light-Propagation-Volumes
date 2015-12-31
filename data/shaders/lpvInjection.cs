#version 430
precision lowp float;

#extension GL_NV_shader_atomic_float : require

layout(local_size_x = 32, local_size_y = 32, local_size_z = 1) in;

uniform vec3 lightPos;

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
    vec3 l = imageLoad(fragColor, ivec2(x, y)).rgb;
    //vec3 s = 1.0 / (lpvCellSize * lpvSize); // self illum shift

    if((pos.x != 0.0) && (pos.y != 0.0) && (pos.z != 0.0) && (l.x != 0.0) && (l.y != 0.0) && (l.z != 0.0))
    {
      vec3 n = normalize(imageLoad(fragNormal, ivec2(x, y)).xyz);
      pos += /*n * s * 0.5 +*/ lpvSize * 0.5;
      float d = max(0.0, dot(n, normalize(lightPos)));
      vec3 f = l/* / 3.14*/ * d;

      vec4 shccl = vec4(0.8862, -1.0233 * n.y, 1.0233 * n.z, -1.0233 * n.x);

      imageStore(lpvImg, ivec3(pos), shccl * ((f.r + f.g + f.b) * 0.34));
    }
  }
}
