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
    static inline void staticClearDrawCalls(CContext *context) { context->getEngine()->clearDrawCalls(); }
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

  public:
    CEngine(
#ifdef ENV_QT
      QObject *parent = NULL
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

    inline void incDrawCalls() { engine.drawCalls++; }
    inline void clearDrawCalls() { engine.drawCalls = 0; }
    void updateTicks();

    std::string getClassName(const CEngineBase *object);

    inline const SEngine *getEngine() const { return &engine; }
};
//------------------------------------------------------------------------------
#endif //ENGINE_H
