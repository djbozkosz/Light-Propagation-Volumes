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
    inline void setChanged(bool changed = true) { framebuffer.changed = changed; }
    inline void setCamera(const SCamera &camera) { framebuffer.camera = camera; }

    void bind() const;

    inline const SFramebuffer *getFrameBuffer() const { return &framebuffer; }
    inline const SFramebufferAttachment *getAttachment(uint32 index) const { if(index >= framebuffer.attachments.size()) return NULL; return &framebuffer.attachments[index]; }
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

    CFramebuffer *addFbo(const SFramebuffer &framebuffer);
    // remove fbo

    void unbind() const;

    inline CFramebuffer *getFramebuffer(const std::string &name) { auto it = framebuffers.find(name); if(it == framebuffers.end()) return NULL; return &it->second; }
};
//------------------------------------------------------------------------------
inline void CFramebuffer::bind() const
{
  COpenGL *gl = context->getOpenGL();
  gl->bindFramebuffer(NOpenGL::FRAMEBUFFER, framebuffer.fbo);
  gl->viewport(0, 0, framebuffer.width, framebuffer.height);
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
  COpenGL *gl = context->getOpenGL();
  gl->bindFramebuffer(NOpenGL::FRAMEBUFFER, 0);

  gl->viewport(0, 0, context->getCamera()->getCamera()->width, context->getCamera()->getCamera()->height);
}
//------------------------------------------------------------------------------
#endif // FRAMEBUFFERS_H
