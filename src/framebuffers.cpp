//------------------------------------------------------------------------------
#include "framebuffers.h"

//------------------------------------------------------------------------------
CFramebuffer::CFramebuffer()
{
}
//------------------------------------------------------------------------------
CFramebuffer::CFramebuffer(CContext *context, const SFramebuffer &framebuffer) : CEngineBase(context), framebuffer(framebuffer)
{
  create();
}
//------------------------------------------------------------------------------
CFramebuffer::~CFramebuffer()
{
}
//------------------------------------------------------------------------------
void CFramebuffer::create()
{
  //COpenGL *gl = context->getOpenGL();

  // color textures
  for(uint32 i = 0; i < framebuffer.attachments.size(); i++)
    framebuffer.attachments[i].map = context->getMaps()->addMap(SMap(CStr(NMap::STR_FBO_MAP_NAME, framebuffer.name.c_str(), i), framebuffer.attachments[i].format, framebuffer.width, framebuffer.height));

  // render buffers
  if(framebuffer.rboFormat & NMap::RBO_DEPTH)
  {
    glGenRenderbuffers(1, &framebuffer.rboDepth);
    glBindRenderbuffer(GL_RENDERBUFFER, framebuffer.rboDepth);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, framebuffer.width, framebuffer.height);
  }
  if(framebuffer.rboFormat & NMap::RBO_STENCIL)
  {
    glGenRenderbuffers(1, &framebuffer.rboStencil);
    glBindRenderbuffer(GL_RENDERBUFFER, framebuffer.rboStencil);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, framebuffer.width, framebuffer.height);
  }

  // framebuffer
  glGenFramebuffers(1, &framebuffer.fbo);
  glBindFramebuffer(GL_FRAMEBUFFER, framebuffer.fbo);

  // attachments
  std::vector<GLenum> colorAttachments;
  for(auto it = framebuffer.attachments.begin(); it != framebuffer.attachments.end(); it++)
  {
    if(it->format & (NMap::FORMAT_DEPTH | NMap::FORMAT_STENCIL))
      glFramebufferTexture2D(GL_FRAMEBUFFER, (it->format & NMap::FORMAT_DEPTH) ? GL_DEPTH_ATTACHMENT : GL_DEPTH_STENCIL, GL_TEXTURE_2D, it->map->getMap()->texture, 0);
    else if(it->format & (NMap::FORMAT_2D | NMap::FORMAT_CUBE))
    {
      glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colorAttachments.size(),
        (it->format & NMap::FORMAT_CUBE) ? GL_TEXTURE_CUBE_MAP_POSITIVE_X : GL_TEXTURE_2D, it->map->getMap()->texture, 0);
      colorAttachments.push_back(GL_COLOR_ATTACHMENT0 + colorAttachments.size());
    }
  }

  // draw buffers
  if(colorAttachments.size())
    glDrawBuffers(colorAttachments.size(), &colorAttachments[0]);
  else
    glDrawBuffer(GL_NONE);

  // render buffers links
  if(framebuffer.rboFormat & NMap::RBO_DEPTH)
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, framebuffer.rboDepth);
  if(framebuffer.rboFormat & NMap::RBO_STENCIL)
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, framebuffer.rboStencil);

  if(GLuint status = glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    context->engineShowMessage(NMap::STR_ERROR_INVALID_FBO, CStr(NMap::STR_ERROR_INVALID_FBO_STATUS, status), false);

  glBindRenderbuffer(GL_RENDERBUFFER, 0);
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
  glBindTexture(GL_TEXTURE_2D, 0);
}
//------------------------------------------------------------------------------
CFramebuffers::CFramebuffers() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CFramebuffers::CFramebuffers(CContext *context) : CEngineBase(context)
{
}
//------------------------------------------------------------------------------
CFramebuffers::~CFramebuffers()
{
}
//------------------------------------------------------------------------------
