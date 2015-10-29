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

  static const uint32 CUBE_SIZE = 6;

  static const uint8 RGB_BITS_SIZE = 24;
  static const uint8 RGBA_BITS_SIZE = 32;

  static const uint8 DEFAULT_MAP_R = 64;
  static const uint8 DEFAULT_MAP_G = 32;
  static const uint8 DEFAULT_MAP_B = 16;
  static const uint8 DEFAULT_MAP_A = 255;
  static const uint8 DEFAULT_MAP_NORMAL_R = 128;
  static const uint8 DEFAULT_MAP_NORMAL_G = 128;
  static const uint8 DEFAULT_MAP_NORMAL_B = 255;
  static const uint8 DEFAULT_MAP_NORMAL_A = 255;

  static const uint32 RGBA_MASK_R = 0x000000ff;
  static const uint32 RGBA_MASK_G = 0x0000ff00;
  static const uint32 RGBA_MASK_B = 0x00ff0000;
  static const uint32 RGBA_MASK_A = 0xff000000;

  static const uint8 COLOR_KEY_OFFSET = 4;

  static const char STR_MAP_SUFFIX_SPEC[] = "_SPEC";
  static const char STR_MAP_SUFFIX_NORMAL[] = "_DDN";
  static const char STR_MAP_SUFFIX[] = "%s%s%s";

  static const char STR_FBO_MAP_NAME[] = "%s_%d";

  static const char *const STR_CUBE_MAP_NAMES[] = { "_px", "_nx", "_py", "_ny", "_pz", "_nz" };

  static const char STR_DEFAULT_NORMAL[] = ":/maps/data/maps/defaultNormal00.png";

  static const char STR_ERROR_UNABLE_TO_OPEN[] = "Unable to open map: \"%s\"";
  static const char STR_ERROR_INVALID_FBO[] = "Unable to create framebuffer!";
  static const char STR_ERROR_INVALID_FBO_STATUS[] = "Status: %ud.";

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

  enum EMapFormat
  {
    FORMAT = 0x00,
    FORMAT_2D = 0x01,
    FORMAT_3D = 0x02,
    FORMAT_CUBE = 0x04,
    FORMAT_DEPTH = 0x08,
    FORMAT_STENCIL = 0x10,
    FORMAT_LINEAR = 0x20,
    FORMAT_MIPMAP = 0x40,
    FORMAT_EDGE = 0x80
  };

  enum ERboFormat
  {
    RBO = 0x00,
    RBO_DEPTH = 0x01,
    RBO_STENCIL = 0x02
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
  inline SColor(uint8 r, uint8 g, uint8 b, uint8 a = NMap::DEFAULT_MAP_A) : r(r), g(g), b(b), a(a) {}
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
  uint8 format;
  uint32 width;
  uint32 height;
  uint32 depth;

  inline SMap() : texture(0), format(NMap::FORMAT_2D), width(0), height(0), depth(0) {}
  inline SMap(const std::string &file, const SColor &color = SColor(NMap::DEFAULT_MAP_R, NMap::DEFAULT_MAP_G, NMap::DEFAULT_MAP_B, NMap::DEFAULT_MAP_A)) : file(file), texture(0), color(color), format(NMap::FORMAT_2D), width(0), height(0), depth(0) {}
  inline SMap(const std::string &file, uint8 format, const SColor &color = SColor(NMap::DEFAULT_MAP_R, NMap::DEFAULT_MAP_G, NMap::DEFAULT_MAP_B, NMap::DEFAULT_MAP_A)) : file(file), texture(0), color(color), format(format), width(0), height(0), depth(0) {}
  inline SMap(const std::string &name, uint8 format, uint32 width, uint32 height, uint32 depth = 0) : file(name), texture(0), format(format), width(width), height(height), depth(depth) {}
};

class CMap;

struct SFramebufferAttachment
{
  uint8 format;
  const CMap *map;

  inline SFramebufferAttachment() : format(NMap::FORMAT_2D), map(NULL) {}
  inline SFramebufferAttachment(uint8 format, const CMap *map) : format(format), map(map) {}
};

struct SFramebuffer
{
  std::string name;
  GLuint fbo;
  GLuint rboDepth;
  GLuint rboStencil;
  std::vector<SFramebufferAttachment> attachments;
  uint8 rboFormat;
  uint32 width;
  uint32 height;
  SCamera camera;

  inline SFramebuffer() : fbo(0), rboDepth(0), rboStencil(0), rboFormat(NMap::RBO_DEPTH), width(1), height(1) {}
  inline SFramebuffer(const std::string &name, const std::vector<uint8> &attachments, uint8 rboFormat, uint32 width, uint32 height) : name(name), fbo(0), rboDepth(0), rboStencil(0), rboFormat(rboFormat), width(width), height(height)
  {
    for(auto it = attachments.cbegin(); it != attachments.cend(); it++)
      this->attachments.push_back(SFramebufferAttachment(*it, NULL));
  }
};
//-----------------------------------------------------------------------------
#endif // MAPSTYPES_H
