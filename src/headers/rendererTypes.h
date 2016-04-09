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
    MODE_DEPTH_CASCADE,
    MODE_GEOMETRY,
    MODE_GEOMETRY_CASCADE,
    MODE_LPV_CLEAR_GEOMETRY,
    MODE_LPV_INJECTION_GEOMETRY,
    MODE_LPV_PROPAGATION_GATHERING_GEOMETRY,
    MODE_LPV_PROPAGATION_SCATTERING_GEOMETRY,
    MODE_LPV_CLEAR_COMPUTE,
    MODE_LPV_INJECTION_COMPUTE,
    MODE_LPV_PROPAGATION_GATHERING_COMPUTE,
    MODE_LPV_PROPAGATION_SCATTERING_COMPUTE
  };
}
//------------------------------------------------------------------------------
struct SRenderMesh
{
  GLuint vboVertices;
  GLuint vboIndices;
  GLuint instances;
  uint32 faceStart;
  uint32 facesCount;
  const SShaderState *technique;
  const SMaterial *material;

  inline SRenderMesh() : vboVertices(0), vboIndices(0), instances(0), faceStart(0), facesCount(0), technique(NULL), material(NULL) {}
  inline SRenderMesh(GLuint vboVertices, GLuint vboIndices, GLuint instances, uint32 faceStart, uint32 facesCount, const SShaderState *technique, const SMaterial *material = NULL) : vboVertices(vboVertices), vboIndices(vboIndices), instances(instances), faceStart(faceStart), facesCount(facesCount), technique(technique), material(material) {}
};
//------------------------------------------------------------------------------
struct SRenderer
{
  NRenderer::EMode mode;

  inline SRenderer() : mode(NRenderer::MODE_STANDARD) {}
};
//------------------------------------------------------------------------------
#endif // RENDERERTYPES_H
