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
    static inline void staticShowMessage(const CContext *context, const std::string &title, const std::string &text, bool modal = true) { context->getEngine()->showMessage(title, text, modal); }
    static inline void staticIncDrawCalls(CContext *context) { context->getEngine()->incDrawCalls(); }
    static inline std::string staticGetClassName(CContext *context, const CEngineBase *object) { return context->getEngine()->getClassName(object); }
    static inline const SEngine *staticGetEngine(const CContext *context) { return context->getEngine()->getEngine(); }

#if defined(ENV_SDL)
    int32 event();
#elif defined(ENV_QT)
  protected slots:
#endif
    void initialize();
    void initializeFinish();
    void mousePress(NEngine::EMouseButton buttons);
    void mouseRelease(NEngine::EMouseButton buttons);
    void mouseMove(int32 x, int32 y);
    void keyPress(NEngine::EKey key);
    void keyRelease(NEngine::EKey key);

  public:
    CEngine(
#ifdef ENV_QT
      QObject *parent = NULL
#endif
      ); // timer.start();
    virtual ~CEngine();

#ifdef ENV_SDL
    inline int32 exec() { return event(); }
#endif

    void showMessage(const std::string &title, const std::string &text, bool modal = true) const;

    inline void incDrawCalls() { engine.drawCalls++; }
    void updateTicks();

    std::string getClassName(const CEngineBase *object);

    inline const SEngine *getEngine() const { return &engine; }
};
//------------------------------------------------------------------------------
#endif //ENGINE_H
