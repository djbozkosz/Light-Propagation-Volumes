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
  static const uint8 KEYS_COUNT = 6;

  static const uint32 REDRAW_TIMER_MS = 17;
  static const float FPS_MS = 0.001f;
  static const uint8 FPS_COUNTER_MAX = 10;

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

  enum EKeys
  {
    KEY_F = 0,
    KEY_B,
    KEY_L,
    KEY_R,
    KEY_D,
    KEY_U
  };

  enum EEngineClasses
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

  glm::vec2 cursor;
  glm::vec2 cursorOld;

  bool keys[NEngine::KEYS_COUNT];

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

  inline SEngine() : activeRendering(false), delayedRendering(false), finishedRendering(false), tickOld(0), tickNew(0), simulationStep(1.0), fps(0.0), fpsCounter(0), drawCalls(0)
  {
    memset(keys, 0, sizeof(bool) * NEngine::KEYS_COUNT);
  }
};
//-----------------------------------------------------------------------------
#endif // ENGINETYPES_H
