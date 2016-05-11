//------------------------------------------------------------------------------
#ifndef ENGINE_H
#define ENGINE_H

#include "window.h"

//------------------------------------------------------------------------------
class CEngine
#ifdef ENV_QT
  : public QObject
#endif
{
  private:
#ifdef ENV_QT
    Q_OBJECT
#endif

    SEngine engine;

    CContext context;
    CWindow *window;
    CScenes scenes;
    CModels models;
    CRenderer renderer;
    CShaders shaders;
    CCulling culling;
    CPickColor pickColor;
    CFramebuffers framebuffers;
    CMaps maps;
    CCamera camera;
    COpenGL openGL;
    CFilesystem filesystem;
    CExceptions exceptions;

  protected:
  // static callbacks
  static inline void staticInitialize(CContext *context) { context->getEngine()->initialize(); }
  static inline void staticInitializeFinish(CContext *context) { context->getEngine()->initializeFinish(); }
#ifdef ENV_SDL
    static inline uint32 staticOnTimeoutInit(uint32 interval, void *context) { SDL_Event event; event.type = reinterpret_cast<CContext *>(context)->engineGetEngine()->initSceneEvent; SDL_PushEvent(&event); return interval; }
    static inline uint32 staticOnTimeout(uint32 interval, void *context) { reinterpret_cast<CContext *>(context)->getEngine()->onTimeout(); return interval; }
#endif
    static inline void staticShowMessage(const CContext *context, const std::string &title, const std::string &text, bool modal = true) { context->getEngine()->showMessage(title, text, modal); }
    static inline void staticIncDrawCalls(CContext *context) { context->getEngine()->incDrawCalls(); }
    static inline void staticSetPlatform(CContext *context, NEngine::EGPUPlatform gpuPlatform, NEngine::EGPUVendor gpuVendor, NEngine::ELPVMode lpvMode, NEngine::ELPVTechnique lpvTechnique) { context->getEngine()->setPlatform(gpuPlatform, gpuVendor, lpvMode, lpvTechnique); }
    static inline void staticClearDrawCalls(CContext *context) { context->getEngine()->clearDrawCalls(); }
    static inline void staticSetShadowViewProj(CContext *context, uint32 index, const glm::mat4 &m) { context->getEngine()->setShadowViewProj(index, m); }
    static inline void staticSetShadowFrustum(CContext *context, uint32 index, const SFrustum &f) { context->getEngine()->setShadowFrustum(index, f); }
    static inline void staticSetGeometryPos(CContext *context, uint32 index, const glm::vec3 &p) { context->getEngine()->setGeometryPos(index, p); }
    static inline void staticSetGeometryViewProj(CContext *context, uint32 index, const glm::mat4 &m) { context->getEngine()->setGeometryViewProj(index, m); }
    static inline void staticSetGeometryFrustum(CContext *context, uint32 index, const SFrustum &f) { context->getEngine()->setGeometryFrustum(index, f); }
    static inline void staticSetSunSkyPose(CContext *context, uint32 index, const glm::vec3 &p, const glm::vec2 &r) { context->getEngine()->setSunSkyPose(index, p, r); }
    static inline void staticSetSunSkyColor(CContext *context, uint32 index, const glm::vec3 &v) { context->getEngine()->setSunSkyColor(index, v); }
    static inline void staticSetLpvPose(CContext *context, uint32 index, const glm::vec3 &v) { context->getEngine()->setLpvPose(index, v); }
    static inline void staticSwapLPV(CContext *context) { context->getEngine()->swapLPV(); }
    static inline double staticGetTime(const CContext *context) { return context->getEngine()->getTime(); }
    static inline std::string staticGetClassName(CContext *context, const CEngineBase *object) { return context->getEngine()->getClassName(object); }
    static inline const SEngine *staticGetEngine(const CContext *context) { return context->getEngine()->getEngine(); }

    void initialize();
    void initializeFinish();

#if defined(ENV_SDL)
    int32 event();
#elif defined(ENV_QT)
  protected slots:
#endif
    void mousePress(NEngine::EMouseButton buttons);
    void mouseRelease(NEngine::EMouseButton buttons);
    void mouseMove(const SPoint &point, NEngine::EMouseButton buttons);
    void keyPress(NEngine::EKey key);
    void keyRelease(NEngine::EKey key);
    void updateSunDir();

  public:
    CEngine(
      uint32 argc = 0, const char *const *const argv = NULL
#ifdef ENV_QT
      , QObject *parent = NULL
#endif
      );
    virtual ~CEngine();

#if defined(ENV_QT)
    inline void quit() { qApp->quit(); }
#elif defined(ENV_SDL)
    inline int32 exec() { return event(); }
    inline void quit() { SDL_Event event; event.type = SDL_QUIT; SDL_PushEvent(&event); }
#endif
    void simulationStep();

#ifdef ENV_QT
  public slots:
#endif
    void onTimeoutInit();
    void onTimeout();
#ifdef ENV_QT
  public:
#endif

    void showMessage(const std::string &title, const std::string &text, bool modal = true) const;

    bool isKeyForDelayedRendering() const;

    inline void setPlatform(NEngine::EGPUPlatform gpuPlatform, NEngine::EGPUVendor gpuVendor, NEngine::ELPVMode lpvMode, NEngine::ELPVTechnique lpvTechnique) { engine.gpuPlatform = gpuPlatform; engine.gpuVendor = gpuVendor; engine.lpvMode = lpvMode; engine.lpvTechnique = lpvTechnique; }
    inline void incDrawCalls() { engine.drawCalls++; }
    inline void clearDrawCalls() { engine.drawCalls = 0; }
    inline void setShadowViewProj(uint32 index, const glm::mat4 &m) { engine.shadowViewProj[index] = m; }
    inline void setShadowFrustum(uint32 index, const SFrustum &f) { engine.shadowFrustum[index] = f; }
    inline void setGeometryPos(uint32 index, const glm::vec3 &p) { engine.geometryPos[index * NMath::VEC3 + 0] = p.x; engine.geometryPos[index * NMath::VEC3 + 1] = p.y; engine.geometryPos[index * NMath::VEC3 + 2] = p.z; }
    inline void setGeometryViewProj(uint32 index, const glm::mat4 &m) { engine.geometryViewProj[index] = m; }
    inline void setGeometryFrustum(uint32 index, const SFrustum &f) { engine.geometryFrustum[index] = f; }
    inline void setSunSkyPose(uint32 index, const glm::vec3 &p, const glm::vec2 &r) { float pp[] = { p.x, p.y, p.z }; float rr[] = { r.x, r.y }; memcpy(&engine.sunSkyPoses[index * NMath::VEC3], pp, sizeof(float) * 3); memcpy(&engine.sunSkyRots[index * NMath::VEC2], rr, sizeof(float) * 2); }
    inline void setSunSkyColor(uint32 index, const glm::vec3 &v) { engine.sunSkyColors[index * NMath::VEC3 + 0] = v.x; engine.sunSkyColors[index * NMath::VEC3 + 1] = v.y; engine.sunSkyColors[index * NMath::VEC3 + 2] = v.z; }
    inline void setLpvPose(uint32 index, const glm::vec3 &v) { engine.lpvPoses[index * NMath::VEC3 + 0] = v.x; engine.lpvPoses[index * NMath::VEC3 + 1] = v.y; engine.lpvPoses[index * NMath::VEC3 + 2] = v.z; }
    inline void swapLPV() { engine.lpvPropagationSwap = !engine.lpvPropagationSwap; }
    void updateTicks();
    double getTime() const;

    std::string getClassName(const CEngineBase *object);

    inline const SEngine *getEngine() const { return &engine; }
};
//------------------------------------------------------------------------------
#endif //ENGINE_H
