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

  CEngineBase::context->getMaps()->loadDefaultMaps();

  std::vector<uint8> fboAttachments;
  const uint32 maxDepthTextureSize = CEngineBase::context->engineGetEngine()->maxDepthTextureSize;
  fboAttachments.push_back(NMap::FORMAT_2D | NMap::FORMAT_DEPTH | NMap::FORMAT_EDGE);
  CEngineBase::context->getFramebuffers()->addFbo(SFramebuffer(NWindow::STR_ORTHO_DEPTH_FBO, fboAttachments, NMap::RBO, maxDepthTextureSize, maxDepthTextureSize));

  for(uint32 i = 0; i < NShader::VERTEX_SHADERS_COUNT; i++)
    s->addShader(SShader(NShader::TYPE_VERTEX, NShader::STR_VERTEX_SHADER_LIST[i]));
  for(uint32 i = 0; i < NShader::FRAGMENT_SHADERS_COUNT; i++)
    s->addShader(SShader(NShader::TYPE_FRAGMENT, NShader::STR_FRAGMENT_SHADER_LIST[i]));

  for(uint32 i = 0; i < NShader::PROGRAMS_COUNT; i++)
    s->addShaderProgram(SShaderProgram(
      static_cast<NShader::EProgram>(i),
      s->getVertexShader(NShader::STR_PROGRAM_VERTEX_SHADER_LIST[i]),
      s->getFragmentShader(NShader::STR_PROGRAM_FRAGMENT_SHADER_LIST[i])));

#ifdef ENV_QT
  emit onInitializeFinishGL();
#endif
}
//------------------------------------------------------------------------------
void CWindow::paintGL()
{
  //COpenGL *gl = CEngineBase::context->getOpenGL();
  CRenderer *ren = CEngineBase::context->getRenderer();
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
    cul->updateFrustum();

    ren->setMode(NRenderer::MODE_BACKDROP);
    s->render();
    ren->dispatch();
    ren->clearGroups();

    // depth map
    CFramebuffer *f = fbo->getFramebuffer(NWindow::STR_ORTHO_DEPTH_FBO);
    CSceneObject *sun = s->getSceneObject(NScene::STR_OBJECT_LIGHT_SUN);
    const glm::vec3 orthoScale(NCamera::ORTHO_DEPTH_SCALE_X, NCamera::ORTHO_DEPTH_SCALE_Y, NCamera::ORTHO_DEPTH_SCALE_Z);

    if((f) && (sun) &&
       ((f->getFrameBuffer()->changed) ||
       (glm::length(glm::vec3(f->getFrameBuffer()->camera.position) * orthoScale - pos) > (e->orthoDepthSize * 0.1f))))
    {
      //std::cout << "update " << glm::to_string(glm::vec3(f->getFrameBuffer()->camera.position) * orthoScale) << " | " << glm::to_string(pos) << "\n";
      cam->setRange(-e->orthoDepthDepth, e->orthoDepthDepth, -e->orthoDepthSize, e->orthoDepthSize, e->orthoDepthSize, -e->orthoDepthSize);

      const glm::quat r = sun->getObject()->rotation;
      const float step = (c->clipRight - c->clipLeft) / f->getFrameBuffer()->width;
      const glm::vec3 invSun = glm::vec3(glm::rotate(glm::rotate(glm::mat4(1.0), r.y, glm::vec3(1.0, 0.0, 0.0)), -r.z, glm::vec3(0.0, 1.0, 0.0)) * glm::vec4(pos, 1.0));
      const glm::vec3 invSunFloor(static_cast<float>(static_cast<int32>(invSun.x / step)) * step, static_cast<float>(static_cast<int32>(invSun.y / step)) * step, static_cast<float>(static_cast<int32>(invSun.z / step)) * step);
      const glm::vec3 sunFloor(glm::rotate(glm::rotate(glm::mat4(1.0), r.z, glm::vec3(0.0, 1.0, 0.0)), -r.y, glm::vec3(1.0, 0.0, 0.0)) * glm::vec4(invSunFloor, 1.0));

      //std::cout << ccc.x << " " << ccc.y << " " << ccc.z << "\n";
      cam->setPosition(sunFloor * orthoScale);
      cam->setRotation(glm::vec3(r.y * NMath::RAD_2_DEG, -r.z * NMath::RAD_2_DEG, 0.0f));
      cam->setScale(c->scale * orthoScale);
      cul->updateFrustum();

      f->setCamera(*c);
      f->bind();
      glClear(GL_DEPTH_BUFFER_BIT);

      ren->setMode(NRenderer::MODE_DEPTH);
      s->render();
      ren->dispatch();
      ren->clearGroups();

      fbo->unbind();
      f->setChanged(false);
    }
    
    // standard
    cam->setPosition(pos);
    cam->setRotation(rot);
    cam->resetScale();
    cam->setRange(clipNear, clipFar);
    cul->updateFrustum();

    ren->setMode(NRenderer::MODE_STANDARD);
    s->render();
    ren->dispatch();
    ren->clearGroups();
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
