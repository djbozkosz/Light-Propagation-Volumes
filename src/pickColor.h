//---------------------------------------------------------------------------
#ifndef PICKCOLOR_H
#define PICKCOLOR_H

#include "framebuffers.h"

//---------------------------------------------------------------------------
class CPickColor : public CEngineBase
{
  private:
  SColor color;

  public:
  inline CPickColor() : CEngineBase() {}
  inline CPickColor(CContext *context) : CEngineBase(context) {}
  inline ~CPickColor() {}

  inline void setColor(const SColor &color) { this->color = color; }
  inline const SColor *getColor() const { return &color; }
  const SColor *getNextColor();
};
//---------------------------------------------------------------------------
inline const SColor *CPickColor::getNextColor()
{
  color.b++;

  if(color.b == 255)
  {
    color.b = 1;
    color.g++;
  }

  if(color.b == 255)
  {
    color.b = 1;
    color.r++;
  }

  if(color.r == 255)
  {
    color.r = 0;
    color.g = 0;
    color.b = 0;
  }

  return &color;
}
//---------------------------------------------------------------------------
#endif // PICKCOLOR_H
