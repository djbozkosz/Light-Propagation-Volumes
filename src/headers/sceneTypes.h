//------------------------------------------------------------------------------
#ifndef SCENETYPES_H
#define SCENETYPES_H

#include "mapTypes.h"
#include "modelTypes.h"
#include "shaderTypes.h"

//------------------------------------------------------------------------------
namespace NScene
{
  enum ESceneObjectType
  {
    OBJECT_TYPE_NONE = 0,
    OBJECT_TYPE_MODEL,
    OBJECT_TYPE_LIGHT,
    OBJECT_TYPE_TEXT
  };

  enum ESceneObjectLightType
  {
    OBJECT_LIGHT_TYPE_POINT = 0,
    OBJECT_LIGHT_TYPE_AMBIENT,
    OBJECT_LIGHT_TYPE_FOG
  };

  enum ESceneUpdateType
  {
    UPDATE_ALL = 0xff,
    UPDATE_MODEL = 0x01,
    UPDATE_TRANSFORMATION = 0x02,
    UPDATE_LIGHTING = 0x04
  };
}
//------------------------------------------------------------------------------
class CModel;
class CScene;

struct SSceneObject
{
  CScene *parent;
  NScene::ESceneObjectType type;
  std::string name;
  glm::vec3 position;
  glm::quat rotation;
  glm::vec3 scale;
  SColor pickColor;
  glm::mat4 mw;
  glm::mat3 mwnit;

  inline SSceneObject() : parent(NULL), type(NScene::OBJECT_TYPE_NONE), scale(1.0, 1.0, 1.0) {}
  inline SSceneObject(const std::string &name, const glm::vec3 &position = glm::vec3(), const glm::quat &rotation = glm::quat(), const glm::vec3 &scale = glm::vec3(1.0, 1.0, 1.0), const SColor &pickColor = SColor()) : parent(NULL), type(NScene::OBJECT_TYPE_NONE), name(name), position(position), rotation(rotation), scale(scale), pickColor(pickColor) {}
  inline SSceneObject(NScene::ESceneObjectType type, const std::string &name, const glm::vec3 &position = glm::vec3(), const glm::quat &rotation = glm::quat(), const glm::vec3 &scale = glm::vec3(1.0, 1.0, 1.0), const SColor &pickColor = SColor()) : parent(NULL), type(type), name(name), position(position), rotation(rotation), scale(scale), pickColor(pickColor) {}
  inline SSceneObject(CScene *parent, NScene::ESceneObjectType type, const std::string &name, const glm::vec3 &position = glm::vec3(), const glm::quat &rotation = glm::quat(), const glm::vec3 &scale = glm::vec3(1.0, 1.0, 1.0), const SColor &pickColor = SColor()) : parent(parent), type(type), name(name), position(position), rotation(rotation), scale(scale), pickColor(pickColor) {}
};
//------------------------------------------------------------------------------
struct SSceneModel
{
  CModel *model;
  bool backdrop;
  std::list<SShaderTechnique> meshes;

  inline SSceneModel() : model(NULL), backdrop(false) {}
  inline SSceneModel(CModel *model, bool backdrop = false) : model(model), backdrop(backdrop) {}
};
//------------------------------------------------------------------------------
struct SSceneLight
{
  NScene::ESceneObjectLightType type;
  glm::vec3 color;
  glm::vec4 specularColor;
  glm::vec2 range;

  inline SSceneLight() : type(NScene::OBJECT_LIGHT_TYPE_POINT) {}
  inline SSceneLight(NScene::ESceneObjectLightType type, const glm::vec3 &color, const glm::vec2 &range = glm::vec2(1.0, 10.0), const glm::vec4 &specularColor = glm::vec4(1.0, 1.0, 1.0, 256.0)) : type(type), color(color), specularColor(specularColor), range(range) {}
};
//------------------------------------------------------------------------------
struct SSceneText
{
  std::string text;
  std::vector<char> rawText; // pro přístup, to nám std::string moc neumožňuje pro jednoduchý char

  inline SSceneText() {}
  inline SSceneText(std::string text) : text(text) {}
};
//------------------------------------------------------------------------------
struct SScene
{
  std::string name;

  inline SScene() {}
  inline SScene(const std::string &name) : name(name) {}
};
//------------------------------------------------------------------------------
#endif // SCENETYPES_H
