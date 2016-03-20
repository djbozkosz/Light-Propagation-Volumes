//------------------------------------------------------------------------------
#ifndef CONTEXT_H
#define CONTEXT_H

#include <iostream>
#include <vector>
#include <list>
#include <map>

#ifdef ENV_QT
#include <QDebug>
#endif

#include "matrix.h"
#include "headers/engineTypes.h"

//------------------------------------------------------------------------------
class CEngineBase;
class CEngine;
class CWindow;
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
class CFilesystem;
class CExceptions;

//------------------------------------------------------------------------------
class CContext
{
  private:
    CEngine *engine;
    CWindow *window;
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
    CFilesystem *filesystem;
    CExceptions *exceptions;

    // callbacks engine static
    void (*fncInitialize)(CContext *context);
    void (*fncInitializeFinish)(CContext *context);
    void (*fncEngineShowMessage)(const CContext *context, const std::string &title, const std::string &text, bool modal);
    void (*fncEngineSetPlatform)(CContext *context, NEngine::EGPUPlatform gpuPlatform, NEngine::ELPVMode lpvMode, NEngine::ELPVTechnique lpvTechnique);
    void (*fncEngineIncDrawCalls)(CContext *context);
    void (*fncEngineClearDrawCalls)(CContext *context);
    void (*fncEngineSetShadowViewProj)(CContext *context, uint32 index, const glm::mat4 &m);
    void (*fncEngineSetShadowFrustum)(CContext *context, uint32 index, const SFrustum &f);
    void (*fncEngineSetGeometryViewProj)(CContext *context, uint32 index, const glm::mat4 &m);
    void (*fncEngineSetGeometryFrustum)(CContext *context, uint32 index, const SFrustum &f);
    void (*fncEngineSetSunSkyPose)(CContext *context, uint32 index, const glm::vec2 &v);
    void (*fncEngineSetSunSkyColor)(CContext *context, uint32 index, const glm::vec3 &v);
    void (*fncEngineSetLpvPose)(CContext *context, uint32 index, const glm::vec3 &v);
    void (*fncEngineSetLpvPoseOut)(CContext *context, uint32 index, const glm::vec3 &v);
    void (*fncEngineSwapLPV)(CContext *context);
    std::string (*fncEngineGetClassName)(CContext *context, const CEngineBase *object);
    const SEngine *(*fncEngineGetEngine)(const CContext *context);

  public:
//------------------------------------------------------------------------------
    inline CContext() :
      engine(NULL),
      scenes(NULL),
      models(NULL),
      renderer(NULL),
      shaders(NULL),
      culling(NULL),
      pickColor(NULL),
      framebuffers(NULL),
      maps(NULL),
      camera(NULL),
      openGL(NULL),
      filesystem(NULL),
      exceptions(NULL),

      fncInitialize(NULL),
      fncInitializeFinish(NULL),
      fncEngineShowMessage(NULL),
      fncEngineSetPlatform(NULL),
      fncEngineIncDrawCalls(NULL),
      fncEngineClearDrawCalls(NULL),
      fncEngineSetShadowViewProj(NULL),
      fncEngineSetShadowFrustum(NULL),
      fncEngineSetGeometryViewProj(NULL),
      fncEngineSetGeometryFrustum(NULL),
      fncEngineSetSunSkyPose(NULL),
      fncEngineSetSunSkyColor(NULL),
      fncEngineSetLpvPose(NULL),
      fncEngineSetLpvPoseOut(NULL),
      fncEngineSwapLPV(NULL),
      fncEngineGetClassName(NULL),
      fncEngineGetEngine(NULL) {}
//------------------------------------------------------------------------------
    inline CContext(
      CEngine *engine,
      CWindow *window,
      CScenes *scenes,
      CModels *models,
      CRenderer *renderer,
      CShaders *shaders,
      CCulling *culling,
      CPickColor *pickColor,
      CFramebuffers *framebuffers,
      CMaps *maps,
      CCamera *camera,
      COpenGL *openGL,
      CFilesystem *filesystem,
      CExceptions *exceptions) :
        engine(engine),
        window(window),
        scenes(scenes),
        models(models),
        renderer(renderer),
        shaders(shaders),
        culling(culling),
        pickColor(pickColor),
        framebuffers(framebuffers),
        maps(maps),
        camera(camera),
        openGL(openGL),
        filesystem(filesystem),
        exceptions(exceptions),

        fncInitialize(NULL),
        fncInitializeFinish(NULL),
        fncEngineShowMessage(NULL),
        fncEngineSetPlatform(NULL),
        fncEngineIncDrawCalls(NULL),
        fncEngineClearDrawCalls(NULL),
        fncEngineSetShadowViewProj(NULL),
        fncEngineSetShadowFrustum(NULL),
        fncEngineSetGeometryViewProj(NULL),
        fncEngineSetGeometryFrustum(NULL),
        fncEngineSetSunSkyPose(NULL),
        fncEngineSetSunSkyColor(NULL),
        fncEngineSetLpvPose(NULL),
        fncEngineSetLpvPoseOut(NULL),
        fncEngineSwapLPV(NULL),
        fncEngineGetClassName(NULL),
        fncEngineGetEngine(NULL) {}
//------------------------------------------------------------------------------
    inline ~CContext() {}
//------------------------------------------------------------------------------
    inline void setContext(
      CEngine *engine,
      CWindow *window,
      CScenes *scenes,
      CModels *models,
      CRenderer *renderer,
      CShaders *shaders,
      CCulling *culling,
      CPickColor *pickColor,
      CFramebuffers *framebuffers,
      CMaps *maps,
      CCamera *camera,
      COpenGL *openGL,
      CFilesystem *filesystem,
      CExceptions *exceptions)
    {
      if(engine)       this->engine = engine;
      if(window)       this->window = window;
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
      if(filesystem)   this->filesystem = filesystem;
      if(exceptions)   this->exceptions = exceptions;
    }
//------------------------------------------------------------------------------
    inline void setEngineCallbacks(
      void (*fncInitialize)(CContext *context),
      void (*fncInitializeFinish)(CContext *context),
      void (*fncEngineShowMessage)(const CContext *context, const std::string &title, const std::string &text, bool modal),
      void (*fncEngineSetPlatform)(CContext *context, NEngine::EGPUPlatform gpuPlatform, NEngine::ELPVMode lpvMode, NEngine::ELPVTechnique lpvTechnique),
      void (*fncEngineIncDrawCalls)(CContext *context),
      void (*fncEngineClearDrawCalls)(CContext *context),
      void (*fncEngineSetShadowViewProj)(CContext *context, uint32 index, const glm::mat4 &m),
      void (*fncEngineSetShadowFrustum)(CContext *context, uint32 index, const SFrustum &f),
      void (*fncEngineSetGeometryViewProj)(CContext *context, uint32 index, const glm::mat4 &m),
      void (*fncEngineSetGeometryFrustum)(CContext *context, uint32 index, const SFrustum &f),
      void (*fncEngineSetSunSkyPose)(CContext *context, uint32 index, const glm::vec2 &v),
      void (*fncEngineSetSunSkyColor)(CContext *context, uint32 index, const glm::vec3 &v),
      void (*fncEngineSetLpvPose)(CContext *context, uint32 index, const glm::vec3 &v),
      void (*fncEngineSetLpvPoseOut)(CContext *context, uint32 index, const glm::vec3 &v),
      void (*fncEngineSwapLPV)(CContext *context),
      std::string (*fncEngineGetClassName)(CContext *context, const CEngineBase *object),
      const SEngine *(*fncEngineGetEngine)(const CContext *context))
    {
      if(fncInitialize)                this->fncInitialize = fncInitialize;
      if(fncInitializeFinish)          this->fncInitializeFinish = fncInitializeFinish;
      if(fncEngineShowMessage)         this->fncEngineShowMessage = fncEngineShowMessage;
      if(fncEngineSetPlatform)         this->fncEngineSetPlatform = fncEngineSetPlatform;
      if(fncEngineIncDrawCalls)        this->fncEngineIncDrawCalls = fncEngineIncDrawCalls;
      if(fncEngineClearDrawCalls)      this->fncEngineClearDrawCalls = fncEngineClearDrawCalls;
      if(fncEngineSetShadowViewProj)   this->fncEngineSetShadowViewProj = fncEngineSetShadowViewProj;
      if(fncEngineSetShadowFrustum)    this->fncEngineSetShadowFrustum = fncEngineSetShadowFrustum;
      if(fncEngineSetGeometryViewProj) this->fncEngineSetGeometryViewProj = fncEngineSetGeometryViewProj;
      if(fncEngineSetGeometryFrustum)  this->fncEngineSetGeometryFrustum = fncEngineSetGeometryFrustum;
      if(fncEngineSetSunSkyPose)       this->fncEngineSetSunSkyPose = fncEngineSetSunSkyPose;
      if(fncEngineSetSunSkyColor)      this->fncEngineSetSunSkyColor = fncEngineSetSunSkyColor;
      if(fncEngineSetLpvPose)          this->fncEngineSetLpvPose = fncEngineSetLpvPose;
      if(fncEngineSetLpvPoseOut)       this->fncEngineSetLpvPoseOut = fncEngineSetLpvPoseOut;
      if(fncEngineSwapLPV)             this->fncEngineSwapLPV = fncEngineSwapLPV;
      if(fncEngineGetClassName)        this->fncEngineGetClassName = fncEngineGetClassName;
      if(fncEngineGetEngine)           this->fncEngineGetEngine = fncEngineGetEngine;
    }
//------------------------------------------------------------------------------

    // callbacks engine
    inline void engineInitialize() { fncInitialize(this); }
    inline void engineInitializeFinish() { fncInitializeFinish(this); }
    inline void engineShowMessage(const std::string &title, const std::string &text, bool modal = true) const { fncEngineShowMessage(this, title, text, modal); }
    inline void engineSetPlatform(NEngine::EGPUPlatform gpuPlatform, NEngine::ELPVMode lpvMode, NEngine::ELPVTechnique lpvTechnique) { fncEngineSetPlatform(this, gpuPlatform, lpvMode, lpvTechnique); }
    inline void engineIncDrawCalls() { fncEngineIncDrawCalls(this); }
    inline void engineClearDrawCalls() { fncEngineClearDrawCalls(this); }
    inline void engineSetShadowViewProj(uint32 index, const glm::mat4 &m) { fncEngineSetShadowViewProj(this, index, m); }
    inline void engineSetShadowFrustum(uint32 index, const SFrustum &f) { fncEngineSetShadowFrustum(this, index, f); }
    inline void engineSetGeometryViewProj(uint32 index, const glm::mat4 &m) { fncEngineSetGeometryViewProj(this, index, m); }
    inline void engineSetGeometryFrustum(uint32 index, const SFrustum &f) { fncEngineSetGeometryFrustum(this, index, f); }
    inline void engineSetSunSkyPose(uint32 index, const glm::vec2 &v) { fncEngineSetSunSkyPose(this, index, v); }
    inline void engineSetSunSkyColor(uint32 index, const glm::vec3 &v) { fncEngineSetSunSkyColor(this, index, v); }
    inline void engineSetLpvPose(uint32 index, const glm::vec3 &v) { fncEngineSetLpvPose(this, index, v); }
    inline void engineSetLpvPoseOut(uint32 index, const glm::vec3 &v) { fncEngineSetLpvPoseOut(this, index, v); }
    inline void engineSwapLPV() { fncEngineSwapLPV(this); }
    inline std::string engineGetClassName(const CEngineBase *object) { return fncEngineGetClassName(this, object); return std::string(); }
    inline const SEngine *engineGetEngine() const { return fncEngineGetEngine(this); return NULL; }

    // console
    inline void log(const std::string &msg) const
    {
#ifdef ENV_QT
      qDebug() << msg.c_str();
#else
      std::cout << msg << "\n";
#endif
    }
    inline void warning(const std::string &msg) const
    {
#ifdef ENV_QT
      qDebug() << "WARNING: " << msg.c_str();
#else
      std::cout << "WARNING: " << msg << "!\n";
#endif
    }
    inline void error(const std::string &msg) const
    {
#ifdef ENV_QT
      qDebug() << "ERROR: " << msg.c_str();
#else
      std::cout << "ERROR: " << msg << "!\n";
#endif
    }

    // gets
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
    inline CFilesystem *getFilesystem() { return filesystem; }
    inline CExceptions *getExceptions() { return exceptions; }

    inline const CEngine *getEngine() const { return engine; }
    inline const CScenes *getScenes() const { return scenes; }
    inline const CModels *getModels() const { return models; }
    inline const CRenderer *getRenderer() const { return renderer; }
    inline const CShaders *getShaders() const { return shaders; }
    inline const CCulling *getCulling() const { return culling; }
    inline const CPickColor *getPickColor() const { return pickColor; }
    inline const CFramebuffers *getFramebuffers() const { return framebuffers; }
    inline const CMaps *getMaps() const { return maps; }
    inline const CCamera *getCamera() const { return camera; }
    inline const COpenGL *getOpenGL() const { return openGL; }
    inline const CFilesystem *getFilesystem() const { return filesystem; }
    inline const CExceptions *getExceptions() const { return exceptions; }
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
#endif // CONTEXT_H
