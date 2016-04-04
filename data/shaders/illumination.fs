#version 150
precision lowp float;

#define BLINN_PHONG
//#define SHADOW_JITTER_CASCADES
#define SHADOW_CASCADES_BLEND_RATIO 0.5
#define LPV_CASCADES_BLEND_RATIO 0.5

#define SHADOW_CASCADES_COUNT
#define LPV_CASCADES_COUNT

in vec3 positionWorld;
#ifndef NOR_TEX
in vec3 normal;
#endif
in vec2 texCoord;
in vec4 color;
#ifdef SHAD_TEX
in vec3 shadowCoord[SHADOW_CASCADES_COUNT];
#endif
#ifdef NOR_TEX
in mat3 mtbnti;
#endif

uniform vec3 cam;

uniform sampler2D difTex;
#ifdef ALP_TEX
uniform sampler2D alpTex;
#endif
uniform sampler2D speTex;
#ifdef NOR_TEX
uniform sampler2D norTex;
#endif
#ifdef SHAD_TEX
uniform sampler2DShadow shadTex;
uniform sampler3D lpvTexR;
uniform sampler3D lpvTexG;
uniform sampler3D lpvTexB;
#endif
#ifdef SHADOW_JITTER
uniform sampler2D shadDepthTex;
#endif

uniform int type;
#ifdef ALP_TEX
uniform float opacity;
#endif
#ifdef SHAD_TEX
uniform vec4 tiles;
uniform vec2 shadowClips[SHADOW_CASCADES_COUNT];
#endif
#ifdef SHADOW_JITTER
uniform vec3 shadowTexSize;
#endif

uniform vec3 lightAmb;
uniform vec3 lightPos;
uniform vec2 lightRange;
uniform vec3 lightColor;
uniform vec4 lightSpeColor;
uniform vec2 fogRange;
uniform vec3 fogColor;

#ifdef SHAD_TEX
uniform vec4 lpvPos[LPV_CASCADES_COUNT];
uniform vec3 lpvTexSize;
uniform vec3 lpvCellSize[LPV_CASCADES_COUNT];
uniform vec2 lpvParams;
#endif

out vec4 glFragColor;

void main()
{
  vec4 fragDif = texture(difTex, texCoord);

  if(((type & 0x20000000) != 0) && (fragDif.a < 0.8))
    discard;

#ifndef ALP_TEX
  float alpha = 1.0;
#else
  vec3 fragAlp = texture(alpTex, texCoord).rgb;
  float alpha = (fragAlp.r + fragAlp.g + fragAlp.b) * 0.3333333334 * color.a * opacity;

  if(alpha == 0.0)
    discard;
#endif

  vec3 fragSpe = texture(speTex, texCoord).rgb;

#ifndef NOR_TEX
  vec3 normalDir = normalize(normal);
#else
  vec3 fragNor = texture(norTex, texCoord).rgb;
  vec3 normalDir = normalize(mtbnti * normalize(fragNor * 2.0 - 1.0));
#endif

#ifdef NOR_TEX_DEBUG
  glFragColor = vec4(normalDir * 0.5 + 0.5, alpha);
  return;
#endif

  float fragDist = distance(cam, positionWorld);
  vec3 lpvColor = vec3(0.0, 0.0, 0.0);

#ifdef SHAD_TEX
  /*vec4 sh = vec4(0.2821, -0.4886 * -normalDir.y, 0.4886 * -normalDir.z, -0.4886 * -normalDir.x);
  vec3 p = (lpvPos[0].xyz + positionWorld) * lpvCellSize[0];
  vec4 lpvShR0 = texture(lpvTexR, p);
  vec4 lpvShG0 = texture(lpvTexG, p);
  vec4 lpvShB0 = texture(lpvTexB, p);
  lpvColor = vec3(dot(sh, lpvShR0), dot(sh, lpvShG0), dot(sh, lpvShB0)) * lpvParams.y;
  if((lpvColor.x < 0.0) || (lpvColor.y < 0.0) || (lpvColor.z < 0.0))
    lpvColor = vec3(0.0);*/

  int lpvIndex = 0;
  float lpvEnd = 0.0;
  float lpvStart = 0.0;

  for(lpvIndex = 0; lpvIndex < LPV_CASCADES_COUNT; lpvIndex++)
  {
    lpvStart = lpvEnd;
    lpvEnd = lpvCellSize[lpvIndex].x * lpvTexSize.y * 0.5;

    if(fragDist <= lpvEnd)
      break;
  }

  float lpvRange = lpvEnd - lpvStart;

  for(int semiCascade = 0; semiCascade < 2; semiCascade++, lpvIndex++)
  {
    vec3 lpvColor2 = vec3(0.0, 0.0, 0.0);

    if(lpvIndex < LPV_CASCADES_COUNT)
    {
      if((semiCascade == 1) && (fragDist < (lpvRange * LPV_CASCADES_BLEND_RATIO + lpvStart)))
        break;

      vec3 lpvP = positionWorld / ((semiCascade == 0) ? lpvEnd : (lpvCellSize[lpvIndex].x * lpvTexSize.y * 0.5)) * 0.5 + 0.5;
      lpvP.x = (lpvP.x + float(lpvIndex)) / float(LPV_CASCADES_COUNT);
      lpvColor2 = texture(lpvTexR, lpvP).rgb;
    }

    if(semiCascade == 0)
      lpvColor = lpvColor2;
    else
      lpvColor = mix(lpvColor, lpvColor2, clamp((fragDist - lpvStart - lpvRange * LPV_CASCADES_BLEND_RATIO) / (lpvRange * (1.0 - LPV_CASCADES_BLEND_RATIO)), 0.0, 1.0));
  }
#endif

#ifndef SHAD_TEX
  float depthVis = 1.0;
#else
  vec3 sCoord[SHADOW_CASCADES_COUNT];
  for(int i = 0; i < SHADOW_CASCADES_COUNT; i++)
    sCoord[i] = shadowCoord[i];

  int shadowIndex = 0;
  float shadowEnd = 0.0;
  float shadowStart = 0.0;

  for(shadowIndex = 0; shadowIndex < SHADOW_CASCADES_COUNT; shadowIndex++)
  {
    shadowStart = shadowEnd;
#if !defined(SHADOW_JITTER) || defined(SHADOW_JITTER_CASCADES)
    shadowEnd = shadowClips[shadowIndex].x;
#else
    shadowEnd = shadowClips[shadowIndex].x - shadowTexSize.x * 0.5 * shadowTexSize.z * shadowClips[shadowIndex].x;
#endif

    if(fragDist <= shadowEnd)
      break;
  }

  float shadowRange = shadowEnd - shadowStart;
  float depthVis = 0.0;

  for(int semiCascade = 0; semiCascade < 2; semiCascade++, shadowIndex++)
  {
    float dVis = 1.0;

    if(shadowIndex < SHADOW_CASCADES_COUNT)
    {
      if((semiCascade == 1) && (fragDist < (shadowRange * SHADOW_CASCADES_BLEND_RATIO + shadowStart)))
        break;

#ifndef SHADOW_JITTER
      vec2 tileMin = vec2(float(shadowIndex % int(tiles.x)), float(shadowIndex / int(tiles.x))) * tiles.zw;
      dVis = texture(shadTex, vec3(sCoord[shadowIndex].xy * tiles.zw + tileMin, sCoord[shadowIndex].z));
#else
#ifdef SHADOW_JITTER_CASCADES
      float depthStart = 0.0;
      float depthCenter = 0.0;
      float kernelOffset[3];
      kernelOffset[0] = -1.0; kernelOffset[1] = 0.0; kernelOffset[2] = 1.0;

      for(int i = 0; i < SHADOW_CASCADES_COUNT; i++)
      {
        if(shadowIndex > i)
          continue;

        vec2 tileMin = vec2(float(i % int(tiles.x)), float(i / int(tiles.x))) * tiles.zw;
        float depthEnd = shadowClips[i].x * ((i == (SHADOW_CASCADES_COUNT - 1)) ? 1.0 : 0.25);

        for(int j = 0; j < 9; j++)
        {
          float penumbraVisOffset = (sCoord[i].z - texture(shadDepthTex, sCoord[i].xy * tiles.zw + tileMin + shadowTexSize.xy * 0.5 * vec2(kernelOffset[j % 3], kernelOffset[j / 3])).r) * shadowClips[i].y;

          if((penumbraVisOffset >= depthStart) && (penumbraVisOffset < depthEnd))
          {
            dVis -= 1.0 - texture(shadTex, vec3(sCoord[i].xy * tiles.zw + tileMin, sCoord[i].z));
            break;
          }
        }

        depthStart = depthEnd - (depthEnd - depthCenter) * 0.5;
        depthCenter = depthEnd;
      }
      dVis = clamp(dVis, 0.0, 1.0);
#else
      vec2 tileMin = vec2(float(shadowIndex % int(tiles.x)), float(shadowIndex / int(tiles.x))) * tiles.zw;

      vec2 kernel[16];
      kernel[0] = vec2(0.0, 1.0);
      kernel[1] = vec2(0.382683, 0.92388);
      kernel[2] = vec2(0.707107, 0.707107);
      kernel[3] = vec2(0.92388, 0.382683);
      kernel[4] = vec2(1.0, 0.0);
      kernel[5] = vec2(0.92388, -0.382684);
      kernel[6] = vec2(0.707107, -0.707107);
      kernel[7] = vec2(0.382683, -0.92388);
      kernel[8] = vec2(-8.74228e-008, -1.0);
      kernel[9] = vec2(-0.382683, -0.92388);
      kernel[10] = vec2(-0.707107, -0.707107);
      kernel[11] = vec2(-0.92388, -0.382683);
      kernel[12] = vec2(-1, 0.0);
      kernel[13] = vec2(-0.923879, 0.382684);
      kernel[14] = vec2(-0.707107, 0.707107);
      kernel[15] = vec2(-0.382683, 0.92388);
      const float ikern = 0.0625;
      vec2 kernSize = shadowTexSize.xy * 0.5 * shadowTexSize.z * (shadowClips[0].x / shadowClips[shadowIndex].x);

      float nearestDepth = 0.0;
      dVis = 0.0;

      for(int i = 0; i < 16; i++)
      {
        float vis = texture(shadDepthTex, sCoord[shadowIndex].xy * tiles.zw + tileMin + kernel[i] * kernSize).r;

        //if((i == 0) || (vis < nearestDepth))
        nearestDepth += vis * ikern;

        if((vis - sCoord[shadowIndex].z) >= 0.0)
          dVis += ikern;
      }

      if((dVis > 0.01) && (dVis < 0.99))
      {
        float penumbraRatio = clamp((sCoord[shadowIndex].z - nearestDepth) * shadowClips[shadowIndex].y * 0.2, 0.0, 1.0);

        dVis = 0.0;
        for(int i = 0; i < 16; i++)
          dVis += texture(shadTex, vec3(sCoord[shadowIndex].xy * tiles.zw + tileMin + kernel[i] * kernSize * penumbraRatio, sCoord[shadowIndex].z)) * ikern;
      }
#endif
#endif
    }

    if(semiCascade == 0)
      depthVis = dVis;
    else
      depthVis = mix(depthVis, dVis, clamp((fragDist - shadowStart - shadowRange * SHADOW_CASCADES_BLEND_RATIO) / (shadowRange * (1.0 - SHADOW_CASCADES_BLEND_RATIO)), 0.0, 1.0));
  }
#endif

  vec3 viewDir = normalize(cam - positionWorld);
  vec3 lightDir = lightPos - positionWorld;

  float lightDist = clamp((length(lightDir) - lightRange.x) / (lightRange.y - lightRange.x) * -1.0 + 1.0, 0.0, 1.0);
  lightDir = normalize(lightDir);
  float lightDot = max(0.0, dot(normalDir, lightDir)) * depthVis;

  vec3 colorDif = lightColor * lightDot * lightDist + lightAmb + lpvColor;
#ifndef BLINN_PHONG
  float lightSpecDot = max(0.0, dot(viewDir, reflect(-lightDir, normalDir))); // phong
#else
  float lightSpecDot = max(0.0, dot(normalDir, normalize(lightDir + viewDir))); // blinn-phong
#endif
  float fresnelSpe = min(pow(1.0 - dot(viewDir, normalDir), 4.0) + 0.25, 1.0);
  vec3 colorSpe = lightSpeColor.rgb * pow(lightSpecDot, lightSpeColor.a) * lightDot * lightDist * fresnelSpe;

  float fogDist = clamp((fragDist - fogRange.x) / (fogRange.y - fogRange.x), 0.0, 1.0);
  /*float fogDot = pow(max(0.0, dot(normalize(cam - lightPos), viewDir)), 16.0);
  float fresPow = clamp(pow(1.0 - dot(viewDir, normalDir) * 0.5, 8.0), 0.0, 1.0) * 1.0;*/

#ifdef ALP_TEX
  alpha += (colorSpe.r + colorSpe.g + colorSpe.b) * 0.3333333334;
#endif
  glFragColor = vec4(mix(fragDif.rgb * color.rgb * colorDif + fragSpe * colorSpe/* + fresPow * fogColor*/, fogColor/* + fogDot * lightColor*/, fogDist), alpha);
}
