//------------------------------------------------------------------------------
#include "models.h"

//------------------------------------------------------------------------------
CModel::CModel() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CModel::CModel(CContext *context, const SModel &model) : CEngineBase(context), model(model)
{
}
//------------------------------------------------------------------------------
CModel::~CModel()
{
}
//------------------------------------------------------------------------------
NModel::EModelState CModel::load()
{
  CFile *f = context->getFilesystem()->open(SFile(model.path));

  if(!f)
  {
    //context->error(CStr(NModel::STR_ERROR_UNABLE_TO_OPEN, model.path.c_str()));
    model.state = NModel::STATE_INVALID_NOT_FOUND;
    return model.state;
  }

  f->read(model.signature, sizeof(char) * NFile::SIGNATURE_LENGTH_LONG);
  model.signature[NFile::SIGNATURE_LENGTH_LONG - 1] = 0;
  if(std::string(model.signature) != std::string(NModel::STR_MODEL_SIGNATURE))
  {
    context->error(CStr(NModel::STR_ERROR_INVALID_SIGNATURE, model.signature));
    model.state = NModel::STATE_INVALID_SIGNATURE;
    return model.state;
  }

  f->read(&model.version, sizeof(uint16));
  if(model.version != NModel::MODEL_VERSION)
  {
    context->error(CStr(NModel::STR_ERROR_INVALID_VERSION, model.version, NModel::MODEL_VERSION));
    model.state = NModel::STATE_INVALID_VERSION;
    return model.state;
  }

  f->read(&model.timestamp, sizeof(uint64));
  f->read(&model.materialsCount, sizeof(uint16));

  for(uint16 i = 0; i < model.materialsCount; i++)
  {
    SMaterial mat;

    if(loadMaterial(f, &mat) != NModel::STATE_VALID)
      return model.state;

    model.materials.push_back(mat);
  }

  f->read(&model.meshesCount, sizeof(uint16));

  for(uint16 i = 0; i < model.meshesCount; i++)
  {
    SMesh mesh;

    if(loadMesh(f, &mesh) != NModel::STATE_VALID)
      return model.state;

    model.meshes[mesh.name] = mesh;
  }

  f->read(&model.allowAnimation, sizeof(uint8));

  f->close();
  model.state = NModel::STATE_VALID;

  return model.state;
}
//------------------------------------------------------------------------------
NModel::EModelState CModel::loadMaterial(CFile *f, SMaterial *mat)
{
  mat->program = context->getShaders()->getProgram(NShader::PROGRAM_ILLUMINATION_SHADOW);

  f->read(&mat->type, sizeof(uint32));
  f->read(&mat->colorAmbient.x, sizeof(float));
  f->read(&mat->colorAmbient.y, sizeof(float));
  f->read(&mat->colorAmbient.z, sizeof(float));
  f->read(&mat->colorDiffuse.x, sizeof(float));
  f->read(&mat->colorDiffuse.y, sizeof(float));
  f->read(&mat->colorDiffuse.z, sizeof(float));
  f->read(&mat->colorEmission.x, sizeof(float));
  f->read(&mat->colorEmission.y, sizeof(float));
  f->read(&mat->colorEmission.z, sizeof(float));
  f->read(&mat->opacity, sizeof(float));

  if(mat->type & NModel::MATERIAL_ENVIRONMENT)
  {
    f->read(&mat->environmentMapRatio, sizeof(float));
    f->read(&mat->environmentMapLength, sizeof(uint8));
    mat->environmentMapName.resize(mat->environmentMapLength);
    f->read(&mat->environmentMapName[0], sizeof(char) * mat->environmentMapLength);
    mat->environmentMap = context->getMaps()->addMap(SMap(mat->environmentMapName));
  }

  f->read(&mat->diffuseMapLength, sizeof(uint8));
  mat->diffuseMapName.resize(mat->diffuseMapLength);
  f->read(&mat->diffuseMapName[0], sizeof(char) * mat->diffuseMapLength);
  mat->diffuseMap = context->getMaps()->addMap(SMap(mat->diffuseMapName));

  if(mat->diffuseMapName.length())
  { // additional maps
    const std::string file = CStr::extPathFile(mat->diffuseMapName);
    const std::string ext = CStr::extExt(mat->diffuseMapName);
    const char *const additionalMapNames[] = { NMap::STR_MAP_SUFFIX_SPEC, NMap::STR_MAP_SUFFIX_NORMAL };
    const CMap **const additionalMaps[] = { &mat->specularMap, &mat->normalMap };
    const SColor defaultColors[] = { SColor(NMap::DEFAULT_MAP_R, NMap::DEFAULT_MAP_G, NMap::DEFAULT_MAP_B, NMap::DEFAULT_MAP_A), SColor(NMap::DEFAULT_MAP_NORMAL_R, NMap::DEFAULT_MAP_NORMAL_G, NMap::DEFAULT_MAP_NORMAL_B, NMap::DEFAULT_MAP_NORMAL_A) };

    for(uint8 i = 0; i < 2; i++)
    {
      const std::string map(CStr(NMap::STR_MAP_SUFFIX, file.c_str(), additionalMapNames[i], ext.c_str()));
      CFile *f = context->getFilesystem()->open(SFile(std::string(NFile::STR_DATA_MAPS)+map, true));
      if(f)
      {
        f->close();
        *additionalMaps[i] = context->getMaps()->addMap(SMap(map, defaultColors[i]));
        if(i == 1)
          mat->program = context->getShaders()->getProgram(NShader::PROGRAM_ILLUMINATION_NORMAL_SHADOW);
      }
    }
  }

  if((mat->type & NModel::MATERIAL_ALPHA) && (mat->diffuseMapLength))
  {
    f->read(&mat->alphaMapLength, sizeof(uint8));
    mat->alphaMapName.resize(mat->alphaMapLength);
    f->read(&mat->alphaMapName[0], sizeof(char) * mat->alphaMapLength);
    mat->alphaMap = context->getMaps()->addMap(SMap(mat->alphaMapName));

    if(mat->alphaMap)
    {
      if(mat->program->getProgram()->name == NShader::PROGRAM_BASIC)
        mat->program = context->getShaders()->getProgram(NShader::PROGRAM_BASIC_ALPHA);
      else if(mat->program->getProgram()->name == NShader::PROGRAM_ILLUMINATION)
        mat->program = context->getShaders()->getProgram(NShader::PROGRAM_ILLUMINATION_ALPHA);
      else if(mat->program->getProgram()->name == NShader::PROGRAM_ILLUMINATION_SHADOW)
        mat->program = context->getShaders()->getProgram(NShader::PROGRAM_ILLUMINATION_ALPHA_SHADOW);
      else if(mat->program->getProgram()->name == NShader::PROGRAM_ILLUMINATION_NORMAL)
        mat->program = context->getShaders()->getProgram(NShader::PROGRAM_ILLUMINATION_NORMAL_ALPHA);
      else if(mat->program->getProgram()->name == NShader::PROGRAM_ILLUMINATION_NORMAL_SHADOW)
        mat->program = context->getShaders()->getProgram(NShader::PROGRAM_ILLUMINATION_NORMAL_ALPHA_SHADOW);
    }
  }

  if(mat->type & NModel::MATERIAL_ANIMATED)
  {
    f->read(&mat->animatedFramesCount, sizeof(uint32));
    f->read(&mat->animatedUndefined0, sizeof(uint16));
    f->read(&mat->animatedFramesPeriod, sizeof(uint32));
    f->read(&mat->animatedUndefined1, sizeof(uint32));
    f->read(&mat->animatedUndefined2, sizeof(uint32));
  }

  return NModel::STATE_VALID;
}
//------------------------------------------------------------------------------
NModel::EModelState CModel::loadMesh(CFile *f, SMesh *mesh)
{
  mesh->index = model.meshes.size() + 1;
  f->read(&mesh->type, sizeof(uint8));

  if((mesh->type != NModel::MESH_TYPE_STANDARD) &&
     (mesh->type != NModel::MESH_TYPE_SECTOR) &&
     (mesh->type != NModel::MESH_TYPE_DUMMY) &&
     (mesh->type != NModel::MESH_TYPE_TARGET) &&
     (mesh->type != NModel::MESH_TYPE_BONE))
  {
    context->error(CStr(NModel::STR_ERROR_INVALID_MESH_TYPE, mesh->type));
    model.state = NModel::STATE_INVALID_MESH_TYPE;
    return model.state;
  }
  if(mesh->type == NModel::MESH_TYPE_STANDARD)
  {
    f->read(&mesh->visualType, sizeof(uint8));
    if((mesh->visualType != NModel::MESH_VISUAL_TYPE_STANDARD) &&
       (mesh->visualType != NModel::MESH_VISUAL_TYPE_SINGLE_MESH) &&
       (mesh->visualType != NModel::MESH_VISUAL_TYPE_SINGLE_MORPH) &&
       (mesh->visualType != NModel::MESH_VISUAL_TYPE_BILLBOARD) &&
       (mesh->visualType != NModel::MESH_VISUAL_TYPE_MORPH) &&
       (mesh->visualType != NModel::MESH_VISUAL_TYPE_GLOW) &&
       (mesh->visualType != NModel::MESH_VISUAL_TYPE_MIRROR))
    {
      context->error(CStr(NModel::STR_ERROR_INVALID_MESH_VISUAL_TYPE, mesh->visualType));
      model.state = NModel::STATE_INVALID_MESH_VISUAL_TYPE;
      return model.state;
    }
    f->read(&mesh->renderFlags, sizeof(uint16));
  }
  f->read(&mesh->linkIndex, sizeof(uint16));
  mesh->link = getMesh(mesh->linkIndex);
  if((!mesh->link) && (mesh->linkIndex))
    context->warning(CStr(NModel::STR_WARNING_INVALID_MESH_LINK));

  f->read(&mesh->position.x, sizeof(float));
  f->read(&mesh->position.y, sizeof(float));
  f->read(&mesh->position.z, sizeof(float));
  f->read(&mesh->scale.x, sizeof(float));
  f->read(&mesh->scale.y, sizeof(float));
  f->read(&mesh->scale.z, sizeof(float));
  f->read(&mesh->rotation.w, sizeof(float));
  f->read(&mesh->rotation.x, sizeof(float));
  f->read(&mesh->rotation.y, sizeof(float));
  f->read(&mesh->rotation.z, sizeof(float));
  f->read(&mesh->cullingFlags, sizeof(uint8));

  f->read(&mesh->nameLength, sizeof(uint8));
  mesh->name.resize(mesh->nameLength);
  f->read(&mesh->name[0], sizeof(char) * mesh->nameLength);

  f->read(&mesh->parametersLength, sizeof(uint8));
  mesh->parameters.resize(mesh->parametersLength);
  f->read(&mesh->parameters[0], sizeof(char) * mesh->parametersLength);

  if(mesh->type == NModel::MESH_TYPE_STANDARD)
  {
    if((mesh->visualType == NModel::MESH_VISUAL_TYPE_STANDARD) ||
       (mesh->visualType == NModel::MESH_VISUAL_TYPE_SINGLE_MESH) ||
       (mesh->visualType == NModel::MESH_VISUAL_TYPE_SINGLE_MORPH) ||
       (mesh->visualType == NModel::MESH_VISUAL_TYPE_BILLBOARD) ||
       (mesh->visualType == NModel::MESH_VISUAL_TYPE_MORPH))
      loadStandardMesh(f, mesh);
    if((mesh->visualType == NModel::MESH_VISUAL_TYPE_SINGLE_MESH) ||
       (mesh->visualType == NModel::MESH_VISUAL_TYPE_SINGLE_MORPH))
      loadSingleMesh(f, mesh);
    if((mesh->visualType == NModel::MESH_VISUAL_TYPE_SINGLE_MORPH) ||
       (mesh->visualType == NModel::MESH_VISUAL_TYPE_MORPH))
      loadMorph(f, mesh);
    if(mesh->visualType == NModel::MESH_VISUAL_TYPE_BILLBOARD)
      loadBillboard(f, mesh);
    if(mesh->visualType == NModel::MESH_VISUAL_TYPE_GLOW)
      loadGlow(f, mesh);
    if(mesh->visualType == NModel::MESH_VISUAL_TYPE_MIRROR)
      loadMirror(f, mesh);
  }
  if(mesh->type == NModel::MESH_TYPE_SECTOR)
    loadSector(f, mesh);
  if(mesh->type == NModel::MESH_TYPE_DUMMY)
    loadDummy(f, mesh);
  if(mesh->type == NModel::MESH_TYPE_TARGET)
    loadTarget(f, mesh);
  if(mesh->type == NModel::MESH_TYPE_BONE)
    loadBone(f, mesh);

  return NModel::STATE_VALID;
}
//------------------------------------------------------------------------------
NModel::EModelState CModel::loadStandardMesh(CFile *f, SMesh *mesh)
{
  SStandardMesh *smesh = &mesh->standardMesh;

  f->read(&smesh->instancedMeshIndex, sizeof(uint16));
  smesh->instancedMesh = getMesh(smesh->instancedMeshIndex);
  if((!smesh->instancedMesh) && (smesh->instancedMeshIndex))
    context->warning(CStr(NModel::STR_WARNING_INVALID_STANDARD_MESH_INSTANCE, mesh->name.c_str()));

  if(smesh->instancedMesh)
    return NModel::STATE_VALID;

  f->read(&smesh->lodsCount, sizeof(uint8));
  if(!smesh->lodsCount)
    context->warning(CStr(NModel::STR_WARNING_STANDARD_MESH_NO_LODS, mesh->name.c_str()));

  for(uint8 i = 0; i < smesh->lodsCount; i++)
  {
    smesh->lods.push_back(SStandardMeshLod());
    SStandardMeshLod *lod = &smesh->lods.back();

    f->read(&lod->ratio, sizeof(float));
    if((lod->ratio == 0.0f) && (smesh->lods.size() < smesh->lodsCount))
      context->warning(CStr(NModel::STR_WARNING_INVALID_STANDARD_MESH_LOD_RATIO, mesh->name.c_str(), i));

    f->read(&lod->verticesCount, sizeof(uint16));
    if(!lod->verticesCount)
      context->warning(CStr(NModel::STR_WARNING_STANDARD_MESH_NO_VERTICES, mesh->name.c_str(), i));
    lod->vertices.resize(lod->verticesCount);

    for(auto vertex = lod->vertices.begin(); vertex != lod->vertices.end(); vertex++)
    {
      f->read(&vertex->position.x, sizeof(float));
      f->read(&vertex->position.y, sizeof(float));
      f->read(&vertex->position.z, sizeof(float));
      f->read(&vertex->normal.x, sizeof(float));
      f->read(&vertex->normal.y, sizeof(float));
      f->read(&vertex->normal.z, sizeof(float));
      f->read(&vertex->texCoord.x, sizeof(float));
      f->read(&vertex->texCoord.y, sizeof(float));
    }

    f->read(&lod->faceGroupsCount, sizeof(uint8));
    if(!lod->faceGroupsCount)
      context->warning(CStr(NModel::STR_WARNING_STANDARD_MESH_NO_FACE_GROUPS, mesh->name.c_str(), i));

    for(uint8 j = 0; j < lod->faceGroupsCount; j++)
    {
      lod->faceGroups.push_back(SFacesGroup());
      SFacesGroup *group = &lod->faceGroups.back();

      f->read(&group->facesCount, sizeof(uint16));
      if(!group->facesCount)
        context->warning(CStr(NModel::STR_WARNING_STANDARD_MESH_GROUP_NO_FACES, mesh->name.c_str(), i, j));
      group->faces.resize(group->facesCount);

      uint32 points = 0;
      uint32 lines = 0;

      for(auto face = group->faces.begin(); face != group->faces.end(); face++)
      {
        f->read(&face->vertex0, sizeof(uint16));
        f->read(&face->vertex1, sizeof(uint16));
        f->read(&face->vertex2, sizeof(uint16));

        if((face->vertex0 == face->vertex1) && (face->vertex0 == face->vertex2))
          points++;
        else if((face->vertex0 == face->vertex1) || (face->vertex0 == face->vertex2) || (face->vertex1 == face->vertex2))
          lines++;
      }

      if((points) || (lines))
        context->warning(CStr(NModel::STR_WARNING_STANDARD_MESH_GROUP_DEGEN_FACES, mesh->name.c_str(), i, j, lines, points));

      f->read(&group->materialIndex, sizeof(uint16));
      group->material = getMaterial(group->materialIndex);
    }
  }

  return NModel::STATE_VALID;
}
//------------------------------------------------------------------------------
NModel::EModelState CModel::loadSingleMesh(CFile *f, SMesh *mesh)
{
  SSingleMesh *sngm = &mesh->singleMesh;

  if(!mesh->standardMesh.lodsCount)
    context->warning(CStr(NModel::STR_WARNING_SINGLE_MESH_NO_LODS, mesh->name.c_str()));

  for(uint8 i = 0; i < mesh->standardMesh.lodsCount; i++)
  {
    sngm->lods.push_back(SSingleMeshLod());
    SSingleMeshLod *lod = &sngm->lods.back();

    f->read(&lod->bonesCount, sizeof(uint8));
    f->read(&lod->undefined0, sizeof(uint32));
    f->read(&lod->boundingBox.minimum.x, sizeof(float));
    f->read(&lod->boundingBox.minimum.y, sizeof(float));
    f->read(&lod->boundingBox.minimum.z, sizeof(float));
    f->read(&lod->boundingBox.maximum.x, sizeof(float));
    f->read(&lod->boundingBox.maximum.y, sizeof(float));
    f->read(&lod->boundingBox.maximum.z, sizeof(float));

    if(!lod->bonesCount)
      context->warning(CStr(NModel::STR_WARNING_SINGLE_MESH_NO_BONES, mesh->name.c_str(), i));

    for(uint8 i = 0; i < lod->bonesCount; i++)
    {
      lod->bones.push_back(SSingleMeshBone());
      SSingleMeshBone *bone = &lod->bones.back();

      f->read(glm::value_ptr(bone->transformation), sizeof(float) * NMath::MAT4);
      f->read(&bone->undefined0, sizeof(uint32));
      f->read(&bone->vertexParametersCount, sizeof(uint32));
      f->read(&bone->bone, sizeof(uint32));
      f->read(&bone->boundingBox.minimum.x, sizeof(float));
      f->read(&bone->boundingBox.minimum.y, sizeof(float));
      f->read(&bone->boundingBox.minimum.z, sizeof(float));
      f->read(&bone->boundingBox.maximum.x, sizeof(float));
      f->read(&bone->boundingBox.maximum.y, sizeof(float));
      f->read(&bone->boundingBox.maximum.z, sizeof(float));

      bone->vertexParameters.resize(bone->vertexParametersCount);
      f->read(&bone->vertexParameters[0], sizeof(float) * bone->vertexParametersCount);
    }
  }

  return NModel::STATE_VALID;
}
//------------------------------------------------------------------------------
NModel::EModelState CModel::loadMorph(CFile *f, SMesh *mesh)
{
  SMorph *mrph = &mesh->morph;

  f->read(&mrph->framesCount, sizeof(uint8));
  if(!mrph->framesCount)
  {
    context->warning(CStr(NModel::STR_WARNING_MORPH_NO_FRAMES, mesh->name.c_str()));
    return NModel::STATE_VALID;
  }
  f->read(&mrph->lodsCount, sizeof(uint8));
  /*if(mrph->lodsCount != mesh->standardMesh.lodsCount)
    context->warning(CStr(NModel::STR_WARNING_MORPH_LODS_COUNT_DIFF, mesh->name.c_str(), mrph->lodsCount, mesh->standardMesh.lodsCount));*/
  f->read(&mrph->undefined0, sizeof(uint8));

  for(uint8 i = 0; i < mrph->lodsCount; i++)
  {
    mrph->lods.push_back(SMorphLod());
    SMorphLod *lod = &mrph->lods.back();

    f->read(&lod->verticesCount, sizeof(uint16));
    if(!(mrph->framesCount * lod->verticesCount))
      context->warning(CStr(NModel::STR_WARNING_MORPH_NO_BONES, mesh->name.c_str(), i));
    else
    {
      lod->vertices.resize(mrph->framesCount * lod->verticesCount);

      for(auto vertex = lod->vertices.begin(); vertex != lod->vertices.end(); vertex++)
      {
        f->read(&vertex->position.x, sizeof(float));
        f->read(&vertex->position.y, sizeof(float));
        f->read(&vertex->position.z, sizeof(float));
        f->read(&vertex->normal.x, sizeof(float));
        f->read(&vertex->normal.y, sizeof(float));
        f->read(&vertex->normal.z, sizeof(float));
      }
      f->read(&lod->undefined0, sizeof(uint8));

      lod->links.resize(lod->verticesCount);
      f->read(&lod->links[0], sizeof(uint16) * lod->verticesCount);
    }
  }

  f->read(&mrph->boundingBox.minimum.x, sizeof(float));
  f->read(&mrph->boundingBox.minimum.y, sizeof(float));
  f->read(&mrph->boundingBox.minimum.z, sizeof(float));
  f->read(&mrph->boundingBox.maximum.x, sizeof(float));
  f->read(&mrph->boundingBox.maximum.y, sizeof(float));
  f->read(&mrph->boundingBox.maximum.z, sizeof(float));
  f->read(&mrph->undefined1, sizeof(float));
  f->read(&mrph->undefined2, sizeof(float));
  f->read(&mrph->undefined3, sizeof(float));
  f->read(&mrph->undefined4, sizeof(float));

  return NModel::STATE_VALID;
}
//------------------------------------------------------------------------------
NModel::EModelState CModel::loadBillboard(CFile *f, SMesh *mesh)
{
  SBillboard *bbrd = &mesh->billboard;

  f->read(&bbrd->rotation, sizeof(uint32));
  f->read(&bbrd->axis, sizeof(uint8));

  return NModel::STATE_VALID;
}
//------------------------------------------------------------------------------
NModel::EModelState CModel::loadGlow(CFile *f, SMesh *mesh)
{
  SGlow *glow = &mesh->glow;

  f->read(&glow->flaresCount, sizeof(uint8));
  if(!glow->flaresCount)
    context->warning(CStr(NModel::STR_WARNING_GLOW_NO_FLARES, mesh->name.c_str()));
  
  for(uint8 i = 0; i < glow->flaresCount; i++)
  {
    glow->flares.push_back(SGlowFlare());
    SGlowFlare *flare = &glow->flares.back();

    f->read(&flare->position, sizeof(float));
    f->read(&flare->materialIndex, sizeof(uint16));
    flare->material = getMaterial(flare->materialIndex);

    if(!flare->material)
      context->warning(CStr(NModel::STR_WARNING_GLOW_FLARE_NO_MAT, mesh->name.c_str()));
  }

  return NModel::STATE_VALID;
}
//------------------------------------------------------------------------------
NModel::EModelState CModel::loadMirror(CFile *f, SMesh *mesh)
{
  SMirror *mirror = &mesh->mirror;

  f->read(&mirror->boundingBox.minimum.x, sizeof(float));
  f->read(&mirror->boundingBox.minimum.y, sizeof(float));
  f->read(&mirror->boundingBox.minimum.z, sizeof(float));
  f->read(&mirror->boundingBox.maximum.x, sizeof(float));
  f->read(&mirror->boundingBox.maximum.y, sizeof(float));
  f->read(&mirror->boundingBox.maximum.z, sizeof(float));
  f->read(&mirror->undefined0, sizeof(float));
  f->read(&mirror->undefined1, sizeof(float));
  f->read(&mirror->undefined2, sizeof(float));
  f->read(&mirror->undefined3, sizeof(float));
  f->read(glm::value_ptr(mirror->transformation), sizeof(float) * NMath::MAT4);
  f->read(&mirror->color.x, sizeof(float));
  f->read(&mirror->color.y, sizeof(float));
  f->read(&mirror->color.z, sizeof(float));
  f->read(&mirror->drawDistance, sizeof(float));

  f->read(&mirror->verticesCount, sizeof(uint32));
  if(!mirror->verticesCount)
    context->warning(CStr(NModel::STR_WARNING_MIRROR_NO_VERTICES, mesh->name.c_str()));
  f->read(&mirror->facesCount, sizeof(uint32));
  if(!mirror->facesCount)
    context->warning(CStr(NModel::STR_WARNING_MIRROR_NO_FACES, mesh->name.c_str()));

  mirror->vertices.resize(mirror->verticesCount);
  for(auto vertex = mirror->vertices.begin(); vertex != mirror->vertices.end(); vertex++)
  {
    f->read(&vertex->position.x, sizeof(float));
    f->read(&vertex->position.y, sizeof(float));
    f->read(&vertex->position.z, sizeof(float));
  }

  mirror->faces.resize(mirror->facesCount);
  uint32 points = 0;
  uint32 lines = 0;
  for(auto face = mirror->faces.begin(); face != mirror->faces.end(); face++)
  {
    f->read(&face->vertex0, sizeof(uint16));
    f->read(&face->vertex1, sizeof(uint16));
    f->read(&face->vertex2, sizeof(uint16));

    if((face->vertex0 == face->vertex1) && (face->vertex0 == face->vertex2))
      points++;
    else if((face->vertex0 == face->vertex1) || (face->vertex0 == face->vertex2) || (face->vertex1 == face->vertex2))
      lines++;
  }

  if((points) || (lines))
    context->warning(CStr(NModel::STR_WARNING_MIRROR_DEGEN_FACES, mesh->name.c_str(), lines, points));

  return NModel::STATE_VALID;
}
//------------------------------------------------------------------------------
NModel::EModelState CModel::loadSector(CFile *f, SMesh *mesh)
{
  SSector *sect = &mesh->sector;

  f->read(&sect->undefined0, sizeof(uint32));
  f->read(&sect->undefined1, sizeof(uint32));

  f->read(&sect->verticesCount, sizeof(uint32));
  if(!sect->verticesCount)
    context->warning(CStr(NModel::STR_WARNING_SECTOR_NO_VERTICES, mesh->name.c_str()));

  f->read(&sect->facesCount, sizeof(uint32));
  if(!sect->facesCount)
    context->warning(CStr(NModel::STR_WARNING_SECTOR_NO_FACES, mesh->name.c_str()));

  sect->vertices.resize(sect->verticesCount);
  for(auto vertex = sect->vertices.begin(); vertex != sect->vertices.end(); vertex++)
  {
    f->read(&vertex->position.x, sizeof(float));
    f->read(&vertex->position.y, sizeof(float));
    f->read(&vertex->position.z, sizeof(float));
  }

  sect->faces.resize(sect->facesCount);
  uint32 points = 0;
  uint32 lines = 0;

  for(auto face = sect->faces.begin(); face != sect->faces.end(); face++)
  {
    f->read(&face->vertex0, sizeof(uint16));
    f->read(&face->vertex1, sizeof(uint16));
    f->read(&face->vertex2, sizeof(uint16));

    if((face->vertex0 == face->vertex1) && (face->vertex0 == face->vertex2))
      points++;
    else if((face->vertex0 == face->vertex1) || (face->vertex0 == face->vertex2) || (face->vertex1 == face->vertex2))
      lines++;
  }

  if((points) || (lines))
    context->warning(CStr(NModel::STR_WARNING_SECTOR_DEGEN_FACES, mesh->name.c_str(), lines, points));

  f->read(&sect->boundingBox.minimum.x, sizeof(float));
  f->read(&sect->boundingBox.minimum.y, sizeof(float));
  f->read(&sect->boundingBox.minimum.z, sizeof(float));
  f->read(&sect->boundingBox.maximum.x, sizeof(float));
  f->read(&sect->boundingBox.maximum.y, sizeof(float));
  f->read(&sect->boundingBox.maximum.z, sizeof(float));

  f->read(&sect->portalsCount, sizeof(uint8));
  
  for(uint8 i = 0; i < sect->portalsCount; i++)
  {
    sect->portals.push_back(SSectorPortal());
    SSectorPortal *portal = &sect->portals.back();

    f->read(&portal->verticesCount, sizeof(uint8));
    if(!portal->verticesCount)
      context->warning(CStr(NModel::STR_WARNING_SECTOR_PORTAL_NO_VERTICES, mesh->name.c_str(), i));

    f->read(&portal->undefined0, sizeof(uint32));
    f->read(&portal->undefined1, sizeof(float));
    f->read(&portal->undefined2, sizeof(float));
    f->read(&portal->undefined3, sizeof(float));
    f->read(&portal->undefined4, sizeof(float));
    f->read(&portal->undefined5, sizeof(float));
    f->read(&portal->undefined6, sizeof(float));

    portal->vertices.resize(portal->verticesCount);

    for(auto vertex = portal->vertices.begin(); vertex != portal->vertices.end(); vertex++)
    {
      f->read(&vertex->position.x, sizeof(float));
      f->read(&vertex->position.y, sizeof(float));
      f->read(&vertex->position.z, sizeof(float));
    }
  }

  return NModel::STATE_VALID;
}
//------------------------------------------------------------------------------
NModel::EModelState CModel::loadDummy(CFile *f, SMesh *mesh)
{
  SDummy *dummy = &mesh->dummy;

  f->read(&dummy->boundingBox.minimum.x, sizeof(float));
  f->read(&dummy->boundingBox.minimum.y, sizeof(float));
  f->read(&dummy->boundingBox.minimum.z, sizeof(float));
  f->read(&dummy->boundingBox.maximum.x, sizeof(float));
  f->read(&dummy->boundingBox.maximum.y, sizeof(float));
  f->read(&dummy->boundingBox.maximum.z, sizeof(float));

  return NModel::STATE_VALID;
}
//------------------------------------------------------------------------------
NModel::EModelState CModel::loadTarget(CFile *f, SMesh *mesh)
{
  STarget *trgt = &mesh->target;

  f->read(&trgt->undefined0, sizeof(uint16));

  f->read(&trgt->targetsCount, sizeof(uint8));
  if(!trgt->targetsCount)
    context->warning(CStr(NModel::STR_WARNING_TARGET_NO_TARGETS, mesh->name.c_str()));

  for(uint8 i = 0; i < trgt->targetsCount; i++)
  {
    trgt->targets.push_back(0);
    uint16 *t = &trgt->targets.back();

    f->read(&t, sizeof(uint16));
  }

  return NModel::STATE_VALID;
}
//------------------------------------------------------------------------------
NModel::EModelState CModel::loadBone(CFile *f, SMesh *mesh)
{
  SBone *bone = &mesh->bone;

  f->read(glm::value_ptr(bone->transformation), sizeof(float) * NMath::MAT4);
  f->read(&bone->bone, sizeof(uint32));

  return NModel::STATE_VALID;
}
//------------------------------------------------------------------------------
void CModel::getTransformedVertices(const SMesh *mesh, uint32 lod, const glm::mat4 &transformation, std::vector<glm::vec3> *vertices)
{
  if(!vertices)
    return;

  if((mesh->type == NModel::MESH_TYPE_STANDARD) &&
    ((mesh->visualType == NModel::MESH_VISUAL_TYPE_STANDARD) ||
     (mesh->visualType == NModel::MESH_VISUAL_TYPE_SINGLE_MESH) ||
     (mesh->visualType == NModel::MESH_VISUAL_TYPE_SINGLE_MORPH) ||
     (mesh->visualType == NModel::MESH_VISUAL_TYPE_BILLBOARD) ||
     (mesh->visualType == NModel::MESH_VISUAL_TYPE_MORPH)))
  {
    if(lod >= mesh->standardMesh.lods.size())
      return;

    auto l = mesh->standardMesh.lods.cbegin();
    std::advance(l, lod);

    vertices->resize(l->vertices.size());
    for(uint32 i = 0; i < l->vertices.size(); i++)
      (*vertices)[i] = glm::vec3(transformation * glm::vec4(l->vertices[i].position, 1.0f));
  }
}
//------------------------------------------------------------------------------
void CModel::update(NModel::EMeshUpdateType type)
{
  if(type & NModel::UPDATE_TRANSFORMATION)
  {
    std::vector<SMesh *> meshes(model.meshes.size(), NULL);
    for(auto it = model.meshes.begin(); it != model.meshes.end(); it++)
      meshes[it->second.index - 1] = &it->second;

    for(uint32 i = 0; i < meshes.size(); i++)
    {
      meshes[i]->transformation = SMatrix::composeTransformation(meshes[i]->position, meshes[i]->rotation, meshes[i]->scale);
      if(meshes[i]->link)
        meshes[i]->transformation = meshes[i]->link->transformation * meshes[i]->transformation;
    }
  }
  if(type & NModel::UPDATE_TANGENT_BASE)
  {
    for(auto it = model.meshes.begin(); it != model.meshes.end(); it++)
    {
      SMesh *mesh = &it->second;

      if(mesh->type == NModel::MESH_TYPE_STANDARD)
      {
        if((mesh->visualType == NModel::MESH_VISUAL_TYPE_STANDARD) ||
           (mesh->visualType == NModel::MESH_VISUAL_TYPE_SINGLE_MESH) ||
           (mesh->visualType == NModel::MESH_VISUAL_TYPE_SINGLE_MORPH) ||
           (mesh->visualType == NModel::MESH_VISUAL_TYPE_BILLBOARD) ||
           (mesh->visualType == NModel::MESH_VISUAL_TYPE_MORPH))
        {
          for(auto lod = mesh->standardMesh.lods.begin(); lod != mesh->standardMesh.lods.end(); lod++)
          {
            std::vector<bool> mappedVertices(lod->vertices.size(), false);

            for(auto group = lod->faceGroups.begin(); group != lod->faceGroups.end(); group++)
            {
              for(auto face = group->faces.begin(); face != group->faces.end(); face++)
              {
                const uint16 v[] = { face->vertex0, face->vertex1, face->vertex2, face->vertex0, face->vertex1 };
                for(uint8 i = 0; i < NModel::FACE_SIZE; i++)
                {
                  if(!mappedVertices[v[i]])
                  {
                    SVertex *v0 = &lod->vertices[v[i]];
                    const SVertex *v1 = &lod->vertices[v[i + 1]];
                    const SVertex *v2 = &lod->vertices[v[i + 2]];

                    const glm::vec3 dv1 = v1->position - v0->position;
                    const glm::vec3 dv2 = v2->position - v0->position;
                    const glm::vec2 dtex1 = v1->texCoord - v0->texCoord;
                    const glm::vec2 dtex2 = v2->texCoord - v0->texCoord;

                    const float recip = 1.0f / (dtex1.x * dtex2.y - dtex1.y * dtex2.x);
                    v0->normalTangent = (dv1 * dtex2.y - dv2 * dtex1.y) * recip;
                    v0->normalBitangent = (dv2 * dtex1.x - dv1 * dtex2.x) * recip;

                    mappedVertices[v[i]] = true;
                  }
                }
              }
            }

            // orthogonalization
            for(auto vx = lod->vertices.begin(); vx != lod->vertices.end(); vx++)
              vx->normalTangent = glm::normalize(glm::vec3(vx->normalTangent - vx->normal * glm::dot(vx->normal, vx->normalTangent)));

            // smooth not linked vertices
            /*std::vector<bool> smoothedVertices(lod->vertices.size(), false);

            for(uint32 vx = 0; vx < lod->vertices.size(); vx++)
            {
              if(!smoothedVertices[vx])
              {
                smoothedVertices[vx] = true;
                std::vector<SVertex *>sameVx;
                sameVx.push_back(&lod->vertices[vx]);
                glm::vec3 t = lod->vertices[vx].normalTangent;
                glm::vec3 b = lod->vertices[vx].normalBitangent;

                for(uint32 vy = 0; vy < lod->vertices.size(); vy++)
                {
                  if((vx != vy) &&
                     (lod->vertices[vx].position == lod->vertices[vy].position) &&
                     (lod->vertices[vx].normal == lod->vertices[vy].normal) &&
                     (lod->vertices[vx].texCoord == lod->vertices[vy].texCoord))
                  {
                    smoothedVertices[vy] = true;
                    sameVx.push_back(&lod->vertices[vy]);
                    t += lod->vertices[vy].normalTangent;
                    b += lod->vertices[vy].normalBitangent;
                  }
                }

                t = glm::normalize(t);
                b = glm::normalize(b);
                for(uint32 vy = 0; vy < sameVx.size(); vy++)
                {
                  sameVx[vy]->normalTangent = t;
                  sameVx[vy]->normalBitangent = b;
                }
              }
            }*/
          }
        }
      }
    }
  }
  if(type & NModel::UPDATE_GEOMETRY)
  {
    COpenGL *gl = context->getOpenGL();

    for(auto it = model.meshes.begin(); it != model.meshes.end(); it++)
    {
      SMesh *mesh = &it->second;

      if(mesh->type == NModel::MESH_TYPE_STANDARD)
      {
        if((mesh->visualType == NModel::MESH_VISUAL_TYPE_STANDARD) ||
           (mesh->visualType == NModel::MESH_VISUAL_TYPE_SINGLE_MESH) ||
           (mesh->visualType == NModel::MESH_VISUAL_TYPE_SINGLE_MORPH) ||
           (mesh->visualType == NModel::MESH_VISUAL_TYPE_BILLBOARD) ||
           (mesh->visualType == NModel::MESH_VISUAL_TYPE_MORPH))
        {
          for(auto lod = mesh->standardMesh.lods.begin(); lod != mesh->standardMesh.lods.end(); lod++)
          {
            std::vector<float> vx(lod->vertices.size() * NModel::VERTEX_PNTBTC_SIZE);
            std::vector<float> vxs(lod->vertices.size() * NModel::VERTEX_PT_SIZE); // simple
            std::vector<uint16> in;

            uint32 i = 0;
            uint32 is = 0;
            for(auto vertex = lod->vertices.begin(); vertex != lod->vertices.end(); vertex++)
            {
              vx[i++] = vertex->position.x;
              vx[i++] = vertex->position.y;
              vx[i++] = vertex->position.z;
              vx[i++] = vertex->normal.x;
              vx[i++] = vertex->normal.y;
              vx[i++] = vertex->normal.z;
              vx[i++] = vertex->normalTangent.x;
              vx[i++] = vertex->normalTangent.y;
              vx[i++] = vertex->normalTangent.z;
              vx[i++] = vertex->normalBitangent.x;
              vx[i++] = vertex->normalBitangent.y;
              vx[i++] = vertex->normalBitangent.z;
              vx[i++] = vertex->texCoord.x;
              vx[i++] = vertex->texCoord.y;
              vx[i++] = vertex->color.x;
              vx[i++] = vertex->color.y;
              vx[i++] = vertex->color.z;
              vx[i++] = vertex->color.w;

              vxs[is++] = vertex->position.x;
              vxs[is++] = vertex->position.y;
              vxs[is++] = vertex->position.z;
              vxs[is++] = vertex->texCoord.x;
              vxs[is++] = vertex->texCoord.y;
            }

            i = 0;
            for(auto group = lod->faceGroups.begin(); group != lod->faceGroups.end(); group++)
            {
              in.resize(in.size() + group->faces.size() * NModel::FACE_SIZE);

              for(auto face = group->faces.begin(); face != group->faces.end(); face++)
              {
                in[i++] = face->vertex0;
                in[i++] = face->vertex1;
                in[i++] = face->vertex2;
              }
            }

            if(lod->vboVertices)
              gl->deleteBuffers(1, &lod->vboVertices);
            if(lod->vboIndices)
              gl->deleteBuffers(1, &lod->vboIndices);

            gl->genBuffers(1, &lod->vboVertices);
            gl->genBuffers(1, &lod->vboSimpleVertices);
            gl->genBuffers(1, &lod->vboIndices);

            gl->bindBuffer(NOpenGL::ARRAY_BUFFER, lod->vboVertices);
            gl->bufferData(NOpenGL::ARRAY_BUFFER, vx.size() * sizeof(float), &vx[0], NOpenGL::STATIC_DRAW);
            gl->bindBuffer(NOpenGL::ARRAY_BUFFER, 0);

            gl->bindBuffer(NOpenGL::ARRAY_BUFFER, lod->vboSimpleVertices);
            gl->bufferData(NOpenGL::ARRAY_BUFFER, vxs.size() * sizeof(float), &vxs[0], NOpenGL::STATIC_DRAW);
            gl->bindBuffer(NOpenGL::ARRAY_BUFFER, 0);

            gl->bindBuffer(NOpenGL::ELEMENT_ARRAY_BUFFER, lod->vboIndices);
            gl->bufferData(NOpenGL::ELEMENT_ARRAY_BUFFER, in.size() * sizeof(uint16), &in[0], NOpenGL::STATIC_DRAW);
            gl->bindBuffer(NOpenGL::ELEMENT_ARRAY_BUFFER, 0);
          }
        }
      }
    }
  }
}
//------------------------------------------------------------------------------
void CModel::updateSceneObject(SSceneObject *sceneObject, SSceneModel *sceneModel) const
{
  sceneModel->meshes.clear();
  std::vector<SBoundingBox> aabbs;

  uint32 mi = 1;
  for(auto m = model.meshes.cbegin(); m != model.meshes.cend(); m++, mi++)
  {
    const SMesh *mesh = &m->second;
    sceneModel->meshes.push_back(std::list<SShaderState>());
    std::list<SShaderState> *sceneMesh = &sceneModel->meshes.back();
    std::vector<SBoundingBox> aabbs2(mesh->standardMesh.lods.size());

    uint32 lod = 0;
    for(auto l = mesh->standardMesh.lods.cbegin(); l != mesh->standardMesh.lods.cend(); l++, lod++)
    {
      sceneMesh->push_back(SShaderState());
      SShaderState *sceneLod = &sceneMesh->back();

      sceneLod->mw = sceneObject->mw * mesh->transformation;
      sceneLod->mwnit = glm::mat3(glm::transpose(glm::inverse(sceneLod->mw)));

      std::vector<glm::vec3> vx;
      getTransformedVertices(mesh, lod, sceneLod->mw, &vx);
      sceneLod->aabb = SBoundingBox(vx);
      aabbs.push_back(sceneLod->aabb);
    }
  }

  sceneModel->aabb = SBoundingBox(aabbs);
}
//------------------------------------------------------------------------------
void CModel::render(const SSceneObject *sceneObject, const SSceneModel *sceneModel) const
{
  if((!sceneObject) || (!sceneModel) || (sceneModel->meshes.size() != model.meshes.size()) || (!context->getCulling()->isAABBInFrustum(sceneModel->aabb)))
    return;

  const SEngine *e = context->engineGetEngine();
  const SCamera *c = context->getCamera()->getCamera();

  NRenderer::EMode mode = context->getRenderer()->getRenderer()->mode;
  bool mergedMeshes = ((mode == NRenderer::MODE_PICK) || (mode == NRenderer::MODE_DEPTH)) ? true : false;
  auto soMesh = sceneModel->meshes.cbegin();

  for(auto it = model.meshes.cbegin(); it != model.meshes.cend(); it++, soMesh++)
  {
    if(!soMesh->size())
      continue;

    const SMesh *mesh = &it->second;
    const SShaderState *soLod = &soMesh->front(); // todo: lod selection

    if(!context->getCulling()->isAABBInFrustum(soLod->aabb))
      continue;

    soLod->mvp = c->viewProjection * soLod->mw;
    if(mode == NRenderer::MODE_DEPTH)
    {
      for(uint32 i = 0; i < NEngine::SHADOW_CASCADES_COUNT; i++)
      {
        const glm::mat4 shadowMvp(e->shadowViewProj[i] * soLod->mw);
        const glm::mat4 shadowMvpBias(glm::mat4(0.5f, 0.0f, 0.0f, 0.0f,   0.0f, 0.5f, 0.0f, 0.0f,   0.0f, 0.0f, 0.5f, 0.0f,   0.5f, 0.5f, 0.5f, 1.0f) * shadowMvp);
        memcpy(&soLod->mvps[NMath::MAT4 * i], glm::value_ptr(shadowMvp), sizeof(float) * NMath::MAT4);
        memcpy(&soLod->mvpsb[NMath::MAT4 * i], glm::value_ptr(shadowMvpBias), sizeof(float) * NMath::MAT4);
      }
    }
    else if(mode == NRenderer::MODE_GEOMETRY)
    {
      for(uint32 i = 0; i < (NEngine::LPV_CASCADES_COUNT * NEngine::LPV_SUN_SKY_DIRS_COUNT); i++)
      {
        const glm::mat4 geometryMvp(e->geometryViewProj[i] * soLod->mw);
        memcpy(&soLod->mvpg[NMath::MAT4 * i], glm::value_ptr(geometryMvp), sizeof(float) * NMath::MAT4);
      }
    }
    soLod->cam = glm::vec3(c->position);

    if(mesh->type == NModel::MESH_TYPE_STANDARD)
    {
      if((mesh->visualType == NModel::MESH_VISUAL_TYPE_STANDARD) ||
         (mesh->visualType == NModel::MESH_VISUAL_TYPE_SINGLE_MESH) ||
         (mesh->visualType == NModel::MESH_VISUAL_TYPE_SINGLE_MORPH) ||
         (mesh->visualType == NModel::MESH_VISUAL_TYPE_BILLBOARD) ||
         (mesh->visualType == NModel::MESH_VISUAL_TYPE_MORPH))
      {
        if(const SStandardMeshLod *lod = getLod(mesh, soLod->cam))
        {
          uint32 faceStart = 0;
          auto last = lod->faceGroups.cend();
          last--;

          for(auto faceGroup = lod->faceGroups.cbegin(); faceGroup != lod->faceGroups.cend(); faceStart += faceGroup->faces.size(), faceGroup++)
          {
            if((!mergedMeshes) || (faceGroup == last))
            {
              context->getRenderer()->addMesh(SRenderMesh(
                (mergedMeshes) ? lod->vboSimpleVertices : lod->vboVertices, lod->vboIndices,
                (mergedMeshes) ? 0 : faceStart,
                ((mergedMeshes) ? faceStart : 0) + faceGroup->faces.size(),
                &(*soLod),
                (mergedMeshes) ? NULL : faceGroup->material));
            }
          }
        }
      }
    }
  }
}
//------------------------------------------------------------------------------
const SStandardMeshLod *CModel::getLod(const SMesh *mesh, const glm::vec3 cam)
{
  if(mesh->type == NModel::MESH_TYPE_STANDARD)
  {
    if((mesh->visualType == NModel::MESH_VISUAL_TYPE_STANDARD) ||
       (mesh->visualType == NModel::MESH_VISUAL_TYPE_SINGLE_MESH) ||
       (mesh->visualType == NModel::MESH_VISUAL_TYPE_SINGLE_MORPH) ||
       (mesh->visualType == NModel::MESH_VISUAL_TYPE_BILLBOARD) ||
       (mesh->visualType == NModel::MESH_VISUAL_TYPE_MORPH))
    { // todo - calc distance
      UNUSED(cam);

      if(mesh->standardMesh.lods.size())
        return &mesh->standardMesh.lods.front();
    }
  }

  return NULL;
}
//------------------------------------------------------------------------------
CModels::CModels() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CModels::CModels(CContext *context) : CEngineBase(context)
{
}
//------------------------------------------------------------------------------
CModels::~CModels()
{
}
//------------------------------------------------------------------------------
