#version 130
precision lowp float;

in vec2 texCoord;
in vec4 color;

uniform sampler2D difTex;
uniform sampler2D alpTex;

uniform float opacity;

out vec4 glFragColor;

void main()
{
  vec3 fragAlp = texture(alpTex, texCoord).rgb;
  glFragColor = vec4(texture(difTex, texCoord).rgb * color.rgb, color.a * (fragAlp.r + fragAlp.g + fragAlp.b) * 0.3333333334 * opacity);
}
