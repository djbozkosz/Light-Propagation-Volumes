//------------------------------------------------------------------------------
#ifndef SHADERSTYPES_H
#define SHADERSTYPES_H

#include "mapTypes.h"
#include "modelTypes.h"

//------------------------------------------------------------------------------
namespace NShader
{
  static const uint32 VERTEX_SHADERS_COUNT = 14;
  static const uint32 TESSELATION_CONTROL_SHADERS_COUNT = 0;
  static const uint32 TESSELATION_EVALUATION_SHADERS_COUNT = 0;
  static const uint32 GEOMETRY_SHADERS_COUNT = 5;
  static const uint32 FRAGMENT_SHADERS_COUNT = 20;
  static const uint32 COMPUTE_SHADERS_COUNT = 4;
  static const uint32 PROGRAMS_COUNT = 28;

  static const uint8 SHADER_MAX_LIGHTS = 1;

  static const GLint ATTRIB_UNDEFINED = -1;
  static const GLint UNIFORM_UNDEFINED = -1;

  // attributes ----------------------------------------------------------------
  static const char STR_ATTRIB_VERTEX_POSITION[] = "_vertexPosition"; // precending '_' due to bug in old ATI drivers - attributes must have "lower name" in alphabet than gl_VertexID or gl_InstanceID
  static const char STR_ATTRIB_VERTEX_NORMAL[] = "_vertexNormal";
  static const char STR_ATTRIB_VERTEX_NORMAL_TANGENT[] = "_vertexNormalTangent";
  static const char STR_ATTRIB_VERTEX_NORMAL_BITANGENT[] = "_vertexNormalBitangent";
  static const char STR_ATTRIB_VERTEX_TEX_COORD[] = "_vertexTexCoord";
  static const char STR_ATTRIB_VERTEX_COLOR[] = "_vertexColor";

  // uniforms ------------------------------------------------------------------
  static const char STR_UNIFORM_MW[] = "mw"; // model world (4x4)
  static const char STR_UNIFORM_MWNIT[] = "mwnit"; // model world normal inversed transposed (3x3)
  static const char STR_UNIFORM_MVP[] = "mvp"; // projection * view * model world (4x4)
  static const char STR_UNIFORM_MVPSB[] = "mvpsb"; // mvps[shad_cascad] shadow biased
  static const char STR_UNIFORM_CAM[] = "cam"; // camera world

  static const char STR_UNIFORM_DIF_TEX[] = "difTex";
  static const char STR_UNIFORM_ALP_TEX[] = "alpTex";
  static const char STR_UNIFORM_SPE_TEX[] = "speTex";
  static const char STR_UNIFORM_NOR_TEX[] = "norTex";
  //static const char STR_UNIFORM_ENV_TEX[] = "envTex";
  static const char STR_UNIFORM_SHAD_TEX[] = "shadTex"; // shadow texture array

  static const char STR_UNIFORM_GEOM_COLOR_TEX[] = "geomColorTex"; // geometry texture arrays, gs in, cs in
  static const char STR_UNIFORM_GEOM_POS_TEX[] = "geomPosTex";
  static const char STR_UNIFORM_GEOM_NORMAL_TEX[] = "geomNormalTex";
  //static const char STR_UNIFORM_GEOM_DEPTH_TEX[] = "geomDepthTex";

  static const char STR_UNIFORM_LPV_TEX_R[] = "lpvTexR"; // gs in, cs out, out draw in
  static const char STR_UNIFORM_LPV_TEX_G[] = "lpvTexG";
  static const char STR_UNIFORM_LPV_TEX_B[] = "lpvTexB";
  static const char STR_UNIFORM_GV_TEX[] = "gvTex"; // gs in, cs in
  static const char STR_UNIFORM_LPV0_TEX_R[] = "lpv0TexR"; // cs swap in
  static const char STR_UNIFORM_LPV0_TEX_G[] = "lpv0TexG";
  static const char STR_UNIFORM_LPV0_TEX_B[] = "lpv0TexB";
  static const char STR_UNIFORM_LPV1_TEX_R[] = "lpv1TexR"; // cs swap out
  static const char STR_UNIFORM_LPV1_TEX_G[] = "lpv1TexG";
  static const char STR_UNIFORM_LPV1_TEX_B[] = "lpv1TexB";

  static const char STR_UNIFORM_TYPE[] = "type";
  static const char STR_UNIFORM_OPACITY[] = "opacity";
  static const char STR_UNIFORM_SHADOW_TEX_SIZE[] = "shadowTexSize"; // vec3, e.g. 1/512, 1/512, jitter

  static const char STR_UNIFORM_LIGHT_AMB[] = "lightAmb"; // or array for geometry render
  static const char STR_UNIFORM_LIGHT_POS[] = "lightPos"; // or array for geometry render
  static const char STR_UNIFORM_LIGHT_RANGE[] = "lightRange";
  static const char STR_UNIFORM_LIGHT_COLOR[] = "lightColor";
  static const char STR_UNIFORM_LIGHT_SPEC_COLOR[] = "lightSpeColor";
  static const char STR_UNIFORM_FOG_RANGE[] = "fogRange";
  static const char STR_UNIFORM_FOG_COLOR[] = "fogColor";

  static const char STR_UNIFORM_GEOM_TEX_SIZE[] = "geomTexSize"; // e.g. 128, 128, 1/128, 1/128
  static const char STR_UNIFORM_LPV_POS[] = "lpvPos"; // vec3[], poses of left bottom corners
  static const char STR_UNIFORM_LPV_TEX_SIZE[] = "lpvTexSize"; // vec3, e.g. 32, 32, 32
  static const char STR_UNIFORM_LPV_CELL_SIZE[] = "lpvCellSize"; // vec3[], e.g.   0.1, 0.1, 0.1,   0.3, 0.3, 0.3,   ...
  static const char STR_UNIFORM_LPV_PARAMS[] = "lpvParams"; // vec2 - propag. count, intensity

  // shader files --------------------------------------------------------------
  static const char STR_SHADER_UNUSED[] = "";

  static const char STR_VERTEX_COLOR[] = "color.vs";
  static const char STR_VERTEX_DEPTH[] = "depth.vs";
  static const char STR_VERTEX_BASIC[] = "basic.vs";
  static const char STR_VERTEX_ILLUMINATION[] = "illumination.vs";
  static const char STR_VERTEX_GEOMETRY[] = "geometry.vs";
  static const char STR_VERTEX_LPV_INJECTION[] = "lpvInjection.vs";
  static const char STR_VERTEX_LPV_PROPAGATION[] = "lpvPropagation.vs";

  static const char STR_GEOMETRY_DEPTH[] = "depth.gs";
  static const char STR_GEOMETRY_GEOMETRY[] = "geometry.gs";
  static const char STR_GEOMETRY_LPV_INJECTION[] = "lpvInjection.gs";
  static const char STR_GEOMETRY_LPV_PROPAGATION[] = "lpvPropagation.gs";

  static const char STR_FRAGMENT_COLOR[] = "color.fs";
  static const char STR_FRAGMENT_DEPTH[] = "depth.fs";
  static const char STR_FRAGMENT_BASIC[] = "basic.fs";
  static const char STR_FRAGMENT_ILLUMINATION[] = "illumination.fs";
  static const char STR_FRAGMENT_GEOMETRY[] = "geometry.fs";
  static const char STR_FRAGMENT_LPV_INJECTION[] = "lpvInjection.fs";
  static const char STR_FRAGMENT_LPV_PROPAGATION[] = "lpvPropagation.fs";

  static const char STR_COMPUTE_LPV_CLEAR[] = "lpvClear.cs";
  static const char STR_COMPUTE_LPV_INJECTION[] = "lpvInjection.cs";
  static const char STR_COMPUTE_LPV_PROPAGATION[] = "lpvPropagation.cs";

  // other strings -------------------------------------------------------------
  static const char STR_SHADER_NAME[] = "%s %s";
  static const char STR_ERROR_COMPILE_SKIP[] = "Shader Compilation Skip: \"%s\"!";
  static const char STR_ERROR_LINK_SKIP[] = "Program Link Skip: \"%s\"!";
  static const char STR_WARNING_COMPILE[] = "Shader Compilation Warning: \"%s\"!\n%s";
  static const char STR_ERROR_COMPILE[] = "Shader Compilation Error: \"%s\"!";
  static const char STR_WARNING_LINK[] = "Program Link Warning: \"%s\"!\n%s";
  static const char STR_ERROR_LINK[] = "Program Link Error: \"%s\"!";
  static const char STR_ERROR_SHADER_ATTACH[] = "No Shader attached to Program: \"%s\"!";

  // programs ------------------------------------------------------------------
  static const char *const STR_PROGRAM_LIST[] =
  {
    "Color",
    "Depth",
    "Depth Color Key",
    "Depth Cascade",
    "Depth Cascade Color Key",
    "Basic",
    "Basic Alpha",
    "Illumination",
    "Illumination Shadow",
    "Illumination Shadow Jitter",
    "Illumination Alpha",
    "Illumination Alpha Shadow",
    "Illumination Alpha Shadow Jitter",
    "Illumination Normal",
    "Illumination Normal Shadow",
    "Illumination Normal Shadow Jitter",
    "Illumination Normal Alpha",
    "Illumination Normal Alpha Shadow",
    "Illumination Normal Alpha Shadow Jitter",
    "Geometry",
    "Geometry Cascade",
    "LPV Injection Geometry",
    "LPV Propagation Geometry Gathering",
    "LPV Propagation Geometry Scattering",
    "LPV Clear Compute",
    "LPV Injection Compute",
    "LPV Propagation Compute Gathering",
    "LPV Propagation Compute Scattering"
  };

  // shader lists --------------------------------------------------------------
  static const char *const STR_VERTEX_SHADER_LIST[][2] =
  {
    { STR_VERTEX_COLOR, "" },
    { STR_VERTEX_DEPTH, "" },
    { STR_VERTEX_DEPTH, "DIF_TEX" },
    { STR_VERTEX_DEPTH, "GS_CASCADE" },
    { STR_VERTEX_DEPTH, "GS_CASCADE DIF_TEX" },
    { STR_VERTEX_BASIC, "" },
    { STR_VERTEX_ILLUMINATION, "" },
    { STR_VERTEX_ILLUMINATION, "SHAD_TEX" },
    { STR_VERTEX_ILLUMINATION, "NOR_TEX" },
    { STR_VERTEX_ILLUMINATION, "NOR_TEX SHAD_TEX" },
    { STR_VERTEX_GEOMETRY, "" },
    { STR_VERTEX_GEOMETRY, "GS_CASCADE" },
    { STR_VERTEX_LPV_INJECTION, "" },
    { STR_VERTEX_LPV_PROPAGATION, "" }
  };

  static const char *const STR_TESSELATION_CONTROL_SHADER_LIST[][2] =
  {
    { STR_SHADER_UNUSED, "" }
  };
  static const char *const STR_TESSELATION_EVALUATION_SHADER_LIST[][2] =
  {
    { STR_SHADER_UNUSED, "" }
  };

  static const char *const STR_GEOMETRY_SHADER_LIST[][2] =
  {
    { STR_GEOMETRY_DEPTH, "" },
    { STR_GEOMETRY_GEOMETRY, "" },
    { STR_GEOMETRY_LPV_INJECTION, "" },
    { STR_GEOMETRY_LPV_PROPAGATION, "" },
    { STR_GEOMETRY_LPV_PROPAGATION, "LPV_SCATTERING" }
  };

  static const char *const STR_FRAGMENT_SHADER_LIST[][2] =
  {
    { STR_FRAGMENT_COLOR, "" },
    { STR_FRAGMENT_DEPTH, "" },
    { STR_FRAGMENT_DEPTH, "DIF_TEX" },
    { STR_FRAGMENT_BASIC, "" },
    { STR_FRAGMENT_BASIC, "ALP_TEX" },
    { STR_FRAGMENT_ILLUMINATION, "" },
    { STR_FRAGMENT_ILLUMINATION, "SHAD_TEX" },
    { STR_FRAGMENT_ILLUMINATION, "SHAD_TEX SHADOW_JITTER" },
    { STR_FRAGMENT_ILLUMINATION, "ALP_TEX" },
    { STR_FRAGMENT_ILLUMINATION, "ALP_TEX SHAD_TEX" },
    { STR_FRAGMENT_ILLUMINATION, "ALP_TEX SHAD_TEX SHADOW_JITTER" },
    { STR_FRAGMENT_ILLUMINATION, "NOR_TEX" },
    { STR_FRAGMENT_ILLUMINATION, "NOR_TEX SHAD_TEX" },
    { STR_FRAGMENT_ILLUMINATION, "NOR_TEX SHAD_TEX SHADOW_JITTER" },
    { STR_FRAGMENT_ILLUMINATION, "ALP_TEX NOR_TEX" },
    { STR_FRAGMENT_ILLUMINATION, "ALP_TEX NOR_TEX SHAD_TEX" },
    { STR_FRAGMENT_ILLUMINATION, "ALP_TEX NOR_TEX SHAD_TEX SHADOW_JITTER" },
    { STR_FRAGMENT_GEOMETRY, "" },
    { STR_FRAGMENT_LPV_INJECTION, "" },
    { STR_FRAGMENT_LPV_PROPAGATION, "" }
  };

  static const char *const STR_COMPUTE_SHADER_LIST[][2] =
  {
    { STR_COMPUTE_LPV_CLEAR, "" },
    { STR_COMPUTE_LPV_INJECTION, "" },
    { STR_COMPUTE_LPV_PROPAGATION, "" },
    { STR_COMPUTE_LPV_PROPAGATION, "LPV_SCATTERING" }
  };

  // linking lists -------------------------------------------------------------
  static const int32 PROGRAM_VERTEX_SHADER_LIST[] =
  {
    0,
    1, 2, 3, 4,
    5, 5,
    6, 7, 7, 6, 7, 7, 8, 9, 9, 8, 9, 9,
    10, 11,
    12, 13, 13,
    -1, -1, -1, -1
  };

  static const int32 PROGRAM_TESSELATION_CONTROL_SHADER_LIST[] =
  {
    -1,
    -1, -1, -1, -1,
    -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1,
    -1, -1, -1,
    -1, -1, -1, -1
  };
  static const int32 PROGRAM_TESSELATION_EVALUATION_SHADER_LIST[] =
  {
    -1,
    -1, -1, -1, -1,
    -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1,
    -1, -1, -1,
    -1, -1, -1, -1
  };

  static const int32 PROGRAM_GEOMETRY_SHADER_LIST[] =
  {
    -1,
    -1, -1, 0, 0,
    -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 1,
    2, 3, 4,
    -1, -1, -1, -1
  };

  static const int32 PROGRAM_FRAGMENT_SHADER_LIST[] =
  {
    0,
    1, 2, 1, 2,
    3, 4,
    5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
    17, 17,
    18, 19, 19,
    -1, -1, -1, -1
  };

  static const int32 PROGRAM_COMPUTE_SHADER_LIST[] =
  {
    -1,
    -1, -1, -1, -1,
    -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1,
    -1, -1, -1,
    0, 1, 2, 3
  };

  // types ---------------------------------------------------------------------
  enum EType
  {
    TYPE_UNDEFINED = 0,
    TYPE_VERTEX,
    TYPE_TESSELATION_CONTROL,
    TYPE_TESSELATION_EVALUATION,
    TYPE_GEOMETRY,
    TYPE_FRAGMENT,
    TYPE_COMPUTE
  };

  static const GLenum TYPE_SHADERS[] =
  {
    NOpenGL::NONE,
    NOpenGL::VERTEX_SHADER,
    NOpenGL::TESS_CONTROL_SHADER,
    NOpenGL::TESS_EVALUATION_SHADER, 
    NOpenGL::GEOMETRY_SHADER,
    NOpenGL::FRAGMENT_SHADER,
    NOpenGL::COMPUTE_SHADER
  };

  enum EProgram
  {
    PROGRAM_COLOR = 0, // vbo attribs pack:   pos, tex
    PROGRAM_DEPTH,
    PROGRAM_DEPTH_COLOR_KEY,
    PROGRAM_DEPTH_CASCADE,
    PROGRAM_DEPTH_CASCADE_COLOR_KEY,
    PROGRAM_BASIC, // vbo attribs pack:   pos, nor, tan, tex, col
    PROGRAM_BASIC_ALPHA,
    PROGRAM_ILLUMINATION,
    PROGRAM_ILLUMINATION_SHADOW,
    PROGRAM_ILLUMINATION_SHADOW_JITTER,
    PROGRAM_ILLUMINATION_ALPHA,
    PROGRAM_ILLUMINATION_ALPHA_SHADOW,
    PROGRAM_ILLUMINATION_ALPHA_SHADOW_JITTER,
    PROGRAM_ILLUMINATION_NORMAL,
    PROGRAM_ILLUMINATION_NORMAL_SHADOW,
    PROGRAM_ILLUMINATION_NORMAL_SHADOW_JITTER,
    PROGRAM_ILLUMINATION_NORMAL_ALPHA,
    PROGRAM_ILLUMINATION_NORMAL_ALPHA_SHADOW,
    PROGRAM_ILLUMINATION_NORMAL_ALPHA_SHADOW_JITTER,
    PROGRAM_GEOMETRY,
    PROGRAM_GEOMETRY_CASCADE,
    PROGRAM_LPV_INJECTION_GEOMETRY, // vbo attribs pack:   reserved float
    PROGRAM_LPV_PROPAGATION_GEOMETRY_GATHERING,
    PROGRAM_LPV_PROPAGATION_GEOMETRY_SCATTERING,
    PROGRAM_LPV_CLEAR_COMPUTE, // no vbo
    PROGRAM_LPV_INJECTION_COMPUTE,
    PROGRAM_LPV_PROPAGATION_COMPUTE_GATHERING,
    PROGRAM_LPV_PROPAGATION_COMPUTE_SCATTERING
  };

  // shader flags --------------------------------------------------------------
  enum EAttrib
  {
    ATTRIB                        = 0x0000,
    ATTRIB_F                      = 0x0001,
    ATTRIB_PT_POSITION            = 0x0002,
    ATTRIB_PT_TEX_COORD           = 0x0004,
    ATTRIB_PNTBTC_POSITION         = 0x0008,
    ATTRIB_PNTBTC_NORMAL           = 0x0010,
    ATTRIB_PNTBTC_NORMAL_TANGENT   = 0x0020,
    ATTRIB_PNTBTC_NORMAL_BITANGENT = 0x0040,
    ATTRIB_PNTBTC_TEX_COORD        = 0x0080,
    ATTRIB_PNTBTC_COLOR            = 0x0100
  };

  enum EUniforms
  {
    UNIFORM                           = 0x00000000,
    UNIFORM_MW                        = 0x00000001,
    UNIFORM_MWNIT                     = 0x00000002,
    UNIFORM_CAM                       = 0x00000004,
    UNIFORM_MVP                       = 0x00000008,
    UNIFORM_MVP_SHAD                  = 0x00000010,
    UNIFORM_MVP_SHAD_CASCADE          = 0x00000020,
    UNIFORM_MVP_GEOM                  = 0x00000040,
    UNIFORM_MVP_GEOM_CASCADE          = 0x00000080,
    UNIFORM_MVPSB                     = 0x00000100,
    UNIFORM_TYPE                      = 0x00000200,
    UNIFORM_OPACITY                   = 0x00000400,
    UNIFORM_SHAD_TEX_SIZE             = 0x00000800,
    UNIFORM_LAMB_COLOR                = 0x00001000,
    UNIFORM_LAMB_PICK                 = 0x00002000,
    UNIFORM_LAMB_LPOS                 = 0x00004000,
    UNIFORM_LAMB_LPOS_INJECT          = 0x00008000,
    UNIFORM_LRAN_LCOL_LSPEC_FRAN_FCOL = 0x00010000,
    UNIFORM_GEOM_TEX_SIZE             = 0x00020000,
    UNIFORM_LPV_POS_TEXS_CELLS_PARAMS = 0x00040000
  };

  enum ESampler
  {
    SAMPLER                                  = 0x00000000,
    SAMPLER_DEPTH_COLOR_KEY                  = 0x00000001,
    SAMPLER_BASIC                            = 0x00000002,
    SAMPLER_BASIC_APLHA                      = 0x00000004,
    SAMPLER_ILLUMINATION                     = 0x00000008,
    SAMPLER_ILLUMINATION_SHADOW              = 0x00000010,
    SAMPLER_ILLUMINATION_ALPHA               = 0x00000020,
    SAMPLER_ILLUMINATION_ALPHA_SHADOW        = 0x00000040,
    SAMPLER_ILLUMINATION_NORMAL              = 0x00000080,
    SAMPLER_ILLUMINATION_NORMAL_SHADOW       = 0x00000100,
    SAMPLER_ILLUMINATION_NORMAL_ALPHA        = 0x00000200,
    SAMPLER_ILLUMINATION_NORMAL_ALPHA_SHADOW = 0x00000400,
    SAMPLER_GEOMETRY                         = 0x00000800,
    SAMPLER_LPV_INJECTION_GEOMETRY           = 0x00001000,
    SAMPLER_LPV_PROPAGATION_GEOMETRY         = 0x00002000,
    IMAGE_LPV_CLEAR_COMPUTE                  = 0x00004000,
    IMAGE_LPV_INJECTION_COMPUTE              = 0x00008000,
    IMAGE_LPV_PROPAGATION_COMPUTE            = 0x00010000,
  };

  enum ERenderStates
  {
    REN_STATE        = 0x00,
    REN_STATE_BLEND  = 0x01,
    REN_STATE_CULL   = 0x02,
    REN_STATE_POLYOF = 0x04,
    REN_STATE_DEPTH  = 0x08
  };

  static const uint32 PROGRAM_ATTRIBS_LIST[] =
  {
    ATTRIB_PT_POSITION,
    ATTRIB_PT_POSITION,
    ATTRIB_PT_POSITION | ATTRIB_PT_TEX_COORD,
    ATTRIB_PT_POSITION,
    ATTRIB_PT_POSITION | ATTRIB_PT_TEX_COORD,
    ATTRIB_PNTBTC_POSITION | ATTRIB_PNTBTC_TEX_COORD | ATTRIB_PNTBTC_COLOR, // vbo attribs pack:   pos, nor, tan, tex, col
    ATTRIB_PNTBTC_POSITION | ATTRIB_PNTBTC_TEX_COORD | ATTRIB_PNTBTC_COLOR,
    ATTRIB_PNTBTC_POSITION | ATTRIB_PNTBTC_NORMAL | ATTRIB_PNTBTC_TEX_COORD | ATTRIB_PNTBTC_COLOR,
    ATTRIB_PNTBTC_POSITION | ATTRIB_PNTBTC_NORMAL | ATTRIB_PNTBTC_TEX_COORD | ATTRIB_PNTBTC_COLOR,
    ATTRIB_PNTBTC_POSITION | ATTRIB_PNTBTC_NORMAL | ATTRIB_PNTBTC_TEX_COORD | ATTRIB_PNTBTC_COLOR,
    ATTRIB_PNTBTC_POSITION | ATTRIB_PNTBTC_NORMAL | ATTRIB_PNTBTC_TEX_COORD | ATTRIB_PNTBTC_COLOR,
    ATTRIB_PNTBTC_POSITION | ATTRIB_PNTBTC_NORMAL | ATTRIB_PNTBTC_TEX_COORD | ATTRIB_PNTBTC_COLOR,
    ATTRIB_PNTBTC_POSITION | ATTRIB_PNTBTC_NORMAL | ATTRIB_PNTBTC_TEX_COORD | ATTRIB_PNTBTC_COLOR,
    ATTRIB_PNTBTC_POSITION | ATTRIB_PNTBTC_NORMAL | ATTRIB_PNTBTC_NORMAL_TANGENT | ATTRIB_PNTBTC_NORMAL_BITANGENT | ATTRIB_PNTBTC_TEX_COORD | ATTRIB_PNTBTC_COLOR,
    ATTRIB_PNTBTC_POSITION | ATTRIB_PNTBTC_NORMAL | ATTRIB_PNTBTC_NORMAL_TANGENT | ATTRIB_PNTBTC_NORMAL_BITANGENT | ATTRIB_PNTBTC_TEX_COORD | ATTRIB_PNTBTC_COLOR,
    ATTRIB_PNTBTC_POSITION | ATTRIB_PNTBTC_NORMAL | ATTRIB_PNTBTC_NORMAL_TANGENT | ATTRIB_PNTBTC_NORMAL_BITANGENT | ATTRIB_PNTBTC_TEX_COORD | ATTRIB_PNTBTC_COLOR,
    ATTRIB_PNTBTC_POSITION | ATTRIB_PNTBTC_NORMAL | ATTRIB_PNTBTC_NORMAL_TANGENT | ATTRIB_PNTBTC_NORMAL_BITANGENT | ATTRIB_PNTBTC_TEX_COORD | ATTRIB_PNTBTC_COLOR,
    ATTRIB_PNTBTC_POSITION | ATTRIB_PNTBTC_NORMAL | ATTRIB_PNTBTC_NORMAL_TANGENT | ATTRIB_PNTBTC_NORMAL_BITANGENT | ATTRIB_PNTBTC_TEX_COORD | ATTRIB_PNTBTC_COLOR,
    ATTRIB_PNTBTC_POSITION | ATTRIB_PNTBTC_NORMAL | ATTRIB_PNTBTC_NORMAL_TANGENT | ATTRIB_PNTBTC_NORMAL_BITANGENT | ATTRIB_PNTBTC_TEX_COORD | ATTRIB_PNTBTC_COLOR,
    ATTRIB_PNTBTC_POSITION | ATTRIB_PNTBTC_NORMAL | ATTRIB_PNTBTC_NORMAL_TANGENT | ATTRIB_PNTBTC_NORMAL_BITANGENT | ATTRIB_PNTBTC_TEX_COORD | ATTRIB_PNTBTC_COLOR,
    ATTRIB_PNTBTC_POSITION | ATTRIB_PNTBTC_NORMAL | ATTRIB_PNTBTC_NORMAL_TANGENT | ATTRIB_PNTBTC_NORMAL_BITANGENT | ATTRIB_PNTBTC_TEX_COORD | ATTRIB_PNTBTC_COLOR,
    ATTRIB_F,
    ATTRIB_F,
    ATTRIB_F,
    ATTRIB,
    ATTRIB,
    ATTRIB,
    ATTRIB
  };

  static const uint32 PROGRAM_UNIFORMS_LIST[] =
  {
    UNIFORM_MVP | UNIFORM_LAMB_COLOR,
    UNIFORM_MVP_SHAD,
    UNIFORM_MVP_SHAD,
    UNIFORM_MVP_SHAD_CASCADE,
    UNIFORM_MVP_SHAD_CASCADE,
    UNIFORM_MVP,
    UNIFORM_MVP | UNIFORM_OPACITY,
    UNIFORM_MVP | UNIFORM_MW | UNIFORM_MWNIT | UNIFORM_CAM | UNIFORM_TYPE | UNIFORM_OPACITY | UNIFORM_LAMB_LPOS | UNIFORM_LRAN_LCOL_LSPEC_FRAN_FCOL | UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_MVP | UNIFORM_MW | UNIFORM_MWNIT | UNIFORM_MVPSB | UNIFORM_CAM | UNIFORM_TYPE | UNIFORM_LAMB_LPOS | UNIFORM_LRAN_LCOL_LSPEC_FRAN_FCOL | UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_MVP | UNIFORM_MW | UNIFORM_MWNIT | UNIFORM_MVPSB | UNIFORM_CAM | UNIFORM_TYPE | UNIFORM_SHAD_TEX_SIZE | UNIFORM_LAMB_LPOS | UNIFORM_LRAN_LCOL_LSPEC_FRAN_FCOL | UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_MVP | UNIFORM_MW | UNIFORM_MWNIT | UNIFORM_CAM | UNIFORM_TYPE | UNIFORM_OPACITY | UNIFORM_LAMB_LPOS | UNIFORM_LRAN_LCOL_LSPEC_FRAN_FCOL | UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_MVP | UNIFORM_MW | UNIFORM_MWNIT | UNIFORM_MVPSB | UNIFORM_CAM | UNIFORM_TYPE | UNIFORM_LAMB_LPOS | UNIFORM_LRAN_LCOL_LSPEC_FRAN_FCOL | UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_MVP | UNIFORM_MW | UNIFORM_MWNIT | UNIFORM_MVPSB | UNIFORM_CAM | UNIFORM_TYPE | UNIFORM_SHAD_TEX_SIZE | UNIFORM_LAMB_LPOS | UNIFORM_LRAN_LCOL_LSPEC_FRAN_FCOL | UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_MVP | UNIFORM_MW | UNIFORM_MWNIT | UNIFORM_CAM | UNIFORM_TYPE | UNIFORM_OPACITY | UNIFORM_LAMB_LPOS | UNIFORM_LRAN_LCOL_LSPEC_FRAN_FCOL | UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_MVP | UNIFORM_MW | UNIFORM_MWNIT | UNIFORM_MVPSB | UNIFORM_CAM | UNIFORM_TYPE | UNIFORM_LAMB_LPOS | UNIFORM_LRAN_LCOL_LSPEC_FRAN_FCOL | UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_MVP | UNIFORM_MW | UNIFORM_MWNIT | UNIFORM_MVPSB | UNIFORM_CAM | UNIFORM_TYPE | UNIFORM_SHAD_TEX_SIZE | UNIFORM_LAMB_LPOS | UNIFORM_LRAN_LCOL_LSPEC_FRAN_FCOL | UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_MVP | UNIFORM_MW | UNIFORM_MWNIT | UNIFORM_CAM | UNIFORM_TYPE | UNIFORM_OPACITY | UNIFORM_LAMB_LPOS | UNIFORM_LRAN_LCOL_LSPEC_FRAN_FCOL | UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_MVP | UNIFORM_MW | UNIFORM_MWNIT | UNIFORM_MVPSB | UNIFORM_CAM | UNIFORM_TYPE | UNIFORM_LAMB_LPOS | UNIFORM_LRAN_LCOL_LSPEC_FRAN_FCOL | UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_MVP | UNIFORM_MW | UNIFORM_MWNIT | UNIFORM_MVPSB | UNIFORM_CAM | UNIFORM_TYPE | UNIFORM_SHAD_TEX_SIZE | UNIFORM_LAMB_LPOS | UNIFORM_LRAN_LCOL_LSPEC_FRAN_FCOL | UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_MVP_GEOM | UNIFORM_MW | UNIFORM_MWNIT | UNIFORM_TYPE,
    UNIFORM_MVP_GEOM_CASCADE | UNIFORM_MW | UNIFORM_MWNIT | UNIFORM_TYPE,
    UNIFORM_LAMB_LPOS_INJECT | UNIFORM_GEOM_TEX_SIZE | UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_LAMB_LPOS_INJECT | UNIFORM_GEOM_TEX_SIZE | UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_LPV_POS_TEXS_CELLS_PARAMS,
    UNIFORM_LPV_POS_TEXS_CELLS_PARAMS
  };

  static const uint32 PROGRAM_SAMPLERS_LIST[] =
  {
    SAMPLER,
    SAMPLER,
    SAMPLER_DEPTH_COLOR_KEY,
    SAMPLER,
    SAMPLER_DEPTH_COLOR_KEY,
    SAMPLER_BASIC,
    SAMPLER_BASIC_APLHA,
    SAMPLER_ILLUMINATION,
    SAMPLER_ILLUMINATION_SHADOW,
    SAMPLER_ILLUMINATION_SHADOW,
    SAMPLER_ILLUMINATION_ALPHA,
    SAMPLER_ILLUMINATION_ALPHA_SHADOW,
    SAMPLER_ILLUMINATION_ALPHA_SHADOW,
    SAMPLER_ILLUMINATION_NORMAL,
    SAMPLER_ILLUMINATION_NORMAL_SHADOW,
    SAMPLER_ILLUMINATION_NORMAL_SHADOW,
    SAMPLER_ILLUMINATION_NORMAL_ALPHA,
    SAMPLER_ILLUMINATION_NORMAL_ALPHA_SHADOW,
    SAMPLER_ILLUMINATION_NORMAL_ALPHA_SHADOW,
    SAMPLER_GEOMETRY,
    SAMPLER_GEOMETRY,
    SAMPLER_LPV_INJECTION_GEOMETRY,
    SAMPLER_LPV_PROPAGATION_GEOMETRY,
    SAMPLER_LPV_PROPAGATION_GEOMETRY,
    IMAGE_LPV_CLEAR_COMPUTE,
    IMAGE_LPV_CLEAR_COMPUTE,
    IMAGE_LPV_INJECTION_COMPUTE,
    IMAGE_LPV_PROPAGATION_COMPUTE
  };

  static const uint32 PROGRAM_RENDER_STATES_LIST[] =
  {
    REN_STATE_CULL,
    REN_STATE_CULL | REN_STATE_POLYOF,
    REN_STATE_CULL | REN_STATE_POLYOF,
    REN_STATE_CULL | REN_STATE_POLYOF,
    REN_STATE_CULL | REN_STATE_POLYOF,
    REN_STATE,
    REN_STATE_BLEND,
    REN_STATE,
    REN_STATE,
    REN_STATE,
    REN_STATE_BLEND,
    REN_STATE_BLEND,
    REN_STATE_BLEND,
    REN_STATE,
    REN_STATE,
    REN_STATE,
    REN_STATE_BLEND,
    REN_STATE_BLEND,
    REN_STATE_BLEND,
    REN_STATE_CULL,
    REN_STATE_CULL,
    REN_STATE_DEPTH,
    REN_STATE_DEPTH,
    REN_STATE_DEPTH,
    REN_STATE,
    REN_STATE,
    REN_STATE,
    REN_STATE
  };

  // texture samplers ----------------------------------------------------------
  enum ESamplerTex
  {
    SAMPLER_TEX_DEPTH_COLOR_KEY_DIF = 0,

    SAMPLER_TEX_BASIC_DIF = 0,

    SAMPLER_TEX_BASIC_APLHA_DIF = 0,
    SAMPLER_TEX_BASIC_APLHA_ALP,

    SAMPLER_TEX_ILLUMINATION_DIF = 0,
    SAMPLER_TEX_ILLUMINATION_SPE,
    SAMPLER_TEX_ILLUMINATION_DEPTH,
    SAMPLER_TEX_ILLUMINATION_LPV0_R,
    SAMPLER_TEX_ILLUMINATION_LPV0_G,
    SAMPLER_TEX_ILLUMINATION_LPV0_B,

    SAMPLER_TEX_ILLUMINATION_ALPHA_DIF = 0,
    SAMPLER_TEX_ILLUMINATION_ALPHA_ALP,
    SAMPLER_TEX_ILLUMINATION_ALPHA_SPE,
    SAMPLER_TEX_ILLUMINATION_ALPHA_DEPTH,
    SAMPLER_TEX_ILLUMINATION_ALPHA_LPV0_R,
    SAMPLER_TEX_ILLUMINATION_ALPHA_LPV0_G,
    SAMPLER_TEX_ILLUMINATION_ALPHA_LPV0_B,

    SAMPLER_TEX_ILLUMINATION_NORMAL_DIF = 0,
    SAMPLER_TEX_ILLUMINATION_NORMAL_SPE,
    SAMPLER_TEX_ILLUMINATION_NORMAL_NOR,
    SAMPLER_TEX_ILLUMINATION_NORMAL_DEPTH,
    SAMPLER_TEX_ILLUMINATION_NORMAL_LPV0_R,
    SAMPLER_TEX_ILLUMINATION_NORMAL_LPV0_G,
    SAMPLER_TEX_ILLUMINATION_NORMAL_LPV0_B,

    SAMPLER_TEX_ILLUMINATION_NORMAL_ALPHA_DIF = 0,
    SAMPLER_TEX_ILLUMINATION_NORMAL_ALPHA_ALP,
    SAMPLER_TEX_ILLUMINATION_NORMAL_ALPHA_SPE,
    SAMPLER_TEX_ILLUMINATION_NORMAL_ALPHA_NOR,
    SAMPLER_TEX_ILLUMINATION_NORMAL_ALPHA_DEPTH,
    SAMPLER_TEX_ILLUMINATION_NORMAL_ALPHA_LPV0_R,
    SAMPLER_TEX_ILLUMINATION_NORMAL_ALPHA_LPV0_G,
    SAMPLER_TEX_ILLUMINATION_NORMAL_ALPHA_LPV0_B,

    SAMPLER_TEX_GEOMETRY_DIF = 0,
    SAMPLER_TEX_GEOMETRY_NOR,

    SAMPLER_TEX_LPV_INJECTION_GEOMETRY_GEOM_COLOR = 0,
    SAMPLER_TEX_LPV_INJECTION_GEOMETRY_GEOM_POS,
    SAMPLER_TEX_LPV_INJECTION_GEOMETRY_GEOM_NORMAL,
    //SAMPLER_TEX_LPV_INJECTION_GEOMETRY_GEOM_DEPTH,

    SAMPLER_TEX_LPV_PROPAGATION_GEOMETRY_LPV_R = 0, // swap in
    SAMPLER_TEX_LPV_PROPAGATION_GEOMETRY_LPV_G,
    SAMPLER_TEX_LPV_PROPAGATION_GEOMETRY_LPV_B,
    SAMPLER_TEX_LPV_PROPAGATION_GEOMETRY_GV,

    IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV0_R = 0,
    IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV0_G,
    IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV0_B,
    IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV1_R,
    IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV1_G,
    IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV1_B,
    IMAGE_TEX_LPV_CLEAR_COMPUTE_GV,

    IMAGE_TEX_LPV_INJECTION_COMPUTE_GEOM_COLOR = 0,
    IMAGE_TEX_LPV_INJECTION_COMPUTE_GEOM_POS,
    IMAGE_TEX_LPV_INJECTION_COMPUTE_GEOM_NORMAL,
    //IMAGE_TEX_LPV_INJECTION_COMPUTE_GEOM_DEPTH,
    IMAGE_TEX_LPV_INJECTION_COMPUTE_LPV_R, // out
    IMAGE_TEX_LPV_INJECTION_COMPUTE_LPV_G,
    IMAGE_TEX_LPV_INJECTION_COMPUTE_LPV_B,
    IMAGE_TEX_LPV_INJECTION_COMPUTE_GV,

    IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_R = 0, // out
    IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_G,
    IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_B,
    IMAGE_TEX_LPV_PROPAGATION_COMPUTE_GV, // static
    IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV0_R, // swap in
    IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV0_G,
    IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV0_B,
    IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV1_R, // swap out
    IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV1_G,
    IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV1_B,
  };
}
//------------------------------------------------------------------------------
struct SShaderUniforms
{
  GLint vertexPosition;
  GLint vertexNormal;
  GLint vertexNormalTangent;
  GLint vertexNormalBitangent;
  GLint vertexTexCoord;
  GLint vertexColor;

  GLint mw;
  GLint mwnit;
  GLint mvp;
  GLint mvpsb;
  GLint cam;

  GLint difTex;
  GLint alpTex;
  GLint speTex;
  GLint norTex;
  //GLint envTex;
  GLint shadTex;

  GLint geomColorTex;
  GLint geomPosTex;
  GLint geomNormalTex;
  //GLint geomDepthTex;

  GLint lpvTexR;
  GLint lpvTexG;
  GLint lpvTexB;
  GLint gvTex;
  GLint lpv0TexR;
  GLint lpv0TexG;
  GLint lpv0TexB;
  GLint lpv1TexR;
  GLint lpv1TexG;
  GLint lpv1TexB;

  GLint type;
  GLint opacity;
  GLint shadowTexSize;

  GLint lightAmb;
  GLint lightPos;
  GLint lightRange;
  GLint lightColor;
  GLint lightSpeColor;

  GLint fogRange;
  GLint fogColor;

  GLint geomTexSize;
  GLint lpvPos;
  GLint lpvTexSize;
  GLint lpvCellSize;
  GLint lpvParams;

  const CMap *shadowMap; // out shadow
  const CMap *geomColorMap; // lpv in geometry
  const CMap *geomPosMap;
  const CMap *geomNormalMap;
  //const CMap *geomDepthMap;

  const CMap *lpvGs0MapR; // gl32 fbo swap textures, out lpv
  const CMap *lpvGs0MapG;
  const CMap *lpvGs0MapB;
  const CMap *gvGs0Map;
  const CMap *lpvGs1MapR;
  const CMap *lpvGs1MapG;
  const CMap *lpvGs1MapB;
  const CMap *gvGs1Map;

  const CMap *lpvCs0MapR; // gl43 swap images
  const CMap *lpvCs0MapG;
  const CMap *lpvCs0MapB;
  const CMap *lpvCs1MapR;
  const CMap *lpvCs1MapG;
  const CMap *lpvCs1MapB;
  const CMap *gvCsMap;

  inline SShaderUniforms() : vertexPosition(0), vertexNormal(0), vertexNormalTangent(0), vertexNormalBitangent(0), vertexTexCoord(0), vertexColor(0),
    mw(0), mwnit(0), mvp(0), mvpsb(0), cam(0),
    difTex(0), alpTex(0), speTex(0), norTex(0), /*envTex(0), */shadTex(0),
    geomColorTex(0), geomPosTex(0), geomNormalTex(0), /*geomDepthTex(0),*/
    lpvTexR(0), lpvTexG(0), lpvTexB(0), gvTex(0), lpv0TexR(0), lpv0TexG(0), lpv0TexB(0), lpv1TexR(0), lpv1TexG(0), lpv1TexB(0),
    type(0), opacity(0), shadowTexSize(0),
    lightAmb(0), lightPos(0), lightRange(0), lightColor(0), lightSpeColor(0),
    fogRange(0), fogColor(0),
    geomTexSize(0), lpvPos(0), lpvTexSize(0), lpvCellSize(0), lpvParams(0),
    shadowMap(NULL), geomColorMap(NULL), geomPosMap(NULL), geomNormalMap(NULL), /*geomDepthMap(NULL),*/
    lpvGs0MapR(NULL), lpvGs0MapG(NULL), lpvGs0MapB(NULL), gvGs0Map(NULL), 
    lpvGs1MapR(NULL), lpvGs1MapG(NULL), lpvGs1MapB(NULL), gvGs1Map(NULL),
    lpvCs0MapR(NULL), lpvCs0MapG(NULL), lpvCs0MapB(NULL), lpvCs1MapR(NULL), lpvCs1MapG(NULL), lpvCs1MapB(NULL), gvCsMap(NULL)
  {
  }
};
//------------------------------------------------------------------------------
struct SShaderLight
{
  glm::vec3 pos;
  glm::vec2 range;
  glm::vec3 color;
  glm::vec4 speColor;

  inline SShaderLight() {}
};
//------------------------------------------------------------------------------
struct SShaderState
{
  glm::mat4 mw; // trochu špatně modelované -> dupliticní pro lody, ale dejme tomu
  glm::mat3 mwnit;
  mutable glm::mat4 mvp;
  mutable float mvps[NMath::MAT4 * NEngine::SHADOW_CASCADES_COUNT]; // shadow mvps
  mutable float mvpsb[NMath::MAT4 * NEngine::SHADOW_CASCADES_COUNT]; // shadow mvps biased
  mutable float mvpg[NMath::MAT4 * NEngine::LPV_CASCADES_COUNT * NEngine::LPV_SUN_SKY_DIRS_COUNT]; // geometry mvps
  mutable glm::vec3 cam;

  mutable const SMaterial *material;

  SBoundingBox aabb;
  glm::vec3 pickColor;
  glm::vec3 lightAmb;
  SShaderLight lights[NEngine::LPV_SUN_SKY_DIRS_COUNT];

  glm::vec2 fogRange;
  glm::vec3 fogColor;

  inline SShaderState() : material(NULL) {}
};
//------------------------------------------------------------------------------
struct SShader
{
  std::string name;
  NShader::EType type;
  std::string file;
  std::string defines;
  GLuint shader;

  inline SShader() : type(NShader::TYPE_UNDEFINED), shader(0) {}
  inline SShader(const std::string &name, NShader::EType type, const std::string &file, const std::string &defines = std::string(), GLuint shader = 0) : name(name), type(type), file(file), defines(defines), shader(shader) {}
};

class CShader;
//------------------------------------------------------------------------------
struct SShaderProgram
{
  NShader::EProgram name;
  CShader *vertexShader;
  CShader *tesselationControlShader;
  CShader *tesselationEvaluationShader;
  CShader *geometryShader;
  CShader *fragmentShader;
  CShader *computeShader;
  uint32 fAttribs;
  uint32 fUniforms;
  uint32 fSamplers;
  uint32 fRenderStates;
  GLuint program;
  SShaderUniforms uniforms;

  inline SShaderProgram() :
    name(NShader::PROGRAM_BASIC),
    vertexShader(NULL),
    tesselationControlShader(NULL),
    tesselationEvaluationShader(NULL),
    geometryShader(NULL),
    fragmentShader(NULL),
    computeShader(NULL),
    fAttribs(NShader::ATTRIB),
    fUniforms(NShader::UNIFORM),
    fSamplers(NShader::SAMPLER),
    fRenderStates(NShader::REN_STATE),
    program(0) {}

  inline SShaderProgram(
    NShader::EProgram name,
    CShader *vertexShader,
    CShader *tesselationControlShader,
    CShader *tesselationEvaluationShader,
    CShader *geometryShader,
    CShader *fragmentShader,
    CShader *computeShader,
    uint32 fAttribs = NShader::ATTRIB,
    uint32 fUniforms = NShader::UNIFORM,
    uint32 fSamplers = NShader::SAMPLER,
    uint32 fRenderStates = NShader::REN_STATE,
    GLuint program = 0,
    SShaderUniforms uniforms = SShaderUniforms()) :
      name(name),
      vertexShader(vertexShader),
      tesselationControlShader(tesselationControlShader),
      tesselationEvaluationShader(tesselationEvaluationShader),
      geometryShader(geometryShader),
      fragmentShader(fragmentShader),
      computeShader(computeShader),
      fAttribs(fAttribs),
      fUniforms(fUniforms),
      fSamplers(fSamplers),
      fRenderStates(fRenderStates),
      program(program),
      uniforms(uniforms) {}
};
//------------------------------------------------------------------------------
#endif // SHADERSTYPES_H
