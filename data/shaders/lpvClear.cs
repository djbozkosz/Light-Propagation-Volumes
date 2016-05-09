#version 430
precision lowp float;

#define LPV_CASCADES_COUNT
#define LPV_SH_COEFFS_COUNT 4
#define LPV_SAMPLE_SIZE 12
#define LPV_GV_SAMPLE_SIZE 8

layout(local_size_x = 32, local_size_y = 32, local_size_z = 1) in;

uniform layout(rgba32f) writeonly image3D lpvAccumTexR;
uniform layout(rgba32f) writeonly image3D lpvAccumTexG;
uniform layout(rgba32f) writeonly image3D lpvAccumTexB;
uniform layout(r32i) writeonly iimage3D lpv0Tex;
uniform layout(r32i) writeonly iimage3D lpv1Tex;
uniform layout(r32i) writeonly iimage3D lpvAccumTex;
uniform layout(r32i) writeonly iimage3D lpvNormalAccumTex;
uniform layout(r32i) writeonly iimage3D gvTex;

uniform vec3 lpvTexSize;

void main()
{
  uint x = gl_GlobalInvocationID.x % uint(lpvTexSize.y);
  uint y = gl_GlobalInvocationID.y % uint(lpvTexSize.y);
  uint z = gl_GlobalInvocationID.y / uint(lpvTexSize.y);
  uint cascade = gl_GlobalInvocationID.x / uint(lpvTexSize.y);

  if((cascade < LPV_CASCADES_COUNT) && (z < uint(lpvTexSize.z)))
  {
    uint texX = cascade * uint(lpvTexSize.y) + x;
    uint lpvGlobTexX = texX * LPV_SAMPLE_SIZE;
    uint lobeGlobTexX = texX * LPV_SH_COEFFS_COUNT * 2;
    uint gvGlobTexX = texX * LPV_SH_COEFFS_COUNT;

    imageStore(lpvAccumTexR, ivec3(texX, y, z), vec4(0.0));
    imageStore(lpvAccumTexG, ivec3(texX, y, z), vec4(0.0));
    imageStore(lpvAccumTexB, ivec3(texX, y, z), vec4(0.0));

    for(int i = 0; i < LPV_SAMPLE_SIZE; i++)
    {
      imageStore(lpv0Tex, ivec3(lpvGlobTexX + i, y, z), ivec4(0, 0, 0, 0));
      imageStore(lpv1Tex, ivec3(lpvGlobTexX + i, y, z), ivec4(0, 0, 0, 0));
      imageStore(lpvAccumTex, ivec3(lpvGlobTexX + i, y, z), ivec4(0, 0, 0, 0));
    }

    for(int i = 0; i < (LPV_SH_COEFFS_COUNT * 2); i++)
      imageStore(lpvNormalAccumTex, ivec3(lobeGlobTexX + i, y, z), ivec4(0, 0, 0, 0));

    for(int i = 0; i < LPV_SH_COEFFS_COUNT; i++)
      imageStore(gvTex, ivec3(gvGlobTexX + i, y, z), ivec4(0, 0, 0, 0));
  }
}
