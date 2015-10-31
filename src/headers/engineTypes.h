//-----------------------------------------------------------------------------
#ifndef ENGINETYPES_H
#define ENGINETYPES_H

#include <string>
#include <vector>
#include <list>
#include <map>

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

  static const uint32 DEFAULT_SCREEN_WIDTH = 1024;
  static const uint32 DEFAULT_SCREEN_HEIGHT = 600;
  static const uint32 MAX_TEXTURE_SIZE = 0;
  static const uint32 MAX_DEPTH_TEXTURE_SIZE = 2048;
  static const uint32 ORTHO_DEPTH_SIZE = 32.0f;
  static const uint32 ORTHO_DEPTH_DEPTH = 200.0f;
  static const uint32 SHADOW_JITTERING = 2.0f;

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

  enum EEngineFlags
  {
    EFLAG = 0x00,
    EFLAG_SHOW_CONSOLE = 0x01,
    EFLAG_MAXIMIZED = 0x02,
    EFLAG_FULLSCREEN = 0x04,
  };

  enum EKey
  {
    KEY = 0x0000,

    KEY_FRONT        = 0x0001,
    KEY_BACK         = 0x0002,
    KEY_LEFT         = 0x0004,
    KEY_RIGHT        = 0x0008,
    KEY_DOWN         = 0x0010,
    KEY_UP           = 0x0020,

    KEY_SPECIAL_FRONT = 0x0040,
    KEY_SPECIAL_BACK  = 0x0080,
    KEY_SPECIAL_LEFT  = 0x0100,
    KEY_SPECIAL_RIGHT = 0x0200,
    KEY_SPECIAL_DOWN  = 0x0400,
    KEY_SPECIAL_UP    = 0x0800,

    KEY_QUIT         = 0x1000
  };

  enum EMouseButton
  {
    MOUSE_BTN = 0x00,
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
  uint8 flags;

  glm::vec2 cursor;
  glm::vec2 cursorOld;

  NEngine::EKey keys;
  std::map<uint32, NEngine::EKey> keysMap;

  uint32 tickOld;
  uint32 tickNew;
  float simulationStep;
  float fps;
  uint32 fpsCounter;

  uint32 drawCalls;

  uint32 defaultScreenWidth;
  uint32 defaultScreenHeight;

  uint32 maxTextureSize;
  uint32 maxDepthTextureSize;
  float orthoDepthSize;
  float orthoDepthDepth;
  float shadowJittering;

#if defined(ENV_QT)
  QElapsedTimer timer;
#elif defined(ENV_SDL)
  std::vector<SDL_TimerID> timers;
#endif

  inline SEngine() : activeRendering(false), flags(NEngine::EFLAG_MAXIMIZED), keys(NEngine::KEY), tickOld(0), tickNew(0), simulationStep(1.0), fps(0.0), fpsCounter(0), drawCalls(0), defaultScreenWidth(NEngine::DEFAULT_SCREEN_WIDTH), defaultScreenHeight(NEngine::DEFAULT_SCREEN_HEIGHT), maxTextureSize(NEngine::MAX_TEXTURE_SIZE), maxDepthTextureSize(NEngine::MAX_DEPTH_TEXTURE_SIZE), orthoDepthSize(NEngine::ORTHO_DEPTH_SIZE), orthoDepthDepth(NEngine::ORTHO_DEPTH_DEPTH), shadowJittering(NEngine::SHADOW_JITTERING) {}
};
//-----------------------------------------------------------------------------
#endif // ENGINETYPES_H
