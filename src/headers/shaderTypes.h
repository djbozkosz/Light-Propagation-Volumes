//------------------------------------------------------------------------------
#ifndef SHADERSTYPES_H
#define SHADERSTYPES_H

#include "mapTypes.h"
#include "modelTypes.h"

//------------------------------------------------------------------------------
namespace NShader
{
  static const uint32 VERTEX_SHADERS_COUNT = 8;
  static const uint32 GEOMETRY_SHADERS_COUNT = 1;
  static const uint32 TESSELATION_CONTROL_SHADERS_COUNT = 1;
  static const uint32 TESSELATION_EVALUATION_SHADERS_COUNT = 1;
  static const uint32 FRAGMENT_SHADERS_COUNT = 17;
  static const uint32 COMPUTE_SHADERS_COUNT = 3;
  static const uint32 PROGRAMS_COUNT = 20;

  static const uint8 SHADER_MAX_LIGHTS = 1;

  static const char STR_ATTRIB_VERTEX_POSITION[] = "vertexPosition";
  static const char STR_ATTRIB_VERTEX_NORMAL[] = "vertexNormal";
  static const char STR_ATTRIB_VERTEX_NORMAL_TANGENT[] = "vertexNormalTangent";
  //static const char STR_ATTRIB_VERTEX_NORMAL_BITANGENT[] = "vertexNormalBitangent";
  static const char STR_ATTRIB_VERTEX_TEX_COORD[] = "vertexTexCoord";
  static const char STR_ATTRIB_VERTEX_COLOR[] = "vertexColor";

  static const char STR_UNIFORM_MW[] = "mw"; // model world (4x4)
  static const char STR_UNIFORM_MWNIT[] = "mwnit"; // model world normal inversed transposed (3x3)
  static const char STR_UNIFORM_MVP[] = "mvp"; // projection * view * model world (4x4)
  static const char STR_UNIFORM_MVPDB[] = "mvpdb"; // mvp depth bias
  static const char STR_UNIFORM_CAM[] = "cam"; // camera world

  static const char STR_UNIFORM_DIF_TEX[] = "difTex";
  static const char STR_UNIFORM_ALP_TEX[] = "alpTex";
  static const char STR_UNIFORM_SPE_TEX[] = "speTex";
  static const char STR_UNIFORM_NOR_TEX[] = "norTex";
  static const char STR_UNIFORM_ENV_TEX[] = "envTex";
  static const char STR_UNIFORM_DEPTH_TEX[] = "depthTex";
  static const char STR_UNIFORM_LPV_TEX_R0[] = "lpvTexR0";
  static const char STR_UNIFORM_LPV_TEX_G0[] = "lpvTexG0";
  static const char STR_UNIFORM_LPV_TEX_B0[] = "lpvTexB0";

  static const char STR_UNIFORM_TYPE[] = "type";
  static const char STR_UNIFORM_OPACITY[] = "opacity";
  static const char STR_UNIFORM_DEPTH_TEXEL_SIZE[] = "depthTexelSize";
  static const char STR_UNIFORM_LIGHT_AMB[] = "lightAmb";
  static const char STR_UNIFORM_LIGHT_POS[] = "lightPos";
  static const char STR_UNIFORM_LIGHT_RANGE[] = "lightRange";
  static const char STR_UNIFORM_LIGHT_COLOR[] = "lightColor";
  static const char STR_UNIFORM_LIGHT_SPEC_COLOR[] = "lightSpeColor";
  static const char STR_UNIFORM_FOG_RANGE[] = "fogRange";
  static const char STR_UNIFORM_FOG_COLOR[] = "fogColor";

  static const char STR_UNIFORM_FRAG_COLOR_IMG[] = "fragColor";
  static const char STR_UNIFORM_FRAG_POS_IMG[] = "fragPos";
  static const char STR_UNIFORM_FRAG_NORMAL_IMG[] = "fragNormal";
  static const char STR_UNIFORM_FRAG_DEPTH_IMG[] = "fragDepth";
  static const char STR_UNIFORM_LPV_IMG_R0[] = "lpvImgR0";
  static const char STR_UNIFORM_LPV_IMG_G0[] = "lpvImgG0";
  static const char STR_UNIFORM_LPV_IMG_B0[] = "lpvImgB0";
  static const char STR_UNIFORM_GV_IMG_A0[] = "gvImgA0";

  static const char STR_UNIFORM_FRAG_SIZE[] = "fragSize";
  static const char STR_UNIFORM_LPV_POS[] = "lpvPos";
  static const char STR_UNIFORM_LPV_SIZE[] = "lpvSize";
  static const char STR_UNIFORM_LPV_CELL_SIZE[] = "lpvCellSize";

  static const char STR_SHADER_UNUSED[] = "";

  static const char STR_VERTEX_COLOR[] = "color.vs";
  static const char STR_VERTEX_DEPTH[] = "depth.vs";
  static const char STR_VERTEX_BASIC[] = "basic.vs";
  static const char STR_VERTEX_PER_FRAGMENT[] = "perFragment.vs";
  static const char STR_VERTEX_PER_FRAGMENT_SHADOW[] = "perFragmentShadow.vs";
  static const char STR_VERTEX_PER_FRAGMENT_NORMAL[] = "perFragmentNormal.vs";
  static const char STR_VERTEX_PER_FRAGMENT_NORMAL_SHADOW[] = "perFragmentNormalShadow.vs";
  static const char STR_VERTEX_GEOMETRY[] = "geometry.vs";

  static const char STR_FRAGMENT_COLOR[] = "color.fs";
  static const char STR_FRAGMENT_DEPTH[] = "depth.fs";
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

  static const char STR_COMPUTE_LPV_CLEAR[] = "lpvClear.cs";
  static const char STR_COMPUTE_LPV_INJECTION[] = "lpvInjection.cs";
  static const char STR_COMPUTE_LPV_PROPAGATION[] = "lpvPropagation.cs";

  static const char STR_ERROR_COMPILE[] = "Shader Compilation Error: \"%s\"!";
  static const char STR_ERROR_LINK[] = "Program Link Error: \"%s\"!";
  //static const char STR_ERROR_VERTEX_ATTACH[] = "No Vertex Shader attached to Program: \"%s\"";
  //static const char STR_ERROR_FRAGMENT_ATTACH[] = "No Fragment Shader attached to Program: \"%s\"";

  static const char *const STR_PROGRAM_LIST[] =
  {
    "Color",
    "Depth",
    "Basic",
    "Basic Alpha",
    "Per Fragment",
    "Per Fragment Normal",
    "Per Fragment Normal Jitter",
    "Per Fragment Alpha",
    "Per Fragment Alpha Normal",
    "Per Fragment Alpha Normal Jitter",
    "Per Fragment Normal",
    "Per Fragment Normal Normal",
    "Per Fragment Normal Normal Jitter",
    "Per Fragment Normal Alpha",
    "Per Fragment Normal Alpha Normal",
    "Per Fragment Normal Alpha Normal Jitter",
    "Geometry",
    "LPV Clear",
    "LPV Injection",
    "LPV Propagation"
  };

  // unique lists --------------------------------------------------------------
  static const char *const STR_VERTEX_SHADER_LIST[] =
  {
    STR_VERTEX_COLOR,
    STR_VERTEX_DEPTH,
    STR_VERTEX_BASIC,
    STR_VERTEX_PER_FRAGMENT,
    STR_VERTEX_PER_FRAGMENT_SHADOW,
    STR_VERTEX_PER_FRAGMENT_NORMAL,
    STR_VERTEX_PER_FRAGMENT_NORMAL_SHADOW,
    STR_VERTEX_GEOMETRY
  };

  static const char *const STR_GEOMETRY_SHADER_LIST[] =
  {
    STR_SHADER_UNUSED
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
    STR_FRAGMENT_GEOMETRY
  };

  static const char *const STR_COMPUTE_SHADER_LIST[] =
  {
    STR_COMPUTE_LPV_CLEAR,
    STR_COMPUTE_LPV_INJECTION,
    STR_COMPUTE_LPV_PROPAGATION
  };

  // linking lists -------------------------------------------------------------
  static const char *const STR_PROGRAM_VERTEX_SHADER_LIST[] =
  {
    STR_VERTEX_COLOR,
    STR_VERTEX_DEPTH,
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
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED,
    STR_SHADER_UNUSED
  };

  static const char *const STR_PROGRAM_GEOMETRY_SHADER_LIST[] =
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
    STR_SHADER_UNUSED
  };

  static const char *const STR_PROGRAM_FRAGMENT_SHADER_LIST[] =
  {
    STR_FRAGMENT_COLOR,
    STR_FRAGMENT_DEPTH,
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
    STR_COMPUTE_LPV_CLEAR,
    STR_COMPUTE_LPV_INJECTION,
    STR_COMPUTE_LPV_PROPAGATION
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
    GL_NONE,
    GL_VERTEX_SHADER,
    GL_GEOMETRY_SHADER,
    GL_TESS_CONTROL_SHADER,
    GL_TESS_EVALUATION_SHADER, 
    GL_FRAGMENT_SHADER,
    GL_COMPUTE_SHADER
  };

  enum EProgram
  {
    PROGRAM_COLOR = 0,
    PROGRAM_DEPTH,
    PROGRAM_BASIC,
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
    PROGRAM_LPV_CLEAR,
    PROGRAM_LPV_INJECTION,
    PROGRAM_LPV_PROPAGATION
  };

  enum ESampler
  {
    SAMPLER_BASIC_DIF = 0,

    SAMPLER_BASIC_APLHA_DIF = 0,
    SAMPLER_BASIC_APLHA_ALP,

    SAMPLER_PER_FRAGMENT_DIF = 0,
    SAMPLER_PER_FRAGMENT_SPE,
    SAMPLER_PER_FRAGMENT_DEPTH,
    SAMPLER_PER_FRAGMENT_LPV_R0,
    SAMPLER_PER_FRAGMENT_LPV_G0,
    SAMPLER_PER_FRAGMENT_LPV_B0,

    SAMPLER_PER_FRAGMENT_ALPHA_DIF = 0,
    SAMPLER_PER_FRAGMENT_ALPHA_ALP,
    SAMPLER_PER_FRAGMENT_ALPHA_SPE,
    SAMPLER_PER_FRAGMENT_ALPHA_DEPTH,
    SAMPLER_PER_FRAGMENT_ALPHA_LPV_R0,
    SAMPLER_PER_FRAGMENT_ALPHA_LPV_G0,
    SAMPLER_PER_FRAGMENT_ALPHA_LPV_B0,

    SAMPLER_PER_FRAGMENT_NORMAL_DIF = 0,
    SAMPLER_PER_FRAGMENT_NORMAL_SPE,
    SAMPLER_PER_FRAGMENT_NORMAL_NOR,
    SAMPLER_PER_FRAGMENT_NORMAL_DEPTH,
    SAMPLER_PER_FRAGMENT_NORMAL_LPV_R0,
    SAMPLER_PER_FRAGMENT_NORMAL_LPV_G0,
    SAMPLER_PER_FRAGMENT_NORMAL_LPV_B0,

    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_DIF = 0,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_ALP,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_SPE,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_NOR,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_DEPTH,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_LPV_R0,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_LPV_G0,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_LPV_B0,

    SAMPLER_GEOMETRY_DIF = 0,
    SAMPLER_GEOMETRY_NOR,

    SAMPLER_LPV_CLEAR_LPV_IMG_R0 = 0,
    SAMPLER_LPV_CLEAR_LPV_IMG_G0,
    SAMPLER_LPV_CLEAR_LPV_IMG_B0,
    SAMPLER_LPV_CLEAR_GV_IMG_A0,

    SAMPLER_LPV_INJECTION_FRAG_COLOR_IMG = 0,
    SAMPLER_LPV_INJECTION_FRAG_POS_IMG,
    SAMPLER_LPV_INJECTION_FRAG_NORMAL_IMG,
    SAMPLER_LPV_INJECTION_FRAG_DEPTH_IMG,
    SAMPLER_LPV_INJECTION_LPV_IMG_R0,
    SAMPLER_LPV_INJECTION_LPV_IMG_G0,
    SAMPLER_LPV_INJECTION_LPV_IMG_B0,
    SAMPLER_LPV_INJECTION_GV_IMG_A0,

    SAMPLER_LPV_PROPAGATION_LPV_IMG_R0 = 0,
    SAMPLER_LPV_PROPAGATION_LPV_IMG_G0,
    SAMPLER_LPV_PROPAGATION_LPV_IMG_B0,
    SAMPLER_LPV_PROPAGATION_GV_IMG_A0
  };
}
//------------------------------------------------------------------------------
struct SShaderUniforms
{
  GLuint vertexPosition;
  GLuint vertexNormal;
  GLuint vertexNormalTangent;
  //GLuint vertexNormalBitangent;
  GLuint vertexTexCoord;
  GLuint vertexColor;

  GLuint mw;
  GLuint mwnit;
  GLuint mvp;
  GLuint mvpdb;
  GLuint cam;

  GLuint difTex;
  GLuint alpTex;
  GLuint speTex;
  GLuint norTex;
  GLuint envTex;
  GLuint depthTex;
  GLuint lpvTexR0;
  GLuint lpvTexG0;
  GLuint lpvTexB0;

  GLuint type;
  GLuint opacity;
  GLuint depthTexelSize;

  GLuint lightAmb;
  GLuint lightPos;
  GLuint lightRange;
  GLuint lightColor;
  GLuint lightSpeColor;

  GLuint fogRange;
  GLuint fogColor;

  GLuint fragColorImg;
  GLuint fragPosImg;
  GLuint fragNormalImg;
  GLuint fragDepthImg;
  GLuint lpvImgR0;
  GLuint lpvImgG0;
  GLuint lpvImgB0;
  GLuint gvImgA0;
  GLuint fragSize;
  GLuint lpvPos;
  GLuint lpvSize;
  GLuint lpvCellSize;

  inline SShaderUniforms() : vertexPosition(0), vertexNormal(0), vertexNormalTangent(0), /*vertexNormalBitangent(0),*/ vertexTexCoord(0), vertexColor(0),
    mw(0), mwnit(0), mvp(0), mvpdb(0), cam(0),
    difTex(0), alpTex(0), speTex(0), norTex(0), envTex(0), depthTex(0), lpvTexR0(0), lpvTexG0(0), lpvTexB0(0),
    type(0), opacity(0), depthTexelSize(0),
    lightAmb(0), lightPos(0), lightRange(0), lightColor(0), lightSpeColor(0),
    fogRange(0), fogColor(0),
    fragColorImg(0), fragPosImg(0), fragNormalImg(0), fragDepthImg(0), lpvImgR0(0), lpvImgG0(0), lpvImgB0(0), gvImgA0(0), fragSize(0), lpvPos(0), lpvSize(0), lpvCellSize(0)
  {
  }
};
//------------------------------------------------------------------------------
struct SShaderTechnique
{
  glm::mat4 mw; // trochu špatně modelované -> dupliticní pro lody, ale dejme tomu
  glm::mat3 mwnit;
  mutable glm::mat4 mvp;
  mutable glm::mat4 mvpdb; // shadow bias
  mutable glm::vec3 cam;

  mutable const SMaterial *material;

  SBoundingBox aabb;
  glm::vec3 pickColor;
  glm::vec3 lightAmb;
  glm::vec3 lightPos;
  glm::vec2 lightRange;
  glm::vec3 lightColor;
  glm::vec4 lightSpeColor;

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
