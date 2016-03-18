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

  static const uint32 INIT_LOAD_TIMER_MS = 100;

  static const uint32 DEFAULT_SCREEN_WIDTH = 1024;
  static const uint32 DEFAULT_SCREEN_HEIGHT = 600;
  static const uint32 DEFAULT_MULTISAMPLING = 4;
  static const uint32 MAX_TEXTURE_SIZE = 0;

  static const uint32 SHADOW_TEXTURE_SIZE = 256;
  static const uint32 SHADOW_CASCADES_COUNT = 1;
  static const float SHADOW_JITTERING = 2.0f;

  static const uint32 GEOMETRY_TEXTURE_SIZE = 32;

  static const float LPV_TEXTURE_SIZE_X = 32.0f;
  static const float LPV_TEXTURE_SIZE_Y = 32.0f;
  static const float LPV_TEXTURE_SIZE_Z = 32.0f;
  static const uint32 LPV_PROPAGATION_STEPS = 5;
  static const float LPV_INTENSITY = 1.0f;
  static const uint32 LPV_MODES_COUNT = 3;
  static const uint32 LPV_TECHNIQUES_COUNT = 2;
  static const uint32 LPV_SH_COUNT = 4;
  static const uint32 LPV_CASCADES_COUNT = 1;
  static const uint32 LPV_SUN_SKY_DIRS_COUNT = 1; // sun + sky
  static const float LPV_CUBE_LENGTH = 1.74f;

  static const float SHADOW_CASCADES_CLIPS[SHADOW_CASCADES_COUNT * NMath::VEC2] =
  {
    2.0f, 50.0f
    /*2.0f, 50.0f, // side, depth
    5.0f, 100.0f,
    10.0f, 150.0f,
    25.0f, 200.0f,
    80.0f, 250.0f,
    160.0f, 300.0f*/
  };

  static const float GEOMETRY_CASCADES_CLIPS[LPV_CASCADES_COUNT * LPV_SUN_SKY_DIRS_COUNT * NMath::VEC2] =
  {
    16.0f * LPV_CUBE_LENGTH, 50.0f
    /*2.0f * LPV_CUBE_LENGTH, 50.0f, // side, depth
    5.0f * LPV_CUBE_LENGTH, 100.0f,
    10.0f * LPV_CUBE_LENGTH, 150.0f,
    25.0f * LPV_CUBE_LENGTH, 200.0f,
    80.0f * LPV_CUBE_LENGTH, 250.0f,
    160.0f * LPV_CUBE_LENGTH, 300.0f*/
  };

  static const float SUN_SKY_POSES[NEngine::LPV_SUN_SKY_DIRS_COUNT * NMath::VEC2] =
  {
    0.0f, 0.0f
  };

  static const float SUN_SKY_COLORS[NEngine::LPV_SUN_SKY_DIRS_COUNT * NMath::VEC3] =
  {
    0.0f, 0.0f, 0.0f
  };

  static const float LPV_CELL_SIZES[LPV_CASCADES_COUNT * NMath::VEC3] =
  {
    1.0f, 1.0f, 1.0f
    /*0.1f, 0.1f, 0.1f,
    0.3f, 0.3f, 0.3f,
    0.8f, 0.8f, 0.8f,
    2.0f, 2.0f, 2.0f,
    6.0f, 6.0f, 6.0f,
    20.0f, 20.0f, 20.0f*/
  };

  static const char STR_APP_NAME[] = "Light Propagation Volumes";

  static const char *const STR_LPV_MODES[] = { "Disabled", "GL 3.2+ - Geometry Shader", "GL 4.3+ - Compute Shader" };
  static const char *const STR_LPV_TECHNIQUES[] = { "Gathering", "Scattering" };

  static const char STR_SUN_SHADOW_FBO[] = "sunShadow";
  static const char STR_SUN_SHADOW_FBO_MAP[] = "sunShadow_0";
  static const char STR_GEOMETRY_FBO[] = "geometry";
  static const char STR_GEOMETRY_FBO_AMB_MAP[] = "geometry_0";
  static const char STR_GEOMETRY_FBO_POS_MAP[] = "geometry_1";
  static const char STR_GEOMETRY_FBO_NORMAL_MAP[] = "geometry_2";
  //static const char STR_GEOMETRY_FBO_DEPTH_MAP[] = "geometry_3";

  static const char STR_LPV0_GS_FBO[] = "lpv0Tex"; // gl 3.2 fbo swap propagation textures - 2
  static const char STR_LPV1_GS_FBO[] = "lpv1Tex";
  static const char STR_LPV0_GS_MAP_R[] = "lpv0Tex_0";
  static const char STR_LPV0_GS_MAP_G[] = "lpv0Tex_1";
  static const char STR_LPV0_GS_MAP_B[] = "lpv0Tex_2";
  static const char STR_LPV1_GS_MAP_R[] = "lpv1Tex_0";
  static const char STR_LPV1_GS_MAP_G[] = "lpv1Tex_1";
  static const char STR_LPV1_GS_MAP_B[] = "lpv1Tex_2";
  static const char STR_GV0_GS_MAP[] = "lpv0Tex_3";
  static const char STR_GV1_GS_MAP[] = "lpv1Tex_3";

  static const char STR_LPV0_CS_IMG_R[] = "lpv0Img_0"; // gl 4.3 swap propagation images - 2
  static const char STR_LPV0_CS_IMG_G[] = "lpv0Img_1";
  static const char STR_LPV0_CS_IMG_B[] = "lpv0Img_2";
  static const char STR_LPV1_CS_IMG_R[] = "lpv1Img_0";
  static const char STR_LPV1_CS_IMG_G[] = "lpv1Img_1";
  static const char STR_LPV1_CS_IMG_B[] = "lpv1Img_2";
  static const char STR_GV_CS_IMG[] = "lpvImg_3";

  static const char STR_APP_TITLE[] = "Light Propagation Volumes (Pos: %f %f %f, Draw calls: %d)";
  static const char STR_SELECT_GL_PLATFORM[] = "Selected OpenGL version: %s.";

  static const char STR_ERROR_INIT_SDL[] = "Unable to init SDL";
  static const char STR_ERROR_INIT_WINDOW[] = "Unable to init window";
  static const char STR_ERROR_INIT_GL_CONTEXT[] = "Unable to init OpenGL context";
  static const char STR_ERROR_INIT_IMG_JPG[] = "Unable to init SDL Image: JPG";
  static const char STR_ERROR_INIT_IMG_PNG[] = "Unable to init SDL Image: PNG";
  static const char STR_ERROR_INIT_GLEW[] = "Unable to init GLEW";
  static const char STR_ERROR_INIT_GL_PLATFORM[] = "Unable to setup OpenGL version: 3.2";

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
    EFLAG              = 0x00,
    EFLAG_SHOW_CONSOLE = 0x01,
    EFLAG_MAXIMIZED    = 0x02,
    EFLAG_FULLSCREEN   = 0x04,
  };

  enum EGPUPlatform
  {
    GPU_PLATFORM_KEEP   = 0,

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

    GPU_PLATFORM_MAX    = 0xffff,
  };

  enum ELPVMode
  {
    LPV_MODE_DISABLED = 0,
    LPV_MODE_GEOMETRY,
    LPV_MODE_COMPUTE
  };

  enum ELPVTechnique
  {
    LPV_TECHNIQUE_GATHERING = 0,
    LPV_TECHNIQUE_SCATTERING
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

    KEY_LPV_MODE              = 0x00001000,
    KEY_LPV_TECHNIQUE         = 0x00002000,
    KEY_LPV_PROPAGATION_DOWN  = 0x00004000,
    KEY_LPV_PROPAGATION_UP    = 0x00008000,
    KEY_LPV_INTENSITY_DOWN    = 0x00010000,
    KEY_LPV_INTENSITY_UP      = 0x00020000,
    KEY_SHADOW_JITTERING_DOWN = 0x00040000,
    KEY_SHADOW_JITTERING_UP   = 0x00080000,

    KEY_FRUSTUM_UPDATE        = 0x10000000,
    KEY_SHOW_GEOMETRY_BUFFERS = 0x20000000,
    KEY_SHOW_SHADOW_BUFFERS   = 0x40000000,

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
  NEngine::ELPVMode lpvMode;
  NEngine::ELPVTechnique lpvTechnique;

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
  bool showShadowBuffer;
  uint32 defaultScreenWidth;
  uint32 defaultScreenHeight;

  uint8 multisampling;
  uint32 maxTextureSize;

  uint32 shadowTextureSize;
  float shadowJittering;
  //glm::vec3 shadowPoses[NEngine::SHADOW_CASCADES_COUNT];
  glm::mat4 shadowViewProj[NEngine::SHADOW_CASCADES_COUNT]; // shadow proj * view, used: mesh render - shadow cascade draw (mpv), out mesh draw (mpvsb[])

  uint32 geometryTextureSize;
  glm::mat4 geometryViewProj[NEngine::LPV_CASCADES_COUNT * NEngine::LPV_SUN_SKY_DIRS_COUNT]; // geometry proj * view, used: mesh render - geom cascade draw (mvp)

  float sunSkyPoses[NEngine::LPV_SUN_SKY_DIRS_COUNT * NMath::VEC2]; // lpv injection, light data
  float sunSkyColors[NEngine::LPV_SUN_SKY_DIRS_COUNT * NMath::VEC3];

  glm::vec3 lpvTextureSize;
  uint32 lpvPropagationSteps;
  bool lpvPropagationSwap;
  float lpvIntensity;
  glm::vec3 lpvPoses[NEngine::LPV_CASCADES_COUNT];
  float lpvPosesOut[NEngine::LPV_CASCADES_COUNT * NMath::VEC3]; // lpv inject, propagate, out mesh draw

#if defined(ENV_QT)
  QElapsedTimer timer;
#elif defined(ENV_SDL)
  std::vector<SDL_TimerID> timers;
  SDL_TimerID initSceneTimer;
  uint32 initSceneEvent;
#endif
  bool waitForFlushTimers;

  inline SEngine() :
    activeRendering(false),
    flags(NEngine::EFLAG_MAXIMIZED),
    gpuPlatform(NEngine::GPU_PLATFORM_MAX),
    lpvMode(NEngine::LPV_MODE_COMPUTE),
    lpvTechnique(NEngine::LPV_TECHNIQUE_SCATTERING),

    keys(NEngine::KEY),

    tickOld(0),
    tickNew(0),
    simulationStep(1.0),
    fps(0.0),
    fpsCounter(0),

    drawCalls(0),

    updateFrustum(true),
    showGeometryBuffer(false),
    showShadowBuffer(false),
    defaultScreenWidth(NEngine::DEFAULT_SCREEN_WIDTH),
    defaultScreenHeight(NEngine::DEFAULT_SCREEN_HEIGHT),

    multisampling(NEngine::DEFAULT_MULTISAMPLING),
    maxTextureSize(NEngine::MAX_TEXTURE_SIZE),

    shadowTextureSize(NEngine::SHADOW_TEXTURE_SIZE),
    shadowJittering(NEngine::SHADOW_JITTERING),

    geometryTextureSize(NEngine::GEOMETRY_TEXTURE_SIZE),

    lpvTextureSize(NEngine::LPV_TEXTURE_SIZE_X, NEngine::LPV_TEXTURE_SIZE_Y, NEngine::LPV_TEXTURE_SIZE_Z),
    lpvPropagationSteps(NEngine::LPV_PROPAGATION_STEPS),
    lpvPropagationSwap(false),
    lpvIntensity(NEngine::LPV_INTENSITY),
    
#ifdef ENV_SDL
    initSceneTimer(0),
    initSceneEvent(0),
#endif
    waitForFlushTimers(false)
  {
    memcpy(sunSkyPoses, NEngine::SUN_SKY_POSES, sizeof(float) * NEngine::LPV_SUN_SKY_DIRS_COUNT * NMath::VEC2);
    memcpy(sunSkyColors, NEngine::SUN_SKY_COLORS, sizeof(float) * NEngine::LPV_SUN_SKY_DIRS_COUNT * NMath::VEC3);
    memset(lpvPosesOut, 0, sizeof(float) * NEngine::LPV_CASCADES_COUNT * NMath::VEC3);

    for(uint32 i = 0; i < NEngine::SHADOW_CASCADES_COUNT; i++)
    {
      //shadowPoses[i] = glm::vec3(0.0f, 0.0f, 0.0f);
      shadowViewProj[i] = glm::mat4();
    }

    for(uint32 i = 0; i < NEngine::LPV_CASCADES_COUNT * NEngine::LPV_SUN_SKY_DIRS_COUNT; i++)
      geometryViewProj[i] = glm::mat4();

    for(uint32 i = 0; i < NEngine::LPV_CASCADES_COUNT; i++)
      lpvPoses[i] = glm::vec3(0.0f, 0.0f, 0.0f);
  }
};
//-----------------------------------------------------------------------------
#endif // ENGINETYPES_H
