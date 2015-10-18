//------------------------------------------------------------------------------
#ifndef MAPS_H
#define MAPS_H

#include "camera.h"
#include "headers/mapsTypes.h"

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

    void bind(GLuint uniform = 0, uint8 sampler = 0, bool mipmap = true, bool edge = false) const;

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
    inline CMap *addFbo(const std::string &name, uint32 width, uint32 height) { maps[name] = CMap(context, SMap(name, width, height)); return &maps.find(name)->second; }
    void removeMap(const std::string &file);

    inline void finishBind() const { /*context->getOpenGL()->*/glActiveTexture(GL_TEXTURE0); }
    void unbind(GLuint uniform = 0, uint8 sampler = 0) const;

    inline CMap *getMap(const std::string &file) { auto it = maps.find(file); if(it == maps.end()) return NULL; return &it->second; }
};
//------------------------------------------------------------------------------
inline void CMap::bind(GLuint uniform, uint8 sampler, bool mipmap, bool edge) const
{
  //COpenGL *gl = context->getOpenGL();
  glActiveTexture(GL_TEXTURE0 + sampler);
  glBindTexture(GL_TEXTURE_2D, map.texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mipmap ? GL_LINEAR_MIPMAP_LINEAR : GL_LINEAR);
  /*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  if(mipmap)
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY, 1.0f);
  else
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY, 8.0f);*/
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, edge ? GL_CLAMP_TO_EDGE : GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, edge ? GL_CLAMP_TO_EDGE : GL_REPEAT);
  glUniform1i(uniform, sampler);
}
//------------------------------------------------------------------------------
inline CMap *CMaps::addMap(const SMap &map)
{
  CMap *m = getMap(map.file);

  if(m)
    return m;

  maps[map.file] = CMap(context, map);

  return &maps.find(map.file)->second;
}
//------------------------------------------------------------------------------
inline void CMaps::removeMap(const std::string &file)
{
  //COpenGL *gl = context->getOpenGL();
  CMap *m = getMap(file);

  if(!m)
    return;

  GLuint texture = m->getMap()->texture;
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
  glBindTexture(GL_TEXTURE_2D, 0);
  glDeleteTextures(1, &texture);
  maps.erase(file);
}
//------------------------------------------------------------------------------
inline void CMaps::unbind(GLuint uniform, uint8 sampler) const
{
  //COpenGL *gl = context->getOpenGL();
  glActiveTexture(GL_TEXTURE0 + sampler);
  glBindTexture(GL_TEXTURE_2D, 0);
  glUniform1i(uniform, sampler);
}
//------------------------------------------------------------------------------
#endif // MAPS_H
