#version 150
precision lowp float;

in vec2 texCoord;
in vec4 color;

#if defined(DIF_2D_ARRAY)
uniform sampler2DArray difTex;
#elif defined(DIF_3D)
uniform sampler3D difTex;
#else
uniform sampler2D difTex;
#endif
#ifdef ALP_TEX
uniform sampler2D alpTex;
#endif

#if defined(DIF_2D_ARRAY) || defined(DIF_3D) || defined(ALP_TEX)
uniform float opacity;
#endif

out vec4 glFragColor;

void main()
{
#ifndef ALP_TEX
  float alpha = 1.0;
#else
  vec3 fragAlp = texture(alpTex, texCoord).rgb;
  float alpha = color.a * (fragAlp.r + fragAlp.g + fragAlp.b) * 0.3333333334 * opacity;

  if(alpha == 0.0)
    discard;
#endif

#if defined(DIF_2D_ARRAY) || defined(DIF_3D)
  vec3 t = vec3(texCoord, opacity);
#else
  vec2 t = texCoord;
#endif

  glFragColor = vec4(texture(difTex, t).rgb * color.rgb, alpha);
}
