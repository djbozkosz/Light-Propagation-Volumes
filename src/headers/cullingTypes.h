//-----------------------------------------------------------------------------
#ifndef CULLINGTYPES_H
#define CULLINGTYPES_H

#include "types.h"

//-----------------------------------------------------------------------------
namespace NCulling
{
  static const uint8 FRUSTUM_PLANES = 6;
  static const uint8 FRUSTUM_PLANE_CORNERS = 4;
}
//-----------------------------------------------------------------------------
struct SFrustum
{
  float frustum[NCulling::FRUSTUM_PLANES][NCulling::FRUSTUM_PLANE_CORNERS];

  inline SFrustum()
  {
    memset(&frustum, 0, sizeof(float) * NCulling::FRUSTUM_PLANES * NCulling::FRUSTUM_PLANE_CORNERS);
  }
};
//-----------------------------------------------------------------------------
#endif // CULLINGTYPES_H
