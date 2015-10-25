//------------------------------------------------------------------------------
#include "renderer.h"

//------------------------------------------------------------------------------
CRenderer::CRenderer() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CRenderer::CRenderer(CContext *context) : CEngineBase(context)
{
  meshes.resize(NShader::SHADERS_COUNT);
}
//------------------------------------------------------------------------------
CRenderer::~CRenderer()
{
}
//------------------------------------------------------------------------------
void CRenderer::addMesh(const SRenderMesh &mesh)
{
  /*if(renderer.mode == NRenderer::MODE_PICK)
    meshes[NShader::PROGRAM_COLOR].push_back(mesh);
  else if(renderer.mode == NRenderer::MODE_DEPTH)
    meshes[NShader::PROGRAM_DEPTH].push_back(mesh);
  else if((mesh.material) && (mesh.material->program))
    meshes[mesh.material->program->getShaderProgram()->name].push_back(mesh);*/
}
//------------------------------------------------------------------------------
void CRenderer::dispatch() const
{
  //COpenGL *gl = context->getOpenGL();

  if(renderer.mode == NRenderer::MODE_BACKDROP)
    glDisable(GL_DEPTH_TEST);

  for(uint32 i = 0; i < NShader::SHADERS_COUNT; i++)
  {
    //const NShader::EProgram p = static_cast<NShader::EProgram>(i);

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

      prog->begin(mesh->technique);
      glDrawElements(GL_TRIANGLES, mesh->facesCount * NModel::FACE_SIZE, GL_UNSIGNED_SHORT, reinterpret_cast<uint16 *>(sizeof(uint16) * mesh->faceStart * NModel::FACE_SIZE));
      prog->end(mesh->technique);

      context->engineIncDrawCalls();

      glBindBuffer(GL_ARRAY_BUFFER, 0);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    //prog->forceEnd();

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
