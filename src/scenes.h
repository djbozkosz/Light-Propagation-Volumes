//------------------------------------------------------------------------------
#ifndef SCENES_H
#define SCENES_H

#include "models.h"
#include "headers/sceneTypes.h"

//------------------------------------------------------------------------------
class CSceneObject : public CEngineBase
{
  private:
  SSceneObject object;
  SSceneModel model;
  SSceneLight light;

  public:
  CSceneObject();
  CSceneObject(CContext *context, const SSceneObject &object);
  CSceneObject(CContext *context, const SSceneObject &object, const SSceneModel &model);
  CSceneObject(CContext *context, const SSceneObject &object, const SSceneLight &light);
  CSceneObject(CContext *context, const SSceneObject &object, const SSceneText &text);
  ~CSceneObject();

  void update(NScene::ESceneUpdateType type = NScene::UPDATE_ALL);

  void render() const;

  inline void setPosition(const glm::vec3 &position) { object.position = position; update(NScene::UPDATE_TRANSFORMATION); }
  inline void setRotation(const glm::quat &rotation) { object.rotation = rotation; update(NScene::UPDATE_TRANSFORMATION); }
  inline void setScale(const glm::vec3 &scale) { object.scale = scale; update(NScene::UPDATE_TRANSFORMATION); }
  void setLight(const SSceneLight &light);

  inline const SSceneObject *getObject() const { return &object; }
  inline const SSceneModel *getModel() const { return &model; }
  inline CModel *getModelObject() { return model.model; }
  inline const SSceneLight *getLight() const { return &light; }
};
//------------------------------------------------------------------------------
class CScene : public CEngineBase
{
  private:
  SScene scene;
  std::map<std::string, CSceneObject> sceneObjects;

  public:
  CScene();
  CScene(CContext *context, const SScene &scene);
  ~CScene();

  inline CSceneObject *addSceneObject(const SSceneObject &object);
  inline CSceneObject *addSceneObjectModel(const SSceneObject &object, const SSceneModel &model);
  inline CSceneObject *addSceneObjectLight(const SSceneObject &object, const SSceneLight &light);
  inline uint32 removeSceneObject(const std::string &name) { return sceneObjects.erase(name); }

  void update(NScene::ESceneUpdateType type = NScene::UPDATE_ALL) { for(auto it = sceneObjects.begin(); it != sceneObjects.end(); it++) it->second.update(type); }
  inline void clear() { sceneObjects.clear(); }

  void render() const { for(auto it = sceneObjects.cbegin(); it != sceneObjects.cend(); it++) it->second.render(); }

  inline const SScene *getScene() const { return &scene; }
  inline CSceneObject *getSceneObject(const std::string &name) { auto it = sceneObjects.find(name); if(it == sceneObjects.end()) return NULL; return &it->second; }
  inline const std::map<std::string, CSceneObject> *getSceneObjects() const { return &sceneObjects; }
};
//------------------------------------------------------------------------------
class CScenes : public CEngineBase
{
  private:
  std::string activeSceneName;
  CScene *activeScene;
  std::map<std::string, CScene> scenes;

  public:
  CScenes();
  CScenes(CContext *context);
  ~CScenes();

  inline CScene *addScene(const SScene &scene) { scenes[scene.name] = CScene(context, scene); return &scenes.find(scene.name)->second; }
  inline uint32 removeScene(const std::string &name) { if(name == activeSceneName) { activeSceneName.clear(); activeScene = NULL; } return scenes.erase(name); }
  CScene *setActiveScene(const std::string &name);

  inline CScene *getScene(const std::string &name) { auto it = scenes.find(name); if(it == scenes.end()) return NULL; return &it->second; }
  inline const std::string &getActiveSceneName() const { return activeSceneName; }
  inline CScene *getActiveScene() { return activeScene; }
};
//------------------------------------------------------------------------------
inline void CSceneObject::setLight(const SSceneLight &light)
{
  this->light = light;
  object.parent->update();
}
//------------------------------------------------------------------------------
inline CSceneObject *CScene::addSceneObject(const SSceneObject &object)
{
  SSceneObject o = object;
  o.parent = this;
  o.pickColor = *context->getPickColor()->getNextColor();
  sceneObjects[object.name] = CSceneObject(context, o);

  return &sceneObjects.find(object.name)->second;
}
//------------------------------------------------------------------------------
inline CSceneObject *CScene::addSceneObjectModel(const SSceneObject &object, const SSceneModel &model)
{
  SSceneObject o = object;
  o.parent = this;
  o.type = NScene::OBJECT_TYPE_MODEL;
  o.pickColor = *context->getPickColor()->getNextColor();
  sceneObjects[object.name] = CSceneObject(context, o, model);

  return &sceneObjects.find(object.name)->second;
}
//------------------------------------------------------------------------------
inline CSceneObject *CScene::addSceneObjectLight(const SSceneObject &object, const SSceneLight &light)
{
  SSceneObject o = object;
  o.parent = this;
  o.type = NScene::OBJECT_TYPE_LIGHT;
  o.pickColor = *context->getPickColor()->getNextColor();
  sceneObjects[object.name] = CSceneObject(context, o, light);

  return &sceneObjects.find(object.name)->second;
}
//------------------------------------------------------------------------------
inline CScene *CScenes::setActiveScene(const std::string &name)
{
  auto it = scenes.find(name);

  if(it == scenes.end())
  {
    activeSceneName.clear();
    activeScene = NULL;
  }
  else
  {
    activeSceneName = it->second.getScene()->name;
    activeScene = &it->second;
  }

  return getActiveScene();
}
//------------------------------------------------------------------------------
#endif // SCENES_H
