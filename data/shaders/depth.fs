#version 150
precision lowp float;

#ifdef DIF_TEX
in vec2 texCoord;
#endif

#ifdef DIF_TEX
uniform sampler2D difTex;
#endif

out float glFragColor;

void main()
{
#ifdef DIF_TEX
  if(texture(difTex, texCoord).a < 0.8)
    discard;
#endif

  glFragColor = gl_FragCoord.z;
}
