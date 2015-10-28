//------------------------------------------------------------------------------
#ifndef RENDERER_H
#define RENDERER_H

#include "shaders.h"
#include "headers/sceneTypes.h"

//------------------------------------------------------------------------------
class CRenderer : public CEngineBase
{
  private:
    SRenderer renderer;

    std::vector<std::vector<SRenderMesh> > meshes;

  public:
    CRenderer();
    CRenderer(CContext *context);
    ~CRenderer();

    void addMesh(const SRenderMesh &mesh);
    void dispatch() const;
    void clearGroups();

    inline void setMode(NRenderer::EMode mode = NRenderer::MODE_STANDARD) { renderer.mode = mode; }

    const SRenderer *getRenderer() const { return &renderer; }
};
//------------------------------------------------------------------------------
#endif // RENDERER_H
