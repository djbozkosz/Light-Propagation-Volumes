//------------------------------------------------------------------------------
#include "engine.h"

//------------------------------------------------------------------------------
CEngine::CEngine(
  uint32 argc, const char *const *const argv
#ifdef ENV_QT
  , QWidget *parent
#endif
  ) :
#ifdef ENV_QT
  QMainWindow(parent), ui(new Ui::CEngine),
#endif
  window(NULL)
{
#ifdef ENV_QT
  ui->setupUi(this);
#endif

//#ifdef ENV_SDL
  engine.flags = NEngine::EFLAG_SHOW_CONSOLE;
//#endif
  //engine.flags = NEngine::EFLAG_FULLSCREEN;
  engine.gpuPlatform = NEngine::GPU_PLATFORM_GL0302;

  engine.defaultScreenWidth = 1024;
  engine.defaultScreenHeight = 600;
  engine.multisampling = 1;

  //engine.maxTextureSize = 256;
  //engine.shadowTextureSize = 256;
  engine.shadowJittering = 0.0f;

  engine.geometryTextureSize = 128;
  engine.lpvPropagationSteps = 8;
  engine.lpvLobe = true;
  engine.lpvSky = true;
  engine.sslpv = true;
  engine.sunSkyUsed[1] = 1;
  engine.lpvReflIntensity = 0.125f;

  uint32 *const args[] = { &engine.maxTextureSize, &engine.shadowTextureSize, &engine.geometryTextureSize };

  for(uint32 i = 0; i < 5; i++)
  {
    if(argc >= (i + 2))
    {
      uint32 d = CStr::strToInt(argv[i + 1]);
      if(d > 0)
      {
        if(i < 3)
          *args[i] = d;
        else if(i == 3)
          engine.lpvTextureSize = glm::vec3(d);
        else if(i == 4)
          engine.timing = true;
      }
    }
  }

  context.setContext(this, window, &scenes, &models, &renderer, &shaders, &culling, &pickColor, &framebuffers, &maps, &camera, &openGL, &filesystem, &exceptions);
  context.setEngineCallbacks(
    &staticInitialize,
    &staticInitializeFinish,
    &staticShowMessage,
    &staticSetPlatform,
    &staticIncDrawCalls,
    &staticClearDrawCalls,
    &staticSetShadowViewProj,
    &staticSetShadowFrustum,
    &staticSetGeometryPos,
    &staticSetGeometryViewProj,
    &staticSetGeometryFrustum,
    &staticSetSunSkyPose,
    &staticSetSunSkyColor,
    &staticSetLpvPose,
    &staticSetCamTrack,
    &staticSwapLPV,
    &staticGetTime,
    &staticGetClassName,
    &staticGetEngine);

  window = new CWindow(&context
#ifdef ENV_QT
    , this
#endif
  );

  context.setContext(this, window, &scenes, &models, &renderer, &shaders, &culling, &pickColor, &framebuffers, &maps, &camera, &openGL, &filesystem, &exceptions);

#if defined(ENV_QT)
  ui->hlCentral->addWidget(window);
  engine.timer.start();

  //connect(window, SIGNAL(onInitializeGL()), this, SLOT(initialize()), Qt::DirectConnection);
  //connect(window, SIGNAL(onInitializeFinishGL()), this, SLOT(initializeFinish()), Qt::DirectConnection);
  connect(window, SIGNAL(onMousePress(NEngine::EMouseButton)), this, SLOT(mousePress(NEngine::EMouseButton)));
  connect(window, SIGNAL(onMouseRelease(NEngine::EMouseButton)), this, SLOT(mouseRelease(NEngine::EMouseButton)));
  connect(window, SIGNAL(onMouseMove(const SPoint &, NEngine::EMouseButton)), this, SLOT(mouseMove(const SPoint &, NEngine::EMouseButton)));
  connect(window, SIGNAL(onKeyPress(NEngine::EKey)), this, SLOT(keyPress(NEngine::EKey)));
  connect(window, SIGNAL(onKeyRelease(NEngine::EKey)), this, SLOT(keyRelease(NEngine::EKey)));

  connect(ui->cbScene, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxChanged(int)));
  connect(ui->cbLPVMode, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxChanged(int)));
  connect(ui->cbLPVTech, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxChanged(int)));
  connect(ui->hsLPVProp, SIGNAL(valueChanged(int)), this, SLOT(onSliderChanged(int)));
  connect(ui->hsLPVInt, SIGNAL(valueChanged(int)), this, SLOT(onSliderChanged(int)));
  connect(ui->hsLPVRefl, SIGNAL(valueChanged(int)), this, SLOT(onSliderChanged(int)));
  connect(ui->cbGV, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxChanged(int)));
  connect(ui->cbLobe, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxChanged(int)));
  connect(ui->cbSky, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxChanged(int)));
  connect(ui->cbSSLPV, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxChanged(int)));
  connect(ui->cbNoColors, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxChanged(int)));
  connect(ui->cbFrustum, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxChanged(int)));
  connect(ui->hsShadJit, SIGNAL(valueChanged(int)), this, SLOT(onSliderChanged(int)));
  connect(ui->hsCamSpeed, SIGNAL(valueChanged(int)), this, SLOT(onSliderChanged(int)));
  connect(ui->cbModel, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxChanged(int)));
  connect(ui->pbPlaceModel, SIGNAL(clicked()), this, SLOT(onPushButtonClicked()));
  connect(ui->cbGVLPV, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxChanged(int)));
  connect(ui->cbCSM, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxChanged(int)));
  connect(ui->cbMode, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxChanged(int)));
  connect(ui->pbCamAnim, SIGNAL(clicked()), this, SLOT(onPushButtonClicked()));

  // fill keys mapping
  engine.keysMap[Qt::Key_W] = NEngine::KEY_FRONT;
  engine.keysMap[Qt::Key_Up] = NEngine::KEY_FRONT;
  engine.keysMap[Qt::Key_S] = NEngine::KEY_BACK;
  engine.keysMap[Qt::Key_Down] = NEngine::KEY_BACK;
  engine.keysMap[Qt::Key_A] = NEngine::KEY_LEFT;
  engine.keysMap[Qt::Key_Left] = NEngine::KEY_LEFT;
  engine.keysMap[Qt::Key_D] = NEngine::KEY_RIGHT;
  engine.keysMap[Qt::Key_Right] = NEngine::KEY_RIGHT;
  engine.keysMap[Qt::Key_Q] = NEngine::KEY_DOWN;
  engine.keysMap[Qt::Key_E] = NEngine::KEY_UP;

  engine.keysMap[Qt::Key_I] = NEngine::KEY_SPECIAL_FRONT;
  engine.keysMap[Qt::Key_K] = NEngine::KEY_SPECIAL_BACK;
  engine.keysMap[Qt::Key_J] = NEngine::KEY_SPECIAL_LEFT;
  engine.keysMap[Qt::Key_L] = NEngine::KEY_SPECIAL_RIGHT;
  engine.keysMap[Qt::Key_U] = NEngine::KEY_SPECIAL_DOWN;
  engine.keysMap[Qt::Key_O] = NEngine::KEY_SPECIAL_UP;

  /*engine.keysMap[Qt::Key_1] = NEngine::KEY_LPV_MODE; // with Qt (cz): shift pressed is needed
  engine.keysMap[Qt::Key_2] = NEngine::KEY_LPV_TECHNIQUE;
  engine.keysMap[Qt::Key_3] = NEngine::KEY_LPV_GV;
  engine.keysMap[Qt::Key_4] = NEngine::KEY_LPV_LOBE;
  engine.keysMap[Qt::Key_5] = NEngine::KEY_LPV_PROPAGATION_DOWN;
  engine.keysMap[Qt::Key_6] = NEngine::KEY_LPV_PROPAGATION_UP;
  engine.keysMap[Qt::Key_7] = NEngine::KEY_LPV_INTENSITY_DOWN;
  engine.keysMap[Qt::Key_8] = NEngine::KEY_LPV_INTENSITY_UP;
  engine.keysMap[Qt::Key_9] = NEngine::KEY_SHADOW_JITTERING_DOWN;
  engine.keysMap[Qt::Key_0] = NEngine::KEY_SHADOW_JITTERING_UP;
  engine.keysMap[Qt::Key_R] = NEngine::KEY_CAM_SPEED_DOWN__SCENE_PREV;
  engine.keysMap[Qt::Key_T] = NEngine::KEY_CAM_SPEED_UP__SCENE_NEXT;
  engine.keysMap[Qt::Key_B] = NEngine::KEY_LPV_REFL_INTENSITY_DOWN__FRUSTUM;
  engine.keysMap[Qt::Key_N] = NEngine::KEY_LPV_REFL_INTENSITY_UP__NO_COLORS;
  engine.keysMap[Qt::Key_V] = NEngine::KEY_LPV_SKY__SSLPV;

  engine.keysMap[Qt::Key_F] = NEngine::KEY_SWITCH_MODE;
  engine.keysMap[Qt::Key_G] = NEngine::KEY_SHOW_GEOMETRY_BUFFERS__SHADOW;
  engine.keysMap[Qt::Key_H] = NEngine::KEY_CAM_PLAY;
  engine.keysMap[Qt::Key_M] = NEngine::KEY_MODEL_SET__MODEL_CHANGE;*/

  engine.keysMap[Qt::Key_Escape] = NEngine::KEY_QUIT;

#elif defined(ENV_SDL)
  engine.keysMap[SDLK_w] = NEngine::KEY_FRONT;
  engine.keysMap[SDLK_UP] = NEngine::KEY_FRONT;
  engine.keysMap[SDLK_s] = NEngine::KEY_BACK;
  engine.keysMap[SDLK_DOWN] = NEngine::KEY_BACK;
  engine.keysMap[SDLK_a] = NEngine::KEY_LEFT;
  engine.keysMap[SDLK_LEFT] = NEngine::KEY_LEFT;
  engine.keysMap[SDLK_d] = NEngine::KEY_RIGHT;
  engine.keysMap[SDLK_RIGHT] = NEngine::KEY_RIGHT;
  engine.keysMap[SDLK_q] = NEngine::KEY_DOWN;
  engine.keysMap[SDLK_e] = NEngine::KEY_UP;

  engine.keysMap[SDLK_i] = NEngine::KEY_SPECIAL_FRONT;
  engine.keysMap[SDLK_k] = NEngine::KEY_SPECIAL_BACK;
  engine.keysMap[SDLK_j] = NEngine::KEY_SPECIAL_LEFT;
  engine.keysMap[SDLK_l] = NEngine::KEY_SPECIAL_RIGHT;
  engine.keysMap[SDLK_u] = NEngine::KEY_SPECIAL_DOWN;
  engine.keysMap[SDLK_o] = NEngine::KEY_SPECIAL_UP;

  engine.keysMap[SDLK_1] = NEngine::KEY_LPV_MODE;
  engine.keysMap[SDLK_2] = NEngine::KEY_LPV_TECHNIQUE;
  engine.keysMap[SDLK_3] = NEngine::KEY_LPV_GV;
  engine.keysMap[SDLK_4] = NEngine::KEY_LPV_LOBE;
  engine.keysMap[SDLK_5] = NEngine::KEY_LPV_PROPAGATION_DOWN;
  engine.keysMap[SDLK_6] = NEngine::KEY_LPV_PROPAGATION_UP;
  engine.keysMap[SDLK_7] = NEngine::KEY_LPV_INTENSITY_DOWN;
  engine.keysMap[SDLK_8] = NEngine::KEY_LPV_INTENSITY_UP;
  engine.keysMap[SDLK_9] = NEngine::KEY_SHADOW_JITTERING_DOWN;
  engine.keysMap[SDLK_0] = NEngine::KEY_SHADOW_JITTERING_UP;
  engine.keysMap[SDLK_r] = NEngine::KEY_CAM_SPEED_DOWN__SCENE_PREV;
  engine.keysMap[SDLK_t] = NEngine::KEY_CAM_SPEED_UP__SCENE_NEXT;
  engine.keysMap[SDLK_b] = NEngine::KEY_LPV_REFL_INTENSITY_DOWN__FRUSTUM;
  engine.keysMap[SDLK_n] = NEngine::KEY_LPV_REFL_INTENSITY_UP__NO_COLORS;
  engine.keysMap[SDLK_v] = NEngine::KEY_LPV_SKY__SSLPV;

  engine.keysMap[SDLK_f] = NEngine::KEY_SWITCH_MODE;
  engine.keysMap[SDLK_g] = NEngine::KEY_SHOW_GEOMETRY_BUFFERS__SHADOW;
  engine.keysMap[SDLK_h] = NEngine::KEY_CAM_PLAY;
  engine.keysMap[SDLK_m] = NEngine::KEY_MODEL_SET__MODEL_CHANGE;

  engine.keysMap[SDLK_ESCAPE] = NEngine::KEY_QUIT;
#endif
}
//------------------------------------------------------------------------------
CEngine::~CEngine()
{
#ifdef ENV_QT
  ui->setupUi(this);
#else
  delete window;
#endif
}
//------------------------------------------------------------------------------
void CEngine::initialize()
{
  scenes = CScenes(&context);
  models = CModels(&context);
  renderer = CRenderer(&context);
  shaders = CShaders(&context);
  culling = CCulling(&context);
  pickColor = CPickColor(&context);
  framebuffers = CFramebuffers(&context);
  maps = CMaps(&context);
  camera = CCamera(&context);
  openGL = COpenGL(&context);
  filesystem = CFilesystem(&context);
  exceptions = CExceptions(&context);

  for(uint32 i = 0; i < NFile::SEARCH_PATHES_COUNT; i++)
    filesystem.addSearchPath(NFile::STR_SEARCH_PATHES[i]);
  //filesystem.addSearchPath("C:/Hry/Mafia/");

  camera.setSize(engine.defaultScreenWidth, engine.defaultScreenHeight);
}
//------------------------------------------------------------------------------
void CEngine::initializeFinish()
{
#if defined(ENV_QT)
  QTimer::singleShot(NEngine::INIT_LOAD_TIMER_MS, this, SLOT(onTimeoutInit()));
#elif defined(ENV_SDL)
  engine.initSceneEvent = SDL_RegisterEvents(1);
  engine.initSceneTimer = SDL_AddTimer(NEngine::INIT_LOAD_TIMER_MS, staticOnTimeoutInit, &context);
#endif
}
//------------------------------------------------------------------------------
void CEngine::onTimeoutInit()
{
#ifdef ENV_SDL
  SDL_RemoveTimer(engine.initSceneTimer);
#endif

  if(scenes.getActiveScene())
    return;

  camera.setRange(0.01f, 200.0f);
  camera.setSpeed(8.0f);
  camera.setPosition(glm::vec3(2.2f, 5.7f, 4.3f));
  camera.setRotation(glm::vec3(5.0f, -90.0f, 0.0f));

  engine.scenes = 3;
  engine.lpvModelsCount = 2;
  engine.activeLpvModel.resize(engine.scenes);
  engine.camTrackPos.resize(engine.scenes);
  engine.camTrackRot.resize(engine.scenes);

  for(uint32 i = 0; i < engine.scenes; i++)
  {
    context.log(std::string("Loading Scene ")+NScene::STR_SCENES[i]+"...");
    CScene *s = scenes.addScene(SScene(CStr(NScene::STR_SCENE, i)));

    // lights
    const glm::quat sunRot(0.0f, 0.0f, 0.91f, 1.87f);
    //const glm::quat sunRot(0.0f, 0.0f, 1.17f, 3.13f);
    const glm::vec3 sunPos(sinf(sunRot.z) * cosf(sunRot.y), sunRot.y, cosf(sunRot.z) * cosf(sunRot.y));
    s->addSceneObjectLight(SSceneObject(NScene::STR_OBJECT_LIGHT_AMB), SSceneLight(NScene::OBJECT_LIGHT_TYPE_AMBIENT, glm::vec3(0.05f, 0.15f, 0.25f) * 0.1f));
    s->addSceneObjectLight(SSceneObject(NScene::STR_OBJECT_LIGHT_FOG), SSceneLight(NScene::OBJECT_LIGHT_TYPE_FOG, glm::vec3(0.819f, 0.839f, 0.729f), glm::vec2(0.0f, 1.0f)));
    s->addSceneObjectLight(SSceneObject(NScene::STR_OBJECT_LIGHT_SUN, sunPos * NScene::SUN_DIR_MUL, sunRot), SSceneLight(NScene::OBJECT_LIGHT_TYPE_POINT, glm::vec3(1.6f, 1.35f, 1.2f) * 1.5f, glm::vec2(9999999.0f, 10000000.0f), glm::vec4(10.0f, 10.0f, 10.0f, 32.0f)));
    glm::vec3 skyColor(0.3f, 0.4f, 0.5f);
    engine.sunSkyColors[1 * NMath::VEC3 + 0] = skyColor.x;
    engine.sunSkyColors[1 * NMath::VEC3 + 1] = skyColor.y;
    engine.sunSkyColors[1 * NMath::VEC3 + 2] = skyColor.z;

    // backdrop
    s->addSceneObjectModel(
      SSceneObject(NScene::STR_OBJECT_BG_SKY, glm::vec3(0.0f), glm::quat(glm::vec3(0.0f, -90.0f, 0.0f))),
      SSceneModel(models.addModel(SModel(std::string(NFile::STR_DATA_MODELS)+"denjasno2.4ds")), true));
    s->addSceneObjectModel(
      SSceneObject(NScene::STR_OBJECT_BG_SUN, sunPos * NScene::SUN_MUL),
      SSceneModel(models.addModel(SModel(std::string(NFile::STR_DATA_MODELS)+"sphere00.4ds")), true));

    // lpv test models
    const char *const lpvModels[] = { "bunny00", "sphere01" };

    for(uint32 j = 0; j < engine.lpvModelsCount; j++)
    {
      CSceneObject *so = s->addSceneObjectModel(
        SSceneObject(CStr(NScene::STR_OBJECT_LPV_MODEL, j), glm::vec3(-4.5f, 5.0f, 4.5f), glm::quat(), glm::vec3(1.0f)),
        SSceneModel(models.addModel(SModel(std::string(NFile::STR_DATA_MODELS)+lpvModels[j]+".4ds"))));
      if(j)
        so->hide();
    }

    engine.activeLpvModel[i] = 0;

    if(i == 0)
    {
      s->addSceneObjectModel(
        SSceneObject(NScene::STR_SCENE_BASE),
        SSceneModel(models.addModel(SModel(std::string(NFile::STR_DATA_MODELS)+"sponza.4ds"))));

      const float trackPos[] =
      {
        -10.6f, 6.6f, -4.4f,
        -8.5f, 6.5f, -1.5f,
        -1.6f, 0.8f, -1.6f,
        -2.2f, 0.5f, 0.0f,
        -3.6f, 0.4f, 5.1f,
        -11.2f, 2.4f, 4.3f,
        -10.3f, 0.4f, 1.3f,
        -5.5f, 1.7f, -2.2f,
        -2.2f, 6.1f, 2.2f,
        6.3f, 6.0f, 5.0f,
        9.3f, 6.5f, 2.0f,
        8.4f, 11.9f, -0.3f,
        2.1f, 6.4f, -2.2f,
        0.0f, 6.4f, -5.6f,

        -10.6f, 6.6f, -4.4f,
        -8.5f, 6.5f, -1.5f,
        -1.6f, 0.8f, -1.6f
      };

      const float trackRot[] =
      {
        19.0f, 0.0f, 0.0f,
        -2.0f, 74.0f, 0.0f,
        -4.0f, -47.0f, 0.0f,
        -40.0f, -142.0f, 0.0f,
        -17.0f, -183.0f, 0.0f,
        10.0f, -193.0f, 0.0f,
        -28.0f, -256.0f, 0.0f,
        -50.0f, -350.0f, 0.0f,
        -1.0f, -135.0f, 0.0f,
        -8.0f, -154.0f, 0.0f,
        1.0f, -103.0f, 0.0f,
        25.0f, -91.0f, 0.0f,
        0.0f, -58.0f, 0.0f,
        -1.0f, -20.0f, 0.0f,

        19.0f, 0.0f, 0.0f,
        -2.0f, 74.0f, 0.0f,
        -4.0f, -47.0f, 0.0f
      };

      for(uint32 j = 0; j < 17; j++)
      {
        engine.camTrackPos[i].push_back(glm::vec3(trackPos[j * 3 + 0], trackPos[j * 3 + 1], trackPos[j * 3 + 2]));
        engine.camTrackRot[i].push_back(glm::vec3(trackRot[j * 3 + 0], trackRot[j * 3 + 1], trackRot[j * 3 + 2]));
      }
    }
    else if(i == 1)
    {
      s->addSceneObjectModel(
        SSceneObject(NScene::STR_SCENE_BASE),
        SSceneModel(models.addModel(SModel(std::string(NFile::STR_DATA_MODELS)+"sibenik.4ds"))));

      const float trackPos[] =
      {
        10.0f, -0.7f, 2.5f,
        4.8f, 1.0f, 1.7f,
        -3.5f, 3.1f, 0.4f,
        -10.4f, 22.6f, -0.5f,
        -5.5f, 7.5f, 0.8f,
        9.0f, 1.67f, -5.27f,

        10.0f, -0.7f, 2.5f,
        4.8f, 1.0f, 1.7f,
        -3.5f, 3.1f, 0.4f,
      };

      const float trackRot[] =
      {
        -42.0f, 112.0f, 0.0f,
        -10.0f, -107.0f, 0.0f,
        -63.0f, -114.0f, 0.0f,
        20.0f, 67.0f, 0.0f,
        19.0f, 96.0f, 0.0f,
        9.0f, 1.0f, 0.0f,

        -42.0f, -248.0f, 0.0f,
        -10.0f, -107.0f, 0.0f,
        -63.0f, -114.0f, 0.0f,
      };

      for(uint32 j = 0; j < 9; j++)
      {
        engine.camTrackPos[i].push_back(glm::vec3(trackPos[j * 3 + 0], trackPos[j * 3 + 1], trackPos[j * 3 + 2]));
        engine.camTrackRot[i].push_back(glm::vec3(trackRot[j * 3 + 0], trackRot[j * 3 + 1], trackRot[j * 3 + 2]));
      }
    }
    else if(i == 2)
    {
      s->addSceneObjectModel(
        SSceneObject(NScene::STR_SCENE_BASE),
        SSceneModel(models.addModel(SModel(std::string(NFile::STR_DATA_MODELS)+"motel.4ds"))));
      s->addSceneObjectModel(
        SSceneObject("tree00", glm::vec3(25.0f, 0.0f, -5.5f), glm::quat(glm::vec3(0.0f, 0.0f, 0.0f)), glm::vec3(1.0f)),
        SSceneModel(models.addModel(SModel(std::string(NFile::STR_DATA_MODELS)+"tree00.4ds"))));
      s->addSceneObjectModel(
        SSceneObject("tree01", glm::vec3(19.0f, 0.0f, 15.3f), glm::quat(glm::vec3(0.0f, 70.0f, 0.0f)), glm::vec3(1.2f)),
        SSceneModel(models.addModel(SModel(std::string(NFile::STR_DATA_MODELS)+"tree00.4ds"))));
      s->addSceneObjectModel(
        SSceneObject("tree02", glm::vec3(26.0f, 0.0f, 38.0f), glm::quat(glm::vec3(0.0f, 120.0f, 0.0f)), glm::vec3(1.5f)),
        SSceneModel(models.addModel(SModel(std::string(NFile::STR_DATA_MODELS)+"tree00.4ds"))));
      s->addSceneObjectModel(
        SSceneObject("tree03", glm::vec3(-20.0f, 0.0f, 50.0f), glm::quat(glm::vec3(0.0f, -70.0f, 0.0f)), glm::vec3(1.1f)),
        SSceneModel(models.addModel(SModel(std::string(NFile::STR_DATA_MODELS)+"tree00.4ds"))));
      s->addSceneObjectModel(
        SSceneObject("tree04", glm::vec3(-30.0f, 0.0f, 40.0f), glm::quat(glm::vec3(0.0f, 150.0f, 0.0f)), glm::vec3(1.4f)),
        SSceneModel(models.addModel(SModel(std::string(NFile::STR_DATA_MODELS)+"tree00.4ds"))));

      const float trackPos[] =
      {
        -26.7, 4.9f, 43.0f,
        -12.0f, 3.3f, 3.2f,
        -6.6f, 1.6f, 15.3f,
        15.1f, 3.6f, 8.3f,
        13.6f, 0.6f, 20.0f,
        9.3f, 2.2f, 46.2f,
        3.0f, 4.86f, 33.5f,
        -4.0f, 4.9f, 31.4f,
        -9.0f, 5.2f, 33.4f,

        -26.7, 4.9f, 43.0f,
        -12.0f, 3.3f, 3.2f,
        -6.6f, 1.6f, 15.3f
      };

      const float trackRot[] =
      {
        6.0f, 125.0f, 0.0f,
        2.0, 17.0f, 0.0f,
        -6.0f, 54.0f, 0.0f,
        10.0f, -40.0f, 0.0f,
        -45.0f, 115.0f, 0.0f,
        4.0f, -124.0f, 0.0f,
        7.0f, -148.0f, 0.0f,
        2.0f, -93.0f, 0.0f,
        0.0f, -23.0f, 0.0f,
        
        6.0f, 125.0f, 0.0f,
        2.0, 17.0f, 0.0f,
        -6.0f, 54.0f, 0.0f
      };

      for(uint32 j = 0; j < 12; j++)
      {
        engine.camTrackPos[i].push_back(glm::vec3(trackPos[j * 3 + 0], trackPos[j * 3 + 1], trackPos[j * 3 + 2]));
        engine.camTrackRot[i].push_back(glm::vec3(trackRot[j * 3 + 0], trackRot[j * 3 + 1], trackRot[j * 3 + 2]));
      }
    }
  }

  scenes.setActiveScene(CStr(NScene::STR_SCENE, 0));
  updateSunDir();
  window->repaint();

#if defined(ENV_QT)
  QTimer::singleShot(NEngine::REDRAW_TIMER_MS, this, SLOT(onTimeout()));
#elif defined(ENV_SDL)
  engine.timers.push_back(SDL_AddTimer(NEngine::REDRAW_TIMER_MS, staticOnTimeout, &context));
#endif

  context.log("Done.");
}
//------------------------------------------------------------------------------
#ifdef ENV_SDL
int32 CEngine::event()
{
  window->initializeGL();

  SDL_Event event;

  while(SDL_WaitEvent(&event))
  {
    if(event.type == SDL_WINDOWEVENT)
    {
      uint32 type = event.window.event;

      if((type == SDL_WINDOWEVENT_EXPOSED) && (!engine.waitForFlushTimers))
        simulationStep();
      else if(type == SDL_WINDOWEVENT_RESIZED)
        window->resizeGL(event.window.data1, event.window.data2);
    }
    else if(event.type == SDL_QUIT)
      break;
    else if(event.type == SDL_MOUSEBUTTONDOWN)
      mousePress(window->getMouseButton(event.button.button));
    else if(event.type == SDL_MOUSEBUTTONUP)
      mouseRelease(window->getMouseButton(event.button.button));
    else if(event.type == SDL_MOUSEMOTION)
      mouseMove(SPoint(event.motion.x, event.motion.y), window->getMouseButton(event.button.button));
    else if(event.type == SDL_KEYDOWN)
      keyPress(window->getKey(event.key.keysym.sym));
    else if(event.type == SDL_KEYUP)
      keyRelease(window->getKey(event.key.keysym.sym));
    else if(event.type == engine.initSceneEvent)
      onTimeoutInit();
  }

  return 0;
}
#endif
//------------------------------------------------------------------------------
void CEngine::simulationStep()
{
  context.getCamera()->setMove();

  if((engine.keys & NEngine::KEY_SPECIAL_FRONT) ||
     (engine.keys & NEngine::KEY_SPECIAL_BACK) ||
     (engine.keys & NEngine::KEY_SPECIAL_LEFT) ||
     (engine.keys & NEngine::KEY_SPECIAL_RIGHT) ||
     (engine.keys & NEngine::KEY_SPECIAL_DOWN) ||
     (engine.keys & NEngine::KEY_SPECIAL_UP))
    updateSunDir();

  window->repaint();
}
//------------------------------------------------------------------------------
void CEngine::onTimeout()
{
#ifdef ENV_SDL
  for(uint32 i = 0; i < engine.timers.size(); i++)
    SDL_RemoveTimer(engine.timers[i]);
  engine.timers.clear();
#endif

  updateTicks();

  if((isKeyForDelayedRendering()) || (engine.activeRendering))
  {
#if defined(ENV_QT)
    simulationStep();
#elif defined(ENV_SDL)
    SDL_Event upEvent;
    engine.waitForFlushTimers = SDL_PeepEvents(&upEvent, 1, SDL_PEEKEVENT, SDL_KEYUP, SDL_KEYUP);

    if(!engine.waitForFlushTimers)
    {
      SDL_Event event;
      event.type = SDL_WINDOWEVENT;
      event.window.event = SDL_WINDOWEVENT_EXPOSED;
      SDL_PushEvent(&event);
    }
#endif
  }

#if defined(ENV_QT)
  QTimer::singleShot(NEngine::REDRAW_TIMER_MS, this, SLOT(onTimeout()));
#elif defined(ENV_SDL)
  engine.timers.push_back(SDL_AddTimer(NEngine::REDRAW_TIMER_MS, staticOnTimeout, &context));
#endif
}
//------------------------------------------------------------------------------
void CEngine::mousePress(NEngine::EMouseButton buttons)
{
  UNUSED(buttons);
}
//------------------------------------------------------------------------------
void CEngine::mouseRelease(NEngine::EMouseButton buttons)
{
  UNUSED(buttons);
}
//------------------------------------------------------------------------------
void CEngine::mouseMove(const SPoint &point, NEngine::EMouseButton buttons)
{
  engine.cursor = glm::vec2(static_cast<float>(point.y), static_cast<float>(point.x));

  if(buttons & NEngine::MOUSE_BTN_RIGHT)
  {
    context.getCamera()->setRotate();
    window->repaint();
  }

  engine.cursorOld = engine.cursor;
}
//------------------------------------------------------------------------------
void CEngine::keyPress(NEngine::EKey key)
{
  if(key & NEngine::KEY_QUIT)
    quit();
  else if(key & NEngine::KEY_LPV_MODE)
  {
    engine.lpvMode = static_cast<NEngine::ELPVMode>((static_cast<uint32>(engine.lpvMode) + 1) % NEngine::LPV_MODES_COUNT);
    if(engine.lpvMode != NEngine::LPV_MODE_DISABLED)
      engine.sunSkyUsed[0] = 1;
    else
      engine.sunSkyUsed[0] = 0;
    context.log(CStr("LPV Mode: %s", NEngine::STR_LPV_MODES[engine.lpvMode]));
  }
  else if(key & NEngine::KEY_LPV_TECHNIQUE)
  {
    engine.lpvTechnique = static_cast<NEngine::ELPVTechnique>((static_cast<uint32>(engine.lpvTechnique) + 1) % NEngine::LPV_TECHNIQUES_COUNT);
    context.log(CStr("LPV Technique: %s", NEngine::STR_LPV_TECHNIQUES[engine.lpvTechnique]));
  }
  else if(key & NEngine::KEY_LPV_GV)
  {
    engine.lpvGV = !engine.lpvGV;
    if(engine.lpvGV)
    {
      engine.sunSkyUsed[1] = 1;
      engine.sunSkyUsed[2] = 1;
    }
    else
    {
      if(!engine.lpvSky)
        engine.sunSkyUsed[1] = 0;
      engine.sunSkyUsed[2] = 0;
    }
    context.log(CStr("LPV GV: %d", engine.lpvGV));
  }
  else if(key & NEngine::KEY_LPV_LOBE)
  {
    engine.lpvLobe = !engine.lpvLobe;
    context.log(CStr("LPV Lobe: %d", engine.lpvLobe));
  }
  else if(key & NEngine::KEY_LPV_PROPAGATION_DOWN)
  {
    if(engine.lpvPropagationSteps > 0)
      engine.lpvPropagationSteps--;
  }
  else if(key & NEngine::KEY_LPV_PROPAGATION_UP)
    engine.lpvPropagationSteps++;
  else if(key & NEngine::KEY_LPV_INTENSITY_DOWN)
  {
    engine.lpvIntensity *= 0.5f;
    if(engine.lpvIntensity < 0.0f)
      engine.lpvIntensity = 0.0;
  }
  else if(key & NEngine::KEY_LPV_INTENSITY_UP)
    engine.lpvIntensity *= 2.0f;
  else if(key & NEngine::KEY_SHADOW_JITTERING_DOWN)
  {
    engine.shadowJittering -= 8.0f;
    if(engine.shadowJittering < 0.0f)
      engine.shadowJittering = 0.0;
  }
  else if(key & NEngine::KEY_SHADOW_JITTERING_UP)
    engine.shadowJittering += 8.0f;
  else if(key & NEngine::KEY_SWITCH_MODE)
  {
    engine.keyMode = !engine.keyMode;
    context.log(CStr("Key Mode: %d", engine.keyMode));
  }
  else if(key & NEngine::KEY_CAM_SPEED_DOWN__SCENE_PREV)
  {
    if(!engine.keyMode)
    {
      float speed = camera.getCamera()->position.w;
      speed *= 0.5f;
      if(speed < 0.0f)
        speed = 0.0;
      camera.setSpeed(speed);
    }
    else
    {
      if(!engine.activeSceneIndex)
        engine.activeSceneIndex = engine.scenes - 1;
      else
        engine.activeSceneIndex--;
      scenes.setActiveScene(CStr(NScene::STR_SCENE, engine.activeSceneIndex));
    }
  }
  else if(key & NEngine::KEY_CAM_SPEED_UP__SCENE_NEXT)
  {
    if(!engine.keyMode)
      camera.setSpeed(camera.getCamera()->position.w * 2.0f);
    else
    {
      engine.activeSceneIndex = (engine.activeSceneIndex + 1) % engine.scenes;
      scenes.setActiveScene(CStr(NScene::STR_SCENE, engine.activeSceneIndex));
    }
  }
  else if(key & NEngine::KEY_LPV_REFL_INTENSITY_DOWN__FRUSTUM)
  {
    if(!engine.keyMode)
    {
      engine.lpvReflIntensity *= 0.5f;
      if(engine.lpvReflIntensity < 0.0f)
        engine.lpvReflIntensity = 0.0;
    }
    else
    {
      engine.updateFrustum = !engine.updateFrustum;
      context.log(CStr("Update Frustum: %d", engine.updateFrustum));
    }
  }
  else if(key & NEngine::KEY_LPV_REFL_INTENSITY_UP__NO_COLORS)
  {
    if(!engine.keyMode)
      engine.lpvReflIntensity *= 2.0f;
    else
      engine.noColors = !engine.noColors;
  }
  else if(key & NEngine::KEY_LPV_SKY__SSLPV)
  {
    if(!engine.keyMode)
    {
      engine.lpvSky = !engine.lpvSky;
      if(engine.lpvSky)
        engine.sunSkyUsed[1] = 1;
      else if(!engine.lpvGV)
        engine.sunSkyUsed[1] = 0;
      context.log(CStr("LPV Sky: %d", engine.lpvSky));
    }
    else
    {
      engine.sslpv = !engine.sslpv;
      context.log(CStr("Subsurface Scattering LPV: %d", engine.sslpv));
    }
  }
  else if(key & NEngine::KEY_SHOW_GEOMETRY_BUFFERS__SHADOW)
  {
    if(!engine.keyMode)
      engine.showGeometryBuffer = !engine.showGeometryBuffer;
    else
      engine.showShadowBuffer = !engine.showShadowBuffer;
  }
  else if(key & NEngine::KEY_CAM_PLAY)
  {
    engine.camPlaying = !engine.camPlaying;
    engine.activeRendering = engine.camPlaying;
    context.log(CStr("Camera Run: %d", engine.camPlaying));
  }
  else if(key & NEngine::KEY_MODEL_SET__MODEL_CHANGE)
  {
    if(engine.keyMode)
      engine.activeLpvModel[engine.activeSceneIndex] = (engine.activeLpvModel[engine.activeSceneIndex] + 1) % engine.lpvModelsCount;

    if(CScene *s = scenes.getActiveScene())
    {
      for(uint32 i = 0; i < engine.lpvModelsCount; i++)
      {
        if(CSceneObject *obj = s->getSceneObject(CStr(NScene::STR_OBJECT_LPV_MODEL, i)))
        {
          if(!engine.keyMode)
            obj->setPosition(glm::vec3(camera.getCamera()->position));
          else
          {
            if(i == engine.activeLpvModel[engine.activeSceneIndex])
              obj->show();
            else
              obj->hide();
          }
        }
      }
    }
  }
  if(key & (NEngine::KEY_LPV_PROPAGATION_DOWN | NEngine::KEY_LPV_PROPAGATION_UP))
    context.log(CStr("LPV Propagation Steps: %ud", engine.lpvPropagationSteps));
  else if(key & (NEngine::KEY_LPV_INTENSITY_DOWN | NEngine::KEY_LPV_INTENSITY_UP))
    context.log(CStr("LPV Intensity: %f", static_cast<double>(engine.lpvIntensity)));
  else if(key & (NEngine::KEY_SHADOW_JITTERING_DOWN | NEngine::KEY_SHADOW_JITTERING_UP))
    context.log(CStr("Shadow Jittering: %f", static_cast<double>(engine.shadowJittering)));
  else if(key & (NEngine::KEY_CAM_SPEED_DOWN__SCENE_PREV | NEngine::KEY_CAM_SPEED_UP__SCENE_NEXT))
  {
    if(!engine.keyMode)
      context.log(CStr("Camera Speed: %f", static_cast<double>(camera.getCamera()->position.w)));
    else
      context.log(CStr("Selected Scene: %s", NScene::STR_SCENES[engine.activeSceneIndex]));
  }
  else if((key & (NEngine::KEY_LPV_REFL_INTENSITY_DOWN__FRUSTUM | NEngine::KEY_LPV_REFL_INTENSITY_UP__NO_COLORS)) && (!engine.keyMode))
    context.log(CStr("LPV Reflection Intensity: %f", static_cast<double>(engine.lpvReflIntensity)));

  if(key)
    window->repaint();

  engine.keys = static_cast<NEngine::EKey>(static_cast<uint32>(engine.keys) | static_cast<uint32>(key));
}
//------------------------------------------------------------------------------
#ifdef ENV_QT
void CEngine::onPushButtonClicked()
{
  const bool k = engine.keyMode;
  engine.keyMode = false;

  if(sender() == ui->pbPlaceModel)
    keyPress(NEngine::KEY_MODEL_SET__MODEL_CHANGE);
  if(sender() == ui->pbCamAnim)
    keyPress(NEngine::KEY_CAM_PLAY);

  engine.keyMode = k;
}
//------------------------------------------------------------------------------
void CEngine::onComboBoxChanged(int v)
{
  const bool k = engine.keyMode;
  engine.keyMode = false;

  if(sender() == ui->cbScene)
  {
    engine.activeSceneIndex = v + 1;
    engine.keyMode = true;
    keyPress(NEngine::KEY_CAM_SPEED_DOWN__SCENE_PREV);
    ui->cbModel->setCurrentIndex(engine.activeLpvModel[engine.activeSceneIndex]);
  }
  else if(sender() == ui->cbLPVMode)
  {
    engine.lpvMode = static_cast<NEngine::ELPVMode>(v - 1);
    keyPress(NEngine::KEY_LPV_MODE);
  }
  else if(sender() == ui->cbLPVTech)
  {
    engine.lpvTechnique = static_cast<NEngine::ELPVTechnique>(v - 1);
    keyPress(NEngine::KEY_LPV_TECHNIQUE);
  }
  else if(sender() == ui->cbModel)
  {
    if(!v)
      engine.activeLpvModel[engine.activeSceneIndex] = engine.lpvModelsCount - 1;
    else
      engine.activeLpvModel[engine.activeSceneIndex] = v - 1;
    engine.keyMode = true;
    keyPress(NEngine::KEY_MODEL_SET__MODEL_CHANGE);
  }

  engine.keyMode = k;
}
//------------------------------------------------------------------------------
void CEngine::onCheckBoxChanged(int v)
{
  UNUSED(v);

  const bool k = engine.keyMode;
  engine.keyMode = false;

  if(sender() == ui->cbGV)
    keyPress(NEngine::KEY_LPV_GV);
  else if(sender() == ui->cbLobe)
    keyPress(NEngine::KEY_LPV_LOBE);
  else if(sender() == ui->cbSky)
    keyPress(NEngine::KEY_LPV_SKY__SSLPV);
  else if(sender() == ui->cbSSLPV)
  {
    engine.keyMode = true;
    keyPress(NEngine::KEY_LPV_SKY__SSLPV);
  }
  else if(sender() == ui->cbNoColors)
  {
    engine.keyMode = true;
    keyPress(NEngine::KEY_LPV_REFL_INTENSITY_UP__NO_COLORS);
  }
  else if(sender() == ui->cbFrustum)
  {
    engine.keyMode = true;
    keyPress(NEngine::KEY_LPV_REFL_INTENSITY_DOWN__FRUSTUM);
  }
  else if(sender() == ui->cbGVLPV)
    keyPress(NEngine::KEY_SHOW_GEOMETRY_BUFFERS__SHADOW);
  else if(sender() == ui->cbCSM)
  {
    engine.keyMode = true;
    keyPress(NEngine::KEY_SHOW_GEOMETRY_BUFFERS__SHADOW);
  }
  else if(sender() == ui->cbMode)
  {
    engine.keyMode = k;
    keyPress(NEngine::KEY_SWITCH_MODE);
    return;
  }

  engine.keyMode = k;
}
//------------------------------------------------------------------------------
void CEngine::onSliderChanged(int v)
{
  if(sender() == ui->hsLPVProp)
  {
    engine.lpvPropagationSteps = v + 1;
    keyPress(NEngine::KEY_LPV_PROPAGATION_DOWN);
  }
  else if(sender() == ui->hsLPVInt)
  {
    engine.lpvIntensity = powf(2.0f, v + 1);
    keyPress(NEngine::KEY_LPV_INTENSITY_DOWN);
  }
  else if(sender() == ui->hsLPVRefl)
  {
    engine.lpvReflIntensity = powf(2.0f, v + 1);
    keyPress(NEngine::KEY_LPV_REFL_INTENSITY_DOWN__FRUSTUM);
  }
  else if(sender() == ui->hsShadJit)
  {
    engine.shadowJittering = v + 1;
    keyPress(NEngine::KEY_SHADOW_JITTERING_DOWN);
  }
  else if(sender() == ui->hsCamSpeed)
  {
    camera.setSpeed(powf(2.0f, v + 1));
    keyPress(NEngine::KEY_CAM_SPEED_DOWN__SCENE_PREV);
  }
}
#endif
//------------------------------------------------------------------------------
void CEngine::keyRelease(NEngine::EKey key)
{
  engine.keys = static_cast<NEngine::EKey>(static_cast<uint32>(engine.keys) & (~static_cast<uint32>(key)));
}
//------------------------------------------------------------------------------
void CEngine::showMessage(const std::string &title, const std::string &text, bool modal) const
{
  context.log(CStr("%s\n%s", title.c_str(), text.c_str()));

#if defined(ENV_QT)
  QMessageBox *msg = new QMessageBox(window);
  msg->setWindowTitle(title.c_str());
  msg->setText(text.c_str());
  msg->setStandardButtons(QMessageBox::Ok);
  msg->setDefaultButton(QMessageBox::Ok);
  msg->setModal(modal);
  msg->show();
#elif defined(ENV_SDL)
  UNUSED(modal);
  SDL_ShowSimpleMessageBox(0, title.c_str(), text.c_str(), NULL);
#endif
}
//------------------------------------------------------------------------------
bool CEngine::isKeyForDelayedRendering() const
{
  if((engine.keys & NEngine::KEY_FRONT) ||
     (engine.keys & NEngine::KEY_BACK) ||
     (engine.keys & NEngine::KEY_LEFT) ||
     (engine.keys & NEngine::KEY_RIGHT) ||
     (engine.keys & NEngine::KEY_UP) ||
     (engine.keys & NEngine::KEY_DOWN) ||
     (engine.keys & NEngine::KEY_SPECIAL_FRONT) ||
     (engine.keys & NEngine::KEY_SPECIAL_BACK) ||
     (engine.keys & NEngine::KEY_SPECIAL_LEFT) ||
     (engine.keys & NEngine::KEY_SPECIAL_RIGHT) ||
     (engine.keys & NEngine::KEY_SPECIAL_UP) ||
     (engine.keys & NEngine::KEY_SPECIAL_DOWN))
    return true;
  
  return false;
}
//------------------------------------------------------------------------------
void CEngine::updateTicks()
{
  engine.tickNew =
#if defined(ENV_QT)
    static_cast<uint32>(engine.timer.elapsed());
#elif defined(ENV_SDL)
    SDL_GetTicks();
#endif

  if(!engine.tickOld)
    engine.tickOld = engine.tickNew;

  if((engine.tickNew != engine.tickOld) && (!engine.fpsCounter))
  {
    engine.simulationStep = static_cast<float>(engine.tickNew - engine.tickOld) * NEngine::FPS_MS / NEngine::FPS_COUNTER_MAX;
    engine.fps = 1.0f / engine.simulationStep;
    engine.tickOld = engine.tickNew;
  }
  engine.fpsCounter++;
  if(engine.fpsCounter == NEngine::FPS_COUNTER_MAX)
    engine.fpsCounter = 0;
}
//------------------------------------------------------------------------------
double CEngine::getTime() const
{
#if defined(_WIN32)
  LARGE_INTEGER freq;
  LARGE_INTEGER time;

  QueryPerformanceFrequency(&freq);
  QueryPerformanceCounter(&time);

  return static_cast<double>(time.QuadPart) / static_cast<double>(freq.QuadPart);
#elif defined(__linux__)
  struct timeval time;
  gettimeofday(&time, NULL);

  return static_cast<double>(time.tv_sec) + static_cast<double>(time.tv_usec) / 1000000.0;
#else
  return 0.0;
#endif
}
//------------------------------------------------------------------------------
void CEngine::updateSunDir()
{
  if(CScene *s = scenes.getActiveScene())
  {
    if(!engine.keyMode)
    {
      if(CSceneObject *sun = s->getSceneObject(NScene::STR_OBJECT_LIGHT_SUN))
      {
        const SSceneObject *o = sun->getObject();
        glm::quat r = o->rotation;
        const float d = NMath::PI / 360.0f; // 2 deg
        //const float d = NMath::PI / 72.0f; // 5 deg

        if(engine.keys & NEngine::KEY_SPECIAL_FRONT)
        {
          r.y += d;
          if(r.y > NMath::DIV_PI)
            r.y = NMath::DIV_PI;
        }
        else if(engine.keys & NEngine::KEY_SPECIAL_BACK)
        {
          r.y -= d;
          if(r.y < -NMath::DIV_PI)
            r.y = -NMath::DIV_PI;
        }
        else if(engine.keys & NEngine::KEY_SPECIAL_LEFT)
          r.z -= d;
        else if(engine.keys & NEngine::KEY_SPECIAL_RIGHT)
          r.z += d;

        const glm::vec3 pos(sinf(r.z) * cosf(r.y), sinf(r.y), cosf(r.z) * cosf(r.y));
        sun->setPosition(pos * NScene::SUN_DIR_MUL);
        sun->setRotation(r);
        s->getSceneObject(NScene::STR_OBJECT_BG_SUN)->setPosition(pos * NScene::SUN_MUL);
        if(CFramebuffer *f = framebuffers.getFramebuffer(NEngine::STR_SUN_SHADOW_FBO))
          f->setChanged();
        //std::cout << "sun " << o->position.x << " " << o->position.y << " " << o->position.z << ", " << (r.y * NMath::RAD_2_DEG) << " " << (r.z * NMath::RAD_2_DEG) << "\n";
      }
    }
    else
    {
      for(uint32 i = 0; i < engine.lpvModelsCount; i++)
      {
        if(CSceneObject *obj = s->getSceneObject(CStr(NScene::STR_OBJECT_LPV_MODEL, i)))
        {
          glm::vec3 pos = obj->getObject()->position;
          const float speed = camera.getCamera()->position.w * 0.01f;

          if(engine.keys & NEngine::KEY_SPECIAL_FRONT)
            pos.x -= speed;
          else if(engine.keys & NEngine::KEY_SPECIAL_BACK)
            pos.x += speed;
          else if(engine.keys & NEngine::KEY_SPECIAL_LEFT)
            pos.z -= speed;
          else if(engine.keys & NEngine::KEY_SPECIAL_RIGHT)
            pos.z += speed;
          else if(engine.keys & NEngine::KEY_SPECIAL_DOWN)
            pos.y -= speed;
          else if(engine.keys & NEngine::KEY_SPECIAL_UP)
            pos.y += speed;

          obj->setPosition(pos);
        }
      }
    }
  }
}
//------------------------------------------------------------------------------
std::string CEngine::getClassName(const CEngineBase *object)
{
  UNUSED(object); // todo doplnit !!! třídy
  return "abc";
}
//------------------------------------------------------------------------------
