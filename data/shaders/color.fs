#version 150
precision lowp float;

#ifdef DIF_TEX
in vec2 texCoord;

uniform sampler2D difTex;
#endif

uniform vec3 lightAmb;

out vec4 glFragColor;

void main()
{
#ifdef DIF_TEX
  if(texture(difTex, texCoord).a < 0.8)
    discard;
#endif

  glFragColor = vec4(lightAmb, 1.0);
}
