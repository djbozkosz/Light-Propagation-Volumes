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
  COpenGL *gl = context->getOpenGL();

  // color textures
  for(uint32 i = 0; i < framebuffer.attachments.size(); i++)
    framebuffer.attachments[i].map = context->getMaps()->addMap(SMap(CStr(NMap::STR_FBO_MAP_NAME, framebuffer.name.c_str(), i), framebuffer.attachments[i].format, framebuffer.width, framebuffer.height));

  // render buffers
  if(framebuffer.rboFormat & NMap::RBO_DEPTH)
  {
    gl->genRenderbuffers(1, &framebuffer.rboDepth);
    gl->bindRenderbuffer(NOpenGL::RENDERBUFFER, framebuffer.rboDepth);
    gl->renderbufferStorage(NOpenGL::RENDERBUFFER, NOpenGL::DEPTH_COMPONENT24, framebuffer.width, framebuffer.height);
  }
  if(framebuffer.rboFormat & NMap::RBO_STENCIL)
  {
    gl->genRenderbuffers(1, &framebuffer.rboStencil);
    gl->bindRenderbuffer(NOpenGL::RENDERBUFFER, framebuffer.rboStencil);
    gl->renderbufferStorage(NOpenGL::RENDERBUFFER, NOpenGL::DEPTH24_STENCIL8, framebuffer.width, framebuffer.height);
  }

  // framebuffer
  gl->genFramebuffers(1, &framebuffer.fbo);
  gl->bindFramebuffer(NOpenGL::FRAMEBUFFER, framebuffer.fbo);

  // attachments
  std::vector<GLenum> colorAttachments;
  for(auto it = framebuffer.attachments.begin(); it != framebuffer.attachments.end(); it++)
  {
    if(it->format & (NMap::FORMAT_DEPTH | NMap::FORMAT_STENCIL))
      gl->framebufferTexture2D(NOpenGL::FRAMEBUFFER, (it->format & NMap::FORMAT_DEPTH) ? NOpenGL::DEPTH_ATTACHMENT : NOpenGL::DEPTH_STENCIL, NOpenGL::TEXTURE_2D, it->map->getMap()->texture, 0);
    else if(it->format & (NMap::FORMAT_2D | NMap::FORMAT_CUBE))
    {
      gl->framebufferTexture2D(NOpenGL::FRAMEBUFFER, NOpenGL::COLOR_ATTACHMENT0 + colorAttachments.size(),
        (it->format & NMap::FORMAT_CUBE) ? NOpenGL::TEXTURE_CUBE_MAP_POSITIVE_X : NOpenGL::TEXTURE_2D, it->map->getMap()->texture, 0);
      colorAttachments.push_back(NOpenGL::COLOR_ATTACHMENT0 + colorAttachments.size());
    }
  }

  // draw buffers
  if(colorAttachments.size())
    gl->drawBuffers(colorAttachments.size(), &colorAttachments[0]);
  else
    gl->drawBuffer(NOpenGL::NONE);

  // render buffers links
  if(framebuffer.rboFormat & NMap::RBO_DEPTH)
    gl->framebufferRenderbuffer(NOpenGL::FRAMEBUFFER, NOpenGL::DEPTH_ATTACHMENT, NOpenGL::RENDERBUFFER, framebuffer.rboDepth);
  if(framebuffer.rboFormat & NMap::RBO_STENCIL)
    gl->framebufferRenderbuffer(NOpenGL::FRAMEBUFFER, NOpenGL::STENCIL_ATTACHMENT, NOpenGL::RENDERBUFFER, framebuffer.rboStencil);

  if(GLuint status = gl->checkFramebufferStatus(NOpenGL::FRAMEBUFFER) != NOpenGL::FRAMEBUFFER_COMPLETE)
    context->engineShowMessage(NMap::STR_ERROR_INVALID_FBO, CStr(NMap::STR_ERROR_INVALID_FBO_STATUS, status), false);

  gl->bindRenderbuffer(NOpenGL::RENDERBUFFER, 0);
  gl->bindFramebuffer(NOpenGL::FRAMEBUFFER, 0);
  glBindTexture(NOpenGL::TEXTURE_2D, 0);
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
