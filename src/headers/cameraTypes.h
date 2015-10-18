//-----------------------------------------------------------------------------
#ifndef CAMERATYPES_H
#define CAMERATYPES_H

#include <glm/glm.hpp>

#include "math.h"

//------------------------------------------------------------------------------
namespace NCamera
{
  static const float CLIP_NEAR = 0.1f;
  static const float CLIP_FAR = 1000.0f;
  static const float CLIP_BACKDROP_NEAR = 10.0f;
  static const float CLIP_BACKDROP_FAR = 10000.0f;
  static const float FOV = 60.0f;

  static const float SCALE_X = -1.0f;
  static const float SCALE_Y = 1.0f;
  static const float SCALE_Z = 1.0f;

  static const uint8 CURSOR_COUNTER_MAX = 3;

  static const uint8 KEYS_COUNT = 6;
  static const float MOVEMENT_SPEED = 1.0f;
  static const float SENSITIVITY_SPEED = 1.0f;

  static const uint32 REDRAW_TIMER_MS = 17;
  static const float FPS_MS = 0.001f;
  static const uint8 FPS_COUNTER_MAX = 10;

  static const int32 TOUCH_MOVE_ID_NONE = -1;

  enum ECameraKeys
  {
    KEY_F = 0,
    KEY_B,
    KEY_L,
    KEY_R,
    KEY_D,
    KEY_U
  };
}
//-----------------------------------------------------------------------------
struct SCamera
{
  bool keys[NCamera::KEYS_COUNT];
  bool active;

  glm::vec4 position;
  glm::vec4 rotation;

  float width;
  float height;

  glm::vec2 cursor;
  glm::vec2 cursorOld;
  glm::vec2 cursorDir; // normalized
  int32 cursorCounter;

  uint32 tickOld;
  uint32 tickNew;
  float simulationStep;
  float fps;
  uint32 fpsCounter;

  uint32 drawCalls;

  float clipNear;
  float clipFar;
  float fov;

  glm::mat4 projection;
  glm::mat4 view;
  glm::mat4 viewProjection;

  SCamera() : active(false), position(0.0, 0.0, 0.0, NCamera::MOVEMENT_SPEED), rotation(0.0, 0.0, 0.0, NCamera::SENSITIVITY_SPEED), width(1.0), height(1.0), cursorCounter(0), tickOld(0), tickNew(0), simulationStep(1.0), fps(0.0), fpsCounter(0), drawCalls(0), clipNear(NCamera::CLIP_NEAR), clipFar(NCamera::CLIP_FAR), fov(NCamera::FOV)
  {
    memset(keys, 0, sizeof(bool) * NCamera::KEYS_COUNT);
  }
};
//-----------------------------------------------------------------------------
#endif // CAMERATYPES_H
