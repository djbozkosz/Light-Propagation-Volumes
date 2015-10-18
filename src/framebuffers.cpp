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

  if(framebuffer.color)
  {
    framebuffer.fboColorTexture = context->getMaps()->addFbo(framebuffer.name, framebuffer.width, framebuffer.height);
    glGenFramebuffers(1, &framebuffer.fboColor);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer.fboColor);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, framebuffer.fboColorTexture->getMap()->texture, 0);
  }
  if(framebuffer.depth)
  {
    glGenRenderbuffers(1, &framebuffer.rboDepth);
    glBindRenderbuffer(GL_RENDERBUFFER, framebuffer.rboDepth);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, framebuffer.width, framebuffer.height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, framebuffer.rboDepth);
  }

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
