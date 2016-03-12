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
  , vboGeoPoints(0)
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
    CEngineBase::context->getExceptions()->throwException(SException(this, NWindow::STR_ERROR_INIT_SDL));

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
    CEngineBase::context->getExceptions()->throwException(SException(this, NWindow::STR_ERROR_INIT_WINDOW));

  if(!(SDLcontext = SDL_GL_CreateContext(SDLwindow)))
    CEngineBase::context->getExceptions()->throwException(SException(this, NWindow::STR_ERROR_INIT_GL_CONTEXT));

  uint32 imgInited = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
  if(!(imgInited & IMG_INIT_JPG))
    CEngineBase::context->getExceptions()->throwException(SException(this, NWindow::STR_ERROR_INIT_IMG_JPG));
  if(!(imgInited & IMG_INIT_PNG))
    CEngineBase::context->getExceptions()->throwException(SException(this, NWindow::STR_ERROR_INIT_IMG_PNG));

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

  const bool gpu43 = (gl->getStatusDispatchCompute() == NOpenGLProc::TYPE_NOT_LOADED);
  CEngineBase::context->engineSetPlatform((gpu43) ? NEngine::GPU_PLATFORM_GL0302 : NEngine::GPU_PLATFORM_GL0403, (gpu43) ? NEngine::LPV_MODE_COMPUTE : NEngine::LPV_MODE_GEOMETRY, NEngine::LPV_TECHNIQUE_SCATTERING);

  gl->enable(NOpenGL::DEPTH_TEST);

  gl->enable(NOpenGL::CULL_FACE);
  gl->frontFace(NOpenGL::CW);

  gl->enable(NOpenGL::BLEND);
  gl->blendFunc(NOpenGL::SRC_ALPHA, NOpenGL::ONE_MINUS_SRC_ALPHA);
  gl->disable(NOpenGL::BLEND);

  gl->clearColor(0.0f, 0.0f, 0.0f, 0.0f);

  maps->loadDefaultMaps();

  // lpv maps
  std::vector<uint32> fboAttachments;

  if((e->gpuPlatform >= NEngine::GPU_PLATFORM_GL0302) && (e->gpuPlatform < NEngine::GPU_PLATFORM_GL0403))
  {
    fboAttachments.push_back(NMap::FORMAT_3D | NMap::FORMAT_LINEAR | NMap::FORMAT_BORDER); // lpv r
    fboAttachments.push_back(NMap::FORMAT_3D | NMap::FORMAT_LINEAR | NMap::FORMAT_BORDER); // lpv g
    fboAttachments.push_back(NMap::FORMAT_3D | NMap::FORMAT_LINEAR | NMap::FORMAT_BORDER); // lpv b
    fboAttachments.push_back(NMap::FORMAT_3D | NMap::FORMAT_LINEAR | NMap::FORMAT_BORDER); // gv
    fbo->addFbo(SFramebuffer(NWindow::STR_LPV0_FBO, fboAttachments, NMap::RBO, e->lpvTextureSize.x, e->lpvTextureSize.y, e->lpvTextureSize.z));
    fbo->addFbo(SFramebuffer(NWindow::STR_LPV1_FBO, fboAttachments, NMap::RBO, e->lpvTextureSize.x, e->lpvTextureSize.y, e->lpvTextureSize.z));
    fboAttachments.clear();

    std::vector<float> vboGeoData(e->geometryTextureSize * e->geometryTextureSize);
    memset(&vboGeoData[0], 0, sizeof(float) * vboGeoData.size());
    gl->genBuffers(1, &vboGeoPoints);
    gl->bindBuffer(NOpenGL::ARRAY_BUFFER, vboGeoPoints);
    gl->bufferData(NOpenGL::ARRAY_BUFFER, sizeof(float) * vboGeoData.size(), &vboGeoData[0], NOpenGL::STATIC_DRAW);
    gl->bindBuffer(NOpenGL::ARRAY_BUFFER, 0);
  }
  else if(e->gpuPlatform >= NEngine::GPU_PLATFORM_GL0403)
  {
    maps->addMap(SMap(NWindow::STR_LPV0_MAP_R, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NWindow::LPV_SH_COUNT, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NWindow::STR_LPV0_MAP_R, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NWindow::LPV_SH_COUNT, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NWindow::STR_LPV0_MAP_R, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NWindow::LPV_SH_COUNT, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NWindow::STR_LPV1_MAP_R, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NWindow::LPV_SH_COUNT, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NWindow::STR_LPV1_MAP_R, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NWindow::LPV_SH_COUNT, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NWindow::STR_LPV1_MAP_R, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NWindow::LPV_SH_COUNT, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NWindow::STR_GV0_MAP, NMap::FORMAT_3D | NMap::FORMAT_BORDER | NMap::FORMAT_INT, e->lpvTextureSize.x * NWindow::LPV_SH_COUNT, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NWindow::STR_LPV_OUT_MAP_R, NMap::FORMAT_3D | NMap::FORMAT_BORDER, e->lpvTextureSize.x, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NWindow::STR_LPV_OUT_MAP_R, NMap::FORMAT_3D | NMap::FORMAT_BORDER, e->lpvTextureSize.x, e->lpvTextureSize.y, e->lpvTextureSize.z));
    maps->addMap(SMap(NWindow::STR_LPV_OUT_MAP_R, NMap::FORMAT_3D | NMap::FORMAT_BORDER, e->lpvTextureSize.x, e->lpvTextureSize.y, e->lpvTextureSize.z));
  }

  // lpv test
  lpvClearData.resize(e->lpvTextureSize.x * e->lpvTextureSize.y * e->lpvTextureSize.z * NMap::RGBA_SIZE);
  /*for(auto it = lpvClearData.begin(); it != lpvClearData.end(); it++)
    *it = static_cast<float>((rand() % 2000) - 1000) * 0.002f;
  gl->bindTexture(NOpenGL::TEXTURE_3D, maps->getMap(NWindow::STR_LPV0_MAP_R)->getMap()->texture);
  gl->texSubImage3D(NOpenGL::TEXTURE_3D, 0, 0, 0, 0, e->lpvTextureSize.x, e->lpvTextureSize.y, e->lpvTextureSize.z, NOpenGL::RGBA, NOpenGL::FLOAT, &lpvClearData[0]);
  gl->bindTexture(NOpenGL::TEXTURE_3D, 0);*/
  memset(&lpvClearData[0], 0, sizeof(float) * lpvClearData.size());

  // shadow framebuffer
  fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_DEPTH | NMap::FORMAT_EDGE);
  fbo->addFbo(SFramebuffer(NWindow::STR_ORTHO_DEPTH_FBO, fboAttachments, NMap::RBO, e->depthTextureSize, e->depthTextureSize));
  fboAttachments.clear();

  // geometry framebuffer
  fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_BORDER); // amb
  fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_BORDER); // pos
  fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_BORDER); // normal
  fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_DEPTH | NMap::FORMAT_BORDER); // depth
  fbo->addFbo(SFramebuffer(NWindow::STR_ORTHO_GEOMETRY_FBO, fboAttachments, NMap::RBO, e->geometryTextureSize, e->geometryTextureSize));
  fboAttachments.clear();

  // shaders
  for(uint32 i = 0; i < NShader::VERTEX_SHADERS_COUNT; i++)
    s->addShader(SShader((std::string(NShader::STR_VERTEX_SHADER_LIST[i]) == NShader::STR_SHADER_UNUSED) ? NShader::TYPE_UNDEFINED : NShader::TYPE_VERTEX, NShader::STR_VERTEX_SHADER_LIST[i]));
  for(uint32 i = 0; i < NShader::GEOMETRY_SHADERS_COUNT; i++)
    s->addShader(SShader((std::string(NShader::STR_GEOMETRY_SHADER_LIST[i]) == NShader::STR_SHADER_UNUSED) ? NShader::TYPE_UNDEFINED : NShader::TYPE_GEOMETRY, NShader::STR_GEOMETRY_SHADER_LIST[i]));
  /*for(uint32 i = 0; i < NShader::TESSELATION_CONTROL_SHADERS_COUNT; i++)
    s->addShader(SShader((std::string(NShader::STR_TESSELATION_CONTROL_SHADER_LIST[i]) == NShader::STR_SHADER_UNUSED) ? NShader::TYPE_UNDEFINED : NShader::TYPE_TESSELATION_CONTROL, NShader::STR_TESSELATION_CONTROL_SHADER_LIST[i]));
  for(uint32 i = 0; i < NShader::TESSELATION_EVALUATION_SHADERS_COUNT; i++)
    s->addShader(SShader((std::string(NShader::STR_TESSELATION_EVALUATION_SHADER_LIST[i]) == NShader::STR_SHADER_UNUSED) ? NShader::TYPE_UNDEFINED : NShader::TYPE_TESSELATION_EVALUATION, NShader::STR_TESSELATION_EVALUATION_SHADER_LIST[i]));*/
  for(uint32 i = 0; i < NShader::FRAGMENT_SHADERS_COUNT; i++)
    s->addShader(SShader((std::string(NShader::STR_FRAGMENT_SHADER_LIST[i]) == NShader::STR_SHADER_UNUSED) ? NShader::TYPE_UNDEFINED : NShader::TYPE_FRAGMENT, NShader::STR_FRAGMENT_SHADER_LIST[i]));
  for(uint32 i = 0; i < NShader::COMPUTE_SHADERS_COUNT; i++)
    s->addShader(SShader((std::string(NShader::STR_COMPUTE_SHADER_LIST[i]) == NShader::STR_SHADER_UNUSED) ? NShader::TYPE_UNDEFINED : NShader::TYPE_COMPUTE, NShader::STR_COMPUTE_SHADER_LIST[i]));

  for(uint32 i = 0; i < NShader::PROGRAMS_COUNT; i++)
    s->addShaderProgram(SShaderProgram(
      static_cast<NShader::EProgram>(i),
      s->getShader(NShader::STR_PROGRAM_VERTEX_SHADER_LIST[i]),
      s->getShader(NShader::STR_PROGRAM_GEOMETRY_SHADER_LIST[i]),
      s->getShader(NShader::STR_PROGRAM_TESSELATION_CONTROL_SHADER_LIST[i]),
      s->getShader(NShader::STR_PROGRAM_TESSELATION_EVALUATION_SHADER_LIST[i]),
      s->getShader(NShader::STR_PROGRAM_FRAGMENT_SHADER_LIST[i]),
      s->getShader(NShader::STR_PROGRAM_COMPUTE_SHADER_LIST[i])));

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

    // sbybox
    cam->setPosition(glm::vec3());
    cam->setRange(NCamera::CLIP_BACKDROP_NEAR, NCamera::CLIP_BACKDROP_FAR);
    if(e->updateFrustum)
      cul->updateFrustum();

    ren->setMode(NRenderer::MODE_BACKDROP);
    s->render();
    ren->dispatch();
    ren->clearGroups();

    // depth map
    CFramebuffer *fboDepth = fbo->getFramebuffer(NWindow::STR_ORTHO_DEPTH_FBO);
    CFramebuffer *fboGeo = fbo->getFramebuffer(NWindow::STR_ORTHO_GEOMETRY_FBO);
    CSceneObject *sun = s->getSceneObject(NScene::STR_OBJECT_LIGHT_SUN);
    const glm::vec3 orthoScale(NCamera::ORTHO_DEPTH_SCALE_X, NCamera::ORTHO_DEPTH_SCALE_Y, NCamera::ORTHO_DEPTH_SCALE_Z);
    //fboDepth->setChanged(); // debug

    if((fboDepth) && (fboGeo) && (sun) &&
       ((fboDepth->getFrameBuffer()->changed) ||
       (glm::length(glm::vec3(fboDepth->getFrameBuffer()->camera.position) * orthoScale - pos) > (e->orthoDepthSize * 0.1f))))
    {
      //std::cout << "update " << glm::to_string(glm::vec3(f->getFrameBuffer()->camera.position) * orthoScale) << " | " << glm::to_string(pos) << "\n";
      cam->setRange(-e->orthoDepthDepth, e->orthoDepthDepth, -e->orthoDepthSize, e->orthoDepthSize, e->orthoDepthSize, -e->orthoDepthSize);

      const glm::quat r = sun->getObject()->rotation;
      const float step = (c->clipRight - c->clipLeft) / fboDepth->getFrameBuffer()->width;
      const glm::vec3 invSun = glm::vec3(glm::rotate(glm::rotate(glm::mat4(1.0), r.y, glm::vec3(1.0, 0.0, 0.0)), -r.z, glm::vec3(0.0, 1.0, 0.0)) * glm::vec4(pos, 1.0));
      const glm::vec3 invSunFloor(static_cast<float>(static_cast<int32>(invSun.x / step)) * step, static_cast<float>(static_cast<int32>(invSun.y / step)) * step, static_cast<float>(static_cast<int32>(invSun.z / step)) * step);
      const glm::vec3 sunFloor(glm::rotate(glm::rotate(glm::mat4(1.0), r.z, glm::vec3(0.0, 1.0, 0.0)), -r.y, glm::vec3(1.0, 0.0, 0.0)) * glm::vec4(invSunFloor, 1.0));

      //std::cout << ccc.x << " " << ccc.y << " " << ccc.z << "\n";
      cam->setPosition(sunFloor * orthoScale);
      cam->setRotation(glm::vec3(r.y * NMath::RAD_2_DEG, -r.z * NMath::RAD_2_DEG, 0.0f));
      cam->setScale(c->scale * orthoScale);
      if(e->updateFrustum)
        cul->updateFrustum();

      fboDepth->setCamera(*c);
      fboDepth->bind();
      gl->clear(NOpenGL::DEPTH_BUFFER_BIT);

      ren->setMode(NRenderer::MODE_DEPTH);
      s->render();
      ren->dispatch();
      ren->clearGroups();

      fbo->unbind();
      fboDepth->setChanged(false);

      // geo light
      fboGeo->setCamera(*c);
      fboGeo->bind();
      gl->clear(NOpenGL::COLOR_BUFFER_BIT | NOpenGL::DEPTH_BUFFER_BIT);

      ren->setMode(NRenderer::MODE_GEOMETRY);
      s->render();
      ren->dispatch();
      ren->clearGroups();

      fbo->unbind();
      fboGeo->setChanged(false);

      cam->setPosition(sun->getObject()->position);
      fboGeo->setCamera(*c);

      if((e->gpuPlatform >= NEngine::GPU_PLATFORM_GL0302) && (e->gpuPlatform < NEngine::GPU_PLATFORM_GL0403))
      {
        maps->getMap(NWindow::STR_LPV0_MAP_R)->fill(&lpvClearData[0]);
        maps->getMap(NWindow::STR_LPV0_MAP_G)->fill(&lpvClearData[0]);
        maps->getMap(NWindow::STR_LPV0_MAP_B)->fill(&lpvClearData[0]);
        maps->getMap(NWindow::STR_GV0_MAP)->fill(&lpvClearData[0]);
        maps->getMap(NWindow::STR_LPV1_MAP_R)->fill(&lpvClearData[0]);
        maps->getMap(NWindow::STR_LPV1_MAP_G)->fill(&lpvClearData[0]);
        maps->getMap(NWindow::STR_LPV1_MAP_B)->fill(&lpvClearData[0]);
        maps->getMap(NWindow::STR_GV0_MAP)->fill(&lpvClearData[0]);

        CShaderProgram *lpvInject = sh->getProgram(NShader::PROGRAM_LPV_INJECTION);

        fbo->getFramebuffer(NWindow::STR_LPV0_FBO)->bind();
        gl->depthMask(NOpenGL::FALSE); // proceed all fragments
        gl->enable(NOpenGL::BLEND);
        gl->blendFunc(NOpenGL::SRC_ALPHA, NOpenGL::ONE_MINUS_SRC_ALPHA); // pseudo imageAtomicAdd() with floats
        lpvInject->bind(); // shader with random access writing
        gl->bindBuffer(NOpenGL::ARRAY_BUFFER, vboGeoPoints);

        lpvInject->begin(NULL, NRenderer::MODE_LPV_INJECTION);
        gl->drawArrays(NOpenGL::POINTS, 0, e->geometryTextureSize * e->geometryTextureSize);
        lpvInject->end(NULL);

        gl->bindBuffer(NOpenGL::ARRAY_BUFFER, 0);
        lpvInject->unbind();
        gl->disable(NOpenGL::BLEND);
        gl->blendFunc(NOpenGL::SRC_ALPHA, NOpenGL::ONE);
        gl->depthMask(NOpenGL::TRUE);
        fbo->unbind();
      }
      else if(e->gpuPlatform >= NEngine::GPU_PLATFORM_GL0403)
      {
        // todo try gl->clearTexImage();

        sh->getProgram(NShader::PROGRAM_LPV_CLEAR_COMPUTE)->
          dispatch(e->lpvTextureSize.x * e->lpvTextureSize.y, e->lpvTextureSize.z, 1, NRenderer::MODE_LPV_CLEAR_COMPUTE);
        sh->getProgram(NShader::PROGRAM_LPV_INJECTION_COMPUTE)->
          dispatch(e->geometryTextureSize, e->geometryTextureSize, 1, NRenderer::MODE_LPV_INJECTION_COMPUTE);
        for(uint32 i = 0; i < e->lpvPropagationSteps; i++)
          sh->getProgram(NShader::PROGRAM_LPV_PROPAGATION_COMPUTE)->
          dispatch(e->lpvTextureSize.x * e->lpvTextureSize.y, e->lpvTextureSize.z, 1, NRenderer::MODE_LPV_PROPAGATION_COMPUTE);
      }
    }
    
    // standard
    cam->setPosition(pos);
    cam->setRotation(rot);
    cam->resetScale();
    cam->setRange(clipNear, clipFar);
    if(e->updateFrustum)
      cul->updateFrustum();
    
    // geo camera
    /*fboGeo->setCamera(*c);
    fboGeo->bind();
    gl->clear(NOpenGL::COLOR_BUFFER_BIT | NOpenGL::DEPTH_BUFFER_BIT);

    ren->setMode(NRenderer::MODE_LPV_INJECTION);
    s->render();
    ren->dispatch();
    ren->clearGroups();

    fbo->unbind();
    fboGeo->setChanged(false);*/

    // standard
    ren->setMode(NRenderer::MODE_STANDARD);
    s->render();
    ren->dispatch();
    ren->clearGroups();

    if((fboGeo) && (e->showGeometryBuffer))
    {
      const float r = c->height / c->width;
      drawTexture(fboGeo->getFrameBuffer()->attachments[0].map->getMap()->texture, 0.0f, 0.0f, 0.25f * r, 0.25f);
      drawTexture(fboGeo->getFrameBuffer()->attachments[1].map->getMap()->texture, 0.0f, 0.25f, 0.25f * r, 0.25f);
      drawTexture(fboGeo->getFrameBuffer()->attachments[2].map->getMap()->texture, 0.0f, 0.5f, 0.25f * r, 0.25f);
      drawTexture(fboGeo->getFrameBuffer()->attachments[3].map->getMap()->texture, 0.0f, 0.75f, 0.25f * r, 0.25f, true);
    }
  }

  std::string title = CStr(
    NWindow::STR_APP_TITLE,
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
void CWindow::drawTexture(GLuint texture, float x, float y, float w, float h, bool isShadow)
{
  COpenGL *gl = CEngineBase::context->getOpenGL();

  gl->useProgram(0);
  gl->enable(NOpenGL::TEXTURE_2D);
  gl->activeTexture(NOpenGL::TEXTURE3);
  gl->bindTexture(NOpenGL::TEXTURE_2D, 0);
  gl->activeTexture(NOpenGL::TEXTURE2);
  gl->bindTexture(NOpenGL::TEXTURE_2D, 0);
  gl->activeTexture(NOpenGL::TEXTURE1);
  gl->bindTexture(NOpenGL::TEXTURE_2D, 0);
  gl->activeTexture(NOpenGL::TEXTURE0);
  gl->bindTexture(NOpenGL::TEXTURE_2D, texture);
  if(isShadow)
    gl->texParameteri(NOpenGL::TEXTURE_2D, NOpenGL::TEXTURE_COMPARE_MODE, NOpenGL::NONE);
  //gl->depthMask(NOpenGL::FALSE);
  gl->disable(NOpenGL::DEPTH_TEST);
  gl->disable(NOpenGL::BLEND);

  const float vx[] = { x * 2.0f - 1.0f, -y * 2.0f + 1.0f, (x + w) * 2.0f - 1.0f, (-y - h) * 2.0f + 1.0f };

  glBegin(NOpenGL::QUADS);
  glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(vx[0], vx[1], 1.0f);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(vx[2], vx[1], 1.0f);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(vx[2], vx[3], 1.0f);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(vx[0], vx[3], 1.0f);
  glEnd();

  if(isShadow)
    gl->texParameteri(NOpenGL::TEXTURE_2D, NOpenGL::TEXTURE_COMPARE_MODE, NOpenGL::COMPARE_REF_TO_TEXTURE);
  gl->bindTexture(NOpenGL::TEXTURE_2D, 0);
  //gl->depthMask(NOpenGL::TRUE);
  gl->enable(NOpenGL::DEPTH_TEST);
  gl->disable(NOpenGL::TEXTURE_2D);
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
