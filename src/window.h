//------------------------------------------------------------------------------
#ifndef WINDOW_H
#define WINDOW_H

#ifdef ENV_QT
#include <QApplication>
#include <QCoreApplication>
#include <QEvent>
#include <QMouseEvent>
#include <QTouchEvent>
#include <QString>

#if QT_VERSION < 0x050400
#include <QGLWidget>
#else
#include <QOpenGLWidget>
#endif
#endif

#include "scenes.h"

//------------------------------------------------------------------------------
class CWindow : public
#ifdef ENV_QT
#if QT_VERSION < 0x050400
  QGLWidget
#else
  QOpenGLWidget
#endif
  , public
#endif
  CEngineBase
{
  private:
#if defined(ENV_QT)
    Q_OBJECT
#elif defined(ENV_SDL)
    SDL_Window *SDLwindow;
    SDL_GLContext SDLcontext;
#endif

  protected:
    virtual void paintGL();
#ifdef ENV_SDL
  public:
#endif
    virtual void initializeGL();
    virtual void resizeGL(int width, int height);
#ifdef ENV_QT
    virtual bool event(QEvent *event);
#endif

  public:
    CWindow(CContext *context
#ifdef ENV_QT
      , QObject *parent = NULL
#endif
      );
    virtual ~CWindow();

#ifdef ENV_SDL
    inline void repaint() { paintGL(); }

    inline const SDL_Window *getSDLWindow() const { return SDLwindow; }
    inline const SDL_GLContext *getSDLContext() const { return &SDLcontext; }
#endif

#ifdef ENV_QT
  signals:
    void onInitializeGL();
    void onInitializeFinishGL();
    void onMousePress(NEngine::EMouseButton buttons);
    void onMouseRelease(NEngine::EMouseButton buttons);
    void onMouseMove(int32 x, int32 y);
    void onKeyPress(NEngine::EKey key);
    void onKeyRelease(NEngine::EKey key);
#endif
};
//------------------------------------------------------------------------------
#endif // WINDOW_H
