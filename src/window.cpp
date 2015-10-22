//------------------------------------------------------------------------------
#include "window.h"

//------------------------------------------------------------------------------
CWindow::CWindow(CContext *context
#ifdef ENV_QT
  , QObject *parent
#endif
  ) :
#ifdef ENV_QT
#if QT_VERSION < 0x050400
  QGLWidget
#else
  QOpenGLWidget
#endif
  (qobject_cast<QWidget *>(parent)),
#endif
  CEngineBase(context)
{
}
//------------------------------------------------------------------------------
CWindow::~CWindow()
{
}
//------------------------------------------------------------------------------
void CWindow::initialize()
{
}
//------------------------------------------------------------------------------
void CWindow::paint()
{
}
//------------------------------------------------------------------------------
void CWindow::resize(int width, int height)
{
  UNUSED(width);
  UNUSED(height);
}
//------------------------------------------------------------------------------
#ifdef ENV_QT
bool CWindow::event(QEvent *event)
{
  return
#if QT_VERSION < 0x050400
    QGLWidget
#else
    QOpenGLWidget
#endif
    ::event(event);
}
#endif
//------------------------------------------------------------------------------
