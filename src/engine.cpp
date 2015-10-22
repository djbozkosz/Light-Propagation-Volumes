//------------------------------------------------------------------------------
#include "engine.h"

//------------------------------------------------------------------------------
CEngine::CEngine(
#ifdef ENV_QT
  QObject *parent
#endif
  ) :
#ifdef ENV_QT
  QObject(parent),
#endif
  window(NULL)
{
  window = new CWindow(&context
#ifdef ENV_QT
    , this
#endif
  );
  context.setContext(this, window, &scenes, &models, &renderer, &shaders, &culling, &pickColor, &framebuffers, &maps, &camera, &openGL, &filesystem, &exceptions);
  context.setEngineCallbacks(&staticShowMessage, &staticIncDrawCalls, &staticGetClassName, &staticGetEngine);

  engine.consoleVisible = true;

#ifdef ENV_QT
  connect(window, SIGNAL(onInitializeGL()), this, SLOT(initialize()));
  connect(window, SIGNAL(onInitializeFinishGL()), this, SLOT(initializeFinish()));
  connect(window, SIGNAL(onMousePress(NEngine::EMouseButton buttons)), this, SLOT(mousePress(NEngine::EMouseButton buttons)));
  connect(window, SIGNAL(onMouseRelease(NEngine::EMouseButton buttons)), this, SLOT(mouseRelease(NEngine::EMouseButton buttons)));
  connect(window, SIGNAL(onMouseMove(int32 x, int32 y)), this, SLOT(mouseMove(int32 x, int32 y)));
  connect(window, SIGNAL(onKeyPress(NEngine::EKey key)), this, SLOT(keyPress(NEngine::EKey key)));
  connect(window, SIGNAL(onKeyRelease(NEngine::EKey key)), this, SLOT(keyRelease(NEngine::EKey key)));
#endif
}
//------------------------------------------------------------------------------
CEngine::~CEngine()
{
#ifndef ENV_QT
  delete window;
#endif
}
//------------------------------------------------------------------------------
void CEngine::initialize()
{
  scenes = CScenes(&context);
  models = CModels(&context);
  renderer = CRenderer(&context);
  shaders = CShaders(&context);
  culling = CCulling(&context);
  pickColor = CPickColor(&context);
  framebuffers = CFramebuffers(&context);
  maps = CMaps(&context);
  camera = CCamera(&context);
  openGL = COpenGL(&context);
  filesystem = CFilesystem(&context);
  exceptions = CExceptions(&context);
}
//------------------------------------------------------------------------------
void CEngine::initializeFinish()
{
}
//------------------------------------------------------------------------------
#ifdef ENV_SDL
int32 CEngine::event()
{
  initialize();
  window->initializeGL();
  initializeFinish();

  SDL_Event event;

  while(SDL_WaitEvent(&event))
  {
    std::cout << event.type << "\n";

    if(event.type == SDL_WINDOWEVENT)
    {
      uint32 w = event.window.windowID;
      std::cout << "  " << w << "\n";

      if((w == SDL_WINDOWEVENT_SHOWN) || (w == SDL_WINDOWEVENT_EXPOSED) || (w == SDL_WINDOWEVENT_RESIZED))
      {
        std::cout << "exposed\n";
        window->resizeGL(100, 100);
        window->repaint();
      }
    }
    else if(event.type == SDL_QUIT)
      break;
  }

  return 0;
}
#endif
//------------------------------------------------------------------------------
void CEngine::mousePress(NEngine::EMouseButton buttons)
{
  UNUSED(buttons);
}
//------------------------------------------------------------------------------
void CEngine::mouseRelease(NEngine::EMouseButton buttons)
{
  UNUSED(buttons);
}
//------------------------------------------------------------------------------
void CEngine::mouseMove(int32 x, int32 y)
{
  UNUSED(x);
  UNUSED(y);
}
//------------------------------------------------------------------------------
void CEngine::keyPress(NEngine::EKey key)
{
  UNUSED(key);
}
//------------------------------------------------------------------------------
void CEngine::keyRelease(NEngine::EKey key)
{
  UNUSED(key);
}
//------------------------------------------------------------------------------
void CEngine::showMessage(const std::string &title, const std::string &text, bool modal) const
{
  std::cout << title << ": " << text << "\n";

#if defined(ENV_QT)
  QMessageBox *msg = new QMessageBox(this);
  msg->setWindowTitle(title.c_str());
  msg->setText(text.c_str());
  msg->setStandardButtons(QMessageBox::Ok);
  msg->setDefaultButton(QMessageBox::Ok);
  msg->setModal(modal);
  msg->show();
#elif defined(ENV_SDL)
  UNUSED(modal);
  SDL_ShowSimpleMessageBox(0, title.c_str(), text.c_str(), NULL);
#endif
}
//------------------------------------------------------------------------------
void CEngine::updateTicks()
{
  engine.tickNew =
#if defined(ENV_QT)
    static_cast<uint32>(timer.elapsed());
#elif defined(ENV_SDL)
    SDL_GetTicks();
#endif

  if(!engine.tickOld)
    engine.tickOld = engine.tickNew;

  if((engine.tickNew != engine.tickOld) && (!engine.fpsCounter))
  {
    engine.simulationStep = static_cast<float>(engine.tickNew - engine.tickOld) * NEngine::FPS_MS / NEngine::FPS_COUNTER_MAX;
    engine.fps = 1.0f / engine.simulationStep;
    engine.tickOld = engine.tickNew;
  }
  engine.fpsCounter++;
  if(engine.fpsCounter == NEngine::FPS_COUNTER_MAX)
    engine.fpsCounter = 0;
}
//------------------------------------------------------------------------------
std::string CEngine::getClassName(const CEngineBase *object)
{
  UNUSED(object);
  return "abc";
}
//------------------------------------------------------------------------------
