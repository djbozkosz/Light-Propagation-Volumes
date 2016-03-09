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

  // for gl 3.2+: fbo + attachments, for gl 4.3+: image load store (int + float)
  static const char STR_LPV0_FBO[] = "lpv0Tex";
  static const char STR_LPV0_MAP_R[] = "lpv0Tex_0";
  static const char STR_LPV0_MAP_G[] = "lpv0Tex_1";
  static const char STR_LPV0_MAP_B[] = "lpv0Tex_2";
  static const char STR_GV0_MAP[] = "lpv0Tex_3";
  static const char STR_LPV1_FBO[] = "lpv1Tex";
  static const char STR_LPV1_MAP_R[] = "lpv1Tex_0";
  static const char STR_LPV1_MAP_G[] = "lpv1Tex_1";
  static const char STR_LPV1_MAP_B[] = "lpv1Tex_2";
  static const char STR_GV1_MAP[] = "lpv1Tex_3";
  static const char STR_LPV_OUT_MAP_R[] = "lpvOutTexR";
  static const char STR_LPV_OUT_MAP_G[] = "lpvOutTexG";
  static const char STR_LPV_OUT_MAP_B[] = "lpvOutTexB";

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
