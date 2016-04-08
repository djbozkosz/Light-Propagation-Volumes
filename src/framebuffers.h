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

    void bind() const;
    void clear();

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
inline void CFramebuffer::clear()
{
  if(!framebuffer.attachments.size())
    return;

  const uint32 format = framebuffer.attachments[0].format;
  COpenGL *gl = context->getOpenGL();
  bind();

  if(format & (NMap::FORMAT_2D_ARRAY | NMap::FORMAT_3D))
  {
    for(uint32 layer = 0; layer < framebuffer.depth; layer++)
    {
      for(uint32 att = 0; att < framebuffer.attachments.size(); att++)
        gl->framebufferTextureLayer(NOpenGL::FRAMEBUFFER, NOpenGL::COLOR_ATTACHMENT0 + att, framebuffer.attachments[att].map->getMap()->texture, 0, layer);
      gl->clear(NOpenGL::COLOR_BUFFER_BIT | NOpenGL::DEPTH_BUFFER_BIT);
    }
    for(uint32 att = 0; att < framebuffer.attachments.size(); att++)
      gl->framebufferTexture(NOpenGL::FRAMEBUFFER, NOpenGL::COLOR_ATTACHMENT0 + att, framebuffer.attachments[att].map->getMap()->texture, 0);
  }
  else
    gl->clear(NOpenGL::COLOR_BUFFER_BIT | NOpenGL::DEPTH_BUFFER_BIT);

  context->getFramebuffers()->unbind();
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
