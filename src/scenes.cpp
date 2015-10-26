//------------------------------------------------------------------------------
#include "scenes.h"

//------------------------------------------------------------------------------
CSceneObject::CSceneObject() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CSceneObject::CSceneObject(CContext *context, const SSceneObject &object) : CEngineBase(context), object(object)
{
}
//------------------------------------------------------------------------------
CSceneObject::CSceneObject(CContext *context, const SSceneObject &object, const SSceneModel &model) : CEngineBase(context), object(object), model(model)
{
}
//------------------------------------------------------------------------------
CSceneObject::CSceneObject(CContext *context, const SSceneObject &object, const SSceneLight &light) : CEngineBase(context), object(object), light(light)
{
}
//------------------------------------------------------------------------------
CSceneObject::~CSceneObject()
{
}
//------------------------------------------------------------------------------
void CSceneObject::update(NScene::ESceneUpdateType type)
{
  UNUSED(type);

  if((object.type == NScene::OBJECT_TYPE_MODEL) && (model.model))
  {
    if(type & NScene::UPDATE_TRANSFORMATION)
      object.mw = SMatrix::composeTransformation(object.position, object.rotation, object.scale);
    if(type & NScene::UPDATE_MODEL)
    {
      model.model->updateSceneObject(&object, &model);

      for(auto mesh = model.meshes.begin(); mesh != model.meshes.end(); mesh++)
        mesh->pickColor = object.pickColor.toVec3();
    }
    if(type & NScene::UPDATE_LIGHTING)
    {
      for(auto mesh = model.meshes.begin(); mesh != model.meshes.end(); mesh++)
      {
        for(auto so = object.parent->getSceneObjects()->cbegin(); so != object.parent->getSceneObjects()->cend(); so++)
        {
          if(so->second.getObject()->type == NScene::OBJECT_TYPE_LIGHT)
          {
            const SSceneLight *light = so->second.getLight();
            if(light->type == NScene::OBJECT_LIGHT_TYPE_AMBIENT)
              mesh->lightAmb = light->color;
            else if(light->type == NScene::OBJECT_LIGHT_TYPE_POINT)
            {
              mesh->lightPos = so->second.getObject()->position;
              mesh->lightRange = light->range;
              mesh->lightColor = light->color;
              mesh->lightSpeColor = light->specularColor;
            }
            else if(light->type == NScene::OBJECT_LIGHT_TYPE_FOG)
            {
              mesh->fogRange = light->range;
              mesh->fogColor = light->color;
            }
          }
        }
      }
    }
  }
}
//------------------------------------------------------------------------------
void CSceneObject::render() const
{
  if(((object.type != NScene::OBJECT_TYPE_MODEL) && (object.type != NScene::OBJECT_TYPE_TEXT)) || (!model.model))
    return;

  const SRenderer *ren = context->getRenderer()->getRenderer();
  if(((!model.backdrop) && (ren->mode != NRenderer::MODE_BACKDROP)) || ((model.backdrop) && (ren->mode == NRenderer::MODE_BACKDROP)))
    model.model->render(&object, &model);
}
//------------------------------------------------------------------------------
CScene::CScene() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CScene::CScene(CContext *context, const SScene &scene) : CEngineBase(context), scene(scene)
{
}
//------------------------------------------------------------------------------
CScene::~CScene()
{
}
//------------------------------------------------------------------------------
CScenes::CScenes() : CEngineBase(), activeScene(NULL)
{
}
//------------------------------------------------------------------------------
CScenes::CScenes(CContext *context) : CEngineBase(context), activeScene(NULL)
{
}
//------------------------------------------------------------------------------
CScenes::~CScenes()
{
}
//------------------------------------------------------------------------------
