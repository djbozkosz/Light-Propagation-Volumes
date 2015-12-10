//------------------------------------------------------------------------------
#ifndef SHADERSTYPES_H
#define SHADERSTYPES_H

#include "mapTypes.h"
#include "modelTypes.h"

//------------------------------------------------------------------------------
namespace NShader
{
  static const uint32 VERTEX_SHADERS_COUNT = 7;
  static const uint32 FRAGMENT_SHADERS_COUNT = 16;
  static const uint32 PROGRAMS_COUNT = 16;

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

  static const char STR_VERTEX_COLOR[] = "color.vs";
  static const char STR_VERTEX_DEPTH[] = "depth.vs";
  static const char STR_VERTEX_BASIC[] = "basic.vs";
  static const char STR_VERTEX_PER_FRAGMENT[] = "perFragment.vs";
  static const char STR_VERTEX_PER_FRAGMENT_SHADOW[] = "perFragmentShadow.vs";
  static const char STR_VERTEX_PER_FRAGMENT_NORMAL[] = "perFragmentNormal.vs";
  static const char STR_VERTEX_PER_FRAGMENT_NORMAL_SHADOW[] = "perFragmentNormalShadow.vs";

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

  static const char STR_ERROR_COMPILE[] = "Shader Compilation Error: \"%s\"!";
  static const char STR_ERROR_LINK[] = "Program Link Error: \"%s\"!";
  static const char STR_ERROR_VERTEX_ATTACH[] = "No Vertex Shader attached to Program: \"%s\"";
  static const char STR_ERROR_FRAGMENT_ATTACH[] = "No Fragment Shader attached to Program: \"%s\"";

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
    "Per Fragment Normal Alpha Normal Jitter"
  };

  // unique lists
  static const char *const STR_VERTEX_SHADER_LIST[] =
  {
    STR_VERTEX_COLOR,
    STR_VERTEX_DEPTH,
    STR_VERTEX_BASIC,
    STR_VERTEX_PER_FRAGMENT,
    STR_VERTEX_PER_FRAGMENT_SHADOW,
    STR_VERTEX_PER_FRAGMENT_NORMAL,
    STR_VERTEX_PER_FRAGMENT_NORMAL_SHADOW
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
    STR_FRAGMENT_PER_FRAGMENT_NORMAL_ALPHA_SHADOW_JITTER
  };

  // linking lists
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
    STR_VERTEX_PER_FRAGMENT_NORMAL_SHADOW
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
    STR_FRAGMENT_PER_FRAGMENT_NORMAL_ALPHA_SHADOW_JITTER
  };

  enum EType
  {
    TYPE_UNDEFINED = 0,
    TYPE_VERTEX,
    TYPE_FRAGMENT
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
    PROGRAM_PER_FRAGMENT_NORMAL_ALPHA_SHADOW_JITTER
  };

  enum ESampler
  {
    SAMPLER_BASIC_DIF = 0,
    SAMPLER_BASIC_APLHA_DIF = 0,
    SAMPLER_BASIC_APLHA_ALP,
    SAMPLER_PER_FRAGMENT_DIF = 0,
    SAMPLER_PER_FRAGMENT_SPE,
    SAMPLER_PER_FRAGMENT_DEPTH,
    SAMPLER_PER_FRAGMENT_ALPHA_DIF = 0,
    SAMPLER_PER_FRAGMENT_ALPHA_ALP,
    SAMPLER_PER_FRAGMENT_ALPHA_SPE,
    SAMPLER_PER_FRAGMENT_ALPHA_DEPTH,
    SAMPLER_PER_FRAGMENT_NORMAL_DIF = 0,
    SAMPLER_PER_FRAGMENT_NORMAL_SPE,
    SAMPLER_PER_FRAGMENT_NORMAL_NOR,
    SAMPLER_PER_FRAGMENT_NORMAL_DEPTH,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_DIF = 0,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_ALP,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_SPE,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_NOR,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_DEPTH
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

  inline SShaderUniforms() : vertexPosition(0), vertexNormal(0), vertexNormalTangent(0), /*vertexNormalBitangent(0),*/ vertexTexCoord(0), vertexColor(0),
    mw(0), mwnit(0), mvp(0), mvpdb(0), cam(0),
    difTex(0), alpTex(0), speTex(0), norTex(0), envTex(0), depthTex(0),
    type(0), opacity(0), depthTexelSize(0),
    lightAmb(0), lightPos(0), lightRange(0), lightColor(0), lightSpeColor(0),
    fogRange(0), fogColor(0)
  {
  }
};
//------------------------------------------------------------------------------
struct SShaderTechnique
{
  glm::mat4 mw;
  glm::mat3 mwnit;
  mutable glm::mat4 mvp;
  mutable glm::mat4 mvpdb;
  mutable glm::vec3 cam;

  mutable const SMaterial *material;

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
  CShader *fragmentShader;
  GLuint program;
  SShaderUniforms uniforms;

  inline SShaderProgram() : name(NShader::PROGRAM_BASIC), vertexShader(NULL), fragmentShader(NULL), program(0) {}
  inline SShaderProgram(NShader::EProgram name, CShader *vertexShader, CShader *fragmentShader, GLuint program = 0, SShaderUniforms uniforms = SShaderUniforms()) : name(name), vertexShader(vertexShader), fragmentShader(fragmentShader), program(program), uniforms(uniforms) {}
};
//------------------------------------------------------------------------------
#endif // SHADERSTYPES_H
