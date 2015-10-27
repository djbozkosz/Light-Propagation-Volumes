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
  static const uint32 RGB_SIZE = 3;
  static const uint32 RGBA_SIZE = 4;

  static const uint8 RGB_BITS_SIZE = 24;
  static const uint8 RGBA_BITS_SIZE = 32;

  static const uint32 RGBA_MASK_R = 0x000000ff;
  static const uint32 RGBA_MASK_G = 0x0000ff00;
  static const uint32 RGBA_MASK_B = 0x00ff0000;
  static const uint32 RGBA_MASK_A = 0xff000000;

  static const uint8 COLOR_KEY_OFFSET = 4;

  static const char STR_DEFAULT_NORMAL[] = ":/maps/data/maps/defaultNormal00.png";

  static const char STR_ERROR_UNABLE_TO_OPEN[] = "Unable to open map: \"%s\"";

  enum EMapDefault
  {
    DEFAULT_NORMAL = 0
  };

  enum EPickColorInc
  {
    PICK_INC_1 = 1,
    PICK_INC_2 = 2,
    PICK_INC_4 = 4,
    PICK_INC_8 = 8
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
  inline SColor(const glm::vec3 &v) : r(v.r * 255.0f), g(v.g * 255.0f), b(v.b * 255.0f), a(0) {}
  inline SColor(const glm::vec4 &v) : r(v.r * 255.0f), g(v.g * 255.0f), b(v.b * 255.0f), a(v.a * 255.0f) {}

  inline glm::vec3 toVec3() { return glm::vec3(static_cast<float>(r) / 255.0f, static_cast<float>(g) / 255.0f, static_cast<float>(b) / 255.0f); }
  inline glm::vec4 toVec4() { return glm::vec4(static_cast<float>(r) / 255.0f, static_cast<float>(g) / 255.0f, static_cast<float>(b) / 255.0f, static_cast<float>(a) / 255.0f); }
};
//-----------------------------------------------------------------------------
struct SPoint
{
  uint32 x;
  uint32 y;

  inline SPoint(uint32 x = 0, uint32 y = 0) : x(x), y(y) {}
};
//-----------------------------------------------------------------------------
struct SSize
{
  uint32 w;
  uint32 h;

  inline SSize(uint32 w = 0, uint32 h = 0) : w(w), h(h) {}
};
//-----------------------------------------------------------------------------
struct SRect
{
  SPoint p;
  SSize s;

  inline SRect() {}
  inline SRect(uint32 x, uint32 y, uint32 w, uint32 h) : p(SPoint(x, y)), s(SSize(w, h)) {}
  inline SRect(const SPoint &p, const SSize &s) : p(p), s(s) {}
};
//-----------------------------------------------------------------------------
struct SMap
{
  std::string file;
  GLuint texture;
  SColor color;
  bool framebuffer;
  uint32 width;
  uint32 height;

  inline SMap() : texture(0), framebuffer(false), width(0), height(0) {}
  inline SMap(const std::string &file, const SColor &color = SColor(64, 32, 16, 255)) : file(file), texture(0), color(color), framebuffer(false), width(0), height(0) {}
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
