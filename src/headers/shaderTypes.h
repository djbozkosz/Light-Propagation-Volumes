//------------------------------------------------------------------------------
#ifndef SHADERSTYPES_H
#define SHADERSTYPES_H

#include "mapTypes.h"
#include "modelTypes.h"

//------------------------------------------------------------------------------
namespace NShader
{
  static const uint32 VERTEX_SHADERS_COUNT = 12;
  static const uint32 GEOMETRY_SHADERS_COUNT = 5;
  static const uint32 TESSELATION_CONTROL_SHADERS_COUNT = 0;
  static const uint32 TESSELATION_EVALUATION_SHADERS_COUNT = 0;
  static const uint32 FRAGMENT_SHADERS_COUNT = 20;
  static const uint32 COMPUTE_SHADERS_COUNT = 4;
  static const uint32 PROGRAMS_COUNT = 28;

  static const uint8 SHADER_MAX_LIGHTS = 1;

  static const GLint ATTRIB_UNDEFINED = -1;
  static const GLint UNIFORM_UNDEFINED = -1;

  static const char STR_ATTRIB_VERTEX_POSITION[] = "_vertexPosition"; // precending '_' due to bug in old ATI drivers - attributes must have "lower name" in alphabet than gl_VertexID or gl_InstanceID
  static const char STR_ATTRIB_VERTEX_NORMAL[] = "_vertexNormal";
  static const char STR_ATTRIB_VERTEX_NORMAL_TANGENT[] = "_vertexNormalTangent";
  //static const char STR_ATTRIB_VERTEX_NORMAL_BITANGENT[] = "_vertexNormalBitangent";
  static const char STR_ATTRIB_VERTEX_TEX_COORD[] = "_vertexTexCoord";
  static const char STR_ATTRIB_VERTEX_COLOR[] = "_vertexColor";

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
  static const char STR_UNIFORM_LPV_SIZE[] = "lpvSize"; // vec3, e.g. 32, 32, 32
  static const char STR_UNIFORM_LPV_CELL_SIZE[] = "lpvCellSize"; // vec3[], e.g.   0.1, 0.1, 0.1,   0.3, 0.3, 0.3,   ...
  static const char STR_UNIFORM_LPV_PARAMS[] = "lpvParams"; // vec2 - propag. count, intensity

  static const char STR_SHADER_UNUSED[] = "";

  static const char STR_VERTEX_COLOR[] = "color.vs";
  static const char STR_VERTEX_DEPTH[] = "depth.vs";
  static const char STR_VERTEX_DEPTH_CASCADE[] = "depthCascade.vs";
  static const char STR_VERTEX_BASIC[] = "basic.vs";
  static const char STR_VERTEX_PER_FRAGMENT[] = "perFragment.vs";
  static const char STR_VERTEX_PER_FRAGMENT_SHADOW[] = "perFragmentShadow.vs";
  static const char STR_VERTEX_PER_FRAGMENT_NORMAL[] = "perFragmentNormal.vs";
  static const char STR_VERTEX_PER_FRAGMENT_NORMAL_SHADOW[] = "perFragmentNormalShadow.vs";
  static const char STR_VERTEX_GEOMETRY[] = "geometry.vs";
  static const char STR_VERTEX_GEOMETRY_CASCADE[] = "geometryCascade.vs";
  static const char STR_VERTEX_LPV_INJECTION[] = "lpvInjection.vs";
  static const char STR_VERTEX_LPV_PROPAGATION[] = "lpvPropagation.vs";

  static const char STR_GEOMETRY_DEPTH_CASCADE[] = "depthCascade.gs";
  static const char STR_GEOMETRY_GEOMETRY_CASCADE[] = "geometryCascade.gs";
  static const char STR_GEOMETRY_LPV_INJECTION[] = "lpvInjection.gs";
  static const char STR_GEOMETRY_LPV_PROPAGATION_GATHERING[] = "lpvPropagationGathering.gs";
  static const char STR_GEOMETRY_LPV_PROPAGATION_SCATTERING[] = "lpvPropagationScattering.gs";

  static const char STR_FRAGMENT_COLOR[] = "color.fs";
  static const char STR_FRAGMENT_DEPTH[] = "depth.fs";
  static const char STR_FRAGMENT_DEPTH_COLOR_KEY[] = "depthColorKey.fs";
  static const char STR_FRAGMENT_BASIC[] = "basic.fs";
  static const char STR_FRAGMENT_BASIC_ALPHA[] = "basicAlpha.fs";
  static const char STR_FRAGMENT_PER_FRAGMENT[] = "perFragment.fs";
  static const char STR_FRAGMENT_PER_FRAGMENT_SHADOW[] = "perFragmentShadow.fs";
  static const char STR_FRAGMENT_PER_FRAGMENT_SHADOW_JITTER[] = "perFragmentShadowJitter.fs";
  static const char STR_FRAGMENT_PER_FRAGMENT_ALPHA[] = "perFragmentAlpha.fs";
  static const char STR_FRAGMENT_PER_FRAGMENT_ALPHA_SHADOW[] = "perFragmentAlphaShadow.fs";
  static const char STR_FRAGMENT_PER_FRAGMENT_ALPHA_SHADOW_JITTER[] = "perFragmentAlphaShadowJitter.fs";
  static const char STR_FRAGMENT_PER_FRAGMENT_NORMAL[] = "perFragmentNormal.fs";
  static const char STR_FRAGMENT_PER_FRAGMENT_NORMAL_SHADOW[] = "perFragmentNormalShadow.fs";
  static const char STR_FRAGMENT_PER_FRAGMENT_NORMAL_SHADOW_JITTER[] = "perFragmentNormalShadowJitter.fs";
  static const char STR_FRAGMENT_PER_FRAGMENT_NORMAL_ALPHA[] = "perFragmentNormalAlpha.fs";
  static const char STR_FRAGMENT_PER_FRAGMENT_NORMAL_ALPHA_SHADOW[] = "perFragmentNormalAlphaShadow.fs";
  static const char STR_FRAGMENT_PER_FRAGMENT_NORMAL_ALPHA_SHADOW_JITTER[] = "perFragmentNormalAlphaShadowJitter.fs";
  static const char STR_FRAGMENT_GEOMETRY[] = "geometry.fs";
  static const char STR_FRAGMENT_LPV_INJECTION[] = "lpvInjection.fs";
  static const char STR_FRAGMENT_LPV_PROPAGATION[] = "lpvPropagation.fs";

  static const char STR_COMPUTE_LPV_CLEAR[] = "lpvClear.cs";
  static const char STR_COMPUTE_LPV_INJECTION[] = "lpvInjection.cs";
  static const char STR_COMPUTE_LPV_PROPAGATION_GATHERING[] = "lpvPropagationGathering.cs";
  static const char STR_COMPUTE_LPV_PROPAGATION_SCATTERING[] = "lpvPropagationScattering.cs";

  static const char STR_ERROR_COMPILE_SKIP[] = "Shader Compilation Skip: \"%s\"!";
  static const char STR_ERROR_LINK_SKIP[] = "Program Link Skip: \"%s\"!";
  static const char STR_ERROR_COMPILE[] = "Shader Compilation Error: \"%s\"!";
  static const char STR_ERROR_LINK[] = "Program Link Error: \"%s\"!";
  //static const char STR_ERROR_VERTEX_ATTACH[] = "No Vertex Shader attached to Program: \"%s\"";
  //static const char STR_ERROR_FRAGMENT_ATTACH[] = "No Fragment Shader attached to Program: \"%s\"";

  static const char *const STR_PROGRAM_LIST[] =
  {
    "Color",
    "Depth",
    "Depth Color Key",
    "Depth Cascade",
    "Depth Cascade Color Key",
    "Basic",
    "Basic Alpha",
    "Per Fragment",
    "Per Fragment Shadow",
    "Per Fragment Shadow Jitter",
    "Per Fragment Alpha",
    "Per Fragment Alpha Shadow",
    "Per Fragment Alpha Shadow Jitter",
    "Per Fragment Normal",
    "Per Fragment Normal Shadow",
    "Per Fragment Normal Shadow Jitter",
    "Per Fragment Normal Alpha",
    "Per Fragment Normal Alpha Shadow",
    "Per Fragment Normal Alpha Shadow Jitter",
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

  // unique lists --------------------------------------------------------------
  static const char *const STR_VERTEX_SHADER_LIST[] =
  {
    STR_VERTEX_COLOR,
    STR_VERTEX_DEPTH,
    STR_VERTEX_DEPTH_CASCADE,
    STR_VERTEX_BASIC,
    STR_VERTEX_PER_FRAGMENT,
    STR_VERTEX_PER_FRAGMENT_SHADOW,
    STR_VERTEX_PER_FRAGMENT_NORMAL,
    STR_VERTEX_PER_FRAGMENT_NORMAL_SHADOW,
    STR_VERTEX_GEOMETRY,
    STR_VERTEX_GEOMETRY_CASCADE,
    STR_VERTEX_LPV_INJECTION,
    STR_VERTEX_LPV_PROPAGATION
  };

  static const char *const STR_GEOMETRY_SHADER_LIST[] =
  {
    STR_GEOMETRY_DEPTH_CASCADE,
    STR_GEOMETRY_GEOMETRY_CASCADE,
    STR_GEOMETRY_LPV_INJECTION,
    STR_GEOMETRY_LPV_PROPAGATION_GATHERING,
    STR_GEOMETRY_LPV_PROPAGATION_SCATTERING
  };

  static const char *const STR_TESSELATION_CONTROL_SHADER_LIST[] =
  {
    STR_SHADER_UNUSED
  };
  static const char *const STR_TESSELATION_EVALUATION_SHADER_LIST[] =
  {
    STR_SHADER_UNUSED
  };

  static const char *const STR_FRAGMENT_SHADER_LIST[] =
  {
    STR_FRAGMENT_COLOR,
    STR_FRAGMENT_DEPTH,
    STR_FRAGMENT_DEPTH_COLOR_KEY,
    STR_FRAGMENT_BASIC,
    STR_FRAGMENT_BASIC_ALPHA,
    STR_FRAGMENT_PER_FRAGMENT,
    STR_FRAGMENT_PER_FRAGMENT_SHADOW,
    STR_FRAGMENT_PER_FRAGMENT_SHADOW_JITTER,
    STR_FRAGMENT_PER_FRAGMENT_ALPHA,
    STR_FRAGMENT_PER_FRAGMENT_ALPHA_SHADOW,
    STR_FRAGMENT_PER_FRAGMENT_ALPHA_SHADOW_JITTER,
    STR_FRAGMENT_PER_FRAGMENT_NORMAL,
    STR_FRAGMENT_PER_FRAGMENT_NORMAL_SHADOW,
    STR_FRAGMENT_PER_FRAGMENT_NORMAL_SHADOW_JITTER,
    STR_FRAGMENT_PER_FRAGMENT_NORMAL_ALPHA,
    STR_FRAGMENT_PER_FRAGMENT_NORMAL_ALPHA_SHADOW,
    STR_FRAGMENT_PER_FRAGMENT_NORMAL_ALPHA_SHADOW_JITTER,
    STR_FRAGMENT_GEOMETRY,
    STR_FRAGMENT_LPV_INJECTION,
    STR_FRAGMENT_LPV_PROPAGATION
  };

  static const char *const STR_COMPUTE_SHADER_LIST[] =
  {
    STR_COMPUTE_LPV_CLEAR,
    STR_COMPUTE_LPV_INJECTION,
    STR_COMPUTE_LPV_PROPAGATION_GATHERING,
    STR_COMPUTE_LPV_PROPAGATION_SCATTERING
  };

  // linking lists -------------------------------------------------------------
  static const char *const STR_PROGRAM_VERTEX_SHADER_LIST[] =
  {
    STR_VERTEX_COLOR,
    STR_VERTEX_DEPTH,
    STR_VERTEX_DEPTH,
    STR_VERTEX_DEPTH_CASCADE,
    STR_VERTEX_DEPTH_CASCADE,
    STR_VERTEX_BASIC,
    STR_VERTEX_BASIC,
    STR_VERTEX_PER_FRAGMENT,
    STR_VERTEX_PER_FRAGMENT_SHADOW,
    STR_VERTEX_PER_FRAGMENT_SHADOW,
    STR_VERTEX_PER_FRAGMENT,
    STR_VERTEX_PER_FRAGMENT_SHADOW,
    STR_VERTEX_PER_FRAGMENT_SHADOW,
    STR_VERTEX_PER_FRAGMENT_NORMAL,
    STR_VERTEX_PER_FRAGMENT_NORMAL_SHADOW,
    STR_VERTEX_PER_FRAGMENT_NORMAL_SHADOW,
    STR_VERTEX_PER_FRAGMENT_NORMAL,
    STR_VERTEX_PER_FRAGMENT_NORMAL_SHADOW,
    STR_VERTEX_PER_FRAGMENT_NORMAL_SHADOW,
    STR_VERTEX_GEOMETRY,
    STR_VERTEX_GEOMETRY_CASCADE,
    STR_VERTEX_LPV_INJECTION,
    STR_VERTEX_LPV_PROPAGATION,
    STR_VERTEX_LPV_PROPAGATION,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED
  };

  static const char *const STR_PROGRAM_GEOMETRY_SHADER_LIST[] =
  {
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_GEOMETRY_DEPTH_CASCADE,
    STR_GEOMETRY_DEPTH_CASCADE,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_GEOMETRY_GEOMETRY_CASCADE,
    STR_GEOMETRY_LPV_INJECTION,
    STR_GEOMETRY_LPV_PROPAGATION_GATHERING,
    STR_GEOMETRY_LPV_PROPAGATION_SCATTERING,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED
  };

  static const char *const STR_PROGRAM_TESSELATION_CONTROL_SHADER_LIST[] =
  {
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED
  };
  static const char *const STR_PROGRAM_TESSELATION_EVALUATION_SHADER_LIST[] =
  {
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED
  };

  static const char *const STR_PROGRAM_FRAGMENT_SHADER_LIST[] =
  {
    STR_FRAGMENT_COLOR,
    STR_FRAGMENT_DEPTH,
    STR_FRAGMENT_DEPTH_COLOR_KEY,
    STR_FRAGMENT_DEPTH,
    STR_FRAGMENT_DEPTH_COLOR_KEY,
    STR_FRAGMENT_BASIC,
    STR_FRAGMENT_BASIC_ALPHA,
    STR_FRAGMENT_PER_FRAGMENT,
    STR_FRAGMENT_PER_FRAGMENT_SHADOW,
    STR_FRAGMENT_PER_FRAGMENT_SHADOW_JITTER,
    STR_FRAGMENT_PER_FRAGMENT_ALPHA,
    STR_FRAGMENT_PER_FRAGMENT_ALPHA_SHADOW,
    STR_FRAGMENT_PER_FRAGMENT_ALPHA_SHADOW_JITTER,
    STR_FRAGMENT_PER_FRAGMENT_NORMAL,
    STR_FRAGMENT_PER_FRAGMENT_NORMAL_SHADOW,
    STR_FRAGMENT_PER_FRAGMENT_NORMAL_SHADOW_JITTER,
    STR_FRAGMENT_PER_FRAGMENT_NORMAL_ALPHA,
    STR_FRAGMENT_PER_FRAGMENT_NORMAL_ALPHA_SHADOW,
    STR_FRAGMENT_PER_FRAGMENT_NORMAL_ALPHA_SHADOW_JITTER,
    STR_FRAGMENT_GEOMETRY,
    STR_FRAGMENT_GEOMETRY,
    STR_FRAGMENT_LPV_INJECTION,
    STR_FRAGMENT_LPV_PROPAGATION,
    STR_FRAGMENT_LPV_PROPAGATION,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED
  };

  static const char *const STR_PROGRAM_COMPUTE_SHADER_LIST[] =
  {
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_COMPUTE_LPV_CLEAR,
    STR_COMPUTE_LPV_INJECTION,
    STR_COMPUTE_LPV_PROPAGATION_GATHERING,
    STR_COMPUTE_LPV_PROPAGATION_SCATTERING
  };

  enum EType
  {
    TYPE_UNDEFINED = 0,
    TYPE_VERTEX,
    TYPE_GEOMETRY,
    TYPE_TESSELATION_CONTROL,
    TYPE_TESSELATION_EVALUATION,
    TYPE_FRAGMENT,
    TYPE_COMPUTE
  };

  static const GLenum TYPE_SHADERS[] =
  {
    NOpenGL::NONE,
    NOpenGL::VERTEX_SHADER,
    NOpenGL::GEOMETRY_SHADER,
    NOpenGL::TESS_CONTROL_SHADER,
    NOpenGL::TESS_EVALUATION_SHADER, 
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
    PROGRAM_PER_FRAGMENT,
    PROGRAM_PER_FRAGMENT_SHADOW,
    PROGRAM_PER_FRAGMENT_SHADOW_JITTER,
    PROGRAM_PER_FRAGMENT_ALPHA,
    PROGRAM_PER_FRAGMENT_ALPHA_SHADOW,
    PROGRAM_PER_FRAGMENT_ALPHA_SHADOW_JITTER,
    PROGRAM_PER_FRAGMENT_NORMAL,
    PROGRAM_PER_FRAGMENT_NORMAL_SHADOW,
    PROGRAM_PER_FRAGMENT_NORMAL_SHADOW_JITTER,
    PROGRAM_PER_FRAGMENT_NORMAL_ALPHA,
    PROGRAM_PER_FRAGMENT_NORMAL_ALPHA_SHADOW,
    PROGRAM_PER_FRAGMENT_NORMAL_ALPHA_SHADOW_JITTER,
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

  enum ESampler
  {
    SAMPLER_BASIC_DIF = 0,

    SAMPLER_BASIC_APLHA_DIF = 0,
    SAMPLER_BASIC_APLHA_ALP,

    SAMPLER_DEPTH_COLOR_KEY_DIF = 0,

    SAMPLER_PER_FRAGMENT_DIF = 0,
    SAMPLER_PER_FRAGMENT_SPE,
    SAMPLER_PER_FRAGMENT_DEPTH,
    SAMPLER_PER_FRAGMENT_LPV0_R,
    SAMPLER_PER_FRAGMENT_LPV0_G,
    SAMPLER_PER_FRAGMENT_LPV0_B,

    SAMPLER_PER_FRAGMENT_ALPHA_DIF = 0,
    SAMPLER_PER_FRAGMENT_ALPHA_ALP,
    SAMPLER_PER_FRAGMENT_ALPHA_SPE,
    SAMPLER_PER_FRAGMENT_ALPHA_DEPTH,
    SAMPLER_PER_FRAGMENT_ALPHA_LPV0_R,
    SAMPLER_PER_FRAGMENT_ALPHA_LPV0_G,
    SAMPLER_PER_FRAGMENT_ALPHA_LPV0_B,

    SAMPLER_PER_FRAGMENT_NORMAL_DIF = 0,
    SAMPLER_PER_FRAGMENT_NORMAL_SPE,
    SAMPLER_PER_FRAGMENT_NORMAL_NOR,
    SAMPLER_PER_FRAGMENT_NORMAL_DEPTH,
    SAMPLER_PER_FRAGMENT_NORMAL_LPV0_R,
    SAMPLER_PER_FRAGMENT_NORMAL_LPV0_G,
    SAMPLER_PER_FRAGMENT_NORMAL_LPV0_B,

    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_DIF = 0,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_ALP,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_SPE,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_NOR,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_DEPTH,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_LPV0_R,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_LPV0_G,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_LPV0_B,

    SAMPLER_GEOMETRY_DIF = 0,
    SAMPLER_GEOMETRY_NOR,

    SAMPLER_LPV_INJECTION_GEOMETRY_GEOM_COLOR = 0,
    SAMPLER_LPV_INJECTION_GEOMETRY_GEOM_POS,
    SAMPLER_LPV_INJECTION_GEOMETRY_GEOM_NORMAL,
    //SAMPLER_LPV_INJECTION_GEOMETRY_GEOM_DEPTH,

    SAMPLER_LPV_PROPAGATION_GEOMETRY_LPV_R = 0, // swap in
    SAMPLER_LPV_PROPAGATION_GEOMETRY_LPV_G,
    SAMPLER_LPV_PROPAGATION_GEOMETRY_LPV_B,
    SAMPLER_LPV_PROPAGATION_GEOMETRY_GV,

    IMAGE_LPV_CLEAR_COMPUTE_LPV0_R = 0,
    IMAGE_LPV_CLEAR_COMPUTE_LPV0_G,
    IMAGE_LPV_CLEAR_COMPUTE_LPV0_B,
    IMAGE_LPV_CLEAR_COMPUTE_LPV1_R,
    IMAGE_LPV_CLEAR_COMPUTE_LPV1_G,
    IMAGE_LPV_CLEAR_COMPUTE_LPV1_B,
    IMAGE_LPV_CLEAR_COMPUTE_GV,

    IMAGE_LPV_INJECTION_COMPUTE_GEOM_COLOR = 0,
    IMAGE_LPV_INJECTION_COMPUTE_GEOM_POS,
    IMAGE_LPV_INJECTION_COMPUTE_GEOM_NORMAL,
    //IMAGE_LPV_INJECTION_COMPUTE_GEOM_DEPTH,
    IMAGE_LPV_INJECTION_COMPUTE_LPV_R, // out
    IMAGE_LPV_INJECTION_COMPUTE_LPV_G,
    IMAGE_LPV_INJECTION_COMPUTE_LPV_B,
    IMAGE_LPV_INJECTION_COMPUTE_GV,

    IMAGE_LPV_PROPAGATION_COMPUTE_LPV_R = 0, // out
    IMAGE_LPV_PROPAGATION_COMPUTE_LPV_G,
    IMAGE_LPV_PROPAGATION_COMPUTE_LPV_B,
    IMAGE_LPV_PROPAGATION_COMPUTE_GV, // static
    IMAGE_LPV_PROPAGATION_COMPUTE_LPV0_R, // swap in
    IMAGE_LPV_PROPAGATION_COMPUTE_LPV0_G,
    IMAGE_LPV_PROPAGATION_COMPUTE_LPV0_B,
    IMAGE_LPV_PROPAGATION_COMPUTE_LPV1_R, // swap out
    IMAGE_LPV_PROPAGATION_COMPUTE_LPV1_G,
    IMAGE_LPV_PROPAGATION_COMPUTE_LPV1_B,
  };
}
//------------------------------------------------------------------------------
struct SShaderUniforms
{
  GLint vertexPosition;
  GLint vertexNormal;
  GLint vertexNormalTangent;
  //GLint vertexNormalBitangent;
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
  GLint lpvSize;
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

  inline SShaderUniforms() : vertexPosition(0), vertexNormal(0), vertexNormalTangent(0), /*vertexNormalBitangent(0), */vertexTexCoord(0), vertexColor(0),
    mw(0), mwnit(0), mvp(0), mvpsb(0), cam(0),
    difTex(0), alpTex(0), speTex(0), norTex(0), /*envTex(0), */shadTex(0),
    geomColorTex(0), geomPosTex(0), geomNormalTex(0), /*geomDepthTex(0),*/
    lpvTexR(0), lpvTexG(0), lpvTexB(0), gvTex(0), lpv0TexR(0), lpv0TexG(0), lpv0TexB(0), lpv1TexR(0), lpv1TexG(0), lpv1TexB(0),
    type(0), opacity(0), shadowTexSize(0),
    lightAmb(0), lightPos(0), lightRange(0), lightColor(0), lightSpeColor(0),
    fogRange(0), fogColor(0),
    geomTexSize(0), lpvPos(0), lpvSize(0), lpvCellSize(0), lpvParams(0),
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
struct SShaderTechnique
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

  inline SShaderTechnique() : material(NULL) {}
};
//------------------------------------------------------------------------------
struct SShader
{
  NShader::EType type;
  std::string file;
  GLuint shader;

  inline SShader() : type(NShader::TYPE_UNDEFINED), shader(0) {}
  inline SShader(NShader::EType type, const std::string &file, GLuint shader = 0) : type(type), file(file), shader(shader) {}
};

class CShader;
//------------------------------------------------------------------------------
struct SShaderProgram
{
  NShader::EProgram name;
  CShader *vertexShader;
  CShader *geometryShader;
  CShader *tesselationControlShader;
  CShader *tesselationEvaluationShader;
  CShader *fragmentShader;
  CShader *computeShader;
  GLuint program;
  SShaderUniforms uniforms;

  inline SShaderProgram() :
    name(NShader::PROGRAM_BASIC),
    vertexShader(NULL),
    geometryShader(NULL),
    tesselationControlShader(NULL),
    tesselationEvaluationShader(NULL),
    fragmentShader(NULL),
    computeShader(NULL),
    program(0) {}

  inline SShaderProgram(
    NShader::EProgram name,
    CShader *vertexShader,
    CShader *geometryShader,
    CShader *tesselationControlShader,
    CShader *tesselationEvaluationShader,
    CShader *fragmentShader,
    CShader *computeShader,
    GLuint program = 0,
    SShaderUniforms uniforms = SShaderUniforms()) :
      name(name),
      vertexShader(vertexShader),
      geometryShader(geometryShader),
      tesselationControlShader(tesselationControlShader),
      tesselationEvaluationShader(tesselationEvaluationShader),
      fragmentShader(fragmentShader),
      computeShader(computeShader),
      program(program),
      uniforms(uniforms) {}
};
//------------------------------------------------------------------------------
#endif // SHADERSTYPES_H
