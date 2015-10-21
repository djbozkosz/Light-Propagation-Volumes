//-----------------------------------------------------------------------------
#ifndef EXCEPTIONTYPES_H
#define EXCEPTIONTYPES_H

#include <string>

#include "types.h"

//-----------------------------------------------------------------------------
namespace NException
{
  //
}
//-----------------------------------------------------------------------------
struct SException
{
  const CEngineBase *sender;
  const std::string text;
  const std::string description;
  const std::string file;
  uint32 code;

  inline SException() : sender(NULL), code(0) {}
  inline SException(const CEngineBase *sender, const std::string &text, const std::string &description = std::string(), const std::string &file = std::string(), uint32 code = 0) : sender(sender), text(text), description(description), file(file), code(code) {}
};
//-----------------------------------------------------------------------------
#endif // EXCEPTIONTYPES_H
