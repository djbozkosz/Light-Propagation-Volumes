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

    // static callbacks
  protected:
    static inline void staticIncDrawCalls(CContext *context) { context->getEngine()->incDrawCalls(); }
    static inline std::string staticGetClassName(CContext *context, const CEngineBase *object) { return context->getEngine()->getClassName(object); }
    static inline const SEngine *staticGetEngine(const CContext *context) { return context->getEngine()->getEngine(); }

    void initialize();
    void initializeFinish();
    void event();
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

    inline void incDrawCalls() { engine.drawCalls++; }
    void updateTicks();

    std::string getClassName(const CEngineBase *object);

    inline const SEngine *getEngine() const { return &engine; }
};
//------------------------------------------------------------------------------
#endif //ENGINE_H
