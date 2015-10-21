//------------------------------------------------------------------------------
#include "models.h"

//------------------------------------------------------------------------------
CModel::CModel() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CModel::CModel(CContext *context, const SModel &model) : CEngineBase(context), model(model)
{
  for(auto mesh = this->model.meshes.begin(); mesh != this->model.meshes.end(); mesh++)
    context->getModels()->createVbo(&(*mesh));
}
//------------------------------------------------------------------------------
CModel::~CModel()
{
}
//------------------------------------------------------------------------------
void CModel::update(SSceneObject *sceneObject, SSceneModel *sceneModel) const
{
  bool soMeshesChanged = false;

  sceneObject->mw = SMatrix::composeTransformation(sceneObject->position, sceneObject->rotation, sceneObject->scale);

  if(sceneModel->meshes.size() != model.meshes.size())
  {
    sceneModel->meshes.clear();
    soMeshesChanged = true;
  }

  auto sceneMesh = sceneModel->meshes.begin();
  for(auto mesh = model.meshes.begin(); mesh != model.meshes.end(); mesh++, sceneMesh++)
  {
    SShaderTechnique *t;

    if(soMeshesChanged)
      sceneModel->meshes.push_back(SShaderTechnique());
    t = &(*sceneMesh);
    t->mw = sceneObject->mw * mesh->transformation;
    t->mwnit = glm::mat3(glm::transpose(glm::inverse(t->mw)));
  }
}
//------------------------------------------------------------------------------
void CModel::render(const SSceneObject *sceneObject, const SSceneModel *sceneModel) const
{
  if((!sceneObject) || (!sceneModel) || (sceneModel->meshes.size() != model.meshes.size()))
    return;

  NRenderer::EMode mode = context->getRenderer()->getRenderer()->mode;
  bool mergedMeshes = ((mode == NRenderer::MODE_PICK) || (mode == NRenderer::MODE_DEPTH)) ? true : false;
  auto soMesh = sceneModel->meshes.cbegin();

  for(auto mesh = model.meshes.cbegin(); mesh != model.meshes.cend(); mesh++, soMesh++)
  {
    const SCamera *c = context->getCamera()->getCamera();
    soMesh->mvp = c->viewProjection * soMesh->mw;
    soMesh->cam = glm::vec3(c->position) * glm::vec3(-1.0, 1.0, -1.0);
    uint32 faceStart = 0;

    for(uint32 j = 0; j < mesh->faces.size(); j++)
    {
      uint32 facesCount = mesh->faces[j].faces.size();

      context->getRenderer()->addMesh(SRenderMesh(
        mesh->vboVertices, mesh->vboIndices,
        (mergedMeshes) ? 0 : faceStart,
        ((mergedMeshes) ? faceStart : 0) + facesCount,
        &(*soMesh),
        (mergedMeshes) ? NULL : mesh->faces[j].material));

      faceStart += facesCount;
    }
  }
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
void CModels::createVbo(SMesh *mesh)
{
  //COpenGL *gl = context->getOpenGL();
  std::vector<float> vx(mesh->vertices.size() * NModel::VERTEX_PNTBTC_SIZE);
  std::vector<uint16> in;

  uint32 i = 0;
  for(auto v = mesh->vertices.begin(); v != mesh->vertices.end(); v++)
  {
    vx[i++] = v->position.x;
    vx[i++] = v->position.y;
    vx[i++] = v->position.z;
    vx[i++] = v->normal.x;
    vx[i++] = v->normal.y;
    vx[i++] = v->normal.z;
    vx[i++] = v->normalTangent.x;
    vx[i++] = v->normalTangent.y;
    vx[i++] = v->normalTangent.z;
    vx[i++] = v->normalBitangent.x;
    vx[i++] = v->normalBitangent.y;
    vx[i++] = v->normalBitangent.z;
    vx[i++] = v->texCoord.x;
    vx[i++] = v->texCoord.y;
    vx[i++] = v->color.x;
    vx[i++] = v->color.y;
    vx[i++] = v->color.z;
    vx[i++] = v->color.w;
  }

  i = 0;
  for(auto faces = mesh->faces.begin(); faces != mesh->faces.end(); faces++)
  {
    in.resize(in.size() + faces->faces.size() * NModel::FACE_SIZE);

    for(auto f = faces->faces.begin(); f != faces->faces.end(); f++)
    {
      in[i++] = f->vertex0;
      in[i++] = f->vertex1;
      in[i++] = f->vertex2;
    }
  }

  if(mesh->vboVertices)
    glDeleteBuffers(1, &mesh->vboVertices);
  if(mesh->vboIndices)
    glDeleteBuffers(1, &mesh->vboIndices);

  glGenBuffers(1, &mesh->vboVertices);
  glGenBuffers(1, &mesh->vboIndices);

  glBindBuffer(GL_ARRAY_BUFFER, mesh->vboVertices);
  glBufferData(GL_ARRAY_BUFFER, vx.size() * sizeof(float), &vx[0], GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->vboIndices);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, in.size() * sizeof(uint16), &in[0], GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
//------------------------------------------------------------------------------
