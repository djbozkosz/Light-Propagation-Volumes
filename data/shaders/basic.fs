#version 150
precision lowp float;

in vec2 texCoord;
in vec4 color;

uniform sampler2D difTex;
#ifdef ALP_TEX
uniform sampler2D alpTex;

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
#endif
  glFragColor = vec4(texture(difTex, texCoord).rgb * color.rgb, alpha);
}
