#version 150
precision lowp float;

#if defined(LPV_GATHERING) || defined(LPV_SCATTERING)
#ifndef LPV_LOBE
#define LPV_PROPAGATION_INTENSITY2 1.0
#else
#define LPV_PROPAGATION_INTENSITY2 2.2
#endif
#ifndef LPV_GV
#define LPV_PROPAGATION_INTENSITY (1.0 * LPV_PROPAGATION_INTENSITY2)
#else
#define LPV_PROPAGATION_INTENSITY (1.4 * LPV_PROPAGATION_INTENSITY2)
#endif
#endif
#define SSLPV_PROPAGATION_INTENSITY 0.3

#define LPV_CASCADES_COUNT

#if (defined(LPV_GATHERING) || defined(LPV_LOBE)) && !defined(LPV_SCATTERING)
in float texPos;
#else
in vec3 texPos;
in vec3 dir;
#endif

#if defined(LPV_GATHERING) || defined(LPV_SCATTERING)
uniform sampler3D lpvTexR;
uniform sampler3D lpvTexG;
uniform sampler3D lpvTexB;
uniform sampler3D lpvAccumTexR;
uniform sampler3D lpvAccumTexG;
uniform sampler3D lpvAccumTexB;
#endif
uniform sampler3D lpvNormalTex;
#if defined(LPV_GATHERING) || defined(LPV_SCATTERING)
uniform sampler3D gvTex;
#endif

uniform vec3 lpvTexSize;
uniform vec4 lpvParams;

#if defined(LPV_GATHERING) || defined(LPV_SCATTERING)
out vec4 glFragColor0LpvR;
out vec4 glFragColor1LpvG;
out vec4 glFragColor2LpvB;
out vec4 glFragColor3LpvAccumR;
out vec4 glFragColor4LpvAccumG;
out vec4 glFragColor5LpvAccumB;
out vec4 glFragColor6LpvNormal;
#else
out vec4 glFragColor0LpvNormal;
#endif

void main()
{
  vec4 cosineLobe = vec4(0.8862, -1.0233, 1.0233, -1.0233);
  vec4 shBase = vec4(0.2821, -0.4886, 0.4886, -0.4886);

  vec3 dirs[6];
  dirs[0] = vec3(0.0, 0.0, -1.0); dirs[1] = vec3(0.0, 0.0, 1.0);
  dirs[2] = vec3(0.0, -1.0, 0.0); dirs[3] = vec3(0.0, 1.0, 0.0);
  dirs[4] = vec3(-1.0, 0.0, 0.0); dirs[5] = vec3(1.0, 0.0, 0.0);

  vec3 tex = 1.0 / lpvTexSize;
#if (defined(LPV_GATHERING) || defined(LPV_LOBE)) && !defined(LPV_SCATTERING)
  vec3 pos = vec3(gl_FragCoord.xy, texPos) * tex;
  int cascade = int(gl_FragCoord.x) / LPV_CASCADES_COUNT;
#endif

#if defined(LPV_GATHERING)
  vec4 shR = vec4(0.0);
  vec4 shG = vec4(0.0);
  vec4 shB = vec4(0.0);

#ifdef LPV_LOBE
  vec4 cellNormal = texture(lpvNormalTex, pos);
  if(length(cellNormal.xyz) > 0.01)
    cellNormal = normalize(cellNormal);
#endif

  for(int cell = 0; cell < 6; cell++)
  {
    vec3 p = pos + tex * dirs[cell];

    //if(cascade == (int(gl_FragCoord.x + dirs[cell].x) / LPV_CASCADES_COUNT)) // lpv cascade border
    //{
      vec4 shCellR = texture(lpvTexR, p);
      vec4 shCellG = texture(lpvTexG, p);
      vec4 shCellB = texture(lpvTexB, p);

      for(int face = 0; face < 6; face++)
      {
        vec3 faceDir = dirs[face] * 0.5 - dirs[cell];
        float faceLength = length(faceDir);

        if(faceLength < 0.6)
          continue;

        float solidAngle = (faceLength < 1.4) ? 0.12732 : 0.13477;
        vec3 normal = normalize(faceDir);
        vec4 shNormal = shBase * vec4(1.0, normal.y, normal.z, normal.x);
        vec4 shDir = cosineLobe * vec4(1.0, dirs[face].y, dirs[face].z, dirs[face].x);

#ifdef LPV_LOBE
        vec4 shOriginal = shBase * vec4(1.0, cellNormal.y, cellNormal.z, cellNormal.x);
        vec4 shLobeOriginal = cosineLobe * vec4(1.0, cellNormal.y, cellNormal.z, cellNormal.x);
        shDir = max(0.0, dot(shDir, shOriginal)) * shLobeOriginal;
#endif

        shDir *= LPV_PROPAGATION_INTENSITY;
        if(lpvParams.w < 0.0)
          shDir *= SSLPV_PROPAGATION_INTENSITY;
#ifdef LPV_GV
        vec4 shGv = texture(gvTex, pos - tex * 0.5 + faceDir * tex * 0.5);
        shDir *= 1.0 - clamp(shGv.x * shNormal.x + abs(dot(shGv.yzw, shNormal.yzw)), 0.0, 1.0);
#endif

        shR += solidAngle * max(0.0, dot(shCellR, shNormal)) * shDir;
        shG += solidAngle * max(0.0, dot(shCellG, shNormal)) * shDir;
        shB += solidAngle * max(0.0, dot(shCellB, shNormal)) * shDir;
      }
    //}
  }

  glFragColor0LpvR = shR;
  glFragColor1LpvG = shG;
  glFragColor2LpvB = shB;
  glFragColor3LpvAccumR = texture(lpvAccumTexR, pos) + shR;
  glFragColor4LpvAccumG = texture(lpvAccumTexG, pos) + shG;
  glFragColor5LpvAccumB = texture(lpvAccumTexB, pos) + shB;
  glFragColor6LpvNormal = vec4(0.0);

#elif defined(LPV_SCATTERING)
  vec3 pos = texPos * tex;

  if(length(dir) < 0.1)
  { // accum pass
    glFragColor0LpvR = vec4(0.0);
    glFragColor1LpvG = vec4(0.0);
    glFragColor2LpvB = vec4(0.0);
    glFragColor3LpvAccumR = texture(lpvAccumTexR, pos);
    glFragColor4LpvAccumG = texture(lpvAccumTexG, pos);
    glFragColor5LpvAccumB = texture(lpvAccumTexB, pos);
    glFragColor6LpvNormal = vec4(0.0);

    return;
  }

  vec4 shR = vec4(0.0);
  vec4 shG = vec4(0.0);
  vec4 shB = vec4(0.0);
  vec4 shCellR = texture(lpvTexR, pos);
  vec4 shCellG = texture(lpvTexG, pos);
  vec4 shCellB = texture(lpvTexB, pos);

#ifdef LPV_LOBE
  vec4 cellNormal = texture(lpvNormalTex, pos);
  if(length(cellNormal.xyz) > 0.01)
    cellNormal = normalize(cellNormal);
#endif

  for(int face = 0; face < 6; face++)
  {
    vec3 faceDir = dir + dirs[face] * 0.5;
    float faceLength = length(faceDir);

    if(faceLength < 0.6)
      continue;

    float solidAngle = (faceLength < 1.4) ? 0.12732 : 0.13477;
    vec3 normal = normalize(faceDir);
    vec4 shNormal = shBase * vec4(1.0, normal.y, normal.z, normal.x);
    vec4 shDir = cosineLobe * vec4(1.0, dirs[face].y, dirs[face].z, dirs[face].x);

#ifdef LPV_LOBE
    vec4 shOriginal = shBase * vec4(1.0, cellNormal.y, cellNormal.z, cellNormal.x);
    vec4 shLobeOriginal = cosineLobe * vec4(1.0, cellNormal.y, cellNormal.z, cellNormal.x);
    shDir = max(0.0, dot(shDir, shOriginal)) * shLobeOriginal;
#endif

    shDir *= LPV_PROPAGATION_INTENSITY;
    if(lpvParams.w < 0.0)
      shDir *= SSLPV_PROPAGATION_INTENSITY;
#ifdef LPV_GV
    vec4 shGv = texture(gvTex, pos - tex * 0.5 + faceDir * tex * 0.5);
    shDir *= 1.0 - clamp(shGv.x * shNormal.x + abs(dot(shGv.yzw, shNormal.yzw)), 0.0, 1.0);
#endif

    shR += solidAngle * max(0.0, dot(shCellR, shNormal)) * shDir;
    shG += solidAngle * max(0.0, dot(shCellG, shNormal)) * shDir;
    shB += solidAngle * max(0.0, dot(shCellB, shNormal)) * shDir;
  }

  glFragColor0LpvR = shR;
  glFragColor1LpvG = shG;
  glFragColor2LpvB = shB;
  glFragColor3LpvAccumR = shR;
  glFragColor4LpvAccumG = shG;
  glFragColor5LpvAccumB = shB;
  glFragColor6LpvNormal = vec4(0.0);

#else // gathering normals dilatation
  vec4 normal = texture(lpvNormalTex, pos);

  if(length(normal) == 0.0)
  {
    int ratio = 1;

    for(int cell = 0; cell < 6; cell++)
    {
      vec3 p = pos + tex * dirs[cell];

      //if(cascade == (int(gl_FragCoord.x + dirs[cell].x) / LPV_CASCADES_COUNT)) // lpv cascade border
      //{
        vec4 cellNormal = texture(lpvNormalTex, p);

        if(length(cellNormal) > 0.0)
        {
          normal = mix(normal, cellNormal, 1.0 / float(ratio));
          ratio++;
        }
      //}
    }
  }

  glFragColor0LpvNormal = normal;
#endif
}
