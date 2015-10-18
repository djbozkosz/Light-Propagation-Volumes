//------------------------------------------------------------------------------
#ifndef SHADERSTYPES_H
#define SHADERSTYPES_H

#include "modelTypes.h"

//------------------------------------------------------------------------------
namespace NShader
{
  static const uint32 SHADERS_COUNT = 8;

  static const uint8 SHADER_MAX_LIGHTS = 1;

  static const char STR_SHADER_UNIFORM_VERTEX_POSITION[] = "vertexPosition";
  static const char STR_SHADER_UNIFORM_VERTEX_NORMAL[] = "vertexNormal";
  static const char STR_SHADER_UNIFORM_VERTEX_NORMAL_TANGENT[] = "vertexNormalTangent";
  static const char STR_SHADER_UNIFORM_VERTEX_NORMAL_BITANGENT[] = "vertexNormalBitangent";
  static const char STR_SHADER_UNIFORM_VERTEX_TEX_COORD[] = "vertexTexCoord";
  static const char STR_SHADER_UNIFORM_VERTEX_COLOR[] = "vertexColor";
  static const char STR_SHADER_UNIFORM_MW[] = "mw"; // model world (4x4)
  static const char STR_SHADER_UNIFORM_MWNIT[] = "mwnit"; // model world normal inversed transposed (3x3)
  static const char STR_SHADER_UNIFORM_MVP[] = "mvp"; // projection * view * model world (4x4)
  static const char STR_SHADER_UNIFORM_CAM[] = "cam"; // camera world
  static const char STR_SHADER_UNIFORM_DIF_TEX[] = "difTex";
  static const char STR_SHADER_UNIFORM_ALP_TEX[] = "alpTex";
  static const char STR_SHADER_UNIFORM_SPE_TEX[] = "speTex";
  static const char STR_SHADER_UNIFORM_NOR_TEX[] = "norTex";
  static const char STR_SHADER_UNIFORM_BUM_TEX[] = "bumTex";
  static const char STR_SHADER_UNIFORM_ENV_TEX[] = "envTex";
  static const char STR_SHADER_UNIFORM_OPACITY[] = "opacity";
  static const char STR_SHADER_UNIFORM_LIGHT_AMB[] = "lightAmb";
  static const char STR_SHADER_UNIFORM_LIGHT_POS[] = "lightPos";
  static const char STR_SHADER_UNIFORM_LIGHT_RANGE[] = "lightRange";
  static const char STR_SHADER_UNIFORM_LIGHT_COLOR[] = "lightColor";
  static const char STR_SHADER_UNIFORM_LIGHT_SPEC_COLOR[] = "lightSpeColor";
  static const char STR_SHADER_UNIFORM_FOG_RANGE[] = "fogRange";
  static const char STR_SHADER_UNIFORM_FOG_COLOR[] = "fogColor";

  static const char STR_SHADER_VERTER_COLOR[] = "data/shaders/color.vs";
  static const char STR_SHADER_VERTER_DEPTH[] = "data/shaders/depth.vs";
  static const char STR_SHADER_VERTER_BASIC[] = "data/shaders/basic.vs";
  static const char STR_SHADER_VERTER_PER_FRAGMENT[] = "data/shaders/perFragment.vs";
  static const char STR_SHADER_VERTER_PER_FRAGMENT_NORMAL[] = "data/shaders/perFragmentNormal.vs";

  static const char STR_SHADER_FRAGMENT_COLOR[] = "data/shaders/color.fs";
  static const char STR_SHADER_FRAGMENT_DEPTH[] = "data/shaders/depth.fs";
  static const char STR_SHADER_FRAGMENT_BASIC[] = "data/shaders/basic.fs";
  static const char STR_SHADER_FRAGMENT_BASIC_ALPHA[] = "data/shaders/basicAlpha.fs";
  static const char STR_SHADER_FRAGMENT_PER_FRAGMENT[] = "data/shaders/perFragment.fs";
  static const char STR_SHADER_FRAGMENT_PER_FRAGMENT_ALPHA[] = "data/shaders/perFragmentAlpha.fs";
  static const char STR_SHADER_FRAGMENT_PER_FRAGMENT_NORMAL[] = "data/shaders/perFragmentNormal.fs";
  static const char STR_SHADER_FRAGMENT_PER_FRAGMENT_NORMAL_ALPHA[] = "data/shaders/perFragmentNormalAlpha.fs";

  static const char *const STR_SHADER_VERTEX_LIST[] =
  {
    STR_SHADER_VERTER_COLOR,
    STR_SHADER_VERTER_DEPTH,
    STR_SHADER_VERTER_BASIC,
    STR_SHADER_VERTER_BASIC,
    STR_SHADER_VERTER_PER_FRAGMENT,
    STR_SHADER_VERTER_PER_FRAGMENT,
    STR_SHADER_VERTER_PER_FRAGMENT_NORMAL,
    STR_SHADER_VERTER_PER_FRAGMENT_NORMAL,
  };

  static const char *const STR_SHADER_FRAGMENT_LIST[] =
  {
    STR_SHADER_FRAGMENT_COLOR,
    STR_SHADER_FRAGMENT_DEPTH,
    STR_SHADER_FRAGMENT_BASIC,
    STR_SHADER_FRAGMENT_BASIC_ALPHA,
    STR_SHADER_FRAGMENT_PER_FRAGMENT,
    STR_SHADER_FRAGMENT_PER_FRAGMENT_ALPHA,
    STR_SHADER_FRAGMENT_PER_FRAGMENT_NORMAL,
    STR_SHADER_FRAGMENT_PER_FRAGMENT_NORMAL_ALPHA,
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
    PROGRAM_PER_FRAGMENT_ALPHA,
    PROGRAM_PER_FRAGMENT_NORMAL,
    PROGRAM_PER_FRAGMENT_NORMAL_ALPHA,
  };

  enum ESampler
  {
    SAMPLER_BASIC_DIF = 0,
    SAMPLER_BASIC_APLHA_DIF = 0,
    SAMPLER_BASIC_APLHA_ALP,
    SAMPLER_PER_FRAGMENT_DIF = 0,
    SAMPLER_PER_FRAGMENT_SPE,
    SAMPLER_PER_FRAGMENT_ALPHA_DIF = 0,
    SAMPLER_PER_FRAGMENT_ALPHA_ALP,
    SAMPLER_PER_FRAGMENT_ALPHA_SPE,
    SAMPLER_PER_FRAGMENT_NORMAL_DIF = 0,
    SAMPLER_PER_FRAGMENT_NORMAL_SPE,
    SAMPLER_PER_FRAGMENT_NORMAL_NOR,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_DIF = 0,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_ALP,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_SPE,
    SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_NOR
  };
}
//------------------------------------------------------------------------------
struct SShaderUniforms
{
  GLuint vertexPosition;
  GLuint vertexNormal;
  GLuint vertexNormalTangent;
  GLuint vertexNormalBitangent;
  GLuint vertexTexCoord;
  GLuint vertexColor;

  GLuint mw;
  GLuint mwnit;
  GLuint mvp;
  GLuint cam;

  GLuint difTex;
  GLuint alpTex;
  GLuint speTex;
  GLuint norTex;
  GLuint bumTex;
  GLuint envTex;

  GLuint opacity;

  GLuint lightAmb;
  GLuint lightPos;
  GLuint lightRange;
  GLuint lightColor;
  GLuint lightSpeColor;

  GLuint fogRange;
  GLuint fogColor;

  inline SShaderUniforms() : vertexPosition(0), vertexNormal(0), vertexNormalTangent(0), vertexNormalBitangent(0), vertexTexCoord(0), vertexColor(0),
    mw(0), mwnit(0), mvp(0), cam(0),
    difTex(0), alpTex(0), speTex(0), norTex(0), bumTex(0), envTex(0),
    opacity(0),
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
  mutable glm::vec3 cam;

  mutable glm::vec4 pos; // pro screen space věci, gui, text, partikly, atd...
  mutable glm::vec4 posOffset;
  mutable glm::vec2 texPos;
  const char *text; // null terminated klasika

  mutable const SMaterial *material;

  glm::vec3 pickColor;
  glm::vec3 lightAmb;
  glm::vec3 lightPos;
  glm::vec2 lightRange;
  glm::vec3 lightColor;
  glm::vec4 lightSpeColor;

  glm::vec2 fogRange;
  glm::vec3 fogColor;

  inline SShaderTechnique() : text(NULL), material(NULL) {}
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
