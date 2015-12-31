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
{
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
  const SEngine *e = CWindow::context->engineGetEngine();
  const SCamera *c = CWindow::context->getCamera()->getCamera();

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
    CWindow::context->getExceptions()->throwException(SException(this, NWindow::STR_ERROR_INIT_SDL));

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
    NEngine::STR_APP_NAME, SDL_WINDOWPOS_UNDEFINED/*1550 - c->width*/, SDL_WINDOWPOS_UNDEFINED/*850 - c->height*/, c->width, c->height,
    SDL_WINDOW_OPENGL | ((e->flags & NEngine::EFLAG_FULLSCREEN) ? SDL_WINDOW_FULLSCREEN :
                         ((e->flags & NEngine::EFLAG_MAXIMIZED) ? (SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE) : SDL_WINDOW_RESIZABLE))
    )))
    CWindow::context->getExceptions()->throwException(SException(this, NWindow::STR_ERROR_INIT_WINDOW));

  if(!(SDLcontext = SDL_GL_CreateContext(SDLwindow)))
    CWindow::context->getExceptions()->throwException(SException(this, NWindow::STR_ERROR_INIT_GL_CONTEXT));

  uint32 imgInited = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
  if(!(imgInited & IMG_INIT_JPG))
    CWindow::context->getExceptions()->throwException(SException(this, NWindow::STR_ERROR_INIT_IMG_JPG));
  if(!(imgInited & IMG_INIT_PNG))
    CWindow::context->getExceptions()->throwException(SException(this, NWindow::STR_ERROR_INIT_IMG_PNG));

  /*if(SDL_GL_SetSwapInterval(-1) == -1)
    SDL_GL_SetSwapInterval(1);*/

  glewExperimental = GL_TRUE;
  if(glewInit() != GLEW_OK)
    CWindow::context->getExceptions()->throwException(SException(this, NWindow::STR_ERROR_INIT_GLEW));
#elif defined(ENV_QT)
  emit onInitializeGL();
#endif

  //COpenGL *gl = CEngineBase::context->getOpenGL();
  CShaders *s = CEngineBase::context->getShaders();
  //gl->makeCurrent();

  CEngineBase::context->log(std::string("Vendor: ")+reinterpret_cast<const char *>(glGetString(GL_VENDOR)));
  CEngineBase::context->log(std::string("Renderer: ")+reinterpret_cast<const char *>(glGetString(GL_RENDERER)));
  CEngineBase::context->log(std::string("Version: ")+reinterpret_cast<const char *>(glGetString(GL_VERSION)));
  CEngineBase::context->log(std::string("GLSL Version: ")+reinterpret_cast<const char *>(glGetString(GL_SHADING_LANGUAGE_VERSION)));

  glEnable(GL_DEPTH_TEST);

  glEnable(GL_CULL_FACE);
  glFrontFace(GL_CW);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glDisable(GL_BLEND);

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

  /*GLint p[2];
  glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &p[0]);
  glGetIntegerv(GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS, &p[1]);
  CEngineBase::context->log(CStr("Max Texture Image Units: %d, Compute Image Units: %d", p[0], p[1]));*/

  // maps
  CMaps *maps = CEngineBase::context->getMaps();
  maps->loadDefaultMaps();
  //CMap *lpvMap = 
  maps->addMap(SMap(NWindow::STR_LPV_MAP_R0, NMap::FORMAT_3D | NMap::FORMAT_LINEAR | NMap::FORMAT_EDGE, e->lpvTextureSize.x, e->lpvTextureSize.y, e->lpvTextureSize.z));
  maps->addMap(SMap(NWindow::STR_LPV_MAP_G0, NMap::FORMAT_3D | NMap::FORMAT_LINEAR | NMap::FORMAT_EDGE, e->lpvTextureSize.x, e->lpvTextureSize.y, e->lpvTextureSize.z));
  maps->addMap(SMap(NWindow::STR_LPV_MAP_B0, NMap::FORMAT_3D | NMap::FORMAT_LINEAR | NMap::FORMAT_EDGE, e->lpvTextureSize.x, e->lpvTextureSize.y, e->lpvTextureSize.z));
  maps->addMap(SMap(NWindow::STR_GV_MAP_A0, NMap::FORMAT_3D | NMap::FORMAT_LINEAR | NMap::FORMAT_EDGE, e->lpvTextureSize.x, e->lpvTextureSize.y, e->lpvTextureSize.z));

  // lpv test
  /*std::vector<float> lpvData(e->lpvTextureSize.x * e->lpvTextureSize.y * e->lpvTextureSize.z * NMap::RGBA_SIZE);
  for(auto it = lpvData.begin(); it != lpvData.end(); it++)
    *it = static_cast<float>((rand() % 2000) - 1900) * 0.001f;
  glBindTexture(GL_TEXTURE_3D, lpvMap->getMap()->texture);
  glTexSubImage3D(GL_TEXTURE_3D, 0, 0, 0, 0, e->lpvTextureSize.x, e->lpvTextureSize.y, e->lpvTextureSize.z, GL_RGBA, GL_FLOAT, &lpvData[0]);
  glBindTexture(GL_TEXTURE_3D, 0);*/

  // framebuffers
  CFramebuffers *fbo = CEngineBase::context->getFramebuffers();
  std::vector<uint32> fboAttachments;
  fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_DEPTH | NMap::FORMAT_EDGE);
  fbo->addFbo(SFramebuffer(NWindow::STR_ORTHO_DEPTH_FBO, fboAttachments, NMap::RBO, e->depthTextureSize, e->depthTextureSize));

  fboAttachments.clear();
  fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_EDGE); // amb
  fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_EDGE); // pos
  fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_EDGE); // normal
  fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_DEPTH | NMap::FORMAT_EDGE); // depth
  fbo->addFbo(SFramebuffer(NWindow::STR_ORTHO_GEOMETRY_FBO, fboAttachments, NMap::RBO, e->geometryTextureSize, e->geometryTextureSize));

  // shaders
  for(uint32 i = 0; i < NShader::VERTEX_SHADERS_COUNT; i++)
    s->addShader(SShader(NShader::TYPE_VERTEX, NShader::STR_VERTEX_SHADER_LIST[i]));
  for(uint32 i = 0; i < NShader::GEOMETRY_SHADERS_COUNT; i++)
    s->addShader(SShader(NShader::TYPE_VERTEX, NShader::STR_GEOMETRY_SHADER_LIST[i]));
  for(uint32 i = 0; i < NShader::TESSELATION_CONTROL_SHADERS_COUNT; i++)
    s->addShader(SShader(NShader::TYPE_VERTEX, NShader::STR_TESSELATION_CONTROL_SHADER_LIST[i]));
  for(uint32 i = 0; i < NShader::TESSELATION_EVALUATION_SHADERS_COUNT; i++)
    s->addShader(SShader(NShader::TYPE_VERTEX, NShader::STR_TESSELATION_EVALUATION_SHADER_LIST[i]));
  for(uint32 i = 0; i < NShader::FRAGMENT_SHADERS_COUNT; i++)
    s->addShader(SShader(NShader::TYPE_FRAGMENT, NShader::STR_FRAGMENT_SHADER_LIST[i]));
  for(uint32 i = 0; i < NShader::COMPUTE_SHADERS_COUNT; i++)
    s->addShader(SShader(NShader::TYPE_COMPUTE, NShader::STR_COMPUTE_SHADER_LIST[i]));

  for(uint32 i = 0; i < NShader::PROGRAMS_COUNT; i++)
    s->addShaderProgram(SShaderProgram(
      static_cast<NShader::EProgram>(i),
      s->getShader(NShader::STR_PROGRAM_VERTEX_SHADER_LIST[i]),
      s->getShader(NShader::STR_PROGRAM_GEOMETRY_SHADER_LIST[i]),
      s->getShader(NShader::STR_PROGRAM_TESSELATION_CONTROL_SHADER_LIST[i]),
      s->getShader(NShader::STR_PROGRAM_TESSELATION_EVALUATION_SHADER_LIST[i]),
      s->getShader(NShader::STR_PROGRAM_FRAGMENT_SHADER_LIST[i]),
      s->getShader(NShader::STR_PROGRAM_COMPUTE_SHADER_LIST[i])));

#ifdef ENV_QT
  emit onInitializeFinishGL();
#endif
}
//------------------------------------------------------------------------------
void CWindow::paintGL()
{
  //COpenGL *gl = CEngineBase::context->getOpenGL();
  CRenderer *ren = CEngineBase::context->getRenderer();
  CShaders *sh = CEngineBase::context->getShaders();
  //CMaps *maps = CEngineBase::context->getMaps();
  CFramebuffers *fbo = CEngineBase::context->getFramebuffers();
  CCamera *cam = CEngineBase::context->getCamera();
  CCulling *cul = CEngineBase::context->getCulling();
  const SCamera *c = cam->getCamera();
  const SEngine *e = CEngineBase::context->engineGetEngine();
  //gl->makeCurrent();

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

    // clear lpv
    /*if(CMap *lpvMap = maps->getMap(NWindow::STR_LPV_MAP))
      lpvMap->clear();
    if(CMap *gvMap = maps->getMap(NWindow::STR_GV_MAP))
      gvMap->clear();*/

    // depth map
    CFramebuffer *fboDepth = fbo->getFramebuffer(NWindow::STR_ORTHO_DEPTH_FBO);
    CFramebuffer *fboGeo = fbo->getFramebuffer(NWindow::STR_ORTHO_GEOMETRY_FBO);
    CSceneObject *sun = s->getSceneObject(NScene::STR_OBJECT_LIGHT_SUN);
    const glm::vec3 orthoScale(NCamera::ORTHO_DEPTH_SCALE_X, NCamera::ORTHO_DEPTH_SCALE_Y, NCamera::ORTHO_DEPTH_SCALE_Z);

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
      glClear(GL_DEPTH_BUFFER_BIT);

      ren->setMode(NRenderer::MODE_DEPTH);
      s->render();
      ren->dispatch();
      ren->clearGroups();

      fbo->unbind();
      fboDepth->setChanged(false);

      // geo light
      fboGeo->setCamera(*c);
      fboGeo->bind();
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      ren->setMode(NRenderer::MODE_GEOMETRY);
      s->render();
      ren->dispatch();
      ren->clearGroups();

      fbo->unbind();
      fboGeo->setChanged(false);

      cam->setPosition(sun->getObject()->position);
      fboGeo->setCamera(*c);

      sh->getProgram(NShader::PROGRAM_LPV_CLEAR)->
        dispatch(e->lpvTextureSize.x * e->lpvTextureSize.y, e->lpvTextureSize.z, 1, NRenderer::MODE_LPV_CLEAR);
      sh->getProgram(NShader::PROGRAM_LPV_INJECTION)->
        dispatch(e->geometryTextureSize, e->geometryTextureSize, 1, NRenderer::MODE_LPV_INJECTION);
      for(uint32 i = 0; i < e->lpvPropagationSteps; i++)
        sh->getProgram(NShader::PROGRAM_LPV_PROPAGATION)->
          dispatch(e->lpvTextureSize.x * e->lpvTextureSize.y, e->lpvTextureSize.z, 1, NRenderer::MODE_LPV_PROPAGATION);
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
      drawTexture(fboGeo->getFrameBuffer()->attachments[0].map->getMap()->texture, 0.0f, 0.0f, 0.25f * r, 0.25f, true);
      drawTexture(fboGeo->getFrameBuffer()->attachments[1].map->getMap()->texture, 0.0f, 0.25f, 0.25f * r, 0.25f, true);
      drawTexture(fboGeo->getFrameBuffer()->attachments[2].map->getMap()->texture, 0.0f, 0.5f, 0.25f * r, 0.25f, true);
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
  //COpenGL *gl = CEngineBase::context->getOpenGL();
  //gl->makeCurrent();

  glViewport(0, 0, width, height);
  CEngineBase::context->getCamera()->setSize(static_cast<float>(width), static_cast<float>(height));

#ifdef ENV_SDL
  repaint();
#endif
}
//------------------------------------------------------------------------------
#ifdef ENV_QT
bool CWindow::event(QEvent *event)
{
  // qt mouse and key events

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
void CWindow::drawTexture(GLuint texture, float x, float y, float w, float h, bool isShadow)
{
  glUseProgram(0);
  glEnable(GL_TEXTURE_2D);
  glActiveTexture(GL_TEXTURE3);
  glBindTexture(GL_TEXTURE_2D, 0);
  glActiveTexture(GL_TEXTURE2);
  glBindTexture(GL_TEXTURE_2D, 0);
  glActiveTexture(GL_TEXTURE1);
  glBindTexture(GL_TEXTURE_2D, 0);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture);
  if(isShadow)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_NONE);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_BLEND);

  const float vx[] = { x * 2.0f - 1.0f, -y * 2.0f + 1.0f, (x + w) * 2.0f - 1.0f, (-y - h) * 2.0f + 1.0f };

  glBegin(GL_QUADS);
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
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);
  glBindTexture(GL_TEXTURE_2D, 0);
  glEnable(GL_DEPTH_TEST);
  glDisable(GL_TEXTURE_2D);
}
//------------------------------------------------------------------------------
//test debug, don't panic !
/*const glm::mat4 rot2_ = glm::rotate(glm::rotate(glm::mat4(1.0), r.z, glm::vec3(0.0, 1.0, 0.0)), -r.y, glm::vec3(1.0, 0.0, 0.0));
glUseProgram(0);
glEnable(GL_BLEND);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glMultMatrixf(glm::value_ptr(c->projection));
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glMultMatrixf(glm::value_ptr(c->view));
glMultMatrixf(glm::value_ptr(rot2_));
const float range = 20.0f;

glBegin(GL_LINES);
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
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
glDisable(GL_BLEND);

glDisable(GL_DEPTH_TEST);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, CEngineBase::context->getMaps()->getMap(NWindow::STR_ORTHO_DEPTH_FBO_MAP)->getMap()->texture);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_NONE);
const float fboW = f->getFrameBuffer()->width * 2.0f / c->width * 2.0f;
const float fboH = f->getFrameBuffer()->height * 2.0f / c->height * 2.0f;
glBegin(GL_QUADS);
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
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);
glDisable(GL_TEXTURE_2D);
glEnable(GL_DEPTH_TEST);*/
//------------------------------------------------------------------------------
