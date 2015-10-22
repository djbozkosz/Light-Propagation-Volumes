//------------------------------------------------------------------------------
#ifndef WINDOW_H
#define WINDOW_H

#ifdef ENV_QT
#include <QApplication>
#include <QCoreApplication>
#include <QEvent>
#include <QMouseEvent>
#include <QTouchEvent>

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
#ifdef ENV_QT
    Q_OBJECT
#endif

  protected:
    virtual void initialize();
    virtual void paint();
    virtual void resize(int width, int height);
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
