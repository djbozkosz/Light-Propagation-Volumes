//-----------------------------------------------------------------------------
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <stdexcept>

#include "context.h"
#include "headers/exceptionTypes.h"

//-----------------------------------------------------------------------------
class CException : std::runtime_error, public CEngineBase
{
  private:
    SException exception;
    std::string msg;

  public:
    CException(CContext *context, const SException &exception) throw();

#ifdef _MSC_VER
    virtual inline const char *what() const { return msg.c_str(); }
#else
    virtual inline const char *what() const noexcept(true) { return msg.c_str(); }
#endif
};
//-----------------------------------------------------------------------------
class CExceptions : public CEngineBase
{
  private:
    //

  public:
    inline CExceptions() : CEngineBase() {}
    inline CExceptions(CContext *context) : CEngineBase(context) {}
    inline ~CExceptions() {}

    inline void throwException(const SException &exception) { CException(context, exception); }
};
//-----------------------------------------------------------------------------
inline CException::CException(CContext *context, const SException &exception) throw() : std::runtime_error(std::string()), CEngineBase(context), exception(exception)
{
  msg = CStr("%s: %s (%s), File: %s, Code: %d", context->engineGetClassName(exception.sender).c_str(), exception.text.c_str(), exception.description.c_str(), exception.file.c_str(), exception.code);
}
//-----------------------------------------------------------------------------
#endif // EXCEPTIONS_H
