//-----------------------------------------------------------------------------
#ifndef WINDOWTYPES_H
#define WINDOWTYPES_H

#include "types.h"

//-----------------------------------------------------------------------------
namespace NWindow
{
  static const char STR_ORTHO_DEPTH_FBO[] = "orthoDepth";
  static const char STR_ORTHO_DEPTH_FBO_MAP[] = "orthoDepth_0";

  static const char STR_APP_TITLE[] = "Light Propagation Volumes (Draw calls: %d)";

  static const char STR_ERROR_INIT_SDL[] = "Unable to init SDL";
  static const char STR_ERROR_INIT_WINDOW[] = "Unable to init window";
  static const char STR_ERROR_INIT_IMG_JPG[] = "Unable to init SDL Image: JPG";
  static const char STR_ERROR_INIT_IMG_PNG[] = "Unable to init SDL Image: PNG";
  static const char STR_ERROR_INIT_GLEW[] = "Unable to init GLEW";
}
//-----------------------------------------------------------------------------
#endif // WINDOWTYPES_H
