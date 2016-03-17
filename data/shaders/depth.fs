#version 150
precision lowp float;

in vec2 texCoord;

#ifdef DIF_TEX
uniform sampler2D difTex;
#endif

out float glFragColor;

void main()
{
#ifndef DIF_TEX
  vec2 t = texCoord; // unused
#else
  if(texture(difTex, texCoord).a < 0.8)
    discard;
#endif

  glFragColor = gl_FragCoord.z;
}
