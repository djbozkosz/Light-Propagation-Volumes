#version 150
precision lowp float;

#ifdef DIF_TEX
in vec2 texCoord;

uniform sampler2D difTex;
#endif

out float glFragColor0;
out float glFragColor1;

void main()
{
#ifdef DIF_TEX
  if(texture(difTex, texCoord).a < 0.8)
    discard;
#endif

  glFragColor0 = gl_FragCoord.z;
  glFragColor1 = gl_FragCoord.z;
}
