//------------------------------------------------------------------------------
#ifndef CAMERA_H
#define CAMERA_H

#include "openGL.h"
#include "headers/cameraTypes.h"

//------------------------------------------------------------------------------
class CCamera : public CEngineBase
{
  private:
    SCamera camera;

  public:
    inline CCamera() : CEngineBase() {}
    inline CCamera(CContext *context) : CEngineBase(context) {}
    inline ~CCamera() {}

    void updateMatrices();

    inline void setCamera(const SCamera &camera) { this->camera = camera; updateMatrices(); }
    inline void setSize(float width, float height) { camera.width = width; camera.height = height; updateMatrices(); }
    inline void setRange(float clipNear, float clipFar, float clipLeft = 0.0f, float clipRight = 0.0f, float clipTop = 0.0f, float clipBottom = 0.0f) { camera.clipNear = clipNear; camera.clipFar = clipFar; camera.clipLeft = clipLeft; camera.clipRight = clipRight; camera.clipTop = clipTop; camera.clipBottom = clipBottom; updateMatrices(); }
    inline void setFov(float fov) { camera.fov = fov; updateMatrices(); }

    inline void setPosition(glm::vec3 position) { camera.position.x = position.x; camera.position.y = position.y; camera.position.z = position.z; updateMatrices(); }
    void setMove();
    inline void setRotation(glm::vec3 rotation) { camera.rotation.x = rotation.x; camera.rotation.y = rotation.y; camera.rotation.z = rotation.z; updateMatrices(); }
    void setRotate();
    inline void setScale(glm::vec3 scale) { camera.scale = scale; updateMatrices(); }
    inline void resetScale() { camera.scale = glm::vec3(NCamera::SCALE_X, NCamera::SCALE_Y, NCamera::SCALE_Z); updateMatrices(); }
    void setGridAlignedOrthoTransform(const glm::vec3 &pos, const glm::vec2 &rot, float step);

    inline void setSpeed(float speed = NCamera::MOVEMENT_SPEED) { camera.position.w = speed; }
    inline void setSensitivity(float sensitivity = NCamera::SENSITIVITY_SPEED) { camera.rotation.w = sensitivity; }

    inline const SCamera *getCamera() const { return &camera; }
};
//------------------------------------------------------------------------------
inline void CCamera::updateMatrices()
{
  if((camera.clipLeft != 0.0f) || (camera.clipRight != 0.0f) || (camera.clipTop != 0.0f) || (camera.clipBottom != 0.0f))
    camera.projType = NCamera::PROJ_ORTOGRAPHIC;
  else
    camera.projType = NCamera::PROJ_PERSPECTIVE;

  camera.view = glm::scale(
    glm::translate(
      glm::rotate(
        glm::rotate(glm::mat4(1.0f), camera.rotation.x * NMath::DEG_2_RAD, glm::vec3(1.0f, 0.0f, 0.0f)),
        (camera.rotation.y + NMath::PI_DEG) * NMath::DEG_2_RAD, glm::vec3(0.0f, 1.0f, 0.0f)),
      glm::vec3(camera.position.x * -NCamera::SCALE_X, camera.position.y * -NCamera::SCALE_Y, camera.position.z * -NCamera::SCALE_Z)),
    camera.scale);

  if(camera.projType == NCamera::PROJ_PERSPECTIVE)
    camera.projection = glm::perspective(camera.fov * NMath::DEG_2_RAD, camera.width / camera.height, camera.clipNear, camera.clipFar);
  else
    camera.projection = glm::ortho<float>(camera.clipLeft, camera.clipRight, camera.clipBottom, camera.clipTop, camera.clipNear, camera.clipFar);

  camera.viewProjection = camera.projection * camera.view;
}
//------------------------------------------------------------------------------
inline void CCamera::setMove()
{
  bool update = false;
  const SEngine *e = context->engineGetEngine();

  if(e->keys & NEngine::KEY_FRONT)
  {
    camera.position.x += camera.position.w * e->simulationStep * sinf(camera.rotation.y * NMath::DEG_2_RAD) * cosf(camera.rotation.x * NMath::DEG_2_RAD);
    camera.position.y -= camera.position.w * e->simulationStep * sinf(camera.rotation.x * NMath::DEG_2_RAD);
    camera.position.z += camera.position.w * e->simulationStep * cosf(camera.rotation.y * NMath::DEG_2_RAD) * cosf(camera.rotation.x * NMath::DEG_2_RAD);
    update = true;
  }
  if(e->keys & NEngine::KEY_BACK)
  {
    camera.position.x -= camera.position.w * e->simulationStep * sinf(camera.rotation.y * NMath::DEG_2_RAD) * cosf(camera.rotation.x * NMath::DEG_2_RAD);
    camera.position.y += camera.position.w * e->simulationStep * sinf(camera.rotation.x * NMath::DEG_2_RAD);
    camera.position.z -= camera.position.w * e->simulationStep * cosf(camera.rotation.y * NMath::DEG_2_RAD) * cosf(camera.rotation.x * NMath::DEG_2_RAD);
    update = true;
  }
  if(e->keys & NEngine::KEY_LEFT)
  {
    camera.position.x -= camera.position.w * e->simulationStep * cosf(camera.rotation.y * NMath::DEG_2_RAD);
    camera.position.z += camera.position.w * e->simulationStep * sinf(camera.rotation.y * NMath::DEG_2_RAD);
    update = true;
  }
  if(e->keys & NEngine::KEY_RIGHT)
  {
    camera.position.x += camera.position.w * e->simulationStep * cosf(camera.rotation.y * NMath::DEG_2_RAD);
    camera.position.z -= camera.position.w * e->simulationStep * sinf(camera.rotation.y * NMath::DEG_2_RAD);
    update = true;
  }
  if(e->keys & NEngine::KEY_DOWN)
  {
    camera.position.x -= camera.position.w * e->simulationStep * sinf(camera.rotation.x * NMath::DEG_2_RAD) * sinf(camera.rotation.y * NMath::DEG_2_RAD);
    camera.position.y -= camera.position.w * e->simulationStep * cosf(camera.rotation.x * NMath::DEG_2_RAD);
    camera.position.z -= camera.position.w * e->simulationStep * sinf(camera.rotation.x * NMath::DEG_2_RAD) * cosf(camera.rotation.y * NMath::DEG_2_RAD);
    update = true;
  }
  if(e->keys & NEngine::KEY_UP)
  {
    camera.position.x += camera.position.w * e->simulationStep * sinf(camera.rotation.x * NMath::DEG_2_RAD) * sinf(camera.rotation.y * NMath::DEG_2_RAD);
    camera.position.y += camera.position.w * e->simulationStep * cosf(camera.rotation.x * NMath::DEG_2_RAD);
    camera.position.z += camera.position.w * e->simulationStep * sinf(camera.rotation.x * NMath::DEG_2_RAD) * cosf(camera.rotation.y * NMath::DEG_2_RAD);
    update = true;
  }

  if(update)
    updateMatrices();
}
//------------------------------------------------------------------------------
inline void CCamera::setRotate()
{
  const SEngine *e = context->engineGetEngine();

  glm::vec2 cur = e->cursorOld - e->cursor;
  camera.rotation.x = camera.rotation.x - cur.x * camera.rotation.w;
  camera.rotation.y = camera.rotation.y - cur.y * camera.rotation.w;
  if(camera.rotation.x > NMath::PI_DEG)
    camera.rotation.x = camera.rotation.x - NMath::PI_2_DEG;
  if(camera.rotation.x < -NMath::PI_DEG)
    camera.rotation.x = camera.rotation.x + NMath::PI_2_DEG;
  if(camera.rotation.y > NMath::PI_DEG)
    camera.rotation.y = camera.rotation.y - NMath::PI_2_DEG;
  if(camera.rotation.y < -NMath::PI_DEG)
    camera.rotation.y = camera.rotation.y + NMath::PI_2_DEG;
  camera.rotation.z = 0.0;

  updateMatrices();
}
//------------------------------------------------------------------------------
inline void CCamera::setGridAlignedOrthoTransform(const glm::vec3 &pos, const glm::vec2 &rot, float step)
{
  const glm::vec3 orthoScale(NCamera::ORTHO_FBO_SCALE_X, NCamera::ORTHO_FBO_SCALE_Y, NCamera::ORTHO_FBO_SCALE_Z);
  const glm::vec3 invRotPos = glm::vec3(glm::rotate(glm::rotate(glm::mat4(1.0f), rot.x, glm::vec3(1.0f, 0.0f, 0.0f)), -rot.y, glm::vec3(0.0f, 1.0f, 0.0f)) * glm::vec4(pos, 1.0f));
  const glm::vec3 invRotPosFloor(static_cast<float>(static_cast<int32>(invRotPos.x / step)) * step, static_cast<float>(static_cast<int32>(invRotPos.y / step)) * step, static_cast<float>(static_cast<int32>(invRotPos.z / step)) * step);
  const glm::vec3 posFloor(glm::rotate(glm::rotate(glm::mat4(1.0f), rot.y, glm::vec3(0.0f, 1.0f, 0.0f)), -rot.x, glm::vec3(1.0f, 0.0f, 0.0f)) * glm::vec4(invRotPosFloor, 1.0f));

  const glm::vec3 p(posFloor * orthoScale);
  const glm::vec3 r(rot.x * NMath::RAD_2_DEG, -rot.y * NMath::RAD_2_DEG, 0.0f);
  const glm::vec3 s(glm::vec3(NCamera::SCALE_X, NCamera::SCALE_Y, NCamera::SCALE_Z) * orthoScale);

  camera.position.x = p.x; camera.position.y = p.y; camera.position.z = p.z;
  camera.rotation.x = r.x; camera.rotation.y = r.y; camera.rotation.z = r.z;
  camera.scale = s;

  updateMatrices();
}
//------------------------------------------------------------------------------
#endif // CAMERA_H
