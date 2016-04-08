#version 150
precision lowp float;

#define LPV_CASCADES_COUNT

#ifdef LPV_GATHERING
in float texPos;
#else
in vec3 texPos;
in vec3 dir;
#endif

uniform sampler3D lpvTexR;
uniform sampler3D lpvTexG;
uniform sampler3D lpvTexB;
uniform sampler3D lpvAccumTexR;
uniform sampler3D lpvAccumTexG;
uniform sampler3D lpvAccumTexB;
uniform sampler3D gvTex;

uniform vec3 lpvTexSize;

out vec4 glFragColor0LpvR;
out vec4 glFragColor1LpvG;
out vec4 glFragColor2LpvB;
out vec4 glFragColor3LpvAccumR;
out vec4 glFragColor4LpvAccumG;
out vec4 glFragColor5LpvAccumB;
out vec4 glFragColor6Gv;

void main()
{
  vec4 cosineLobe = vec4(0.8862, -1.0233, 1.0233, -1.0233);
  vec4 shBase = vec4(0.2821, -0.4886, 0.4886, -0.4886);

  vec3 dirs[6];
  dirs[0] = vec3(0.0, 0.0, -1.0); dirs[1] = vec3(0.0, 0.0, 1.0);
  dirs[2] = vec3(0.0, -1.0, 0.0); dirs[3] = vec3(0.0, 1.0, 0.0);
  dirs[4] = vec3(-1.0, 0.0, 0.0); dirs[5] = vec3(1.0, 0.0, 0.0);

#ifdef LPV_GATHERING
  vec3 tex = 1.0 / lpvTexSize;
  vec3 pos = vec3(gl_FragCoord.xy, texPos) * tex;
  int cascade = int(gl_FragCoord.x) / LPV_CASCADES_COUNT;

  vec4 shR = vec4(0.0);
  vec4 shG = vec4(0.0);
  vec4 shB = vec4(0.0);

  for(int cell = 0; cell < 6; cell++)
  {
    vec3 p = pos + tex * dirs[cell];

    //if(cascade == (int(gl_FragCoord.x + dirs[cell].x) / LPV_CASCADES_COUNT))
    //{
      vec4 shCellR = texture(lpvTexR, p);
      vec4 shCellG = texture(lpvTexG, p);
      vec4 shCellB = texture(lpvTexB, p);

      for(int face = 0; face < 6; face++)
      {
        vec3 faceDir = dirs[face] * 0.5 - dirs[cell];
        float faceLength = length(faceDir);

        if(faceLength > 0.6)
        {
          float solidAngle = 0.0;

          if(faceLength < 1.4)
            solidAngle = 0.12732;
          else
            solidAngle = 0.13477;

          vec3 normal = normalize(faceDir);
          vec4 shNormal = shBase * vec4(1.0, normal.y, normal.z, normal.x);
          vec4 shDir = cosineLobe * vec4(1.0, dirs[face].y, dirs[face].z, dirs[face].x);

          shR += solidAngle * max(0.0, dot(shCellR, shNormal)) * shDir;
          shG += solidAngle * max(0.0, dot(shCellG, shNormal)) * shDir;
          shB += solidAngle * max(0.0, dot(shCellB, shNormal)) * shDir;
        }
      }
    //}
  }

  glFragColor0LpvR = shR;
  glFragColor1LpvG = shG;
  glFragColor2LpvB = shB;
  glFragColor3LpvAccumR = texture(lpvAccumTexR, pos) + shR;
  glFragColor4LpvAccumG = texture(lpvAccumTexG, pos) + shG;
  glFragColor5LpvAccumB = texture(lpvAccumTexB, pos) + shB;
  glFragColor6Gv = texture(gvTex, pos);
#else
  vec3 tex = 1.0 / lpvTexSize;
  vec3 pos = texPos * tex;

  if(length(dir) < 0.1)
  { // acc, gv pass
    glFragColor0LpvR = vec4(0.0);
    glFragColor1LpvG = vec4(0.0);
    glFragColor2LpvB = vec4(0.0);
    glFragColor3LpvAccumR = texture(lpvAccumTexR, pos);
    glFragColor4LpvAccumG = texture(lpvAccumTexG, pos);
    glFragColor5LpvAccumB = texture(lpvAccumTexB, pos);
    glFragColor6Gv = texture(gvTex, pos);

    return;
  }

  vec4 shR = vec4(0.0);
  vec4 shG = vec4(0.0);
  vec4 shB = vec4(0.0);
  vec4 shCellR = texture(lpvTexR, pos);
  vec4 shCellG = texture(lpvTexG, pos);
  vec4 shCellB = texture(lpvTexB, pos);

  for(int face = 0; face < 6; face++)
  {
    vec3 faceDir = dirs[face] * 0.5 - dir;
    float faceLength = length(faceDir);

    if(faceLength > 0.6)
    {
      float solidAngle = 0.0;

      if(faceLength < 1.4)
        solidAngle = 0.12732;
      else
        solidAngle = 0.13477;

      vec3 normal = normalize(faceDir);
      vec4 shNormal = shBase * vec4(1.0, normal.y, normal.z, normal.x);
      vec4 shDir = cosineLobe * vec4(1.0, dirs[face].y, dirs[face].z, dirs[face].x);

      shR += solidAngle * max(0.0, dot(shCellR, shNormal)) * shDir;
      shG += solidAngle * max(0.0, dot(shCellG, shNormal)) * shDir;
      shB += solidAngle * max(0.0, dot(shCellB, shNormal)) * shDir;
    }
  }

  glFragColor0LpvR = shR;
  glFragColor1LpvG = shG;
  glFragColor2LpvB = shB;
  glFragColor3LpvAccumR = shR;
  glFragColor4LpvAccumG = shG;
  glFragColor5LpvAccumB = shB;
  glFragColor6Gv = texture(gvTex, pos);
#endif
}
