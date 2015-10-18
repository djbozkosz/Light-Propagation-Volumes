//------------------------------------------------------------------------------
#ifndef OPENGL_H
#define OPENGL_H

#include "context.h"
#include "headers/openGLTypes.h"

//------------------------------------------------------------------------------
class COpenGL : public CEngineBase
{
  private:
  //

  public:
    COpenGL();
    COpenGL(CContext *context);
    ~COpenGL();
    void makeCurrent();
};
//------------------------------------------------------------------------------
inline COpenGL::COpenGL() : CEngineBase()
{
  //
}
//------------------------------------------------------------------------------
inline COpenGL::COpenGL(CContext *context) : CEngineBase(context)
{
  //
}
//------------------------------------------------------------------------------
inline COpenGL::~COpenGL()
{
  //
}
//------------------------------------------------------------------------------
inline void COpenGL::makeCurrent()
{
  //
}
//------------------------------------------------------------------------------
#endif // OPENGL_H
