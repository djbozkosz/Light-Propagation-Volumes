//------------------------------------------------------------------------------
#ifndef MODELTYPES_H
#define MODELTYPES_H

#include <string>
#include <vector>
#include <list>
#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "openGLTypes.h"

//------------------------------------------------------------------------------
namespace NModel
{
  static const uint32 VERTEX_PNT_SIZE = 8;
  static const uint32 VERTEX_PNTBTC_SIZE = 18;
  static const uint8 VBO_OFFSET_POSITION = 0;
  static const uint8 VBO_OFFSET_NORMAL = 3;
  static const uint8 VBO_OFFSET_NORMAL_TANGENT = 6;
  static const uint8 VBO_OFFSET_NORMAL_BITANGENT = 9;
  static const uint8 VBO_OFFSET_TEX_COORD = 12;
  static const uint8 VBO_OFFSET_COLOR = 14;

  static const uint32 FACE_SIZE = 3;
}
//-----------------------------------------------------------------------------
class CShaderProgram;
class CMap;

struct SMaterial
{
  const CShaderProgram *program;
  const CMap *diffuseTexture;
  const CMap *alphaTexture;
  const CMap *specularTexture;
  const CMap *normalTexture;
  float opacity;
  bool mipmap;
  bool edge;

  inline SMaterial() : program(NULL), diffuseTexture(NULL), alphaTexture(NULL), specularTexture(NULL), normalTexture(NULL), opacity(1.0f), mipmap(true), edge(false) {}
  inline SMaterial(const CShaderProgram *program, const CMap *diffuseTexture, const CMap *alphaTexture, const CMap *specularTexture, const CMap *normalTexture, float opacity, bool mipmap, bool edge) : program(program), diffuseTexture(diffuseTexture), alphaTexture(alphaTexture), specularTexture(specularTexture), normalTexture(normalTexture), opacity(opacity), mipmap(mipmap), edge(edge) {}
};
//-----------------------------------------------------------------------------
struct SFace
{
  uint16 vertex0;
  uint16 vertex1;
  uint16 vertex2;

  inline SFace() : vertex0(0), vertex1(0), vertex2(0) {}
  inline SFace(uint16 vertex0, uint16 vertex1, uint16 vertex2) : vertex0(vertex0), vertex1(vertex1), vertex2(vertex2) {}
};
//-----------------------------------------------------------------------------
struct SFaces
{
  std::vector<SFace> faces;
  const SMaterial *material;

  inline SFaces() : material(NULL) {}
  inline SFaces(const SMaterial *material) : material(material) {}
};
//-----------------------------------------------------------------------------
struct SVertex
{
  glm::vec3 position;
  glm::vec3 normal;
  glm::vec3 normalTangent;
  glm::vec3 normalBitangent;
  glm::vec2 texCoord;
  glm::vec4 color;

  inline SVertex() : normal(0.0, 1.0, 0.0), normalTangent(1.0, 0.0, 0.0), normalBitangent(0.0, 0.0, 1.0), color(1.0, 1.0, 1.0, 1.0) {}
  inline SVertex(const glm::vec3 &position, const glm::vec3 &normal, const glm::vec3 &normalTangent, const glm::vec3 &normalBitangent, const glm::vec2 &texCoord, const glm::vec4 &color) : position(position), normal(normal), normalTangent(normalTangent), normalBitangent(normalBitangent), texCoord(texCoord), color(color) {}
};
//-----------------------------------------------------------------------------
struct SMesh
{
  glm::vec3 position;
  glm::quat rotation;
  glm::vec3 scale;
  glm::mat4 transformation;
  std::vector<SVertex> vertices;
  std::vector<SFaces> faces;
  GLuint vboVertices;
  GLuint vboIndices;

  inline SMesh() : scale(1.0, 1.0, 1.0), vboVertices(0), vboIndices(0) {}
};
//-----------------------------------------------------------------------------
struct SModel
{
  std::string name;
  std::list<SMaterial> materials;
  std::list<SMesh> meshes;

  inline SModel() {}
  inline SModel(const std::string &name) : name(name) {}
};
//------------------------------------------------------------------------------
#endif // MODELTYPES_H
