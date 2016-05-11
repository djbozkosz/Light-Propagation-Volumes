#version 150
precision lowp float;

#define BLINN_PHONG
//#define NOR_TEX_DEBUG
//#define SHADOW_JITTER_CASCADES
//#define SSLPV
//#define SSLPV_CASCADES
#define LPV_REFLECTIONS
//#define LPV_CASCADE_REFLECTIONS
#define SHADOW_CASCADES_BLEND_RATIO 0.8
#define LPV_CASCADES_BLEND_RATIO 0.1
#define LPV_MULTI_CASCADES 2
#define SSLPV_MULTI_CASCADES 1
#define SSLPV_DEPTH 5
#define LPV_FIXED_REFL_CASCADE 2
#define LPV_REFLECTION_DEPTH 5

#define SHADOW_CASCADES_COUNT
#define LPV_CASCADES_COUNT

in vec3 positionWorld;
#ifndef NOR_TEX
in vec3 normal;
#endif
in vec2 texCoord;
in vec4 color;
#ifdef SHAD_TEX
in vec4 shadowCoord[SHADOW_CASCADES_COUNT];
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
uniform sampler3D lpvAccumTexR;
uniform sampler3D lpvAccumTexG;
uniform sampler3D lpvAccumTexB;
#if defined(SSLPV) || defined(SSLPV_CASCADES)
uniform sampler3D sslpvAccumTexR;
uniform sampler3D sslpvAccumTexG;
uniform sampler3D sslpvAccumTexB;
#endif
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
uniform vec3 lpvPos[LPV_CASCADES_COUNT];
uniform vec3 lpvTexSize;
uniform vec3 lpvCellSize[LPV_CASCADES_COUNT];
uniform vec4 lpvParams;
#endif

out vec4 glFragColor;

void main()
{
  vec4 fragDif = texture(difTex, texCoord);

  if(((type & 0x20000000) != 0) && (fragDif.a < 0.8))
    discard;

#ifdef SHAD_TEX
  if(lpvParams.x != 0.0)
    fragDif.xyz = vec3(1.0);
#endif

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

/*#ifdef NOR_TEX_DEBUG
  glFragColor = vec4(normalDir * 0.5 + 0.5, alpha);
  return;
#endif*/

  float fragDist = distance(cam, positionWorld);
  vec3 viewDir = normalize(cam - positionWorld);
  vec3 lpvColor = vec3(0.0, 0.0, 0.0);
  vec3 lpvColorSpec = vec3(0.0, 0.0, 0.0);

#ifdef SHAD_TEX
  int lpvIndex = 0;
  int lpvReflIndex = 0;
  float lpvEnd = 0.0;
  float lpvStart = 0.0;

  vec4 shBase = vec4(0.2821, -0.4886, 0.4886, -0.4886);
  //vec4 shBase = vec4(0.8862, -1.0233, 1.0233, -1.0233);

  for(lpvIndex = 0; lpvIndex < LPV_CASCADES_COUNT; lpvIndex++)
  {
    lpvStart = lpvEnd;
    lpvEnd = lpvCellSize[lpvIndex].x * lpvTexSize.y * 0.5;

    if(fragDist <= lpvEnd)
      break;
  }

  lpvReflIndex = lpvIndex;
  float lpvRange = lpvEnd - lpvStart;
  float lpvRatio = clamp((fragDist - lpvStart - lpvRange * LPV_CASCADES_BLEND_RATIO) / (lpvRange * (1.0 - LPV_CASCADES_BLEND_RATIO)), 0.0, 1.0);

  for(int semiCascade = 0; semiCascade < (LPV_MULTI_CASCADES + 2); semiCascade++, lpvIndex++)
  {
    vec3 lpvColor2 = vec3(0.0, 0.0, 0.0);

    if(lpvIndex >= LPV_CASCADES_COUNT)
      lpvIndex--;

    if((semiCascade == (LPV_MULTI_CASCADES + 1)) && (fragDist < (lpvRange * LPV_CASCADES_BLEND_RATIO + lpvStart)))
      break;

    vec3 lpvP = (positionWorld - lpvPos[lpvIndex]) / (lpvCellSize[lpvIndex].x * lpvTexSize.y * 0.5) * 0.5 + 0.5;
    lpvP.x = (lpvP.x + float(lpvIndex)) / float(LPV_CASCADES_COUNT);

    vec4 shNormal = shBase * vec4(1.0, -normalDir.y, -normalDir.z, -normalDir.x);
    vec4 lpvShR = texture(lpvAccumTexR, lpvP);
    vec4 lpvShG = texture(lpvAccumTexG, lpvP);
    vec4 lpvShB = texture(lpvAccumTexB, lpvP);
    lpvColor2 = vec3(max(0.0, dot(shNormal, lpvShR)), max(0.0, dot(shNormal, lpvShG)), max(0.0, dot(shNormal, lpvShB))) * lpvParams.y * ((lpvIndex == 0) ? 2.0 : 1.0);
    //lpvColor2 = lpvShR.rgb;

    if(semiCascade == 0)
      lpvColor2 *= 1.0 - lpvRatio;
    else if(semiCascade == (LPV_MULTI_CASCADES + 1))
      lpvColor2 *= lpvRatio;

    lpvColor += lpvColor2;
  }

  lpvColor /= float(LPV_MULTI_CASCADES + 1);
  lpvIndex = lpvReflIndex;

#if defined(SSLPV)
  vec3 sslpvColor = vec3(0.0);

  for(int semiCascade = 0; semiCascade < (SSLPV_MULTI_CASCADES + 2); semiCascade++, lpvIndex++)
  {
    vec3 lpvColor2 = vec3(0.0, 0.0, 0.0);

    if(lpvIndex >= LPV_CASCADES_COUNT)
      lpvIndex--;

    if((semiCascade == (SSLPV_MULTI_CASCADES + 1)) && (fragDist < (lpvRange * LPV_CASCADES_BLEND_RATIO + lpvStart)))
      break;

    vec3 lpvP = (positionWorld - lpvPos[lpvIndex]) / (lpvCellSize[lpvIndex].x * lpvTexSize.y * 0.5) * 0.5 + 0.5;
    lpvP.x = (lpvP.x + float(lpvIndex)) / float(LPV_CASCADES_COUNT);

    vec3 lPos = normalize(lightPos);
    vec4 shNormal = shBase * vec4(1.0, -lPos.y, -lPos.z, -lPos.x);
    vec4 lpvShR = texture(sslpvAccumTexR, lpvP);
    vec4 lpvShG = texture(sslpvAccumTexG, lpvP);
    vec4 lpvShB = texture(sslpvAccumTexB, lpvP);
    lpvColor2 = pow(vec3(max(0.0, dot(shNormal, lpvShR)), max(0.0, dot(shNormal, lpvShG)), max(0.0, dot(shNormal, lpvShB))) * lpvParams.y * ((lpvIndex == 0) ? 2.0 : 1.0), vec3(2.0));

    if(semiCascade == 0)
      lpvColor2 *= 1.0 - lpvRatio;
    else if(semiCascade == (SSLPV_MULTI_CASCADES + 1))
      lpvColor2 *= lpvRatio;

    sslpvColor += lpvColor2;
  }

  sslpvColor /= float(SSLPV_MULTI_CASCADES + 1);
  lpvColor += sslpvColor;
#elif defined(SSLPV_CASCADES)
  vec3 lPos = normalize(lightPos);
  vec3 ssDist = lpvCellSize[0].x * -viewDir * 1.732;
  vec3 ssPos = positionWorld;
  float ssRatio = 1.0 / float(SSLPV_DEPTH);

  for(int ssSample = 0; ssSample < SSLPV_DEPTH; ssSample++)
  {
    for(int sslpvI = lpvReflIndex; (sslpvI < (lpvReflIndex + 2)) && (sslpvI < LPV_CASCADES_COUNT); sslpvI++)
    {
      vec3 lpvP = (ssPos - lpvPos[sslpvI]) / (lpvCellSize[sslpvI].x * lpvTexSize.y * 0.5) * 0.5 + 0.5;
      lpvP.x = (lpvP.x + float(sslpvI)) / float(LPV_CASCADES_COUNT);

      vec4 shNormal = shBase * vec4(1.0, -lPos.y, -lPos.z, -lPos.x);
      vec4 lpvShR = texture(lpvAccumTexR, lpvP);
      vec4 lpvShG = texture(lpvAccumTexG, lpvP);
      vec4 lpvShB = texture(lpvAccumTexB, lpvP);
      lpvColor += vec3(max(0.0, dot(shNormal, lpvShR)), max(0.0, dot(shNormal, lpvShG)), max(0.0, dot(shNormal, lpvShB))) * ((sslpvI == lpvReflIndex) ? (1.0 - lpvRatio) : lpvRatio) * ssRatio * 0.5 * lpvParams.y;
    }

    ssPos += ssDist;
    ssDist *= 1.0;
    float ssDistWorld = distance(cam, ssPos);

    if(ssDistWorld > lpvEnd)
    {
      lpvReflIndex++;

      if(lpvReflIndex >= LPV_CASCADES_COUNT)
        break;
      else
      {
        lpvStart = lpvEnd;
        lpvEnd = lpvCellSize[lpvReflIndex].x * lpvTexSize.y * 0.5;
        lpvRange = lpvEnd - lpvStart;
        lpvRatio = clamp((ssDistWorld - lpvStart - lpvRange * LPV_CASCADES_BLEND_RATIO) / (lpvRange * (1.0 - LPV_CASCADES_BLEND_RATIO)), 0.0, 1.0);
      }
    }
  }
#endif

#if defined(LPV_REFLECTIONS)
  vec3 reflDir = reflect(-viewDir, normalDir);
  vec3 reflDist = lpvCellSize[2].x * reflDir * 1.732;
  vec3 relfPos = positionWorld;
  float reflRatio = 1.0 / float(LPV_REFLECTION_DEPTH);

  if(lpvReflIndex <= LPV_FIXED_REFL_CASCADE)
  {
    for(int reflSample = 0; reflSample < LPV_REFLECTION_DEPTH; reflSample++)
    {
      vec3 lpvP = (relfPos - lpvPos[LPV_FIXED_REFL_CASCADE]) / (lpvCellSize[LPV_FIXED_REFL_CASCADE].x * lpvTexSize.y * 0.5) * 0.5 + 0.5;
      lpvP.x = (lpvP.x + float(LPV_FIXED_REFL_CASCADE)) / float(LPV_CASCADES_COUNT);

      vec4 shNormal = shBase * vec4(1.0, -reflDir.y, -reflDir.z, -reflDir.x);
      vec4 lpvShR = texture(lpvAccumTexR, lpvP);
      vec4 lpvShG = texture(lpvAccumTexG, lpvP);
      vec4 lpvShB = texture(lpvAccumTexB, lpvP);
      lpvColorSpec += vec3(max(0.0, dot(shNormal, lpvShR)), max(0.0, dot(shNormal, lpvShG)), max(0.0, dot(shNormal, lpvShB))) * ((lpvReflIndex == LPV_FIXED_REFL_CASCADE) ? (1.0 - lpvRatio) : 1.0) * reflRatio * 0.5 * lpvParams.z;

      relfPos += reflDist;
    }
  }
#elif defined(LPV_CASCADE_REFLECTIONS)
  vec3 reflDir = reflect(-viewDir, normalDir);
  float reflDist = lpvCellSize[0].x * 1.732;
  vec3 relfPos = positionWorld;
  vec3 relfPos2 = positionWorld;
  float reflRatio = 1.0 / float(LPV_REFLECTION_DEPTH);

  for(int reflSample = 0; reflSample < LPV_REFLECTION_DEPTH; reflSample++)
  {
    for(int lpvReflI = lpvReflIndex; (lpvReflI < (lpvReflIndex + 2)) && (lpvReflI < LPV_CASCADES_COUNT); lpvReflI++)
    {
      vec3 lpvP = (relfPos - lpvPos[lpvReflI]) / (lpvCellSize[lpvReflI].x * lpvTexSize.y * 0.5) * 0.5 + 0.5;
      lpvP.x = (lpvP.x + float(lpvReflI)) / float(LPV_CASCADES_COUNT);

      vec4 shNormal = shBase * vec4(1.0, -reflDir.y, -reflDir.z, -reflDir.x);
      vec4 lpvShR = texture(lpvAccumTexR, lpvP);
      vec4 lpvShG = texture(lpvAccumTexG, lpvP);
      vec4 lpvShB = texture(lpvAccumTexB, lpvP);
      lpvColorSpec += vec3(max(0.0, dot(shNormal, lpvShR)), max(0.0, dot(shNormal, lpvShG)), max(0.0, dot(shNormal, lpvShB))) * ((lpvReflI == lpvReflIndex) ? (1.0 - lpvRatio) : lpvRatio) * reflRatio * 0.5 * lpvParams.z;
    }

    relfPos += reflDist * reflDir;
    relfPos2 += reflDist * viewDir;
    reflDist *= 2.0;
    float reflDistWorld = distance(cam, relfPos2);

    if(reflDistWorld > lpvEnd)
    {
      lpvReflIndex++;

      if(lpvReflIndex >= LPV_CASCADES_COUNT)
        break;
      else
      {
        lpvStart = lpvEnd;
        lpvEnd = lpvCellSize[lpvReflIndex].x * lpvTexSize.y * 0.5;
        lpvRange = lpvEnd - lpvStart;
        lpvRatio = clamp((reflDistWorld - lpvStart - lpvRange * LPV_CASCADES_BLEND_RATIO) / (lpvRange * (1.0 - LPV_CASCADES_BLEND_RATIO)), 0.0, 1.0);
      }
    }
  }
#endif
#endif

#ifndef SHAD_TEX
  float depthVis = 1.0;
#else
  vec4 sCoord[SHADOW_CASCADES_COUNT];
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
      dVis = textureProj(shadTex, sCoord[shadowIndex]);
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

        float depthEnd = shadowClips[i].x * ((i == (SHADOW_CASCADES_COUNT - 1)) ? 1.0 : 0.25);

        for(int j = 0; j < 9; j++)
        {
          float penumbraVisOffset = (sCoord[i].z - textureProj(shadDepthTex, vec3(sCoord[i].xy + shadowTexSize.xy * 0.5 * vec2(kernelOffset[j % 3], kernelOffset[j / 3]), sCoord[i].w)).r) * shadowClips[i].y;

          if((penumbraVisOffset >= depthStart) && (penumbraVisOffset < depthEnd))
          {
            dVis -= 1.0 - textureProj(shadTex, sCoord[shadowIndex]);
            break;
          }
        }

        depthStart = depthEnd - (depthEnd - depthCenter) * 0.5;
        depthCenter = depthEnd;
      }
      dVis = clamp(dVis, 0.0, 1.0);
#else
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
        float vis = textureProj(shadDepthTex, vec3(sCoord[shadowIndex].xy + kernel[i] * kernSize, sCoord[shadowIndex].w)).r;

        //if((i == 0) || (vis < nearestDepth))
        nearestDepth += vis * ikern;

        if((vis - sCoord[shadowIndex].z) >= 0.0)
          dVis += ikern;
      }

      //if((dVis > 0.01) && (dVis < 0.99))
      //{
        float penumbraRatio = clamp((sCoord[shadowIndex].z - nearestDepth) * shadowClips[shadowIndex].y * 0.2, 0.0, 1.0);

        dVis = 0.0;
        for(int i = 0; i < 16; i++)
          dVis += textureProj(shadTex, vec4(sCoord[shadowIndex].xy + kernel[i] * kernSize * penumbraRatio, sCoord[shadowIndex].z, sCoord[shadowIndex].w)) * ikern;
      //}
#endif
#endif
    }

    if(semiCascade == 0)
      depthVis = dVis;
    else
      depthVis = mix(depthVis, dVis, clamp((fragDist - shadowStart - shadowRange * SHADOW_CASCADES_BLEND_RATIO) / (shadowRange * (1.0 - SHADOW_CASCADES_BLEND_RATIO)), 0.0, 1.0));
  }
#endif

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
  glFragColor = vec4(mix(fragDif.rgb * color.rgb * colorDif + fragSpe * colorSpe + lpvColorSpec/* + fresPow * fogColor*/, fogColor/* + fogDot * lightColor*/, fogDist), alpha);

#ifdef NOR_TEX_DEBUG
  glFragColor = vec4(normalDir * 0.5 + 0.5, alpha);
#endif
}
