//------------------------------------------------------------------------------
#ifndef CAMERA_H
#define CAMERA_H

#if defined(ENV_QT)
#include <QElapsedTimer>
#elif defined(ENV_SDL)
#include <SDL2/SDL.h>
#endif

#include "openGL.h"
#include "headers/cameraTypes.h"

//------------------------------------------------------------------------------
class CCamera : public CEngineBase
{
  private:
    SCamera camera;
#if defined(ENV_QT)
    QElapsedTimer timer;
#elif defined(ENV_SDL)
    SDL_TimerID timer;
#endif

  public:
    inline CCamera() : CEngineBase() {}
    CCamera(CContext *context);
    inline ~CCamera() {}

    void updateMatrices();

    inline void setActive(bool active) { camera.active = active; }

    inline void setCamera(const SCamera &camera) { this->camera = camera; updateMatrices(); }
    inline void setSize(float width, float height) { camera.width = width; camera.height = height; updateMatrices(); }
    inline void setRange(float clipNear, float clipFar) { camera.clipNear = clipNear; camera.clipFar = clipFar; updateMatrices(); }
    inline void setFov(float fov) { camera.fov = fov; updateMatrices(); }

    inline void setPosition(glm::vec3 position) { camera.position.x = position.x; camera.position.y = position.y; camera.position.z = position.z; updateMatrices(); }
    bool setMove();
    inline void setRotation(glm::vec3 rotation) { camera.rotation.x = rotation.x; camera.rotation.y = rotation.y; camera.rotation.z = rotation.z; updateMatrices(); }
    void setRotate(int32 x, int32 y, bool active);
    void setHover(int32 x = 0, int32 y = 0);
    inline void setKeys(const bool *keys) { memcpy(camera.keys, keys, sizeof(bool) * NCamera::KEYS_COUNT); }
    inline void setSpeed(float speed = NCamera::MOVEMENT_SPEED) { camera.position.w = speed; }
    inline void setSensitivity(float sensitivity = NCamera::SENSITIVITY_SPEED) { camera.rotation.w = sensitivity; }

    void updateTicks();
    inline void incDrawCalls() { camera.drawCalls++; }
    inline void clearDrawCalls() { camera.drawCalls = 0; }

    inline const SCamera *getCamera() const { return &camera; }
#if defined(ENV_QT)
    inline const QElapsedTimer *getTimer() const { return &timer; }
#elif defined(ENV_SDL)
    inline const SDL_TimerID *getTimer() const { return &timer; }
#endif
};
//------------------------------------------------------------------------------
inline CCamera::CCamera(CContext *context) : CEngineBase(context)
{
#if defined(ENV_QT)
  timer.start();
#elif defined(ENV_SDL)
  //timer;
#endif
}
//------------------------------------------------------------------------------
inline void CCamera::updateMatrices()
{
  camera.view = glm::scale(
    glm::translate(
      glm::rotate(
        glm::rotate(glm::mat4(1.0), camera.rotation.x * NMath::DEG_2_RAD, glm::vec3(1.0, 0.0, 0.0)),
        (camera.rotation.y + NMath::PI_RAD) * NMath::DEG_2_RAD, glm::vec3(0.0, 1.0, 0.0)),
      glm::vec3(camera.position.x * -NCamera::SCALE_X, camera.position.y * -NCamera::SCALE_Y, camera.position.z * -NCamera::SCALE_Z)),
    glm::vec3(NCamera::SCALE_X, NCamera::SCALE_Y, NCamera::SCALE_Z));
  camera.projection = glm::perspective(camera.fov * NMath::DEG_2_RAD, camera.width / camera.height, camera.clipNear, camera.clipFar);
  camera.viewProjection = camera.projection * camera.view;
}
//------------------------------------------------------------------------------
inline bool CCamera::setMove()
{
  bool ret = false;

  if(camera.keys[NCamera::KEY_F])
  {
    camera.position.x += camera.position.w * camera.simulationStep * sinf(camera.rotation.y * NMath::DEG_2_RAD) * cosf(camera.rotation.x * NMath::DEG_2_RAD);
    camera.position.y -= camera.position.w * camera.simulationStep * sinf(camera.rotation.x * NMath::DEG_2_RAD);
    camera.position.z += camera.position.w * camera.simulationStep * cosf(camera.rotation.y * NMath::DEG_2_RAD) * cosf(camera.rotation.x * NMath::DEG_2_RAD);
    ret = true;
  }
  else if(camera.keys[NCamera::KEY_B])
  {
    camera.position.x -= camera.position.w * camera.simulationStep * sinf(camera.rotation.y * NMath::DEG_2_RAD) * cosf(camera.rotation.x * NMath::DEG_2_RAD);
    camera.position.y += camera.position.w * camera.simulationStep * sinf(camera.rotation.x * NMath::DEG_2_RAD);
    camera.position.z -= camera.position.w * camera.simulationStep * cosf(camera.rotation.y * NMath::DEG_2_RAD) * cosf(camera.rotation.x * NMath::DEG_2_RAD);
    ret = true;
  }
  else if(camera.keys[NCamera::KEY_L])
  {
    camera.position.x -= camera.position.w * camera.simulationStep * cosf(camera.rotation.y * NMath::DEG_2_RAD);
    camera.position.z += camera.position.w * camera.simulationStep * sinf(camera.rotation.y * NMath::DEG_2_RAD);
    ret = true;
  }
  else if(camera.keys[NCamera::KEY_R])
  {
    camera.position.x += camera.position.w * camera.simulationStep * cosf(camera.rotation.y * NMath::DEG_2_RAD);
    camera.position.z -= camera.position.w * camera.simulationStep * sinf(camera.rotation.y * NMath::DEG_2_RAD);
    ret = true;
  }
  else if(camera.keys[NCamera::KEY_D])
  {
    camera.position.x -= camera.position.w * camera.simulationStep * sinf(camera.rotation.x * NMath::DEG_2_RAD) * sinf(camera.rotation.y * NMath::DEG_2_RAD);
    camera.position.y -= camera.position.w * camera.simulationStep * cosf(camera.rotation.x * NMath::DEG_2_RAD);
    camera.position.z -= camera.position.w * camera.simulationStep * sinf(camera.rotation.x * NMath::DEG_2_RAD) * cosf(camera.rotation.y * NMath::DEG_2_RAD);
    ret = true;
  }
  else if(camera.keys[NCamera::KEY_U])
  {
    camera.position.x += camera.position.w * camera.simulationStep * sinf(camera.rotation.x * NMath::DEG_2_RAD) * sinf(camera.rotation.y * NMath::DEG_2_RAD);
    camera.position.y += camera.position.w * camera.simulationStep * cosf(camera.rotation.x * NMath::DEG_2_RAD);
    camera.position.z += camera.position.w * camera.simulationStep * sinf(camera.rotation.x * NMath::DEG_2_RAD) * cosf(camera.rotation.y * NMath::DEG_2_RAD);
    ret = true;
  }

  if(ret)
    updateMatrices();

  return ret;
}
//------------------------------------------------------------------------------
inline void CCamera::setRotate(int32 x, int32 y, bool active)
{
  glm::vec2 v(static_cast<float>(x), static_cast<float>(y));

  if(active)
  {
    camera.cursor = camera.cursorOld - v;
    camera.rotation.x = camera.rotation.x - camera.cursor.x * camera.rotation.w;
    camera.rotation.y = camera.rotation.y - camera.cursor.y * camera.rotation.w;
    if(camera.rotation.x > NMath::PI_RAD)
      camera.rotation.x = camera.rotation.x - NMath::PI_2_RAD;
    if(camera.rotation.x < -NMath::PI_RAD)
      camera.rotation.x = camera.rotation.x + NMath::PI_2_RAD;
    if(camera.rotation.y > NMath::PI_RAD)
      camera.rotation.y = camera.rotation.y - NMath::PI_2_RAD;
    if(camera.rotation.y < -NMath::PI_RAD)
      camera.rotation.y = camera.rotation.y + NMath::PI_2_RAD;
    camera.rotation.z = 0.0;

    updateMatrices();
  }

  camera.cursorOld = v;
}
//------------------------------------------------------------------------------
inline void CCamera::updateTicks()
{
  camera.tickNew =
#if defined(ENV_QT)
    static_cast<uint32>(timer.elapsed());
#elif defined(ENV_SDL)
    SDL_GetTicks();
#endif

  if(!camera.tickOld)
    camera.tickOld = camera.tickNew;

  if((camera.tickNew != camera.tickOld) && (!camera.fpsCounter))
  {
    camera.simulationStep = static_cast<float>(camera.tickNew - camera.tickOld) * NCamera::FPS_MS / NCamera::FPS_COUNTER_MAX;
    camera.fps = 1.0f / camera.simulationStep;
    camera.tickOld = camera.tickNew;
  }
  camera.fpsCounter++;
  if(camera.fpsCounter == NCamera::FPS_COUNTER_MAX)
    camera.fpsCounter = 0;
}
//------------------------------------------------------------------------------
#endif // CAMERA_H
