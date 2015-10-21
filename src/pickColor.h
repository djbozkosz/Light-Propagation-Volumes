//---------------------------------------------------------------------------
#ifndef PICKCOLOR_H
#define PICKCOLOR_H

#include "framebuffers.h"

//---------------------------------------------------------------------------
class CPickColor : public CEngineBase
{
  private:
    NMap::EPickColorInc inc;
    SColor color;

  public:
    inline CPickColor() : CEngineBase() {}
    inline CPickColor(CContext *context, NMap::EPickColorInc inc = NMap::PICK_INC_1) : CEngineBase(context), inc(inc) { uint8 i = static_cast<uint8>(inc); color = SColor(i, i, i); }
    inline ~CPickColor() {}

    inline void setInc(NMap::EPickColorInc inc) { this->inc = inc; }
    inline void setColor(const SColor &color) { this->color = color; }
    inline const SColor *getColor() const { return &color; }
    const SColor *getNextColor();
};
//---------------------------------------------------------------------------
inline const SColor *CPickColor::getNextColor()
{
  uint8 i = static_cast<uint8>(inc);
  color.b += i;

  if(color.b >= 255)
  {
    color.b = i;
    color.g += i;
  }

  if(color.b >= 255)
  {
    color.b = i;
    color.r += i;
  }

  if(color.r >= 255)
  {
    color.r = 0;
    color.g = 0;
    color.b = 0;
  }

  return &color;
}
//---------------------------------------------------------------------------
#endif // PICKCOLOR_H
