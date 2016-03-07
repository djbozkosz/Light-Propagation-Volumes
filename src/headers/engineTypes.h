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
  static const uint32 DEFAULT_MULTISAMPLING = 4;
  static const uint32 MAX_TEXTURE_SIZE = 0;
  static const uint32 DEPTH_TEXTURE_SIZE = 2048;
  static const uint32 GEOMETRY_TEXTURE_SIZE = 32;
  static const float LPV_POS_X = 0.0f;
  static const float LPV_POS_Y = 0.0f;
  static const float LPV_POS_Z = 0.0f;
  static const float LPV_TEXTURE_SIZE_X = 32.0f;
  static const float LPV_TEXTURE_SIZE_Y = 32.0f;
  static const float LPV_TEXTURE_SIZE_Z = 32.0f;
  static const float LPV_CELL_SIZE_X = 1.0f;
  static const float LPV_CELL_SIZE_Y = 1.0f;
  static const float LPV_CELL_SIZE_Z = 1.0f;
  static const uint32 LPV_PROPAGATION_STEPS = 5;
  static const float LPV_INTENSITY = 1.0f;
  static const float ORTHO_DEPTH_SIZE = 32.0f;
  static const float ORTHO_DEPTH_DEPTH = 200.0f;
  static const float SHADOW_JITTERING = 2.0f;

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

  enum EGPUPlatform
  {
    GPU_PLATFORM_KEEP = 0,

    GPU_PLATFORM_GL0100 = 0100,
    GPU_PLATFORM_GL0101 = 0101,
    GPU_PLATFORM_GL0102 = 0102,
    GPU_PLATFORM_GL0103 = 0103,
    GPU_PLATFORM_GL0104 = 0104,
    GPU_PLATFORM_GL0105 = 0105,
    GPU_PLATFORM_GL0200 = 0200,
    GPU_PLATFORM_GL0200_ES = 0200,
    GPU_PLATFORM_GL0201 = 0201,
    GPU_PLATFORM_GL0300 = 0300,
    GPU_PLATFORM_GL0301 = 0301,
    GPU_PLATFORM_GL0302 = 0302,
    GPU_PLATFORM_GL0303 = 0303,
    GPU_PLATFORM_GL0400 = 0400,
    GPU_PLATFORM_GL0401 = 0401,
    GPU_PLATFORM_GL0402 = 0402,
    GPU_PLATFORM_GL0403 = 0403,
    GPU_PLATFORM_GL0404 = 0404,
    GPU_PLATFORM_GL0405 = 0405,

    GPU_PLATFORM_MAX = 0xffff,
  };

  enum EKey
  {
    KEY                       = 0x00000000,

    KEY_FRONT                 = 0x00000001,
    KEY_BACK                  = 0x00000002,
    KEY_LEFT                  = 0x00000004,
    KEY_RIGHT                 = 0x00000008,
    KEY_DOWN                  = 0x00000010,
    KEY_UP                    = 0x00000020,

    KEY_SPECIAL_FRONT         = 0x00000040,
    KEY_SPECIAL_BACK          = 0x00000080,
    KEY_SPECIAL_LEFT          = 0x00000100,
    KEY_SPECIAL_RIGHT         = 0x00000200,
    KEY_SPECIAL_DOWN          = 0x00000400,
    KEY_SPECIAL_UP            = 0x00000800,

    KEY_LPV_PROPAGATION_DOWN  = 0x00001000,
    KEY_LPV_PROPAGATION_UP    = 0x00002000,
    KEY_LPV_INTENSITY_DOWN    = 0x00004000,
    KEY_LPV_INTENSITY_UP      = 0x00008000,
    KEY_SHADOW_JITTERING_DOWN = 0x00010000,
    KEY_SHADOW_JITTERING_UP   = 0x00020000,

    KEY_FRUSTUM_UPDATE        = 0x10000000,
    KEY_SHOW_GEOMETRY_BUFFER  = 0x20000000,
    KEY_SHOW_LPV              = 0x40000000,

    KEY_QUIT                  = 0x80000000
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
  NEngine::EGPUPlatform gpuPlatform;

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

  bool updateFrustum;
  bool showGeometryBuffer;
  bool showLPV;
  uint32 defaultScreenWidth;
  uint32 defaultScreenHeight;

  uint8 multisampling;
  uint32 maxTextureSize;
  uint32 depthTextureSize;
  uint32 geometryTextureSize;
  glm::vec3 lpvPos;
  glm::vec3 lpvTextureSize;
  glm::vec3 lpvCellSize;
  uint32 lpvPropagationSteps;
  float lpvIntensity;
  float orthoDepthSize;
  float orthoDepthDepth;
  float shadowJittering;

#if defined(ENV_QT)
  QElapsedTimer timer;
#elif defined(ENV_SDL)
  std::vector<SDL_TimerID> timers;
#endif
  bool waitForFlushTimers;

  inline SEngine() :
    activeRendering(false),
    flags(NEngine::EFLAG_MAXIMIZED),
    gpuPlatform(NEngine::GPU_PLATFORM_MAX),
    keys(NEngine::KEY),
    tickOld(0),
    tickNew(0),
    simulationStep(1.0),
    fps(0.0),
    fpsCounter(0),
    drawCalls(0),
    updateFrustum(true),
    showGeometryBuffer(false),
    showLPV(true),
    defaultScreenWidth(NEngine::DEFAULT_SCREEN_WIDTH),
    defaultScreenHeight(NEngine::DEFAULT_SCREEN_HEIGHT),
    multisampling(NEngine::DEFAULT_MULTISAMPLING),
    maxTextureSize(NEngine::MAX_TEXTURE_SIZE),
    depthTextureSize(NEngine::DEPTH_TEXTURE_SIZE),
    geometryTextureSize(NEngine::GEOMETRY_TEXTURE_SIZE),
    lpvPos(NEngine::LPV_POS_X, NEngine::LPV_POS_Y, NEngine::LPV_POS_Z),
    lpvTextureSize(NEngine::LPV_TEXTURE_SIZE_X, NEngine::LPV_TEXTURE_SIZE_Y, NEngine::LPV_TEXTURE_SIZE_Z),
    lpvCellSize(NEngine::LPV_CELL_SIZE_X, NEngine::LPV_CELL_SIZE_Y, NEngine::LPV_CELL_SIZE_Z),
    lpvPropagationSteps(NEngine::LPV_PROPAGATION_STEPS),
    lpvIntensity(NEngine::LPV_INTENSITY),
    orthoDepthSize(NEngine::ORTHO_DEPTH_SIZE),
    orthoDepthDepth(NEngine::ORTHO_DEPTH_DEPTH),
    shadowJittering(NEngine::SHADOW_JITTERING),
    waitForFlushTimers(false) {}
};
//-----------------------------------------------------------------------------
#endif // ENGINETYPES_H
