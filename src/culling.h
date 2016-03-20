//------------------------------------------------------------------------------
#ifndef CULLING_H
#define CULLING_H

#include "pickColor.h"
#include "headers/modelTypes.h"
#include "headers/cullingTypes.h"

//------------------------------------------------------------------------------
class CCulling : public CEngineBase
{
  private:
    SFrustum frustum;

  public:
    inline CCulling() : CEngineBase() {}
    inline CCulling(CContext *context) : CEngineBase(context) {}
    inline ~CCulling() {}

    void updateFrustum();

    bool isSphereInFrustum(const glm::vec3 &pos, float radius) const;
    bool isAABBInFrustum(const SBoundingBox &aabb) const;

    inline void setFrustum(const SFrustum &f) { frustum = f; }

    inline const SFrustum *getFrustum() const { return &frustum; }
};
//------------------------------------------------------------------------------
inline void CCulling::updateFrustum()
{
  const SCamera *c = context->getCamera()->getCamera();
  const float *proj = glm::value_ptr(c->projection);
  const float *modl = glm::value_ptr(c->view);
  float clip[16] = { 0.0f, 0.0f, 0.0f, 0.0f,  0.0f, 0.0f, 0.0f, 0.0f,  0.0f, 0.0f, 0.0f, 0.0f,  0.0f, 0.0f, 0.0f, 0.0f };
  float t;

  /* Combine the two matrices (multiply projection by modelview) */
  clip[0] = modl[0] * proj[0] + modl[1] * proj[4] + modl[2] * proj[8] + modl[3] * proj[12];
  clip[1] = modl[0] * proj[1] + modl[1] * proj[5] + modl[2] * proj[9] + modl[3] * proj[13];
  clip[2] = modl[0] * proj[2] + modl[1] * proj[6] + modl[2] * proj[10] + modl[3] * proj[14];
  clip[3] = modl[0] * proj[3] + modl[1] * proj[7] + modl[2] * proj[11] + modl[3] * proj[15];

  clip[4] = modl[4] * proj[0] + modl[5] * proj[4] + modl[6] * proj[8] + modl[7] * proj[12];
  clip[5] = modl[4] * proj[1] + modl[5] * proj[5] + modl[6] * proj[9] + modl[7] * proj[13];
  clip[6] = modl[4] * proj[2] + modl[5] * proj[6] + modl[6] * proj[10] + modl[7] * proj[14];
  clip[7] = modl[4] * proj[3] + modl[5] * proj[7] + modl[6] * proj[11] + modl[7] * proj[15];

  clip[8] = modl[8] * proj[0] + modl[9] * proj[4] + modl[10] * proj[8] + modl[11] * proj[12];
  clip[9] = modl[8] * proj[1] + modl[9] * proj[5] + modl[10] * proj[9] + modl[11] * proj[13];
  clip[10] = modl[8] * proj[2] + modl[9] * proj[6] + modl[10] * proj[10] + modl[11] * proj[14];
  clip[11] = modl[8] * proj[3] + modl[9] * proj[7] + modl[10] * proj[11] + modl[11] * proj[15];

  clip[12] = modl[12] * proj[0] + modl[13] * proj[4] + modl[14] * proj[8] + modl[15] * proj[12];
  clip[13] = modl[12] * proj[1] + modl[13] * proj[5] + modl[14] * proj[9] + modl[15] * proj[13];
  clip[14] = modl[12] * proj[2] + modl[13] * proj[6] + modl[14] * proj[10] + modl[15] * proj[14];
  clip[15] = modl[12] * proj[3] + modl[13] * proj[7] + modl[14] * proj[11] + modl[15] * proj[15];

  /* Extract the numbers for the RIGHT plane */
  frustum.frustum[0][0] = clip[3] - clip[0];
  frustum.frustum[0][1] = clip[7] - clip[4];
  frustum.frustum[0][2] = clip[11] - clip[8];
  frustum.frustum[0][3] = clip[15] - clip[12];

  /* Normalize the result */
  t = sqrtf(frustum.frustum[0][0] * frustum.frustum[0][0] + frustum.frustum[0][1] * frustum.frustum[0][1] + frustum.frustum[0][2] * frustum.frustum[0][2]);
  frustum.frustum[0][0] /= t;
  frustum.frustum[0][1] /= t;
  frustum.frustum[0][2] /= t;
  frustum.frustum[0][3] /= t;

  /* Extract the numbers for the LEFT plane */
  frustum.frustum[1][0] = clip[3] + clip[0];
  frustum.frustum[1][1] = clip[7] + clip[4];
  frustum.frustum[1][2] = clip[11] + clip[8];
  frustum.frustum[1][3] = clip[15] + clip[12];

  /* Normalize the result */
  t = sqrtf(frustum.frustum[1][0] * frustum.frustum[1][0] + frustum.frustum[1][1] * frustum.frustum[1][1] + frustum.frustum[1][2] * frustum.frustum[1][2]);
  frustum.frustum[1][0] /= t;
  frustum.frustum[1][1] /= t;
  frustum.frustum[1][2] /= t;
  frustum.frustum[1][3] /= t;

  /* Extract the BOTTOM plane */
  frustum.frustum[2][0] = clip[3] + clip[1];
  frustum.frustum[2][1] = clip[7] + clip[5];
  frustum.frustum[2][2] = clip[11] + clip[9];
  frustum.frustum[2][3] = clip[15] + clip[13];

  /* Normalize the result */
  t = sqrtf(frustum.frustum[2][0] * frustum.frustum[2][0] + frustum.frustum[2][1] * frustum.frustum[2][1] + frustum.frustum[2][2] * frustum.frustum[2][2]);
  frustum.frustum[2][0] /= t;
  frustum.frustum[2][1] /= t;
  frustum.frustum[2][2] /= t;
  frustum.frustum[2][3] /= t;

  /* Extract the TOP plane */
  frustum.frustum[3][0] = clip[3] - clip[1];
  frustum.frustum[3][1] = clip[7] - clip[5];
  frustum.frustum[3][2] = clip[11] - clip[9];
  frustum.frustum[3][3] = clip[15] - clip[13];

  /* Normalize the result */
  t = sqrtf(frustum.frustum[3][0] * frustum.frustum[3][0] + frustum.frustum[3][1] * frustum.frustum[3][1] + frustum.frustum[3][2] * frustum.frustum[3][2]);
  frustum.frustum[3][0] /= t;
  frustum.frustum[3][1] /= t;
  frustum.frustum[3][2] /= t;
  frustum.frustum[3][3] /= t;

  /* Extract the FAR plane */
  frustum.frustum[4][0] = clip[3] - clip[2];
  frustum.frustum[4][1] = clip[7] - clip[6];
  frustum.frustum[4][2] = clip[11] - clip[10];
  frustum.frustum[4][3] = clip[15] - clip[14];

  /* Normalize the result */
  t = sqrtf(frustum.frustum[4][0] * frustum.frustum[4][0] + frustum.frustum[4][1] * frustum.frustum[4][1] + frustum.frustum[4][2] * frustum.frustum[4][2]);
  frustum.frustum[4][0] /= t;
  frustum.frustum[4][1] /= t;
  frustum.frustum[4][2] /= t;
  frustum.frustum[4][3] /= t;

  /* Extract the NEAR plane */
  frustum.frustum[5][0] = clip[3] + clip[2];
  frustum.frustum[5][1] = clip[7] + clip[6];
  frustum.frustum[5][2] = clip[11] + clip[10];
  frustum.frustum[5][3] = clip[15] + clip[14];

  /* Normalize the result */
  t = sqrtf(frustum.frustum[5][0] * frustum.frustum[5][0] + frustum.frustum[5][1] * frustum.frustum[5][1] + frustum.frustum[5][2] * frustum.frustum[5][2]);
  frustum.frustum[5][0] /= t;
  frustum.frustum[5][1] /= t;
  frustum.frustum[5][2] /= t;
  frustum.frustum[5][3] /= t;
}
//------------------------------------------------------------------------------
inline bool CCulling::isSphereInFrustum(const glm::vec3 &pos, float radius) const
{
  for(uint32 i = 0; i < NCulling::FRUSTUM_PLANES; i++)
    if(frustum.frustum[i][0] * pos.x + frustum.frustum[i][1] * pos.y + frustum.frustum[i][2] * pos.z + frustum.frustum[i][3] <= -radius)
      return false;

  return true;
}
//------------------------------------------------------------------------------
inline bool CCulling::isAABBInFrustum(const SBoundingBox &aabb) const
{
  for(unsigned char i = 0; i < NCulling::FRUSTUM_PLANES; i++)
  {
    if(frustum.frustum[i][0] * aabb.minimum.x + frustum.frustum[i][1] * aabb.minimum.y + frustum.frustum[i][2] * aabb.minimum.z + frustum.frustum[i][3] > 0) continue;
    if(frustum.frustum[i][0] * aabb.maximum.x + frustum.frustum[i][1] * aabb.minimum.y + frustum.frustum[i][2] * aabb.minimum.z + frustum.frustum[i][3] > 0) continue;
    if(frustum.frustum[i][0] * aabb.minimum.x + frustum.frustum[i][1] * aabb.maximum.y + frustum.frustum[i][2] * aabb.minimum.z + frustum.frustum[i][3] > 0) continue;
    if(frustum.frustum[i][0] * aabb.maximum.x + frustum.frustum[i][1] * aabb.maximum.y + frustum.frustum[i][2] * aabb.minimum.z + frustum.frustum[i][3] > 0) continue;
    if(frustum.frustum[i][0] * aabb.minimum.x + frustum.frustum[i][1] * aabb.minimum.y + frustum.frustum[i][2] * aabb.maximum.z + frustum.frustum[i][3] > 0) continue;
    if(frustum.frustum[i][0] * aabb.maximum.x + frustum.frustum[i][1] * aabb.minimum.y + frustum.frustum[i][2] * aabb.maximum.z + frustum.frustum[i][3] > 0) continue;
    if(frustum.frustum[i][0] * aabb.minimum.x + frustum.frustum[i][1] * aabb.maximum.y + frustum.frustum[i][2] * aabb.maximum.z + frustum.frustum[i][3] > 0) continue;
    if(frustum.frustum[i][0] * aabb.maximum.x + frustum.frustum[i][1] * aabb.maximum.y + frustum.frustum[i][2] * aabb.maximum.z + frustum.frustum[i][3] > 0) continue;

    return false;
  }

  return true;
}
//------------------------------------------------------------------------------
#endif // CULLING_H
