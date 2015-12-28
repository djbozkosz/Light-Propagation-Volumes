//------------------------------------------------------------------------------
#ifndef RENDERERTYPES_H
#define RENDERERTYPES_H

#include "shaderTypes.h"

//------------------------------------------------------------------------------
namespace NRenderer
{
  enum EMode
  {
    MODE_STANDARD = 0,
    MODE_BACKDROP,
    MODE_PICK,
    MODE_DEPTH,
    MODE_GEOMETRY
  };
}
//------------------------------------------------------------------------------
struct SRenderMesh
{
  GLuint vboVertices;
  GLuint vboIndices;
  uint32 faceStart;
  uint32 facesCount;
  const SShaderTechnique *technique;
  const SMaterial *material;

  inline SRenderMesh() : vboVertices(0), vboIndices(0), faceStart(0), facesCount(0), technique(NULL), material(NULL) {}
  inline SRenderMesh(GLuint vboVertices, GLuint vboIndices, uint32 faceStart, uint32 facesCount, const SShaderTechnique *technique, const SMaterial *material = NULL) : vboVertices(vboVertices), vboIndices(vboIndices), faceStart(faceStart), facesCount(facesCount), technique(technique), material(material) {}
};
//------------------------------------------------------------------------------
struct SRenderer
{
  NRenderer::EMode mode;

  inline SRenderer() : mode(NRenderer::MODE_STANDARD) {}
};
//------------------------------------------------------------------------------
#endif // RENDERERTYPES_H
