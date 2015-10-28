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

    NModel::EModelState load();
    NModel::EModelState loadMaterial(CFile *f, SMaterial *mat);
    NModel::EModelState loadMesh(CFile *f, SMesh *mesh);
    NModel::EModelState loadStandardMesh(CFile *f, SMesh *mesh);
    NModel::EModelState loadSingleMesh(CFile *f, SMesh *mesh);
    NModel::EModelState loadMorph(CFile *f, SMesh *mesh);
    NModel::EModelState loadBillboard(CFile *f, SMesh *mesh);
    NModel::EModelState loadGlow(CFile *f, SMesh *mesh);
    NModel::EModelState loadMirror(CFile *f, SMesh *mesh);
    NModel::EModelState loadSector(CFile *f, SMesh *mesh);
    NModel::EModelState loadDummy(CFile *f, SMesh *mesh);
    NModel::EModelState loadTarget(CFile *f, SMesh *mesh);
    NModel::EModelState loadBone(CFile *f, SMesh *mesh);

    void update(NModel::EMeshUpdateType type = NModel::UPDATE_ALL);
    void updateSceneObject(SSceneObject *sceneObject, SSceneModel *sceneModel) const;
    void render(const SSceneObject *sceneObject, const SSceneModel *sceneModel) const;

    static const SStandardMeshLod *getLod(const SMesh *mesh, const glm::vec3 cam);
    inline const SModel *getModel() const { return &model; }
    inline const SMaterial *getMaterial(uint16 index) const { if((!index) || (index > model.materials.size())) return NULL; auto it = model.materials.cbegin(); std::advance(it, index - 1); return &(*it); } // starts from 1
    inline const SMesh *getMesh(const std::string &name) const { auto it = model.meshes.find(name); if(it == model.meshes.end()) return NULL; return &it->second; }
    inline const SMesh *getMesh(uint16 index) const { if((!index) || (index > model.meshes.size())) return NULL; for(auto it = model.meshes.cbegin(); it != model.meshes.cend(); it++) { if(it->second.index == index) return &it->second; } return NULL; } // starts from 1
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

    //void createVbo(SMesh *mesh);
    CModel *addModel(const SModel &model);
    inline uint32 removeModel(const std::string &name) { return models.erase(name); }
    inline CModel *getModel(const std::string &name) { auto it = models.find(name); if(it == models.end()) return NULL; return &it->second; }
};
//------------------------------------------------------------------------------
inline CModel *CModels::addModel(const SModel &model)
{
  CModel *m = getModel(model.path);
  if(m)
    return m;

  models[model.path] = CModel(context, model);
  m = getModel(model.path);
  m->load();
  m->update();

  return m;
}
//------------------------------------------------------------------------------
#endif // MODELS_H
