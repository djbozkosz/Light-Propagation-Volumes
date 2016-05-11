//------------------------------------------------------------------------------
#ifndef MAPS_H
#define MAPS_H

#if defined(ENV_QT)
#include <QImage>
#elif defined(ENV_SDL)
#include <SDL2/SDL_image.h>
#endif

#include "camera.h"
#include "headers/mapTypes.h"

//------------------------------------------------------------------------------
class CMap : public CEngineBase
{
  private:
    SMap map;

  public:
    CMap();
    CMap(CContext *context, const SMap &map);
    ~CMap();

    void load();
    static void setColorKeyIntoAlpha(uint8 *data, uint32 width, uint32 height); // rgba 32-bit
    static void clampBitmap(uint8 *data, uint32 width, uint32 height, uint32 &newWidth, uint32 &newHeight, uint32 maxSize);

    void bind(GLuint uniform = 0, uint8 sampler = 0, uint32 format = NMap::FORMAT_MIPMAP) const;
    void clear();
    void fill(const void *data);

    inline const SMap *getMap() const { return &map; }
};
//------------------------------------------------------------------------------
class CMaps : public CEngineBase
{
  private:
    std::map<std::string, CMap> maps;

  public:
    CMaps();
    CMaps(CContext *context);
    ~CMaps();

    void loadDefaultMaps();

    CMap *addMap(const SMap &map);
    uint32 removeMap(const std::string &file);

    inline void finishBind() const { context->getOpenGL()->activeTexture(NOpenGL::TEXTURE0); }
    void unbind(GLuint uniform = 0, uint8 sampler = 0, uint32 format = 0) const;

    inline CMap *getMap(const std::string &file) { auto it = maps.find(file); if(it == maps.end()) return NULL; return &it->second; }
};
//------------------------------------------------------------------------------
inline void CMap::bind(GLuint uniform, uint8 sampler, uint32 format) const
{
  COpenGL *gl = context->getOpenGL();
  
  if((format & (NMap::FORMAT_IMAGE_R | NMap::FORMAT_IMAGE_W | NMap::FORMAT_IMAGE_RW)))
  {
    gl->bindImageTexture(sampler, map.texture, 0, NOpenGL::TRUE, 0,
      (format & NMap::FORMAT_IMAGE_R) ? NOpenGL::READ_ONLY : ((format & NMap::FORMAT_IMAGE_W) ? NOpenGL::WRITE_ONLY : NOpenGL::READ_WRITE),
      (map.format & NMap::FORMAT_INT) ? NOpenGL::R32I : ((map.format & NMap::FORMAT_UINT) ? NOpenGL::R32UI : NOpenGL::RGBA32F));
    gl->uniform1i(uniform, sampler);
  }
  else
  {
    const GLenum texFormat = (map.format & NMap::FORMAT_3D) ? NOpenGL::TEXTURE_3D : ((map.format & NMap::FORMAT_2D_ARRAY) ? NOpenGL::TEXTURE_2D_ARRAY : ((map.format & NMap::FORMAT_CUBE) ? NOpenGL::TEXTURE_CUBE_MAP : NOpenGL::TEXTURE_2D));
    gl->activeTexture(NOpenGL::TEXTURE0 + sampler);
    gl->bindTexture(texFormat, map.texture);
    gl->texParameteri(texFormat, NOpenGL::TEXTURE_MAG_FILTER, (format & NMap::FORMAT_LINEAR) ? NOpenGL::LINEAR : ((format & NMap::FORMAT_MIPMAP) ? NOpenGL::LINEAR : NOpenGL::NEAREST));
    gl->texParameteri(texFormat, NOpenGL::TEXTURE_MIN_FILTER, (format & NMap::FORMAT_LINEAR) ? NOpenGL::LINEAR : ((format & NMap::FORMAT_MIPMAP) ? NOpenGL::LINEAR_MIPMAP_LINEAR : NOpenGL::NEAREST));
    if(map.format & (NMap::FORMAT_3D | NMap::FORMAT_2D_ARRAY))
      gl->texParameteri(texFormat, NOpenGL::TEXTURE_WRAP_R, (format & NMap::FORMAT_EDGE) ? NOpenGL::CLAMP_TO_EDGE : ((format & NMap::FORMAT_BORDER) ? NOpenGL::CLAMP_TO_BORDER : NOpenGL::REPEAT));
    gl->texParameteri(texFormat, NOpenGL::TEXTURE_WRAP_S, (format & NMap::FORMAT_EDGE) ? NOpenGL::CLAMP_TO_EDGE : ((format & NMap::FORMAT_BORDER) ? NOpenGL::CLAMP_TO_BORDER : NOpenGL::REPEAT));
    gl->texParameteri(texFormat, NOpenGL::TEXTURE_WRAP_T, (format & NMap::FORMAT_EDGE) ? NOpenGL::CLAMP_TO_EDGE : ((format & NMap::FORMAT_BORDER) ? NOpenGL::CLAMP_TO_BORDER : NOpenGL::REPEAT));
    if(format & NMap::FORMAT_DEPTH)
    {
      gl->texParameteri(texFormat, NOpenGL::TEXTURE_COMPARE_MODE, NOpenGL::COMPARE_REF_TO_TEXTURE);
      gl->texParameteri(texFormat, NOpenGL::TEXTURE_COMPARE_FUNC, NOpenGL::LEQUAL);
    }
    else
      gl->texParameteri(texFormat, NOpenGL::TEXTURE_COMPARE_MODE, NOpenGL::NONE);
    gl->uniform1i(uniform, sampler);
  }
}
//------------------------------------------------------------------------------
inline void CMap::clear()
{
  COpenGL *gl = context->getOpenGL();
  if(gl->getStatusClearTexImage() != NOpenGLProc::TYPE_NOT_LOADED)
    gl->clearTexImage(map.texture, 0, NOpenGL::RGBA, NOpenGL::FLOAT, NULL);
  else
  {
    const GLenum texFormat = (map.format & NMap::FORMAT_3D) ? NOpenGL::TEXTURE_3D : ((map.format & NMap::FORMAT_2D_ARRAY) ? NOpenGL::TEXTURE_2D_ARRAY : ((map.format & NMap::FORMAT_CUBE) ? NOpenGL::TEXTURE_CUBE_MAP : NOpenGL::TEXTURE_2D));
    std::vector<float> d(map.width * map.height * ((map.depth) ? map.depth : 1) * NMap::RGBA_SIZE);
    memset(&d[0], 0, sizeof(float) * d.size());
    gl->bindTexture(texFormat, map.texture);
    if(map.format & (NMap::FORMAT_2D_ARRAY | NMap::FORMAT_3D))
      gl->texSubImage3D(texFormat, 0, 0, 0, 0, map.width, map.height, map.depth, NOpenGL::RGBA, NOpenGL::FLOAT, &d[0]);
    else
      gl->texSubImage2D(texFormat, 0, 0, 0, map.width, map.height, NOpenGL::RGBA, NOpenGL::FLOAT, &d[0]);
    gl->bindTexture(texFormat, 0);
  }
}
//------------------------------------------------------------------------------
inline void CMap::fill(const void *data)
{
  COpenGL *gl = context->getOpenGL();
  gl->activeTexture(NOpenGL::TEXTURE0);
  gl->bindTexture(NOpenGL::TEXTURE_3D, map.texture);
  gl->texSubImage3D(NOpenGL::TEXTURE_3D, 0, 0, 0, 0, map.width, map.height, map.depth, NOpenGL::RGBA, NOpenGL::FLOAT, data);
  gl->bindTexture(NOpenGL::TEXTURE_3D, 0);
}
//------------------------------------------------------------------------------
inline CMap *CMaps::addMap(const SMap &map)
{
  CMap *m = getMap(map.file);

  if(m)
    return m;

  maps[map.file] = CMap(context, map);
  m = getMap(map.file);
  m->load();

  return m;
}
//------------------------------------------------------------------------------
inline uint32 CMaps::removeMap(const std::string &file)
{
  COpenGL *gl = context->getOpenGL();

  if(CMap *m = getMap(file))
  {
    GLuint texture = m->getMap()->texture;
    gl->bindTexture(NOpenGL::TEXTURE_2D, texture);
    gl->texImage2D(NOpenGL::TEXTURE_2D, 0, NOpenGL::RGBA, 0, 0, 0, NOpenGL::RGBA, NOpenGL::UNSIGNED_BYTE, NULL);
    gl->bindTexture(NOpenGL::TEXTURE_2D, 0);
    gl->deleteTextures(1, &texture);
    return maps.erase(file);
  }

  return 0;
}
//------------------------------------------------------------------------------
inline void CMaps::unbind(GLuint uniform, uint8 sampler, uint32 format) const
{
  COpenGL *gl = context->getOpenGL();

  if((format & (NMap::FORMAT_IMAGE_R | NMap::FORMAT_IMAGE_W | NMap::FORMAT_IMAGE_RW)))
  {
    gl->bindImageTexture(sampler, 0, 0, NOpenGL::FALSE, 0, (format & NMap::FORMAT_IMAGE_R) ? NOpenGL::READ_ONLY : ((format & NMap::FORMAT_IMAGE_W) ? NOpenGL::WRITE_ONLY : NOpenGL::READ_WRITE), NOpenGL::RGBA32F);
    gl->uniform1i(uniform, sampler);
  }
  else
  {
    gl->activeTexture(NOpenGL::TEXTURE0 + sampler);
    glBindTexture(NOpenGL::TEXTURE_2D, 0);
    gl->uniform1i(uniform, sampler);
  }
}
//------------------------------------------------------------------------------
#endif // MAPS_H
