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
  static const uint32 VERTEX_F_SIZE = 0;

  static const uint32 VERTEX_PT_SIZE = 5;
  static const uint32 VERTEX_PNTTC_SIZE = 15; // PNTBTC 18

  static const uint8 VERTEX_F_OFFSET = 0;

  static const uint8 VERTEX_PT_OFFSET_POSITION = 0;
  static const uint8 VERTEX_PT_OFFSET_TEX_COORD = 3;

  static const uint8 VERTEX_PNTTC_OFFSET_POSITION = 0;
  static const uint8 VERTEX_PNTTC_OFFSET_NORMAL = 3;
  static const uint8 VERTEX_PNTTC_OFFSET_NORMAL_TANGENT = 6;
  //static const uint8 VERTEX_PNTTC_OFFSET_NORMAL_BITANGENT = 9;
  static const uint8 VERTEX_PNTTC_OFFSET_TEX_COORD = 9; // 12
  static const uint8 VERTEX_PNTTC_OFFSET_TEX_COORD0 = 3;
  static const uint8 VERTEX_PNTTC_OFFSET_COLOR = 11; // 14

  static const uint8 VERTEX_SIZE_F = 1;

  static const uint8 VERTEX_SIZE_POSITION = 3;
  static const uint8 VERTEX_SIZE_NORMAL = 3;
  static const uint8 VERTEX_SIZE_NORMAL_TANGENT = 3;
  //static const uint8 VERTEX_SIZE_NORMAL_BITANGENT = 3;
  static const uint8 VERTEX_SIZE_TEX_COORD = 2;
  static const uint8 VERTEX_SIZE_COLOR = 4;

  static const uint32 FACE_SIZE = 3;

  static const uint32 MODEL_DUMMY_BOX_VERTICES_COUNT = 24;
  static const uint32 MODEL_DUMMY_BOX_FACES_COUNT = 12;

  static const uint16 MODEL_VERSION = 0x001D; // Mafia PC version, (c) 2002 - Illusion Softworks

  static const char STR_MODEL_SIGNATURE[] = "4DS";
  static const char STR_MESH_HIDDEN_WCOL[] = "wcol";

  static const char STR_ERROR_UNABLE_TO_OPEN[] = "Unable to open model: \"%s\"";
  static const char STR_ERROR_INVALID_SIGNATURE[] = "Invalid signature: \"%s\"";
  static const char STR_ERROR_INVALID_VERSION[] = "Invalid version: %x (supported version only: %x)";
  static const char STR_ERROR_INVALID_MESH_TYPE[] = "Invalid mesh type: %x";
  static const char STR_ERROR_INVALID_MESH_VISUAL_TYPE[] = "Invalid mesh visual type: %x";

  static const char STR_WARNING_INVALID_MESH_LINK[] = "Invalid mesh link index";
  static const char STR_WARNING_INVALID_STANDARD_MESH_INSTANCE[] = "Invalid standard mesh: \"%s\" instance index";
  static const char STR_WARNING_STANDARD_MESH_NO_LODS[] = "Standard mesh: \"%s\" has no LODs";
  static const char STR_WARNING_INVALID_STANDARD_MESH_LOD_RATIO[] = "Standard mesh: \"%s\" has non-last level LOD: %d with zero LOD ratio - this LOD won't be visible";
  static const char STR_WARNING_STANDARD_MESH_NO_VERTICES[] = "Standard mesh: \"%s\", LOD: %d has no vertices";
  static const char STR_WARNING_STANDARD_MESH_NO_FACE_GROUPS[] = "Standard mesh: \"%s\", LOD: %d has no face groups";
  static const char STR_WARNING_STANDARD_MESH_GROUP_NO_FACES[] = "Standard mesh: \"%s\", LOD: %d, face group: %d has no faces";
  static const char STR_WARNING_STANDARD_MESH_GROUP_DEGEN_FACES[] = "Standard mesh: \"%s\", LOD: %d, face group: %d has degenerated faces to %d lines and %d points";
  static const char STR_WARNING_SINGLE_MESH_NO_LODS[] = "Single mesh: \"%s\" has no LODs";
  static const char STR_WARNING_SINGLE_MESH_NO_BONES[] = "Single mesh: \"%s\", LOD: %d has no bones";
  static const char STR_WARNING_MORPH_NO_FRAMES[] = "Morph: \"%s\" has no frames";
  static const char STR_WARNING_MORPH_LODS_COUNT_DIFF[] = "Morph: \"%s\" has different LODs count: %d to standard mesh LODs count: %d";
  static const char STR_WARNING_MORPH_NO_BONES[] = "Morph: \"%s\", LOD: %d has no vertices";
  static const char STR_WARNING_GLOW_NO_FLARES[] = "Glow: \"%s\" has no flares";
  static const char STR_WARNING_GLOW_FLARE_NO_MAT[] = "Glow: \"%s\", flare: %d has no material";
  static const char STR_WARNING_MIRROR_NO_VERTICES[] = "Mirror: \"%s\" has no vertices";
  static const char STR_WARNING_MIRROR_NO_FACES[] = "Mirror: \"%s\" has no faces";
  static const char STR_WARNING_MIRROR_DEGEN_FACES[] = "Mirror: \"%s\" has degenerated faces to %d lines and %d points";
  static const char STR_WARNING_SECTOR_NO_VERTICES[] = "Sector: \"%s\" has no vertices";
  static const char STR_WARNING_SECTOR_NO_FACES[] = "Sector: \"%s\" has no faces";
  static const char STR_WARNING_SECTOR_DEGEN_FACES[] = "Sector: \"%s\" has degenerated faces to %d lines and %d points";
  static const char STR_WARNING_SECTOR_PORTAL_NO_VERTICES[] = "Sector: \"%s\", portal: %d has no vertices";
  static const char STR_WARNING_TARGET_NO_TARGETS[] = "Target: \"%s\" has no targets";

  enum EModelState
  {
    STATE_VALID = 0,
    STATE_INVALID,
    STATE_INVALID_NOT_FOUND,
    STATE_INVALID_SIGNATURE,
    STATE_INVALID_VERSION,
    STATE_INVALID_MESH_TYPE,
    STATE_INVALID_MESH_VISUAL_TYPE
  };

  enum EMeshUpdateType
  {
    UPDATE_ALL = 0xff,
    UPDATE_TRANSFORMATION = 0x01,
    UPDATE_TANGENT_BASE = 0x02,
    UPDATE_GEOMETRY = 0x04
  };

  enum EMaterial // : uint32
  {
    MATERIAL_DEFAULT              = 0x00000001,
    MATERIAL_UNDEFINED_00000002   = 0x00000002,
    MATERIAL_UNDEFINED_00000004   = 0x00000004,
    MATERIAL_UNDEFINED_00000008   = 0x00000008,
    MATERIAL_UNDEFINED_00000010   = 0x00000010,
    MATERIAL_UNDEFINED_00000020   = 0x00000020,
    MATERIAL_UNDEFINED_00000040   = 0x00000040,
    MATERIAL_UNDEFINED_00000080   = 0x00000080,
    MATERIAL_ENVIRONMENT_BLEND    = 0x00000100,
    MATERIAL_ENVIRONMENT_MULTIPLY = 0x00000200,
    MATERIAL_ENVIRONMENT_ADDITIVE = 0x00000400,
    MATERIAL_UNDEFINED_00000800   = 0x00000800,
    MATERIAL_ENVIRONMENT_Y_AXIS   = 0x00001000,
    MATERIAL_DETAIL_MAP_Y         = 0x00002000,
    MATERIAL_DETAIL_MAP_Z         = 0x00004000,
    MATERIAL_ADD_EFFECT           = 0x00008000,
    MATERIAL_UNDEFINED_00010000   = 0x00010000,
    MATERIAL_UNDEFINED_00020000   = 0x00020000,
    MATERIAL_DIFFUSE              = 0x00040000,
    MATERIAL_ENVIRONMENT          = 0x00080000,
    MATERIAL_UNDEFINED_00100000   = 0x00100000,
    MATERIAL_GLOW                 = 0x00200000,
    MATERIAL_UNDEFINED_00400000   = 0x00400000,
    MATERIAL_MIP_MAPPING          = 0x00800000,
    MATERIAL_UNDEFINED_01000000   = 0x01000000,
    MATERIAL_ANIMATED_ALPHA       = 0x02000000,
    MATERIAL_ANIMATED             = 0x04000000,
    MATERIAL_COLORING             = 0x08000000,
    MATERIAL_TWO_SIDED            = 0x10000000,
    MATERIAL_COLOR_KEY            = 0x20000000,
    MATERIAL_ALPHA                = 0x40000000,
    MATERIAL_ADDITIVE_BLEND       = 0x80000000
  };

  enum EMeshRender // : uint16
  {
    MESH_RENDER_Z_BIAS             = 0x0001,
    MESH_RENDER_RECEIVE_SHADOWS    = 0x0002,
    MESH_RENDER_UNDEFINED_0004     = 0x0004,
    MESH_RENDER_UNDEFINED_0008     = 0x0008,
    MESH_RENDER_UNDEFINED_0010     = 0x0010,
    MESH_RENDER_RECEIVE_PROJECTORS = 0x0020,
    MESH_RENDER_UNDEFINED_0040     = 0x0040,
    MESH_RENDER_NO_FOG             = 0x0080,
    MESH_RENDER_UNDEFINED_0100     = 0x0100,
    MESH_RENDER_UNDEFINED_0200     = 0x0200,
    MESH_RENDER_UNDEFINED_0400     = 0x0400,
    MESH_RENDER_UNDEFINED_0800     = 0x0800,
    MESH_RENDER_UNDEFINED_1000     = 0x1000,
    MESH_RENDER_UNDEFINED_2000     = 0x2000,
    MESH_RENDER_UNDEFINED_4000     = 0x4000,
    MESH_RENDER_UNDEFINED_8000     = 0x8000
  };

  enum EMeshCulling // : uint8
  {
    MESH_CULLING_VISIBLE           = 0x01,
    MESH_CULLING_UNDEFINED_02      = 0x02,
    MESH_CULLING_SECTOR            = 0x04,
    MESH_CULLING_DEFAULT           = 0x08,
    MESH_CULLING_SECTOR_PORTAL     = 0x10,
    MESH_CULLING_SECTOR_UNDER_MESH = 0x20,
    MESH_CULLING_SECTOR_MESH       = 0x40,
    MESH_CULLING_UNDEFINED_80      = 0x80
  };

  enum EMeshType // : uint8
  {
    MESH_TYPE_STANDARD = 0x01,
    MESH_TYPE_SECTOR   = 0x05,
    MESH_TYPE_DUMMY    = 0x06,
    MESH_TYPE_TARGET   = 0x07,
    MESH_TYPE_BONE     = 0x0A
  };

  enum EMeshVisualType // : uint8
  {
    MESH_VISUAL_TYPE_STANDARD     = 0x00,
    MESH_VISUAL_TYPE_SINGLE_MESH  = 0x02,
    MESH_VISUAL_TYPE_SINGLE_MORPH = 0x03,
    MESH_VISUAL_TYPE_BILLBOARD    = 0x04,
    MESH_VISUAL_TYPE_MORPH        = 0x05,
    MESH_VISUAL_TYPE_GLOW         = 0x06,
    MESH_VISUAL_TYPE_MIRROR       = 0x08
  };

  enum EBillboardRotation // : uint32
  {
    MESH_BILLBOARD_ROTATION_X = 0,
    MESH_BILLBOARD_ROTATION_Y,
    MESH_BILLBOARD_ROTATION_Z
  };

  enum EBillboardAxis // : uint8
  {
    MESH_BILLBOARD_AXIS_ALL = 0,
    MESH_BILLBOARD_AXIS_ONE
  };
}
//------------------------------------------------------------------------------
class CMap;
class CShaderProgram;
struct SMesh;

//------------------------------------------------------------------------------
struct SMaterial
{
  uint32 type;
  const CShaderProgram *program;

  glm::vec3 colorAmbient;
  glm::vec3 colorDiffuse;
  glm::vec3 colorEmission;
  float opacity;

  float environmentMapRatio;
  uint8 environmentMapLength;
  std::string environmentMapName;
  const CMap *environmentMap;

  uint8 diffuseMapLength;
  std::string diffuseMapName;
  const CMap *diffuseMap;

  uint8 alphaMapLength;
  std::string alphaMapName;
  const CMap *alphaMap;

  const CMap *specularMap;
  const CMap *normalMap;

  uint32 animatedFramesCount;
  uint16 animatedUndefined0;
  uint32 animatedFramesPeriod;
  uint32 animatedUndefined1;
  uint32 animatedUndefined2;

  inline SMaterial() :
    type(0),
    program(NULL),
    opacity(1.0f),
    environmentMapRatio(0.0f),
    environmentMapLength(0),
    environmentMap(NULL),
    diffuseMapLength(0),
    diffuseMap(NULL),
    alphaMapLength(0),
    alphaMap(NULL),
    specularMap(NULL),
    normalMap(NULL),
    animatedFramesCount(0),
    animatedUndefined0(0),
    animatedFramesPeriod(1000),
    animatedUndefined1(0),
    animatedUndefined2(0) {}
};
//------------------------------------------------------------------------------
struct SBoundingBox
{
  bool used;
  glm::vec3 minimum;
  glm::vec3 maximum;

  inline SBoundingBox() : used(false), minimum(0.0f, 0.0f, 0.0f), maximum(0.0f, 0.0f, 0.0f) {}
  inline SBoundingBox(const glm::vec3 &min, const glm::vec3 &max) : used(true), minimum(min), maximum(max) {}
  SBoundingBox(const std::vector<SBoundingBox> &aabb);
  SBoundingBox(const std::vector<glm::vec3> &vertices);

  void expand(const SBoundingBox &aabb);
  bool isIn(const glm::vec3 &pos) const;

  inline glm::vec3 getSize() { return glm::vec3(maximum - minimum); }
};
//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
struct SFace
{
  uint16 vertex0;
  uint16 vertex1;
  uint16 vertex2;

  inline SFace() : vertex0(0), vertex1(0), vertex2(0) {}
  inline SFace(uint16 vertex0, uint16 vertex1, uint16 vertex2) : vertex0(vertex0), vertex1(vertex1), vertex2(vertex2) {}
};
//------------------------------------------------------------------------------
struct SFacesGroup
{
  uint16 facesCount;
  std::vector<SFace> faces;
  uint16 materialIndex;
  const SMaterial *material;

  inline SFacesGroup() : facesCount(0), materialIndex(0), material(NULL) {}
};
//------------------------------------------------------------------------------
struct SStandardMeshLod
{
  float ratio;
  uint16 verticesCount;
  std::vector<SVertex> vertices;
  GLuint vboVertices;
  GLuint vboSimpleVertices;
  GLuint vboIndices;
  uint8 faceGroupsCount;
  std::list<SFacesGroup> faceGroups;

  inline SStandardMeshLod() : ratio(0.0f), verticesCount(0), vboVertices(0), vboSimpleVertices(0), vboIndices(0), faceGroupsCount(0) {}
};
//------------------------------------------------------------------------------
struct SStandardMesh
{
  uint16 instancedMeshIndex;
  const SMesh *instancedMesh;
  uint8 lodsCount;
  std::list<SStandardMeshLod> lods;

  inline SStandardMesh() : instancedMeshIndex(0), instancedMesh(NULL), lodsCount(0) {}
};
//------------------------------------------------------------------------------
struct SSingleMeshBone
{
  glm::mat4 transformation;
  uint32 undefined0;
  uint32 vertexParametersCount;
  uint32 bone;
  SBoundingBox boundingBox;
  std::vector<float> vertexParameters;

  inline SSingleMeshBone() : undefined0(0), vertexParametersCount(0), bone(0) {}
};
//------------------------------------------------------------------------------
struct SSingleMeshLod
{
  uint8 bonesCount;
  uint32 undefined0;
  SBoundingBox boundingBox;
  std::list<SSingleMeshBone> bones;

  inline SSingleMeshLod() : bonesCount(0), undefined0(0) {}
};
//------------------------------------------------------------------------------
struct SSingleMesh
{
  std::list<SSingleMeshLod> lods;

  inline SSingleMesh() {}
};
//------------------------------------------------------------------------------
struct SBillboard
{
  NModel::EBillboardRotation rotation;
  NModel::EBillboardAxis axis;

  inline SBillboard() : rotation(NModel::MESH_BILLBOARD_ROTATION_X), axis(NModel::MESH_BILLBOARD_AXIS_ALL) {}
};
//------------------------------------------------------------------------------
struct SMorphLod
{
  uint16 verticesCount;
  std::vector<SVertex> vertices;
  uint8 undefined0;
  std::vector<uint16> links;

  inline SMorphLod() : verticesCount(0), undefined0(0) {}
};
//------------------------------------------------------------------------------
struct SMorph
{
  uint8 framesCount;
  uint8 lodsCount;
  uint8 undefined0;
  std::list<SMorphLod> lods;
  SBoundingBox boundingBox;
  float undefined1;
  float undefined2;
  float undefined3;
  float undefined4;

  inline SMorph() : framesCount(0), lodsCount(0), undefined0(0), undefined1(0.0f), undefined2(0.0f), undefined3(0.0f), undefined4(0.0f) {}
};
//------------------------------------------------------------------------------
struct SGlowFlare
{
  float position;
  uint16 materialIndex;
  const SMaterial *material;

  inline SGlowFlare() : position(0.0f), materialIndex(0), material(NULL) {}
};
//------------------------------------------------------------------------------
struct SGlow
{
  uint8 flaresCount;
  std::list<SGlowFlare> flares;

  inline SGlow() : flaresCount(0) {}
};
//------------------------------------------------------------------------------
struct SMirror
{
  SBoundingBox boundingBox;
  float undefined0;
  float undefined1;
  float undefined2;
  float undefined3;
  glm::mat4 transformation;
  glm::vec3 color;
  float drawDistance;
  uint32 verticesCount;
  uint32 facesCount;
  std::vector<SVertex> vertices;
  std::vector<SFace> faces;
  GLuint vboVertices;
  GLuint vboIndices;

  inline SMirror() : undefined0(0.0f), undefined1(0.0f), undefined2(0.0f), undefined3(0.0f), drawDistance(0.0f), verticesCount(0), facesCount(0), vboVertices(0), vboIndices(0) {}
};
//------------------------------------------------------------------------------
struct SSectorPortal
{
  uint8 verticesCount;
  uint32 undefined0;
  float undefined1;
  float undefined2;
  float undefined3;
  float undefined4;
  float undefined5;
  float undefined6;
  std::vector<SVertex> vertices;

  inline SSectorPortal() : verticesCount(0), undefined0(0), undefined1(0.0f), undefined2(0.0f), undefined3(0.0f), undefined4(0.0f), undefined5(0.0f), undefined6(0.0f) {}
};
//------------------------------------------------------------------------------
struct SSector
{
  uint32 undefined0;
  uint32 undefined1;
  uint32 verticesCount;
  uint32 facesCount;
  std::vector<SVertex> vertices;
  std::vector<SFace> faces;
  GLuint vboVertices;
  SBoundingBox boundingBox;
  uint8 portalsCount;
  std::list<SSectorPortal> portals;

  inline SSector() : undefined0(0), undefined1(0), verticesCount(0), facesCount(0), vboVertices(0), portalsCount(0) {}
};
//------------------------------------------------------------------------------
struct SDummy
{
  SBoundingBox boundingBox;

  inline SDummy() {}
};
//------------------------------------------------------------------------------
struct STarget
{
  uint16 undefined0;
  uint8 targetsCount;
  std::list<uint16> targets;

  inline STarget() : undefined0(0), targetsCount(0) {}
};
//------------------------------------------------------------------------------
struct SBone
{
  glm::mat4 transformation;
  uint32 bone;

  inline SBone() : bone(0) {}
};
//------------------------------------------------------------------------------
struct SMesh
{
  uint16 index;
  NModel::EMeshType type;
  NModel::EMeshVisualType visualType;
  uint16 renderFlags;
  uint16 linkIndex;
  const SMesh *link;
  //uint16 visualSector;
  glm::vec3 position;
  glm::quat rotation;
  glm::vec3 scale;
  glm::mat4 transformation;
  uint8 cullingFlags;
  uint8 nameLength;
  std::string name;
  uint8 parametersLength;
  std::string parameters;

  SStandardMesh standardMesh;
  SSingleMesh singleMesh;
  SBillboard billboard;
  SMorph morph;
  SGlow glow;
  SMirror mirror;
  SSector sector;
  SDummy dummy;
  STarget target;
  SBone bone;

  inline SMesh() : index(0), type(NModel::MESH_TYPE_STANDARD), visualType(NModel::MESH_VISUAL_TYPE_STANDARD), renderFlags(0), linkIndex(0), link(NULL), cullingFlags(0), nameLength(0), parametersLength(0) {}
};
//------------------------------------------------------------------------------
struct SModel
{
  NModel::EModelState state;
  std::string path;
  char signature[NFile::SIGNATURE_LENGTH_LONG];
  uint16 version;
  uint64 timestamp;
  uint16 materialsCount;
  std::list<SMaterial> materials;
  uint16 meshesCount;
  std::map<std::string, SMesh> meshes;
  uint8 allowAnimation;

  inline SModel(const std::string &path = std::string()) : state(NModel::STATE_INVALID), path(path), version(0), timestamp(0), materialsCount(0), meshesCount(0), allowAnimation(0)
  {
    memset(signature, 0, sizeof(char) * NFile::SIGNATURE_LENGTH_LONG);
  }
};
//------------------------------------------------------------------------------
inline SBoundingBox::SBoundingBox(const std::vector<SBoundingBox> &aabb)
{
  if(!aabb.size())
    return;

  used = true;
  minimum = aabb[0].minimum;
  maximum = aabb[0].maximum;

  for(auto it = aabb.cbegin(); it != aabb.cend(); it++)
    expand(SBoundingBox(it->minimum, it->maximum));
}
//------------------------------------------------------------------------------
inline SBoundingBox::SBoundingBox(const std::vector<glm::vec3> &vertices)
{
  if(!vertices.size())
    return;

  used = true;
  minimum = vertices[0];
  maximum = vertices[0];

  for(auto it = vertices.cbegin(); it != vertices.cend(); it++)
    expand(SBoundingBox(*it, *it));
}
//------------------------------------------------------------------------------
inline void SBoundingBox::expand(const SBoundingBox &aabb)
{
  if(!used)
  {
    used = true;
    minimum = aabb.minimum;
    maximum = aabb.maximum;

    return;
  }

  if(aabb.minimum.x < minimum.x) minimum.x = aabb.minimum.x;
  if(aabb.minimum.y < minimum.y) minimum.y = aabb.minimum.y;
  if(aabb.minimum.z < minimum.z) minimum.z = aabb.minimum.z;
  if(aabb.maximum.x > maximum.x) maximum.x = aabb.maximum.x;
  if(aabb.maximum.y > maximum.y) maximum.y = aabb.maximum.y;
  if(aabb.maximum.z > maximum.z) maximum.z = aabb.maximum.z;
}
//------------------------------------------------------------------------------
inline bool SBoundingBox::isIn(const glm::vec3 &pos) const
{
  if((pos.x >= minimum.x) && (pos.y >= minimum.y) && (pos.z >= minimum.z) && (pos.x <= maximum.x) && (pos.y <= maximum.y) && (pos.z <= maximum.z))
    return true;

  return false;
}
//------------------------------------------------------------------------------
#endif // MODELTYPES_H
