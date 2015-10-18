//-----------------------------------------------------------------------------
#ifndef MAPSTYPES_H
#define MAPSTYPES_H

#include <string>
#include <fstream>
#include <glm/glm.hpp>

#include "openGLTypes.h"

//-----------------------------------------------------------------------------
namespace NMap
{ // todo
  static const char STR_DEFAULT_NORMAL[] = ":/maps/data/maps/defaultNormal00.png";

  enum EMapDefault
  {
    DEFAULT_NORMAL = 0
  };
}
//-----------------------------------------------------------------------------
struct SColor
{
  uint8 r;
  uint8 g;
  uint8 b;
  uint8 a;

  inline SColor() : r(0), g(0), b(0), a(0) {}
  inline SColor(uint8 r, uint8 g, uint8 b, uint8 a = 255) : r(r), g(g), b(b), a(a) {}
};
//-----------------------------------------------------------------------------
struct SMap
{
  std::string file;
  GLuint texture;
  glm::vec4 color;
  bool framebuffer;
  uint32 width;
  uint32 height;

  inline SMap() : texture(0), framebuffer(false), width(0), height(0) {}
  inline SMap(const std::string &file, const glm::vec4 &color = glm::vec4(0.6, 0.3, 0.2, 1.0)) : file(file), texture(0), color(color), framebuffer(false), width(0), height(0) {}
  inline SMap(const std::string &fboName, uint32 width, uint32 height) : file(fboName), texture(0), framebuffer(true), width(width), height(height) {}
};

class CMap;

struct SFramebuffer
{
  std::string name;
  GLuint fboColor;
  GLuint rboDepth;
  const CMap *fboColorTexture;
  bool color;
  bool depth;
  uint32 width;
  uint32 height;

  inline SFramebuffer() : fboColor(0), rboDepth(0), fboColorTexture(NULL), color(false), depth(false), width(1), height(1) {}
  inline SFramebuffer(const std::string &name, bool color, bool depth, uint32 width, uint32 height) : name(name), fboColor(0), rboDepth(0), fboColorTexture(NULL), color(color), depth(depth), width(width), height(height) {}
};
//-----------------------------------------------------------------------------
#endif // MAPSTYPES_H
