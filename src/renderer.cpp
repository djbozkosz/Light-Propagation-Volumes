//------------------------------------------------------------------------------
#include "renderer.h"

//------------------------------------------------------------------------------
CRenderer::CRenderer() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CRenderer::CRenderer(CContext *context) : CEngineBase(context)
{
  meshes.resize(NShader::PROGRAMS_COUNT);
}
//------------------------------------------------------------------------------
CRenderer::~CRenderer()
{
}
//------------------------------------------------------------------------------
void CRenderer::addMesh(const SRenderMesh &mesh)
{
  if(renderer.mode == NRenderer::MODE_PICK)
    meshes[NShader::PROGRAM_COLOR].push_back(mesh);
  else if(renderer.mode == NRenderer::MODE_DEPTH)
    meshes[NShader::PROGRAM_DEPTH].push_back(mesh);
  else if((mesh.material) && (mesh.material->program))
  {
    NShader::EProgram p = mesh.material->program->getShaderProgram()->name;

    if(renderer.mode == NRenderer::MODE_BACKDROP)
    {
      if((p >= NShader::PROGRAM_PER_FRAGMENT_ALPHA) && (p <= NShader::PROGRAM_PER_FRAGMENT_NORMAL_SHADOW_JITTER))
        meshes[NShader::PROGRAM_BASIC_ALPHA].push_back(mesh);
      else
        meshes[NShader::PROGRAM_BASIC].push_back(mesh);
    }
    else
      meshes[mesh.material->program->getShaderProgram()->name + ((context->engineGetEngine()->shadowJittering > 0.0f) ? 1 : 0)].push_back(mesh);
  }
}
//------------------------------------------------------------------------------
void CRenderer::dispatch() const
{
  //COpenGL *gl = context->getOpenGL();

  if(renderer.mode == NRenderer::MODE_BACKDROP)
    glDisable(GL_DEPTH_TEST);

  for(uint32 i = 0; i < NShader::PROGRAMS_COUNT; i++)
  {
    const NShader::EProgram p = static_cast<NShader::EProgram>(i);

    if((p == NShader::PROGRAM_COLOR) || (p == NShader::PROGRAM_DEPTH))
    {
      glDisable(GL_CULL_FACE);
      glEnable(GL_POLYGON_OFFSET_FILL);
      glPolygonOffset(context->engineGetEngine()->shadowJittering * 0.5f + 1.5f, 1.0f);
    }
    /*if(p == NShader::PROGRAM_GUI_TEXT)
      glDisable(GL_DEPTH_TEST);*/

    const CShaderProgram *prog = context->getShaders()->getShaderProgram(static_cast<NShader::EProgram>(i));

    /*if((context->getCamera()->getCamera()->renderMode == NCamera::RENDER_MODE_REFLECTION) && ((prog->getShaderProgram()->name == NShader::PROGRAM_WATER) || (prog->getShaderProgram()->name == NShader::PROGRAM_UNDER_WATER)))
    continue;*/

    prog->bind();

    for(auto mesh = meshes[i].cbegin(); mesh != meshes[i].cend(); mesh++)
    {
      //const SRenderMesh *mesh;
      if(!mesh->technique)
        continue;

      glBindBuffer(GL_ARRAY_BUFFER, mesh->vboVertices);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->vboIndices);

      mesh->technique->material = mesh->material;

      if((p != NShader::PROGRAM_COLOR) && (p != NShader::PROGRAM_DEPTH) && (mesh->material->type & NModel::MATERIAL_TWO_SIDED))
        glDisable(GL_CULL_FACE);

      prog->begin(mesh->technique, renderer.mode);
      glDrawElements(GL_TRIANGLES, mesh->facesCount * NModel::FACE_SIZE, GL_UNSIGNED_SHORT, reinterpret_cast<uint16 *>(sizeof(uint16) * mesh->faceStart * NModel::FACE_SIZE));
      prog->end(mesh->technique);

      context->engineIncDrawCalls();

      if((p != NShader::PROGRAM_COLOR) && (p != NShader::PROGRAM_DEPTH) && (mesh->material->type & NModel::MATERIAL_TWO_SIDED))
        glEnable(GL_CULL_FACE);

      glBindBuffer(GL_ARRAY_BUFFER, 0);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    if((p == NShader::PROGRAM_COLOR) || (p == NShader::PROGRAM_DEPTH))
    {
      glPolygonOffset(0.0f, 0.0f);
      glDisable(GL_POLYGON_OFFSET_FILL);
      glEnable(GL_CULL_FACE);
    }
    /*if(p == NShader::PROGRAM_GUI_TEXT)
      glEnable(GL_DEPTH_TEST);*/
  }

  if(renderer.mode == NRenderer::MODE_BACKDROP)
    glEnable(GL_DEPTH_TEST);
}
//------------------------------------------------------------------------------
void CRenderer::clearGroups()
{
  for(auto group = meshes.begin(); group != meshes.end(); group++)
    group->clear();
}
//------------------------------------------------------------------------------
