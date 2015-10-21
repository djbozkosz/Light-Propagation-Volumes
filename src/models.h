//------------------------------------------------------------------------------
#ifndef MODELS_H
#define MODELS_H

#include "renderer.h"
#include "headers/modelTypes.h"

//------------------------------------------------------------------------------
class CModel : public CEngineBase
{
  private:
    SModel model;

  public:
    CModel();
    CModel(CContext *context, const SModel &model);
    ~CModel();

    void update(SSceneObject *sceneObject, SSceneModel *sceneModel) const;

    void render(const SSceneObject *sceneObject, const SSceneModel *sceneModel) const;

    inline const SModel *getModel() const { return &model; }
};
//------------------------------------------------------------------------------
class CModels : public CEngineBase
{
  private:
    std::map<std::string, CModel> models;

  public:
    CModels();
    CModels(CContext *context);
    ~CModels();

    void createVbo(SMesh *mesh);

    CModel *addModel(const SModel &model);
    inline uint32 removeModel(const std::string &name) { return models.erase(name); }
    inline CModel *getModel(const std::string &name) { auto it = models.find(name); if(it == models.end()) return NULL; return &it->second; }
};
//------------------------------------------------------------------------------
inline CModel *CModels::addModel(const SModel &model)
{
  if(CModel *m = getModel(model.name))
    return m;

  models[model.name] = CModel(context, model);

  return &models.find(model.name)->second;
}
//------------------------------------------------------------------------------
#endif // MODELS_H
