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
  else if(renderer.mode == NRenderer::MODE_GEOMETRY)
    meshes[NShader::PROGRAM_GEOMETRY].push_back(mesh);
  else if((mesh.material) && (mesh.material->program))
  {
    NShader::EProgram p = mesh.material->program->getProgram()->name;

    if(renderer.mode == NRenderer::MODE_BACKDROP)
    {
      if((p >= NShader::PROGRAM_PER_FRAGMENT_ALPHA) && (p <= NShader::PROGRAM_PER_FRAGMENT_NORMAL_SHADOW_JITTER))
        meshes[NShader::PROGRAM_BASIC_ALPHA].push_back(mesh);
      else
        meshes[NShader::PROGRAM_BASIC].push_back(mesh);
    }
    else
      meshes[mesh.material->program->getProgram()->name + ((context->engineGetEngine()->shadowJittering > 0.0f) ? 1 : 0)].push_back(mesh);
  }
}
//------------------------------------------------------------------------------
void CRenderer::dispatch() const
{
  COpenGL *gl = context->getOpenGL();

  if(renderer.mode == NRenderer::MODE_BACKDROP)
    gl->depthMask(NOpenGL::FALSE);

  for(uint32 i = 0; i < NShader::PROGRAMS_COUNT; i++)
  {
    const NShader::EProgram p = static_cast<NShader::EProgram>(i);

    if((p == NShader::PROGRAM_COLOR) || (p == NShader::PROGRAM_DEPTH))
    {
      gl->disable(NOpenGL::CULL_FACE);
      gl->enable(NOpenGL::POLYGON_OFFSET_FILL);
      gl->polygonOffset(context->engineGetEngine()->shadowJittering * 0.5f + 1.5f, 1.0f);
    }
    else if(p == NShader::PROGRAM_GEOMETRY)
      gl->disable(NOpenGL::CULL_FACE);
    /*if(p == NShader::PROGRAM_GUI_TEXT)
      gl->depthMask(NOpenGL::FALSE);*/

    const CShaderProgram *prog = context->getShaders()->getProgram(static_cast<NShader::EProgram>(i));

    /*if((context->getCamera()->getCamera()->renderMode == NCamera::RENDER_MODE_REFLECTION) && ((prog->getProgram()->name == NShader::PROGRAM_WATER) || (prog->getProgram()->name == NShader::PROGRAM_UNDER_WATER)))
    continue;*/

    prog->bind();

    for(auto mesh = meshes[i].cbegin(); mesh != meshes[i].cend(); mesh++)
    {
      //const SRenderMesh *mesh;
      if(!mesh->technique)
        continue;

      gl->bindBuffer(NOpenGL::ARRAY_BUFFER, mesh->vboVertices);
      gl->bindBuffer(NOpenGL::ELEMENT_ARRAY_BUFFER, mesh->vboIndices);

      mesh->technique->material = mesh->material;

      if((p != NShader::PROGRAM_COLOR) && (p != NShader::PROGRAM_DEPTH) && (mesh->material->type & NModel::MATERIAL_TWO_SIDED))
        gl->disable(NOpenGL::CULL_FACE);
      else if(p == NShader::PROGRAM_GEOMETRY)
        gl->disable(NOpenGL::CULL_FACE);

      prog->begin(mesh->technique, renderer.mode);
      gl->drawElements(NOpenGL::TRIANGLES, mesh->facesCount * NModel::FACE_SIZE, NOpenGL::UNSIGNED_SHORT, reinterpret_cast<uint16 *>(sizeof(uint16) * mesh->faceStart * NModel::FACE_SIZE));
      prog->end(mesh->technique);

      context->engineIncDrawCalls();

      if((p != NShader::PROGRAM_COLOR) && (p != NShader::PROGRAM_DEPTH) && (mesh->material->type & NModel::MATERIAL_TWO_SIDED))
        gl->enable(NOpenGL::CULL_FACE);
      else if(p == NShader::PROGRAM_GEOMETRY)
        gl->enable(NOpenGL::CULL_FACE);

      gl->bindBuffer(NOpenGL::ARRAY_BUFFER, 0);
      gl->bindBuffer(NOpenGL::ELEMENT_ARRAY_BUFFER, 0);
    }

    if((p == NShader::PROGRAM_COLOR) || (p == NShader::PROGRAM_DEPTH))
    {
      gl->polygonOffset(0.0f, 0.0f);
      gl->disable(NOpenGL::POLYGON_OFFSET_FILL);
      gl->enable(NOpenGL::CULL_FACE);
    }
    else if(p == NShader::PROGRAM_GEOMETRY)
      gl->enable(NOpenGL::CULL_FACE);
    /*if(p == NShader::PROGRAM_GUI_TEXT)
      gl->depthMask(NOpenGL::TRUE);*/
  }

  if(renderer.mode == NRenderer::MODE_BACKDROP)
    gl->depthMask(NOpenGL::TRUE);
}
//------------------------------------------------------------------------------
void CRenderer::clearGroups()
{
  for(auto group = meshes.begin(); group != meshes.end(); group++)
    group->clear();
}
//------------------------------------------------------------------------------
