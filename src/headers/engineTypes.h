//-----------------------------------------------------------------------------
#ifndef ENGINETYPES_H
#define ENGINETYPES_H

#include <string>
#include <vector>

#if defined(ENV_QT)
#include <QElapsedTimer>
#elif defined(ENV_SDL)
#include <SDL2/SDL.h>
#endif

#include "types.h"

//-----------------------------------------------------------------------------
namespace NEngine
{
  static const uint32 REDRAW_TIMER_MS = 17;
  static const float FPS_MS = 0.001f;
  static const uint8 FPS_COUNTER_MAX = 10;

  static const char STR_APP_NAME[] = "Light Propagation Volumes";

  static const char *const STR_ENGINE_CLASSES[] =
  {
    "Camera",
    "Context",
    "Culling",
    "Engine",
    "Engine Base",
    "File",
    "Filesystem",
    "Framebuffer",
    "Map",
    "Maps",
    "Model",
    "Models",
    "OpenGL",
    "Pick Color",
    "Renderer",
    "Scene",
    "Scenes",
    "Shader",
    "Shader Program",
    "Shaders",
    "Str",
  };

  enum EKey
  {
    KEY = 0x01,
    KEY_FRONT = 0x01,
    KEY_BACK = 0x02,
    KEY_LEFT = 0x04,
    KEY_RIGHT = 0x08,
    KEY_DOWN = 0x10,
    KEY_UP = 0x11
  };

  enum EMouseButton
  {
    MOUSE_BTN_NO = 0x00,
    MOUSE_BTN_LEFT = 0x01,
    MOUSE_BTN_RIGHT = 0x02
  };

  enum EEngineClass
  {
    ENGINE_CAMERA = 0,
    ENGINE_CONTEXT,
    ENGINE_CULLING,
    ENGINE_ENGINE,
    ENGINE_ENGINE_BASE,
    ENGINE_FILE,
    ENGINE_FILESYSTEM,
    ENGINE_FRAMEBUFFER,
    ENGINE_MAP,
    ENGINE_MAPS,
    ENGINE_MODEL,
    ENGINE_MODELS,
    ENGINE_OPENGL,
    ENGINE_PICK_COLOR,
    ENGINE_RENDERER,
    ENGINE_SCENE,
    ENGINE_SCENES,
    ENGINE_SHADER,
    ENGINE_SHADER_PROGRAM,
    ENGINE_SHADERS,
    ENGINE_STR
  };
}
//-----------------------------------------------------------------------------
struct SEngine
{
  bool activeRendering;
  bool delayedRendering;
  bool finishedRendering;

  bool fullscreen;
  bool consoleVisible;

  glm::vec2 cursor;
  glm::vec2 cursorOld;

  NEngine::EKey keysMovement;

  uint32 tickOld;
  uint32 tickNew;
  float simulationStep;
  float fps;
  uint32 fpsCounter;

  uint32 drawCalls;

#if defined(ENV_QT)
  QElapsedTimer timer;
#elif defined(ENV_SDL)
  SDL_TimerID timer;
#endif
  //std::vector<SDL_TimerID> timers;

  inline SEngine() : activeRendering(false), delayedRendering(false), finishedRendering(false), fullscreen(false), consoleVisible(false), keysMovement(NEngine::KEY), tickOld(0), tickNew(0), simulationStep(1.0), fps(0.0), fpsCounter(0), drawCalls(0) {}
};
//-----------------------------------------------------------------------------
#endif // ENGINETYPES_H
