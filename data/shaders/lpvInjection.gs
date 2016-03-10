#version 150
precision lowp float;

layout(points) in;
//layout(points, max_vertices = 1) out;
layout(triangle_strip, max_vertices = 4) out;

/*flat in int vertexID[];

uniform sampler2D fragColor;
uniform sampler2D fragPos;
uniform sampler2D fragNormal;
uniform sampler2D fragDepth;

uniform vec3 lightPos;

uniform vec4 fragSize; // e.g.: 128, 128, 1/128, 1/128
uniform vec4 lpvPos;
uniform vec3 lpvSize;
uniform vec3 lpvCellSize;*/

void main()
{
  /*vec2 p = vec2(float(vertexID[0] % int(fragSize.x)), float(vertexID[0] / int(fragSize.y))) * fragSize.zw;
  vec3 pos = texture(fragPos, p).xyz;
  vec3 l = texture(fragColor, p).xyz;

  if((pos.x != 0.0) && (pos.y != 0.0) && (pos.z != 0.0) && (l.x != 0.0) && (l.y != 0.0) && (l.z != 0.0))
  {
    vec3 n = normalize(texture(fragNormal, p).xyz);
    pos = vec3(pos.xy / (lpvSize.xy * 0.5), clamp(pos.z + lpvSize.z * 0.5, 0.0, lpvSize.z));

    gl_Layer = int(pos.z);
    gl_Position = vec4(pos.xy, 0.0, 1.0);
    EmitVertex();
  }

  EndPrimitive();*/
  gl_Layer = 16;
  gl_Position = gl_in[0].gl_Position;
  gl_Position = vec4(-1.0,  1.0, 0.5, 1.0); EmitVertex();
  gl_Position = vec4( 1.0,  1.0, 0.5, 1.0); EmitVertex();
  gl_Position = vec4(-1.0, -1.0, 0.5, 1.0); EmitVertex();
  gl_Position = vec4( 1.0, -1.0, 0.5, 1.0); EmitVertex();
  EndPrimitive();
}
