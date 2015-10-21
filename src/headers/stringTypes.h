//------------------------------------------------------------------------------
#ifndef STRINGTYPES_H
#define STRINGTYPES_H

#include "types.h"

//------------------------------------------------------------------------------
namespace NStr
{
  static const uint32 MAX_PATH_LEN = 100;

  static const char C_FORMAT_SIGN = '%';
  static const char C_FORMAT_EXCEPT = '\\';

  static const char C_FORMAT_CHARACTER = 'c';
  static const char C_FORMAT_BYTE = 'b';
  static const char C_FORMAT_SHORT = 'h';
  static const char C_FORMAT_INT = 'i';
  static const char C_FORMAT_INTEGER = 'd';
  static const char C_FORMAT_LONG = 'l';
  static const char C_FORMAT_HEX_INT = 'x';
  static const char C_FORMAT_HEX_LONG = 'y';
  static const char C_FORMAT_DOUBLE_FLOAT = 'f';
  static const char C_FORMAT_POINTER = 'p';
  static const char C_FORMAT_STRING = 's';
  static const char C_FORMAT_UNSIGNED = 'u';

  static const char STR_HEX_PREFIX[] = "0x";
  static const char STR_PATH_SEPARATORS[] = "/\\";
  static const char STR_EXTENSION_SEPARATOR[] = ".";

  static const char STR_UNIX_EXE_PATH[] = "/proc/%ud/exe";

  static const char STR_TYPE_SIZES[] =
    "         bool      %d\n"
    "         char      %d\n"
    "unsigned char      %d\n"
    "         short     %d\n"
    "unsigned short     %d\n"
    "         int       %d\n"
    "unsigned int       %d\n"
    "         long      %d\n"
    "unsigned long      %d\n"
    "         long long %d\n"
    "unsigned long long %d\n"
    "         float     %d\n"
    "         void      %d\n"
    "         int8_t    %d\n"
    "        uint8_t    %d\n"
    "         int16_t   %d\n"
    "        uint16_t   %d\n"
    "         int32_t   %d\n"
    "        uint32_t   %d\n"
    "         int64_t   %d\n"
    "        uint64_t   %d\n";
}
//------------------------------------------------------------------------------
#endif //STRINGTYPES_H