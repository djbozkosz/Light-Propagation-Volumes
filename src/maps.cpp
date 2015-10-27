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
  //COpenGL *gl = context->getOpenGL();

  if(map.framebuffer)
  {
    std::vector<uint8> i(map.width * map.height * NMap::RGBA_SIZE, 0);
    glGenTextures(1, &map.texture);
    glBindTexture(GL_TEXTURE_2D, map.texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, map.width, map.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &i[0]);
    glBindTexture(GL_TEXTURE_2D, 0);
  }
  else
  {
    bool loaded = false;
    CFile *f = (map.file.length()) ? context->getFilesystem()->open(SFile(std::string(NFile::STR_DATA_MAPS)+map.file)) : NULL;
    std::vector<uint8> data;
    const uint32 maxTextureSize = context->engineGetEngine()->maxTextureSize;

    glGenTextures(1, &map.texture);
    glBindTexture(GL_TEXTURE_2D, map.texture);

    if(f)
    {
      data.resize(f->size());
      f->read(&data[0], data.size());

#if defined(ENV_QT)
      QImage i;
      i.loadFromData(&d[0], data.size());

      if(!i.isNull())
      {
        loaded = true;

        //i = i.convertToFormat(QImage::Format_RGBA8888);
        data.resize(i.width() * i.height() * NMap::RGBA_SIZE);
        memcpy(&data[0], i.constBits(), sizeof(uint8) * i.width() * i.height() * NMap::RGBA_SIZE);
        for(int32 j = 0; j < (i.width() * i.height() * 4); j += NMap::RGBA_SIZE)
        {
          uint8 b = data[j + 0];
          data[j + 0] = data[j + 2];
          data[j + 2] = b;
        }
        map.width = i.width();
        map.height = i.height();
        setColorKeyIntoAlpha(&data[0], map.width, map.height);
        if(maxTextureSize)
          clampBitmap(&data[0], map.width, map.height, map.width, map.height, maxTextureSize);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, map.width, map.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &data[0]);
      }
#elif defined(ENV_SDL)
      SDL_RWops *rw = SDL_RWFromConstMem(&data[0], data.size());
      SDL_Surface *ii = IMG_Load_RW(rw, 1);

      if(ii)
      {
        SDL_PixelFormat pf = { SDL_PIXELFORMAT_RGBA8888, NULL, NMap::RGBA_BITS_SIZE, NMap::RGBA_SIZE, {0, 0}, NMap::RGBA_MASK_R, NMap::RGBA_MASK_G, NMap::RGBA_MASK_B, NMap::RGBA_MASK_A, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL };
        SDL_Surface *i = SDL_ConvertSurface(ii, &pf, 0);

        if(i)
        {
          loaded = true;

          //std::cout << i->w << " " << i->h << " " << std::hex << i->format->format << std::dec << " " << (uint32)i->format->BitsPerPixel << " " << (uint32)i->format->BytesPerPixel << " " << i->format->palette << "\n";
          map.width = i->w;
          map.height = i->h;
          uint8 *d = reinterpret_cast<uint8 *>(i->pixels);
          setColorKeyIntoAlpha(d, map.width, map.height);
          if(maxTextureSize)
            clampBitmap(d, map.width, map.height, map.width, map.height, maxTextureSize);
          glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, map.width, map.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, d);

          SDL_FreeSurface(i);
        }
        SDL_FreeSurface(ii);
      }
#endif
    }

    if(!loaded)
    {
      //context->error(CStr(NMap::STR_ERROR_UNABLE_TO_OPEN, map.file.c_str()));
      const uint8 color[4] = { map.color.r, map.color.g, map.color.b, map.color.a };
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, color);
    }
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
  }
}
//------------------------------------------------------------------------------
void CMap::setColorKeyIntoAlpha(uint8 *data, uint32 width, uint32 height)
{
  if(!data)
    return;

  uint32 stepX = static_cast<uint32>(1.0f / 64.0f * static_cast<float>(width));
  uint32 stepY = static_cast<uint32>(1.0f / 64.0f * static_cast<float>(height));
  if(stepX < 1)
    stepX = 1;
  if(stepY < 1)
    stepY = 1;

  for(uint32 i = 0; i < ((width < height) ? width : height); i += stepX)
  { // po diagonále fast ček na alfu
    if(data[(i + i * width) * NMap::RGBA_SIZE + 3] != 255)
      return;
  }

  std::map<uint32, uint32> colors;

  for(uint32 i = 0; i < width * height; i += stepX + (((i / width) != ((i + stepX) / width)) ? width * stepY : 0))
  { // ťupky podle stepu na most barvu
    uint32 c = *reinterpret_cast<int32 *>(&data[i * NMap::RGBA_SIZE]);
    auto it = colors.find(c);

    if(it == colors.end())
      colors[c] = 1;
    else
      it->second++;
  }

  std::pair<uint32, uint32> clr;
  clr.first = 0;
  clr.second = 0;

  for(auto it = colors.begin(); it != colors.end(); it++)
  { // výběr most barvy
    if(it->second > clr.second)
      clr = *it;
  }

  uint8 *key = reinterpret_cast<uint8 *>(&clr.first);
  //std::cout << (uint32)p[0] << " " << (uint32)p[1] << " " << (uint32)p[2] << " " << (uint32)p[3] << "\n";
  //std::cout << "most color: " << std::hex << clr.first << std::dec << " " << clr.second << "\n";

  for(uint32 i = 0; i < width * height; i++)
  { // zatemění alfy pro color key barvy a jejich podobných barev
    uint8 c[3] = { data[i * NMap::RGBA_SIZE + 0], data[i * NMap::RGBA_SIZE + 1], data[i * NMap::RGBA_SIZE + 2] };
    bool isTransp = true;

    for(uint8 j = 0; j < 3; j++)
    { // je v rozsahu ?
      if((c[j] < (key[j] - NMap::COLOR_KEY_OFFSET)) || (c[j] > (key[j] + NMap::COLOR_KEY_OFFSET)))
      {
        isTransp = false;
        break;
      }
    }

    if(isTransp)
      data[i * NMap::RGBA_SIZE + 3] = 0;
  }
}
//------------------------------------------------------------------------------
void CMap::clampBitmap(uint8 *data, uint32 width, uint32 height, uint32 &newWidth, uint32 &newHeight, uint32 maxSize)
{
  if(!data)
    return;

  uint32 size = (width > height) ? width : height;
  if(size <= maxSize)
    return;

  uint32 step = size / maxSize;
  newWidth = width / step;
  newHeight = height / step;

  std::vector<uint32> d(newWidth * newHeight);
  for(uint32 i = 0; i < d.size(); i++)
    d[i] = *reinterpret_cast<uint32 *>(&data[((i % newWidth) * step + (i / newWidth) * step * width) * NMap::RGBA_SIZE]);

  memset(data, 0, sizeof(uint32) * width * height);
  memcpy(data, &d[0], sizeof(uint32) * d.size());
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
  //addMap(SMap(NMap::STR_DEFAULT_NORMAL, glm::vec4(0.5, 0.5, 1.0, 1.0)));
}
//------------------------------------------------------------------------------
CMaps::~CMaps()
{
}
//------------------------------------------------------------------------------
