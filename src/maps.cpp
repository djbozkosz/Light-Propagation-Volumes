//------------------------------------------------------------------------------
#include "maps.h"

//------------------------------------------------------------------------------
CMap::CMap() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CMap::CMap(CContext *context, const SMap &map) : CEngineBase(context), map(map)
{
  load();
}
//------------------------------------------------------------------------------
CMap::~CMap()
{
}
//------------------------------------------------------------------------------
void CMap::load()
{
  /*COpenGL *gl = context->getOpenGL();

  if(map.framebuffer)
  {
    QImage i(map.width, map.height, QImage::Format_ARGB32);
    glGenTextures(1, &map.texture);
    glBindTexture(GL_TEXTURE_2D, map.texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, i.width(), i.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, i.constBits());
    glBindTexture(GL_TEXTURE_2D, 0);
  }
  else
  {
    QImage i(map.file);
    glGenTextures(1, &map.texture);
    glBindTexture(GL_TEXTURE_2D, map.texture);
    if(!i.isNull())
    {
      //i = i.convertToFormat(QImage::Format_RGBA8888);
      QVector<uint8> data(i.width() * i.height() * 4);
      memcpy(&data[0], i.constBits(), sizeof(uint8) * i.width() * i.height() * 4);
      for(int32 j = 0; j < (i.width() * i.height() * 4); j += 4)
      {
        uint8 b = data[j + 0];
        data[j + 0] = data[j + 2];
        data[j + 2] = b;
      }
      //qDebug(QString("Texture loaded: "+map.file).toStdString().c_str());
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, i.width(), i.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, &data[0]);
    }
    else
    {
      qDebug(QString("Unable to load texture: "+map.file).toStdString().c_str());
      const uint8 color[4] = { static_cast<uint8>(map.color.x() * 255.0f), static_cast<uint8>(map.color.y() * 255.0f), static_cast<uint8>(map.color.z() * 255.0f), static_cast<uint8>(map.color.w() * 255.0f) };
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, color);
    }
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
  }*/
}
//------------------------------------------------------------------------------
CMaps::CMaps() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CMaps::CMaps(CContext *context) : CEngineBase(context)
{
}
//------------------------------------------------------------------------------
void CMaps::loadDefaultMaps()
{
  addMap(SMap(NMap::STR_DEFAULT_NORMAL, glm::vec4(0.5, 0.5, 1.0, 1.0)));
}
//------------------------------------------------------------------------------
CMaps::~CMaps()
{
}
//------------------------------------------------------------------------------
