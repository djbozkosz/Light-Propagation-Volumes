//------------------------------------------------------------------------------
#ifndef FRAMEBUFFERS_H
#define FRAMEBUFFERS_H

#include "maps.h"

//------------------------------------------------------------------------------
class CFramebuffer : public CEngineBase
{
  private:
  SFramebuffer framebuffer;

  public:
  CFramebuffer();
  CFramebuffer(CContext *context, const SFramebuffer &framebuffer);
  ~CFramebuffer();

  void create();
  inline void setChanged(bool changed) { framebuffer.changed = changed; }
  inline void setCamera(const SCamera &camera) { framebuffer.camera = camera; }

  void bind() const;

  inline const SFramebuffer *getFrameBuffer() const { return &framebuffer; }
};
//------------------------------------------------------------------------------
class CFramebuffers : public CEngineBase
{
  private:
  std::map<std::string, CFramebuffer> framebuffers;

  public:
  CFramebuffers();
  CFramebuffers(CContext *context);
  ~CFramebuffers();

  inline CFramebuffer *addFbo(const SFramebuffer &framebuffer);
  // remove fbo

  void unbind() const;

  inline CFramebuffer *getFramebuffer(const std::string &name) { auto it = framebuffers.find(name); if(it == framebuffers.end()) return NULL; return &it->second; }
};
//------------------------------------------------------------------------------
inline void CFramebuffer::bind() const
{
  //COpenGL *gl = context->getOpenGL();
  glBindFramebuffer(GL_FRAMEBUFFER, framebuffer.fbo);
  glViewport(0, 0, framebuffer.width, framebuffer.height);
}
//------------------------------------------------------------------------------
inline CFramebuffer *CFramebuffers::addFbo(const SFramebuffer &framebuffer)
{
  if(CFramebuffer *f = getFramebuffer(framebuffer.name))
    return f;

  framebuffers[framebuffer.name] = CFramebuffer(context, framebuffer);

  return &framebuffers.find(framebuffer.name)->second;
}
//------------------------------------------------------------------------------
inline void CFramebuffers::unbind() const
{
  //COpenGL *gl = context->getOpenGL();
  glBindFramebuffer(GL_FRAMEBUFFER, 0);

  glViewport(0, 0, context->getCamera()->getCamera()->width, context->getCamera()->getCamera()->height);
}
//------------------------------------------------------------------------------
#endif // FRAMEBUFFERS_H
