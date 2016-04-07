//------------------------------------------------------------------------------
#include "window.h"

//------------------------------------------------------------------------------
CWindow::CWindow(CContext *context
#ifdef ENV_QT
  , QObject *parent
#endif
  ) :
#ifdef ENV_QT
#if QT_VERSION < 0x050400
  QGLWidget
#else
  QOpenGLWidget
#endif
  (qobject_cast<QWidget *>(parent)),
#endif
  CEngineBase(context)
#ifdef ENV_SDL
  , SDLwindow(NULL)
#endif
  , vboGeoPoints(0),
  vboLPVGathPoints(0),
  vboLPVScatPoints(0),
  vboQuad(0)
{
#if defined(ENV_QT)
  const SEngine *e = CEngineBase::context->engineGetEngine();

  show();
  setGeometry(50, 50, e->defaultScreenWidth, e->defaultScreenHeight);
  move(QApplication::desktop()->screen()->rect().center() - rect().center());
  setMouseTracking(true);
  //setFocusPolicy(Qt::StrongFocus);
#endif
}
//------------------------------------------------------------------------------
CWindow::~CWindow()
{
#ifdef ENV_SDL
  IMG_Quit();
#endif
}
//------------------------------------------------------------------------------
void CWindow::initializeGL()
{
  const SEngine *e = CEngineBase::context->engineGetEngine();
  CFramebuffers *fbo = CEngineBase::context->getFramebuffers();
  CMaps *maps = CEngineBase::context->getMaps();
  CShaders *s = CEngineBase::context->getShaders();
  COpenGL *gl = CEngineBase::context->getOpenGL();

  if(e->flags & NEngine::EFLAG_SHOW_CONSOLE)
  {
#if defined(_WIN32)
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
#elif defined(__linux__)
    //
#endif
  }

#if defined(ENV_SDL)
  int32 ret;

  if((ret = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER)) < -1)
    CEngineBase::context->getExceptions()->throwException(SException(this, NEngine::STR_ERROR_INIT_SDL));

  /*SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);*/

  if(e->multisampling > 1)
  {
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, e->multisampling);
  }

  if(!(SDLwindow = SDL_CreateWindow(
    NEngine::STR_APP_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, e->defaultScreenWidth, e->defaultScreenHeight,
    SDL_WINDOW_OPENGL | ((e->flags & NEngine::EFLAG_FULLSCREEN) ? SDL_WINDOW_FULLSCREEN :
                         ((e->flags & NEngine::EFLAG_MAXIMIZED) ? (SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE) : SDL_WINDOW_RESIZABLE))
    )))
    CEngineBase::context->getExceptions()->throwException(SException(this, NEngine::STR_ERROR_INIT_WINDOW));

  if(!(SDLcontext = SDL_GL_CreateContext(SDLwindow)))
    CEngineBase::context->getExceptions()->throwException(SException(this, NEngine::STR_ERROR_INIT_GL_CONTEXT));

  uint32 imgInited = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
  if(!(imgInited & IMG_INIT_JPG))
    CEngineBase::context->getExceptions()->throwException(SException(this, NEngine::STR_ERROR_INIT_IMG_JPG));
  if(!(imgInited & IMG_INIT_PNG))
    CEngineBase::context->getExceptions()->throwException(SException(this, NEngine::STR_ERROR_INIT_IMG_PNG));

  /*glewExperimental = NOpenGL::TRUE;
  if(glewInit() != GLEW_OK)
    CEngineBase::context->getExceptions()->throwException(SException(this, NWindow::STR_ERROR_INIT_GLEW));*/
    /*#elif defined(ENV_QT)
      emit onInitializeGL();*/
#endif
  CEngineBase::context->engineInitialize();

  gl->makeCurrent();
  gl->initializeGLFunctions(NEngine::GPU_PLATFORM_MAX);
  //context->log(gl->getStatus());

  CEngineBase::context->log(std::string("Vendor: ")+reinterpret_cast<const char *>(glGetString(NOpenGL::VENDOR)));
  CEngineBase::context->log(std::string("Renderer: ")+reinterpret_cast<const char *>(glGetString(NOpenGL::RENDERER)));
  CEngineBase::context->log(std::string("Version: ")+reinterpret_cast<const char *>(glGetString(NOpenGL::VERSION)));
  CEngineBase::context->log(std::string("GLSL Version: ")+reinterpret_cast<const char *>(glGetString(NOpenGL::SHADING_LANGUAGE_VERSION)));

  const bool gpu32 = (gl->getStatusFramebufferTexture() != NOpenGLProc::TYPE_NOT_LOADED);
  const bool gpu43 = ((gl->getStatusDispatchCompute() != NOpenGLProc::TYPE_NOT_LOADED) && (gl->getStatusBindImageTexture() != NOpenGLProc::TYPE_NOT_LOADED));
  if(!gpu32)
    CEngineBase::context->getExceptions()->throwException(SException(this, NEngine::STR_ERROR_INIT_GL_PLATFORM));
  CEngineBase::context->log(CStr(NEngine::STR_SELECT_GL_PLATFORM, (gpu43) ? "4.3" : "3.2"));
  CEngineBase::context->engineSetPlatform((gpu43) ? NEngine::GPU_PLATFORM_GL0403 : NEngine::GPU_PLATFORM_GL0302, (gpu43) ? NEngine::LPV_MODE_COMPUTE : NEngine::LPV_MODE_GEOMETRY, NEngine::LPV_TECHNIQUE_SCATTERING);

  gl->enable(NOpenGL::DEPTH_TEST);

  gl->enable(NOpenGL::CULL_FACE);
  gl->frontFace(NOpenGL::CW);

  gl->enable(NOpenGL::BLEND);
  gl->blendFunc(NOpenGL::SRC_ALPHA, NOpenGL::ONE_MINUS_SRC_ALPHA);
  gl->disable(NOpenGL::BLEND);

  gl->clearColor(0.0f, 0.0f, 0.0f, 0.0f);

  maps->loadDefaultMaps();

  // lpv framebuffers, images
  std::vector<uint32> fboAttachments;

  if(e->gpuPlatform >= NEngine::GPU_PLATFORM_GL0302)
  {
    fboAttachments.push_back(NMap::FORMAT_3D | NMap::FORMAT_LINEAR | NMap::FORMAT_BORDER); // lpv r
    fboAttachments.push_back(NMap::FORMAT_3D | NMap::FORMAT_LINEAR | NMap::FORMAT_BORDER); // lpv g
    fboAttachments.push_back(NMap::FORMAT_3D | NMap::FORMAT_LINEAR | NMap::FORMAT_BORDER); // lpv b
    fboAttachments.push_back(NMap::FORMAT_3D | NMap::FORMAT_LINEAR | NMap::FORMAT_BORDER); // accum lpv r
    fboAttachments.push_back(NMap::FORMAT_3D | NMap::FORMAT_LINEAR | NMap::FORMAT_BORDER); // accum lpv g
    fboAttachments.push_back(NMap::FORMAT_3D | NMap::FORMAT_LINEAR | NMap::FORMAT_BORDER); // accum lpv b
    fboAttachments.push_back(NMap::FORMAT_3D | NMap::FORMAT_LINEAR | NMap::FORMAT_BORDER); // gv
    fbo->addFbo(SFramebuffer(NEngine::STR_LPV0_GS_FBO, fboAttachments, NMap::RBO, e->lpvTextureSize.x * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z));
    fbo->addFbo(SFramebuffer(NEngine::STR_LPV1_GS_FBO, fboAttachments, NMap::RBO, e->lpvTextureSize.x * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z));
    fboAttachments.clear();

    // lpv vbo data
    std::vector<float> vboGeoData(e->geometryTextureSize * e->geometryTiles.x * e->geometryTextureSize * e->geometryTiles.y);
    std::vector<float> vboLPVData(65536);
    memset(&vboGeoData[0], 0, sizeof(float) * vboGeoData.size());
    memset(&vboLPVData[0], 0, sizeof(float) * vboLPVData.size());
    gl->genBuffers(1, &vboGeoPoints);
    gl->bindBuffer(NOpenGL::ARRAY_BUFFER, vboGeoPoints);
    gl->bufferData(NOpenGL::ARRAY_BUFFER, sizeof(float) * vboGeoData.size(), &vboGeoData[0], NOpenGL::STATIC_DRAW);
    gl->bindBuffer(NOpenGL::ARRAY_BUFFER, 0);
    gl->genBuffers(1, &vboLPVGathPoints);
    gl->bindBuffer(NOpenGL::ARRAY_BUFFER, vboLPVGathPoints);
    gl->bufferData(NOpenGL::ARRAY_BUFFER, sizeof(float) * e->lpvTextureSize.z, &vboLPVData[0], NOpenGL::STATIC_DRAW);
    gl->bindBuffer(NOpenGL::ARRAY_BUFFER, 0);
    gl->genBuffers(1, &vboLPVScatPoints);
    gl->bindBuffer(NOpenGL::ARRAY_BUFFER, vboLPVScatPoints);
    gl->bufferData(NOpenGL::ARRAY_BUFFER, sizeof(float) * vboLPVData.size(), &vboLPVData[0], NOpenGL::STATIC_DRAW);
    gl->bindBuffer(NOpenGL::ARRAY_BUFFER, 0);
  }
  else if(e->gpuPlatform >= NEngine::GPU_PLATFORM_GL0403)
  {
    maps->addMap(SMap(NEngine::STR_LPV0_CS_IMG_R, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NEngine::LPV_SH_COUNT * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NEngine::STR_LPV0_CS_IMG_G, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NEngine::LPV_SH_COUNT * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NEngine::STR_LPV0_CS_IMG_B, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NEngine::LPV_SH_COUNT * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NEngine::STR_LPV0_ACCUM_CS_IMG_R, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NEngine::LPV_SH_COUNT * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NEngine::STR_LPV0_ACCUM_CS_IMG_G, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NEngine::LPV_SH_COUNT * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NEngine::STR_LPV0_ACCUM_CS_IMG_B, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NEngine::LPV_SH_COUNT * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NEngine::STR_LPV1_CS_IMG_R, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NEngine::LPV_SH_COUNT * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NEngine::STR_LPV1_CS_IMG_G, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NEngine::LPV_SH_COUNT * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NEngine::STR_LPV1_CS_IMG_B, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NEngine::LPV_SH_COUNT * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NEngine::STR_LPV1_ACCUM_CS_IMG_R, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NEngine::LPV_SH_COUNT * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NEngine::STR_LPV1_ACCUM_CS_IMG_G, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NEngine::LPV_SH_COUNT * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NEngine::STR_LPV1_ACCUM_CS_IMG_B, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NEngine::LPV_SH_COUNT * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NEngine::STR_GV_CS_IMG, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NEngine::LPV_SH_COUNT * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z));
  }

  // lpv test
  lpvClearData.resize(e->lpvTextureSize.x * e->lpvCascadesCount * e->lpvTextureSize.y * e->lpvTextureSize.z * NMap::RGBA_SIZE);
  /*for(auto it = lpvClearData.begin(); it != lpvClearData.end(); it++)
    *it = static_cast<float>((rand() % 2000) - 1000) * 0.002f;
  gl->bindTexture(NOpenGL::TEXTURE_3D, maps->getMap(NEngine::STR_SKY0_GS_MAP_R)->getMap()->texture);
  gl->texSubImage3D(NOpenGL::TEXTURE_3D, 0, 0, 0, 0, e->lpvTextureSize.x * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z, NOpenGL::RGBA, NOpenGL::FLOAT, &lpvClearData[0]);
  gl->bindTexture(NOpenGL::TEXTURE_3D, 0);*/
  memset(&lpvClearData[0], 0, sizeof(float) * lpvClearData.size());

  // shadow framebuffer
  fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_DEPTH | NMap::FORMAT_BORDER);
  fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_BORDER);
  fbo->addFbo(SFramebuffer(NEngine::STR_SUN_SHADOW_FBO, fboAttachments, NMap::RBO, e->shadowTextureSize * e->shadowTiles.x, e->shadowTextureSize * e->shadowTiles.y));
  fboAttachments.clear();

  // geometry framebuffer
  fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_BORDER); // amb
  fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_BORDER); // pos
  fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_BORDER); // normal
  //fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_DEPTH | NMap::FORMAT_BORDER); // depth
  fbo->addFbo(SFramebuffer(NEngine::STR_GEOMETRY_FBO, fboAttachments, NMap::RBO_DEPTH, e->geometryTextureSize * e->geometryTiles.x, e->geometryTextureSize * e->geometryTiles.y));
  fboAttachments.clear();

  // shaders
  const uint32 shaderCounts[] =
  {
    NShader::PROGRAMS_COUNT, NShader::VERTEX_SHADERS_COUNT, NShader::TESSELATION_CONTROL_SHADERS_COUNT, NShader::TESSELATION_EVALUATION_SHADERS_COUNT,
    NShader::GEOMETRY_SHADERS_COUNT, NShader::FRAGMENT_SHADERS_COUNT, NShader::COMPUTE_SHADERS_COUNT
  };

  const char *const (*const shaderFiles[])[2] =
  {
    NULL, NShader::STR_VERTEX_SHADER_LIST, NShader::STR_TESSELATION_CONTROL_SHADER_LIST, NShader::STR_TESSELATION_EVALUATION_SHADER_LIST,
    NShader::STR_GEOMETRY_SHADER_LIST, NShader::STR_FRAGMENT_SHADER_LIST, NShader::STR_COMPUTE_SHADER_LIST
  };

  for(uint32 type = NShader::TYPE_VERTEX; type <= NShader::TYPE_COMPUTE; type++)
    for(uint32 sh = 0; sh < shaderCounts[type]; sh++)
      s->addShader(SShader(
        CStr(NShader::STR_SHADER_NAME, shaderFiles[type][sh][0], shaderFiles[type][sh][1]),
        static_cast<NShader::EType>(type),
        shaderFiles[type][sh][0],
        shaderFiles[type][sh][1]));

  for(uint32 p = 0; p < NShader::PROGRAMS_COUNT; p++)
    s->addShaderProgram(SShaderProgram(
      static_cast<NShader::EProgram>(p),
      (NShader::PROGRAM_VERTEX_SHADER_LIST[p] == -1) ? NULL : s->getShader(CStr(NShader::STR_SHADER_NAME,
        NShader::STR_VERTEX_SHADER_LIST[NShader::PROGRAM_VERTEX_SHADER_LIST[p]][0],
        NShader::STR_VERTEX_SHADER_LIST[NShader::PROGRAM_VERTEX_SHADER_LIST[p]][1])),
      (NShader::PROGRAM_TESSELATION_CONTROL_SHADER_LIST[p] == -1) ? NULL : s->getShader(CStr(NShader::STR_SHADER_NAME,
        NShader::STR_TESSELATION_CONTROL_SHADER_LIST[NShader::PROGRAM_TESSELATION_CONTROL_SHADER_LIST[p]][0],
        NShader::STR_TESSELATION_CONTROL_SHADER_LIST[NShader::PROGRAM_TESSELATION_CONTROL_SHADER_LIST[p]][1])),
      (NShader::PROGRAM_TESSELATION_EVALUATION_SHADER_LIST[p] == -1) ? NULL : s->getShader(CStr(NShader::STR_SHADER_NAME,
        NShader::STR_TESSELATION_EVALUATION_SHADER_LIST[NShader::PROGRAM_TESSELATION_EVALUATION_SHADER_LIST[p]][0],
        NShader::STR_TESSELATION_EVALUATION_SHADER_LIST[NShader::PROGRAM_TESSELATION_EVALUATION_SHADER_LIST[p]][1])),
      (NShader::PROGRAM_GEOMETRY_SHADER_LIST[p] == -1) ? NULL : s->getShader(CStr(NShader::STR_SHADER_NAME,
        NShader::STR_GEOMETRY_SHADER_LIST[NShader::PROGRAM_GEOMETRY_SHADER_LIST[p]][0],
        NShader::STR_GEOMETRY_SHADER_LIST[NShader::PROGRAM_GEOMETRY_SHADER_LIST[p]][1])),
      (NShader::PROGRAM_FRAGMENT_SHADER_LIST[p] == -1) ? NULL : s->getShader(CStr(NShader::STR_SHADER_NAME,
        NShader::STR_FRAGMENT_SHADER_LIST[NShader::PROGRAM_FRAGMENT_SHADER_LIST[p]][0],
        NShader::STR_FRAGMENT_SHADER_LIST[NShader::PROGRAM_FRAGMENT_SHADER_LIST[p]][1])),
      (NShader::PROGRAM_COMPUTE_SHADER_LIST[p] == -1) ? NULL : s->getShader(CStr(NShader::STR_SHADER_NAME,
        NShader::STR_COMPUTE_SHADER_LIST[NShader::PROGRAM_COMPUTE_SHADER_LIST[p]][0],
        NShader::STR_COMPUTE_SHADER_LIST[NShader::PROGRAM_COMPUTE_SHADER_LIST[p]][1])),
      NShader::PROGRAM_ATTRIBS_LIST[p], NShader::PROGRAM_UNIFORMS_LIST[p], NShader::PROGRAM_SAMPLERS_LIST[p], NShader::PROGRAM_RENDER_STATES_LIST[p]
      ));

  // vbo quad
  const float vboQuadData[] =
  {
    0.0f,  0.0f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,
    2.0f,  0.0f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,
    2.0f, -2.0f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,
    0.0f, -2.0f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f
  };

  gl->genBuffers(1, &vboQuad);
  gl->bindBuffer(NOpenGL::ARRAY_BUFFER, vboQuad);
  gl->bufferData(NOpenGL::ARRAY_BUFFER, NModel::VERTEX_PNTBTC_SIZE_F * 4, vboQuadData, NOpenGL::STATIC_DRAW);
  gl->bindBuffer(NOpenGL::ARRAY_BUFFER, 0);
  quadTechnique.material = &quadMaterial;

/*#ifdef ENV_QT
  emit onInitializeFinishGL();
#endif*/
  CEngineBase::context->engineInitializeFinish();
}
//------------------------------------------------------------------------------
void CWindow::paintGL()
{
  COpenGL *gl = CEngineBase::context->getOpenGL();
  CRenderer *ren = CEngineBase::context->getRenderer();
  CShaders *sh = CEngineBase::context->getShaders();
  CMaps *maps = CEngineBase::context->getMaps();
  CFramebuffers *fbo = CEngineBase::context->getFramebuffers();
  CCamera *cam = CEngineBase::context->getCamera();
  CCulling *cul = CEngineBase::context->getCulling();
  const SCamera *c = cam->getCamera();
  const SEngine *e = CEngineBase::context->engineGetEngine();
  gl->makeCurrent();

  gl->clear(NOpenGL::COLOR_BUFFER_BIT | NOpenGL::DEPTH_BUFFER_BIT);
  CEngineBase::context->engineClearDrawCalls();

  if(CScene *s = CEngineBase::context->getScenes()->getActiveScene())
  {
    const glm::vec3 pos = glm::vec3(c->position);
    const glm::vec3 rot = glm::vec3(c->rotation);
    const float clipNear = c->clipNear;
    const float clipFar = c->clipFar;

    // backdrop
    cam->setPosition(glm::vec3());
    cam->setRange(NCamera::CLIP_BACKDROP_NEAR, NCamera::CLIP_BACKDROP_FAR);
    if(e->updateFrustum)
      cul->updateFrustum();

    ren->setMode(NRenderer::MODE_BACKDROP);
    s->render();
    ren->dispatch();
    ren->clearGroups();

    CFramebuffer *fboShadow = fbo->getFramebuffer(NEngine::STR_SUN_SHADOW_FBO);
    CFramebuffer *fboGeometry = fbo->getFramebuffer(NEngine::STR_GEOMETRY_FBO);
    CSceneObject *sun = s->getSceneObject(NScene::STR_OBJECT_LIGHT_SUN);

    if((fboShadow) && (sun))
    { // shadow map
      for(uint32 i = 0; i < e->shadowCascadesCount; i++)
      {
        const float clipSide = e->shadowCascadesClips[i * NMath::VEC2 + 0];
        const float clipDepth = e->shadowCascadesClips[i * NMath::VEC2 + 1];
        const glm::vec2 sunRot(sun->getObject()->rotation.y, sun->getObject()->rotation.z);

        cam->setRange(-clipDepth, clipDepth, -clipSide, clipSide, clipSide, -clipSide); // sets orthographic projection
        cam->setGridAlignedOrthoTransform(pos, sunRot, (clipSide * 2.0f) / static_cast<float>(e->shadowTextureSize));
        CEngineBase::context->engineSetShadowViewProj(i, c->viewProjection);

        if(e->updateFrustum)
          cul->updateFrustum();
        CEngineBase::context->engineSetShadowFrustum(i, *cul->getFrustum());
      }

      fboShadow->bind();
      gl->clear(NOpenGL::DEPTH_BUFFER_BIT);

      ren->setMode(NRenderer::MODE_DEPTH_CASCADE);
      s->render();
      ren->dispatch();
      ren->clearGroups();

      fbo->unbind();
      fboShadow->setChanged(false);
    }

    if((fboGeometry) && (sun) && (e->lpvMode != NEngine::LPV_MODE_DISABLED))
    { // geometry map
      CEngineBase::context->engineSetSunSkyPose(0, sun->getObject()->position, glm::vec2(sun->getObject()->rotation.y, sun->getObject()->rotation.z)); // update sun for inject
      CEngineBase::context->engineSetSunSkyColor(0, glm::vec3(sun->getLight()->color));

      for(uint32 cascade = 0; cascade < e->lpvCascadesCount; cascade++)
      {
        const float clipSide = e->geometryCascadesClips[cascade * NMath::VEC2 + 0];
        const float clipDepth = e->geometryCascadesClips[cascade * NMath::VEC2 + 1];

        cam->setRange(-clipDepth, clipDepth, -clipSide, clipSide, clipSide, -clipSide); // sets orthographic projection

        CEngineBase::context->engineSetLpvPose(cascade, glm::vec3(
          static_cast<float>(static_cast<int32>(pos.x / e->lpvCellSizes[cascade * NMath::VEC3 + 0])) * e->lpvCellSizes[cascade * NMath::VEC3 + 0],
          static_cast<float>(static_cast<int32>(pos.y / e->lpvCellSizes[cascade * NMath::VEC3 + 1])) * e->lpvCellSizes[cascade * NMath::VEC3 + 1],
          static_cast<float>(static_cast<int32>(pos.z / e->lpvCellSizes[cascade * NMath::VEC3 + 2])) * e->lpvCellSizes[cascade * NMath::VEC3 + 2]));

        for(uint32 dir = 0; dir < e->lpvSunSkyCount; dir++)
        {
          const glm::vec2 sunSkyRot(e->sunSkyRots[dir * NMath::VEC2 + 0], e->sunSkyRots[dir * NMath::VEC2 + 1]);

          cam->setGridAlignedOrthoTransform(pos, sunSkyRot, (clipSide * 2.0f) / static_cast<float>(e->geometryTextureSize));
          CEngineBase::context->engineSetGeometryViewProj(cascade * e->lpvSunSkyCount + dir, c->viewProjection);

          if(e->updateFrustum)
            cul->updateFrustum();
          CEngineBase::context->engineSetGeometryFrustum(cascade * e->lpvSunSkyCount + dir, *cul->getFrustum());
        }
      }

      fboGeometry->bind();
      gl->clear(NOpenGL::COLOR_BUFFER_BIT | NOpenGL::DEPTH_BUFFER_BIT);

      ren->setMode(NRenderer::MODE_GEOMETRY_CASCADE);
      s->render();
      ren->dispatch();
      ren->clearGroups();

      fbo->unbind();
      fboGeometry->setChanged(false);
    }

    // lpv
    CFramebuffer *fboLpvGs0 = fbo->getFramebuffer(NEngine::STR_LPV0_GS_FBO);
    CFramebuffer *fboLpvGs1 = fbo->getFramebuffer(NEngine::STR_LPV1_GS_FBO);
    CShaderProgram *shaderlpvGsInject = sh->getProgram(NShader::PROGRAM_LPV_INJECTION_GEOMETRY);
    CShaderProgram *shaderlpvGsPropGath = sh->getProgram(NShader::PROGRAM_LPV_PROPAGATION_GEOMETRY_GATHERING);
    CShaderProgram *shaderlpvGsPropScat = sh->getProgram(NShader::PROGRAM_LPV_PROPAGATION_GEOMETRY_SCATTERING);

    if((fboLpvGs0) && (fboLpvGs1) && (shaderlpvGsInject) && (shaderlpvGsPropGath) && (shaderlpvGsPropScat) &&
       (e->lpvMode == NEngine::LPV_MODE_GEOMETRY) && (e->gpuPlatform >= NEngine::GPU_PLATFORM_GL0302))
    { // gl 3.2
      maps->getMap(NEngine::STR_LPV0_GS_MAP_R)->fill(&lpvClearData[0]);
      maps->getMap(NEngine::STR_LPV0_GS_MAP_G)->fill(&lpvClearData[0]);
      maps->getMap(NEngine::STR_LPV0_GS_MAP_B)->fill(&lpvClearData[0]);
      maps->getMap(NEngine::STR_LPV0_ACCUM_GS_MAP_R)->fill(&lpvClearData[0]);
      maps->getMap(NEngine::STR_LPV0_ACCUM_GS_MAP_G)->fill(&lpvClearData[0]);
      maps->getMap(NEngine::STR_LPV0_ACCUM_GS_MAP_B)->fill(&lpvClearData[0]);
      maps->getMap(NEngine::STR_GV0_GS_MAP)->fill(&lpvClearData[0]);
      maps->getMap(NEngine::STR_LPV1_GS_MAP_R)->fill(&lpvClearData[0]);
      maps->getMap(NEngine::STR_LPV1_GS_MAP_G)->fill(&lpvClearData[0]);
      maps->getMap(NEngine::STR_LPV1_GS_MAP_B)->fill(&lpvClearData[0]);
      maps->getMap(NEngine::STR_LPV1_ACCUM_GS_MAP_R)->fill(&lpvClearData[0]);
      maps->getMap(NEngine::STR_LPV1_ACCUM_GS_MAP_G)->fill(&lpvClearData[0]);
      maps->getMap(NEngine::STR_LPV1_ACCUM_GS_MAP_B)->fill(&lpvClearData[0]);
      maps->getMap(NEngine::STR_GV1_GS_MAP)->fill(&lpvClearData[0]);

      gl->depthMask(NOpenGL::FALSE); // proceed all fragments
      gl->enable(NOpenGL::BLEND);
      gl->blendFunc(NOpenGL::ONE, NOpenGL::ONE); // pseudo imageAtomicAdd() with floats

      // injection
      fboLpvGs0->bind();
      shaderlpvGsInject->bind(); // shader with random access writing
      gl->bindBuffer(NOpenGL::ARRAY_BUFFER, vboGeoPoints);
      shaderlpvGsInject->begin(NULL, NRenderer::MODE_LPV_INJECTION_GEOMETRY);
      gl->drawArrays(NOpenGL::POINTS, 0, e->geometryTextureSize * e->geometryTiles.x * e->geometryTextureSize * e->geometryTiles.y);
      shaderlpvGsInject->end(NULL);
      gl->bindBuffer(NOpenGL::ARRAY_BUFFER, 0);
      shaderlpvGsInject->unbind();
      fbo->unbind();

      // propagation
      if(e->lpvPropagationSwap)
        CEngineBase::context->engineSwapLPV();

      for(uint32 i = 0; i < e->lpvPropagationSteps; i++)
      {
        if(!e->lpvPropagationSwap)
        {
          maps->getMap(NEngine::STR_LPV1_GS_MAP_R)->fill(&lpvClearData[0]);
          maps->getMap(NEngine::STR_LPV1_GS_MAP_G)->fill(&lpvClearData[0]);
          maps->getMap(NEngine::STR_LPV1_GS_MAP_B)->fill(&lpvClearData[0]);
          maps->getMap(NEngine::STR_LPV1_ACCUM_GS_MAP_R)->fill(&lpvClearData[0]);
          maps->getMap(NEngine::STR_LPV1_ACCUM_GS_MAP_G)->fill(&lpvClearData[0]);
          maps->getMap(NEngine::STR_LPV1_ACCUM_GS_MAP_B)->fill(&lpvClearData[0]);
          maps->getMap(NEngine::STR_GV1_GS_MAP)->fill(&lpvClearData[0]);
          fboLpvGs1->bind();
        }
        else
        {
          maps->getMap(NEngine::STR_LPV0_GS_MAP_R)->fill(&lpvClearData[0]);
          maps->getMap(NEngine::STR_LPV0_GS_MAP_G)->fill(&lpvClearData[0]);
          maps->getMap(NEngine::STR_LPV0_GS_MAP_B)->fill(&lpvClearData[0]);
          maps->getMap(NEngine::STR_LPV0_ACCUM_GS_MAP_R)->fill(&lpvClearData[0]);
          maps->getMap(NEngine::STR_LPV0_ACCUM_GS_MAP_G)->fill(&lpvClearData[0]);
          maps->getMap(NEngine::STR_LPV0_ACCUM_GS_MAP_B)->fill(&lpvClearData[0]);
          maps->getMap(NEngine::STR_GV0_GS_MAP)->fill(&lpvClearData[0]);
          fboLpvGs0->bind();
        }

        if(e->lpvTechnique == NEngine::LPV_TECHNIQUE_GATHERING)
        {
          shaderlpvGsPropGath->bind();
          gl->bindBuffer(NOpenGL::ARRAY_BUFFER, vboLPVGathPoints);
          shaderlpvGsPropGath->begin(NULL, NRenderer::MODE_LPV_PROPAGATION_GEOMETRY_GATHERING);
          gl->drawArrays(NOpenGL::POINTS, 0, e->lpvTextureSize.z);
          shaderlpvGsPropGath->end(NULL);
          gl->bindBuffer(NOpenGL::ARRAY_BUFFER, 0);
          shaderlpvGsPropGath->unbind();
        }
        else
        {
          const GLint u = shaderlpvGsPropScat->getProgram()->uniforms.lpvParams;
          int32 cells = e->lpvTextureSize.x * e->lpvCascadesCount * e->lpvTextureSize.y * e->lpvTextureSize.z;

          shaderlpvGsPropScat->bind();
          gl->bindBuffer(NOpenGL::ARRAY_BUFFER, vboLPVScatPoints);
          shaderlpvGsPropScat->begin(NULL, NRenderer::MODE_LPV_PROPAGATION_GEOMETRY_SCATTERING);

          for(uint32 c = 0; cells >= 65536; cells -= 65536, c++)
          { // draw each 65536 points from lpv cells
            gl->uniform2f(u, c, 0);
            gl->drawArrays(NOpenGL::POINTS, 0, 65536);
          }
          if(cells > 0) // render last reimaining points
            gl->drawArrays(NOpenGL::POINTS, 0, cells);

          shaderlpvGsPropScat->end(NULL);
          gl->bindBuffer(NOpenGL::ARRAY_BUFFER, 0);
          shaderlpvGsPropScat->unbind();
        }

        fbo->unbind();
        CEngineBase::context->engineSwapLPV();
      }

      gl->disable(NOpenGL::BLEND);
      gl->blendFunc(NOpenGL::SRC_ALPHA, NOpenGL::ONE_MINUS_SRC_ALPHA);
      gl->depthMask(NOpenGL::TRUE);
    }
    else if((e->lpvMode == NEngine::LPV_MODE_COMPUTE) && (e->gpuPlatform >= NEngine::GPU_PLATFORM_GL0302))
    { // gl 4.3
      // todo try gl->clearTexImage();

      /*sh->getProgram(NShader::PROGRAM_LPV_CLEAR_COMPUTE)->
        dispatch(e->lpvTextureSize.x * e->lpvTextureSize.y, e->lpvTextureSize.z, 1, NRenderer::MODE_LPV_CLEAR_COMPUTE);
      sh->getProgram(NShader::PROGRAM_LPV_INJECTION_COMPUTE)->
        dispatch(e->geometryTextureSize, e->geometryTextureSize, 1, NRenderer::MODE_LPV_INJECTION_COMPUTE);
      for(uint32 i = 0; i < e->lpvPropagationSteps; i++)
        sh->getProgram(NShader::PROGRAM_LPV_PROPAGATION_COMPUTE)->
        dispatch(e->lpvTextureSize.x * e->lpvTextureSize.y, e->lpvTextureSize.z, 1, NRenderer::MODE_LPV_PROPAGATION_COMPUTE);*/
    }
    
    // standard
    cam->setPosition(pos);
    cam->setRotation(rot);
    cam->resetScale();
    cam->setRange(clipNear, clipFar);
    if(e->updateFrustum)
      cul->updateFrustum();

    // standard
    ren->setMode(NRenderer::MODE_STANDARD);
    s->render();
    ren->dispatch();
    ren->clearGroups();

    if((fboShadow) && (e->showShadowBuffer))
    {
      const CMap *m = fboShadow->getFrameBuffer()->attachments[0].map;
      const float r = (c->height / c->width) * (static_cast<float>(m->getMap()->width) / static_cast<float>(m->getMap()->height));
      drawTexture(0.0f, 0.0f, 0.4f * r, 0.4f, m, 0, true);
    }

    if((fboGeometry) && (e->showGeometryBuffer))
    {
      const CMap *m = fboGeometry->getFrameBuffer()->attachments[0].map;
      const float r = (c->height / c->width) * (static_cast<float>(m->getMap()->width) / static_cast<float>(m->getMap()->height));
      drawTexture(0.0f, 0.0f, 0.333f * r, 0.333f, fboGeometry->getFrameBuffer()->attachments[0].map);
      drawTexture(0.0f, 0.333f, 0.333f * r, 0.333f, fboGeometry->getFrameBuffer()->attachments[1].map);
      drawTexture(0.0f, 0.666f, 0.333f * r, 0.333f, fboGeometry->getFrameBuffer()->attachments[2].map);
      //drawTexture(0.0f, 0.666f, 0.333f * r, 0.333f, fboGeometry->getFrameBuffer()->attachments[3].map);

      m = fbo->getFramebuffer((!e->lpvPropagationSwap) ? NEngine::STR_LPV0_GS_FBO : NEngine::STR_LPV1_GS_FBO)->getFrameBuffer()->attachments[4].map;
      for(uint8 i = 0; i < 8; i++)
        drawTexture(0.8f, static_cast<float>(i) * 0.11f, 0.2f, 0.1f, m, i * 4);
    }
  }

  std::string title = CStr(
    NEngine::STR_APP_TITLE,
    static_cast<double>(static_cast<float>(static_cast<int32>(c->position.x / 0.01f)) * 0.01f),
    static_cast<double>(static_cast<float>(static_cast<int32>(c->position.y / 0.01f)) * 0.01f),
    static_cast<double>(static_cast<float>(static_cast<int32>(c->position.z / 0.01f)) * 0.01f),
    e->drawCalls);

#if defined(ENV_QT)
  setWindowTitle(title.c_str());
#elif defined(ENV_SDL)
  SDL_SetWindowTitle(SDLwindow, title.c_str());
  SDL_GL_SwapWindow(SDLwindow);
#endif
}
//------------------------------------------------------------------------------
void CWindow::resizeGL(int width, int height)
{
  COpenGL *gl = CEngineBase::context->getOpenGL();
  gl->makeCurrent();

  gl->viewport(0, 0, width, height);
  CEngineBase::context->getCamera()->setSize(static_cast<float>(width), static_cast<float>(height));

#ifdef ENV_SDL
  repaint();
#endif
}
//------------------------------------------------------------------------------
#ifdef ENV_QT
bool CWindow::event(QEvent *event)
{
  if((event->type() == QEvent::MouseButtonPress) || (event->type() == QEvent::MouseButtonRelease) || (event->type() == QEvent::MouseMove))
  {
    QMouseEvent *e = static_cast<QMouseEvent *>(event);
    const NEngine::EMouseButton b = getMouseButton(e->buttons());

    if(event->type() == QEvent::MouseButtonPress)
      emit onMousePress(b);
    else if(event->type() == QEvent::MouseButtonRelease)
      emit onMouseRelease(b);
    else if(event->type() == QEvent::MouseMove)
      emit onMouseMove(SPoint(e->pos().x(), e->pos().y()), b);

    return true;
  }
  else if((event->type() == QEvent::KeyPress) || (event->type() == QEvent::KeyRelease))
  {
    QKeyEvent *e = static_cast<QKeyEvent *>(event);
    const uint32 k = e->key();

    if(event->type() == QEvent::KeyPress)
      emit onKeyPress(getKey(k));
    else
      emit onKeyRelease(getKey(k));

    return true;
  }

  return
#if QT_VERSION < 0x050400
    QGLWidget
#else
    QOpenGLWidget
#endif
    ::event(event);
}
#endif
//------------------------------------------------------------------------------
NEngine::EMouseButton CWindow::getMouseButton(int32 button)
{
#if defined(ENV_QT)
  return static_cast<NEngine::EMouseButton>(
    ((button & Qt::LeftButton) ? NEngine::MOUSE_BTN_LEFT : NEngine::MOUSE_BTN) |
    ((button & Qt::RightButton) ? NEngine::MOUSE_BTN_RIGHT : NEngine::MOUSE_BTN));
#elif defined(ENV_SDL)
  return static_cast<NEngine::EMouseButton>(
    (((button == SDL_BUTTON_LEFT) || (button == SDL_BUTTON_X2)) ? NEngine::MOUSE_BTN_LEFT : NEngine::MOUSE_BTN) |
    (((button == SDL_BUTTON_RIGHT) || (button == SDL_BUTTON_X1) || (button == SDL_BUTTON_X2)) ? NEngine::MOUSE_BTN_RIGHT : NEngine::MOUSE_BTN));
#endif

  return NEngine::MOUSE_BTN;
}
//------------------------------------------------------------------------------
NEngine::EKey CWindow::getKey(int32 key) const
{
  const SEngine *e = CEngineBase::context->engineGetEngine();
  auto it = e->keysMap.find(key);

  if(it == e->keysMap.cend())
    return NEngine::KEY;

  return it->second;
}
//------------------------------------------------------------------------------
void CWindow::drawTexture(float x, float y, float w, float h, const CMap *texture, uint32 level, bool isShadow)
{
  COpenGL *gl = CEngineBase::context->getOpenGL();
  CShaders *s = CEngineBase::context->getShaders();
  const uint32 format = texture->getMap()->format;
  const GLenum texFormat = (format & NMap::FORMAT_3D) ? NOpenGL::TEXTURE_3D : ((format & NMap::FORMAT_2D_ARRAY) ? NOpenGL::TEXTURE_2D_ARRAY : ((format & NMap::FORMAT_CUBE) ? NOpenGL::TEXTURE_CUBE_MAP : NOpenGL::TEXTURE_2D));

  quadMaterial.program = (format & NMap::FORMAT_3D) ? s->getProgram(NShader::PROGRAM_BASIC_3D) : ((format & NMap::FORMAT_2D_ARRAY) ? s->getProgram(NShader::PROGRAM_BASIC_2D_ARRAY) : s->getProgram(NShader::PROGRAM_BASIC));
  quadMaterial.program->bind();
  gl->bindBuffer(NOpenGL::ARRAY_BUFFER, vboQuad);
  quadTechnique.mvp = glm::scale(glm::translate(glm::mat4(1.0f), glm::vec3(x * 2.0f - 1.0f, 1.0f - y * 2.0f, 0.0f)), glm::vec3(w, h, 1.0f));
  quadMaterial.diffuseMap = texture;
  quadMaterial.program->begin(&quadTechnique);
  if(texture->getMap()->depth)
    gl->uniform1f(quadMaterial.program->getProgram()->uniforms.opacity, (static_cast<float>(level) + 0.5f) / static_cast<float>(texture->getMap()->depth));

  //gl->texParameteri(texFormat, NOpenGL::TEXTURE_MAG_FILTER, NOpenGL::NEAREST);
  //gl->texParameteri(texFormat, NOpenGL::TEXTURE_MIN_FILTER, NOpenGL::NEAREST);
  if(format & (NMap::FORMAT_3D | NMap::FORMAT_2D_ARRAY))
    gl->texParameteri(texFormat, NOpenGL::TEXTURE_WRAP_R, NOpenGL::CLAMP_TO_EDGE);
  gl->texParameteri(texFormat, NOpenGL::TEXTURE_WRAP_S, NOpenGL::CLAMP_TO_EDGE);
  gl->texParameteri(texFormat, NOpenGL::TEXTURE_WRAP_T, NOpenGL::CLAMP_TO_EDGE);

  gl->depthMask(NOpenGL::FALSE);
  if(isShadow)
    gl->texParameteri(texFormat, NOpenGL::TEXTURE_COMPARE_MODE, NOpenGL::NONE);
  gl->drawArrays(NOpenGL::QUADS, 0, 4);
  gl->depthMask(NOpenGL::TRUE);
  quadMaterial.program->end(&quadTechnique);
  gl->bindBuffer(NOpenGL::ARRAY_BUFFER, 0);
  quadMaterial.program->unbind();
}
//------------------------------------------------------------------------------
//test debug, don't panic !
/*const glm::mat4 rot2_ = glm::rotate(glm::rotate(glm::mat4(1.0), r.z, glm::vec3(0.0, 1.0, 0.0)), -r.y, glm::vec3(1.0, 0.0, 0.0));
glUseProgram(0);
glEnable(NOpenGL::BLEND);
glMatrixMode(NOpenGL::PROJECTION);
glLoadIdentity();
glMultMatrixf(glm::value_ptr(c->projection));
glMatrixMode(NOpenGL::MODELVIEW);
glLoadIdentity();
glMultMatrixf(glm::value_ptr(c->view));
glMultMatrixf(glm::value_ptr(rot2_));
const float range = 20.0f;

glBegin(NOpenGL::LINES);
glColor4f(0.5f, 0.5f, 1.0f, 0.2f);

for(float y = -step * range; y <= (step * range); y += step)
{
  for(float x = -step * range; x <= (step * range); x += step)
  {
    glVertex3f(-range, y, x);
    glVertex3f(range, y, x);
    glVertex3f(x, -range, y);
    glVertex3f(x, range, y);
    glVertex3f(x, y, -range);
    glVertex3f(x, y, range);
  }
}
glEnd();

glLoadIdentity();
glMatrixMode(NOpenGL::PROJECTION);
glLoadIdentity();
glMatrixMode(NOpenGL::MODELVIEW);
glDisable(NOpenGL::BLEND);

glDisable(NOpenGL::DEPTH_TEST);
glEnable(NOpenGL::TEXTURE_2D);
glBindTexture(NOpenGL::TEXTURE_2D, CEngineBase::context->getMaps()->getMap(NWindow::STR_ORTHO_DEPTH_FBO_MAP)->getMap()->texture);
glTexParameteri(NOpenGL::TEXTURE_2D, NOpenGL::TEXTURE_COMPARE_MODE, NOpenGL::NONE);
const float fboW = f->getFrameBuffer()->width * 2.0f / c->width * 2.0f;
const float fboH = f->getFrameBuffer()->height * 2.0f / c->height * 2.0f;
glBegin(NOpenGL::QUADS);
glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
glTexCoord2f(1.0f, 1.0f);
glVertex3f(-1.0f, 1.0f, 1.0f);
glTexCoord2f(0.0f, 1.0f);
glVertex3f(-1.0f + fboW, 1.0f, 1.0f);
glTexCoord2f(0.0f, 0.0f);
glVertex3f(-1.0f + fboW, 1.0f - fboH, 1.0f);
glTexCoord2f(1.0f, 0.0f);
glVertex3f(-1.0f, 1.0f - fboH, 1.0f);
glEnd();
glTexParameteri(NOpenGL::TEXTURE_2D, NOpenGL::TEXTURE_COMPARE_MODE, NOpenGL::COMPARE_R_TO_TEXTURE);
glDisable(NOpenGL::TEXTURE_2D);
glEnable(NOpenGL::DEPTH_TEST);*/
//------------------------------------------------------------------------------
