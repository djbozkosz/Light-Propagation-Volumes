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
  static const float SCALE_Y =  1.0f;
  static const float SCALE_Z =  1.0f;

  static const float MOVEMENT_SPEED = 1.0f;
  static const float SENSITIVITY_SPEED = 1.0f;

  enum EProjection
  {
    PROJ_PERSPECTIVE = 0,
    PROJ_ORTOGRAPHIC
  };
}
//-----------------------------------------------------------------------------
struct SCamera
{
  glm::vec4 position;
  glm::vec4 rotation;

  float width;
  float height;

  NCamera::EProjection projType;

  float clipNear;
  float clipFar;
  float clipLeft;
  float clipRight;
  float clipTop;
  float clipBottom;

  float fov;

  glm::mat4 projection;
  glm::mat4 view;
  glm::mat4 viewProjection;

  SCamera() : position(0.0, 0.0, 0.0, NCamera::MOVEMENT_SPEED), rotation(0.0, 0.0, 0.0, NCamera::SENSITIVITY_SPEED), width(1.0), height(1.0), projType(NCamera::PROJ_PERSPECTIVE), clipNear(NCamera::CLIP_NEAR), clipFar(NCamera::CLIP_FAR), clipLeft(0.0f), clipRight(0.0f), clipTop(0.0f), clipBottom(0.0f), fov(NCamera::FOV) {}
};
//-----------------------------------------------------------------------------
#endif // CAMERATYPES_H
