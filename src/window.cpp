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
#ifdef ENV_SDL
  , SDLwindow(NULL)
#endif
{
}
//------------------------------------------------------------------------------
CWindow::~CWindow()
{
}
//------------------------------------------------------------------------------
void CWindow::initializeGL()
{
  if(CWindow::context->engineGetEngine()->consoleVisible)
  {
#if defined(_WIN32)
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
#elif defined(__linux__)
    //
#endif
  }

#if defined(ENV_SDL)
  int32 ret;

  if((ret = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER)) < -1)
    CWindow::context->getExceptions()->throwException(SException(this, "Unable to init SDL!"));

  if(!(SDLwindow = SDL_CreateWindow(NEngine::STR_APP_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE)))
    CWindow::context->getExceptions()->throwException(SException(this, "Unable to init window!"));

  SDLcontext = SDL_GL_CreateContext(SDLwindow);

  if(SDL_GL_SetSwapInterval(-1) == -1)
    SDL_GL_SetSwapInterval(1);

  if(glewInit() != GLEW_OK)
    CWindow::context->getExceptions()->throwException(SException(this, "Unable to init GLEW!"));
#elif defined(ENV_QT)
  emit onInitializeGL();
#endif

  //COpenGL *gl = CEngineBase::context->getOpenGL();

  glClearColor(0.0, 0.0, 0.0, 0.0);

#ifdef ENV_QT
  emit onInitializeFinishGL();
#endif
}
//------------------------------------------------------------------------------
void CWindow::paintGL()
{
  //COpenGL *gl = CEngineBase::context->getOpenGL();

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
//------------------------------------------------------------------------------
void CWindow::resizeGL(int width, int height)
{
  //COpenGL *gl = CEngineBase::context->getOpenGL();

  glViewport(0, 0, width, height);
}
//------------------------------------------------------------------------------
#ifdef ENV_QT
bool CWindow::event(QEvent *event)
{
  // qt mouse and key events

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
