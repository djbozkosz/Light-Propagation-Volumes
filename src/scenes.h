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

    void update(uint8 type = NScene::UPDATE_ALL);

    void render() const;

    inline void setPosition(const glm::vec3 &position) { object.position = position; update(NScene::UPDATE_TRANSFORMATION | NScene::UPDATE_MODEL); }
    inline void setRotation(const glm::quat &rotation) { object.rotation = rotation; update(NScene::UPDATE_TRANSFORMATION | NScene::UPDATE_MODEL); }
    inline void setScale(const glm::vec3 &scale) { object.scale = scale; update(NScene::UPDATE_TRANSFORMATION | NScene::UPDATE_MODEL); }
    inline void setModel(const SSceneModel &model) { this->model = model; object.type = NScene::OBJECT_TYPE_MODEL; update(); }
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

    inline void setChanged(bool changed) { scene.changed = changed; }

    void update(uint8 type = NScene::UPDATE_ALL) { for(auto it = sceneObjects.begin(); it != sceneObjects.end(); it++) it->second.update(type); }
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
    CScene *activeScene;
    std::map<std::string, CScene> scenes;

  public:
    CScenes();
    CScenes(CContext *context);
    ~CScenes();

    CScene *addScene(const SScene &scene);
    inline uint32 removeScene(const std::string &name) { if((activeScene) && (name == activeScene->getScene()->name)) { activeScene = NULL; } return scenes.erase(name); }
    CScene *setActiveScene(const std::string &name);

    inline CScene *getScene(const std::string &name) { auto it = scenes.find(name); if(it == scenes.end()) return NULL; return &it->second; }
    inline CScene *getActiveScene() { return activeScene; }
};
//------------------------------------------------------------------------------
inline void CSceneObject::setLight(const SSceneLight &light)
{ // inline due scene forward declaration
  this->light = light;
  object.type = NScene::OBJECT_TYPE_LIGHT;
  object.parent->update(NScene::UPDATE_LIGHTING);
}
//------------------------------------------------------------------------------
inline CSceneObject *CScene::addSceneObject(const SSceneObject &object)
{
  SSceneObject o = object;
  o.parent = this;
  o.pickColor = context->getPickColor()->getNextColor();
  sceneObjects[object.name] = CSceneObject(context, o);
  CSceneObject *so = getSceneObject(object.name);
  so->update();

  return so;
}
//------------------------------------------------------------------------------
inline CSceneObject *CScene::addSceneObjectModel(const SSceneObject &object, const SSceneModel &model)
{
  SSceneObject o = object;
  o.parent = this;
  o.type = NScene::OBJECT_TYPE_MODEL;
  o.pickColor = context->getPickColor()->getNextColor();
  sceneObjects[object.name] = CSceneObject(context, o, model);
  CSceneObject *so = getSceneObject(object.name);
  so->update();

  return so;
}
//------------------------------------------------------------------------------
inline CSceneObject *CScene::addSceneObjectLight(const SSceneObject &object, const SSceneLight &light)
{
  SSceneObject o = object;
  o.parent = this;
  o.type = NScene::OBJECT_TYPE_LIGHT;
  o.pickColor = context->getPickColor()->getNextColor();
  sceneObjects[object.name] = CSceneObject(context, o, light);
  CSceneObject *so = getSceneObject(object.name);
  so->update();

  return so;
}
//------------------------------------------------------------------------------
inline CScene *CScenes::addScene(const SScene &scene)
{
  if(CScene *s = getScene(scene.name))
    return s;

  scenes[scene.name] = CScene(context, scene);

  return getScene(scene.name);
}
//------------------------------------------------------------------------------
inline CScene *CScenes::setActiveScene(const std::string &name)
{
  auto it = scenes.find(name);

  if(it == scenes.end())
    activeScene = NULL;
  else
    activeScene = &it->second;

  return getActiveScene();
}
//------------------------------------------------------------------------------
#endif // SCENES_H
