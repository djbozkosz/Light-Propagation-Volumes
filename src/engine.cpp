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

#if defined(ENV_QT)
  connect(window, SIGNAL(onInitializeGL()), this, SLOT(initialize()));
  connect(window, SIGNAL(onInitializeFinishGL()), this, SLOT(initializeFinish()));
  connect(window, SIGNAL(onMousePress(NEngine::EMouseButton buttons)), this, SLOT(mousePress(NEngine::EMouseButton buttons)));
  connect(window, SIGNAL(onMouseRelease(NEngine::EMouseButton buttons)), this, SLOT(mouseRelease(NEngine::EMouseButton buttons)));
  connect(window, SIGNAL(onMouseMove(int32 x, int32 y)), this, SLOT(mouseMove(int32 x, int32 y)));
  connect(window, SIGNAL(onKeyPress(NEngine::EKey key)), this, SLOT(keyPress(NEngine::EKey key)));
  connect(window, SIGNAL(onKeyRelease(NEngine::EKey key)), this, SLOT(keyRelease(NEngine::EKey key)));

  // fill keys move map
#elif defined(ENV_SDL)
  engine.keysMap[SDLK_ESCAPE] = NEngine::KEY_QUIT;

  engine.keysMap[SDLK_w] = NEngine::KEY_FRONT;
  engine.keysMap[SDLK_UP] = NEngine::KEY_FRONT;
  engine.keysMap[SDLK_s] = NEngine::KEY_BACK;
  engine.keysMap[SDLK_DOWN] = NEngine::KEY_BACK;
  engine.keysMap[SDLK_a] = NEngine::KEY_LEFT;
  engine.keysMap[SDLK_LEFT] = NEngine::KEY_LEFT;
  engine.keysMap[SDLK_d] = NEngine::KEY_RIGHT;
  engine.keysMap[SDLK_RIGHT] = NEngine::KEY_RIGHT;
  engine.keysMap[SDLK_q] = NEngine::KEY_DOWN;
  engine.keysMap[SDLK_e] = NEngine::KEY_UP;
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
  engine.timer = SDL_AddTimer(NEngine::REDRAW_TIMER_MS, staticOnTimeout, &context);
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
    if(event.type == SDL_WINDOWEVENT)
    {
      uint32 type = event.window.windowID;

      if((type == SDL_WINDOWEVENT_SHOWN) || (type == SDL_WINDOWEVENT_EXPOSED))
        simulationStep();
      else if(type == SDL_WINDOWEVENT_RESIZED)
        window->resizeGL(event.window.data1, event.window.data2);
    }
    else if(event.type == SDL_QUIT)
      break;
    else if(event.type == SDL_MOUSEBUTTONDOWN)
      mousePress(getMouseButton(event.button.button));
    else if(event.type == SDL_MOUSEBUTTONUP)
      mouseRelease(getMouseButton(event.button.button));
    else if(event.type == SDL_MOUSEMOTION)
      mouseMove(SPoint(event.motion.x, event.motion.y), getMouseButton(event.button.button));
    else if(event.type == SDL_KEYDOWN)
      keyPress(getKey(event.key.keysym.sym));
    else if(event.type == SDL_KEYUP)
      keyRelease(getKey(event.key.keysym.sym));
  }

  return 0;
}
#endif
//------------------------------------------------------------------------------
void CEngine::simulationStep()
{
  std::cout << "simulationStep\n";
  context.getCamera()->setMove();
  window->repaint();
}
//------------------------------------------------------------------------------
void CEngine::onTimeout()
{
  std::cout << "onTimeout\n";
#ifdef ENV_SDL
  SDL_RemoveTimer(engine.timer);
#endif

  updateTicks();

  if((isKeyForDelayedRendering()) || (engine.activeRendering))
  {
    std::cout << "repaintWindow\n";
#if defined(ENV_QT)
    simulationStep();
#elif defined(ENV_SDL)
    SDL_Event event;
    event.type = SDL_WINDOWEVENT_EXPOSED;
    SDL_PushEvent(&event);
#endif
  }

#if defined(ENV_QT)
  QTimer::singleShot(NEngine::REDRAW_TIMER_MS, this, SLOT(onTimeout()));
#elif defined(ENV_SDL)
  engine.timer = SDL_AddTimer(NEngine::REDRAW_TIMER_MS, staticOnTimeout, &context);
#endif
}
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
void CEngine::mouseMove(const SPoint &point, NEngine::EMouseButton buttons)
{
  if(buttons & NEngine::MOUSE_BTN_RIGHT)
  {
    std::cout << "mouseMove\n";
    engine.cursor = glm::vec2(static_cast<float>(point.x), static_cast<float>(point.x));
    context.getCamera()->setRotate();
    engine.cursorOld = engine.cursor;
    window->repaint();
  }
}
//------------------------------------------------------------------------------
void CEngine::keyPress(NEngine::EKey key)
{
  if(key & NEngine::KEY_QUIT)
    quit();

  engine.keys = static_cast<NEngine::EKey>(static_cast<uint32>(engine.keys) | static_cast<uint32>(key));
}
//------------------------------------------------------------------------------
void CEngine::keyRelease(NEngine::EKey key)
{
  engine.keys = static_cast<NEngine::EKey>(static_cast<uint32>(engine.keys) & (~static_cast<uint32>(key)));
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
bool CEngine::isKeyForDelayedRendering() const
{
  if((engine.keys & NEngine::KEY_FRONT) ||
     (engine.keys & NEngine::KEY_BACK) ||
     (engine.keys & NEngine::KEY_LEFT) ||
     (engine.keys & NEngine::KEY_RIGHT) ||
     (engine.keys & NEngine::KEY_UP) ||
     (engine.keys & NEngine::KEY_DOWN))
    return true;
  
  return false;
}
//------------------------------------------------------------------------------
NEngine::EMouseButton CEngine::getMouseButton(int32 button) const
{
  return static_cast<NEngine::EMouseButton>(
    ((button == SDL_BUTTON_LEFT) ? NEngine::MOUSE_BTN_LEFT : NEngine::MOUSE_BTN_NO) |
    ((button == SDL_BUTTON_RIGHT) ? NEngine::MOUSE_BTN_RIGHT : NEngine::MOUSE_BTN_NO));
}
//------------------------------------------------------------------------------
NEngine::EKey CEngine::getKey(int32 key) const
{
  std::cout << "getKey " << key << "\n";
  auto it = engine.keysMap.find(key);

  if(it == engine.keysMap.cend())
    return NEngine::KEY;

  return it->second;
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
