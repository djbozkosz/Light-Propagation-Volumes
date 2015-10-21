//------------------------------------------------------------------------------
#ifndef CULLING_H
#define CULLING_H

#include "pickColor.h"
#include "headers/cullingTypes.h"

//------------------------------------------------------------------------------
class CCulling : public CEngineBase
{
  private:
    //

  public:
    inline CCulling() : CEngineBase() {}
    inline CCulling(CContext *context) : CEngineBase(context) {}
    inline ~CCulling() {}
};
//------------------------------------------------------------------------------
#endif // CULLING_H
