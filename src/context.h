//------------------------------------------------------------------------------
#ifndef CONTEXT_H
#define CONTEXT_H

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>

#include "headers/types.h"

//------------------------------------------------------------------------------
class CEngine;
class CScenes;
class CModels;
class CRenderer;
class CShaders;
class CCulling;
class CPickColor;
class CFramebuffers;
class CMaps;
class CCamera;
class COpenGL;

//------------------------------------------------------------------------------
class CContext
{
  private:
    CEngine *engine;
    CScenes *scenes;
    CModels *models;
    CRenderer *renderer;
    CShaders *shaders;
    CCulling *culling;
    CPickColor *pickColor;
    CFramebuffers *framebuffers;
    CMaps *maps;
    CCamera *camera;
    COpenGL *openGL;

  public:
    inline CContext() : engine(NULL), scenes(NULL), models(NULL), renderer(NULL), shaders(NULL), culling(NULL), pickColor(NULL), framebuffers(NULL), maps(NULL), camera(NULL), openGL(NULL) {}
    inline CContext(CEngine *engine, CScenes *scenes, CModels *models, CRenderer *renderer, CShaders *shaders, CCulling *culling, CPickColor *pickColor, CFramebuffers *framebuffers, CMaps *maps, CCamera *camera, COpenGL *openGL) : engine(engine), scenes(scenes), models(models), renderer(renderer), shaders(shaders), culling(culling), pickColor(pickColor), framebuffers(framebuffers), maps(maps), camera(camera), openGL(openGL) {}
    inline ~CContext() {}

    void setContext(CEngine *engine, CScenes *scenes, CModels *models, CRenderer *renderer, CShaders *shaders, CCulling *culling, CPickColor *pickColor, CFramebuffers *framebuffers, CMaps *maps, CCamera *camera, COpenGL *openGL);

    inline CEngine *getEngine() { return engine; }
    inline CScenes *getScenes() { return scenes; }
    inline CModels *getModels() { return models; }
    inline CRenderer *getRenderer() { return renderer; }
    inline CShaders *getShaders() { return shaders; }
    inline CCulling *getCulling() { return culling; }
    inline CPickColor *getPickColor() { return pickColor; }
    inline CFramebuffers *getFramebuffers() { return framebuffers; }
    inline CMaps *getMaps() { return maps; }
    inline CCamera *getCamera() { return camera; }
    inline COpenGL *getOpenGL() { return openGL; }
};
//------------------------------------------------------------------------------
class CEngineBase
{
  protected:
    CContext *context;

  public:
    inline CEngineBase() : context(NULL) {}
    inline CEngineBase(CContext *context) : context(context) {}
    inline ~CEngineBase() {}

    inline CContext *getContext() { return context; }
};
//------------------------------------------------------------------------------
inline void CContext::setContext(CEngine *engine, CScenes *scenes, CModels *models, CRenderer *renderer, CShaders *shaders, CCulling *culling, CPickColor *pickColor, CFramebuffers *framebuffers, CMaps *maps, CCamera *camera, COpenGL *openGL)
{
  if(engine)       this->engine = engine;
  if(scenes)       this->scenes = scenes;
  if(models)       this->models = models;
  if(renderer)     this->renderer = renderer;
  if(shaders)      this->shaders = shaders;
  if(culling)      this->culling = culling;
  if(pickColor)    this->pickColor = pickColor;
  if(framebuffers) this->framebuffers = framebuffers;
  if(maps)         this->maps = maps;
  if(camera)       this->camera = camera;
  if(openGL)       this->openGL = openGL;
}
//------------------------------------------------------------------------------
#endif // CONTEXT_H
