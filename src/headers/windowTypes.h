//-----------------------------------------------------------------------------
#ifndef WINDOWTYPES_H
#define WINDOWTYPES_H

#include "types.h"

//-----------------------------------------------------------------------------
namespace NWindow
{
  static const char STR_ORTHO_DEPTH_FBO[] = "orthoDepth";
  static const char STR_ORTHO_DEPTH_FBO_MAP[] = "orthoDepth_0";
  static const char STR_ORTHO_GEOMETRY_FBO[] = "orthoGeometry";
  static const char STR_ORTHO_GEOMETRY_FBO_AMB_MAP[] = "orthoGeometry_0";
  static const char STR_ORTHO_GEOMETRY_FBO_POS_MAP[] = "orthoGeometry_1";
  static const char STR_ORTHO_GEOMETRY_FBO_NORMAL_MAP[] = "orthoGeometry_2";
  static const char STR_ORTHO_GEOMETRY_FBO_DEPTH_MAP[] = "orthoGeometry_3";

  static const char STR_LPV_FBO[] = "lpv%dTex"; // %d cascades
  static const char STR_LPV_MAP_R[] = "lpv%dTex_0";
  static const char STR_LPV_MAP_G[] = "lpv%dTex_1";
  static const char STR_LPV_MAP_B[] = "lpv%dTex_2";

  static const char STR_LPV_SWAP_FBO[] = "lpvSwap%dTex"; // gl 3.2 fbo swap propagation textures
  static const char STR_LPV_SWAP_MAP_R[] = "lpvSwap%dTex_0";
  static const char STR_LPV_SWAP_MAP_G[] = "lpvSwap%dTex_1";
  static const char STR_LPV_SWAP_MAP_B[] = "lpvSwap%dTex_2";
  static const char STR_GV_SWAP_MAP[] = "lpvSwap%dTex_3";

  static const char STR_LPV_SWAP_IMG_R[] = "lpvSwap%dImg_0"; // gl 4.3 swap propagation images
  static const char STR_LPV_SWAP_IMG_G[] = "lpvSwap%dImg_1";
  static const char STR_LPV_SWAP_IMG_B[] = "lpvSwap%dImg_2";
  static const char STR_GV_SWAP_IMG[] = "lpvSwapImg_3";

  static const char STR_APP_TITLE[] = "Light Propagation Volumes (Pos: %f %f %f, Draw calls: %d)";

  static const char STR_ERROR_INIT_SDL[] = "Unable to init SDL";
  static const char STR_ERROR_INIT_WINDOW[] = "Unable to init window";
  static const char STR_ERROR_INIT_GL_CONTEXT[] = "Unable to init OpenGL context";
  static const char STR_ERROR_INIT_IMG_JPG[] = "Unable to init SDL Image: JPG";
  static const char STR_ERROR_INIT_IMG_PNG[] = "Unable to init SDL Image: PNG";
  static const char STR_ERROR_INIT_GLEW[] = "Unable to init GLEW";
}
//-----------------------------------------------------------------------------
#endif // WINDOWTYPES_H
