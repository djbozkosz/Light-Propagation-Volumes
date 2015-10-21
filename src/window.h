//------------------------------------------------------------------------------
#ifndef WINDOW_H
#define WINDOW_H

#include "scenes.h"

//------------------------------------------------------------------------------
class CWindow : public CEngineBase
{
  private:
    //

  protected:
    virtual void initialize();
    virtual void paint();
    virtual void resize(uint32 width, uint32 height);

  public:
    CWindow();
    CWindow(CContext *context);
    ~CWindow();
};
//------------------------------------------------------------------------------
#endif // WINDOW_H
