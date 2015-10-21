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

  if(object.type == NScene::OBJECT_TYPE_MODEL)
  {
    if(((type & NScene::UPDATE_MODEL) || (type & NScene::UPDATE_TRANSFORMATION)) && (model.model))
      model.model->update(&object, &model);
    if(type & NScene::UPDATE_LIGHTING)
    {
      for(auto t = model.meshes.begin(); t != model.meshes.end(); t++)
      {
        //SShaderTechnique *t; // test
        t->pickColor = object.pickColor.toVec3();

        for(auto so = object.parent->getSceneObjects()->cbegin(); so != object.parent->getSceneObjects()->cend(); so++)
        {
          //CSceneObject *so; // test
          if(so->second.getObject()->type == NScene::OBJECT_TYPE_LIGHT)
          {
            const SSceneLight *light = so->second.getLight();
            if(light->type == NScene::OBJECT_LIGHT_TYPE_AMBIENT)
              t->lightAmb = light->color;
            else if(light->type == NScene::OBJECT_LIGHT_TYPE_POINT)
            {
              t->lightPos = so->second.getObject()->position;
              t->lightRange = light->range;
              t->lightColor = light->color;
              t->lightSpeColor = light->specularColor;
            }
            else if(light->type == NScene::OBJECT_LIGHT_TYPE_FOG)
            {
              t->fogRange = light->range;
              t->fogColor = light->color;
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
