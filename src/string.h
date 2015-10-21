//-----------------------------------------------------------------------------
#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <cstdarg>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

#if defined(_WIN32)
#include <windows.h>
#elif defined(__linux__)
#include <unistd.h>
#endif

#include "headers/stringTypes.h"

//-----------------------------------------------------------------------------
class CStr
{
  private:
    std::string s;

  public:
    CStr(const std::string text, ...);
    ~CStr();
    operator std::string() const;
    const std::string &str() const;
    const char *c_str() const;
    static std::string intToStr(int64 number);
    static std::string uintToStr(uint64 number);
    static std::string floatToStr(float number);
    static std::string doubleToStr(double number);
    static std::string uintToHex(uint64 number);
    static std::string pointToHex(const void *pointer);
    static int64       strToInt(const std::string &text);
    static float       strToFloat(const std::string &text);
    static double      strToDouble(const std::string &text);
    static std::string replaceAll(const std::string &src, const std::string &before, const std::string &after);
    static std::string strToUp(const std::string &text);
    static std::string strToLow(const std::string &text);
    static std::string extPath(const std::string &text);
    static std::string extPathFile(const std::string &text);
    static std::string extFile(const std::string &text);
    static std::string extFile2(const std::string &text);
    static std::string extExt(const std::string &text);
    static std::string extExt2(const std::string &text);
    static std::string exe();
    static std::string exeFile();
    static std::string exePath();
    static std::string getSizes();
};
//-----------------------------------------------------------------------------
inline CStr::CStr(const std::string text, ...)
{
  // c - char
  // b - int8
  // h - int16
  // i, d - int32
  // l - int64
  // x - hex int32
  // y - hex int64
  // f - float, double
  // p - pointer
  // s - string
  // u* - unsigned

  char c = 0;
  char lastC = 0;
  bool replaced = false;

  s = text;
  va_list args;
  va_start(args, text);

  for(uint32 i = 0; i < s.size(); lastC = c, i++)
  {
    replaced = false;
    c = s[i];

    if((c == NStr::C_FORMAT_SIGN) && (lastC != NStr::C_FORMAT_EXCEPT) && (i < (s.size() - 1)))
    {
      lastC = c;
      i++;
      c = s[i];

      if(c == NStr::C_FORMAT_CHARACTER)
      {
        s = s.replace(i - 1, 2, std::string(1, va_arg(args, int32)));
        replaced = true;
      }
      else if((c == NStr::C_FORMAT_BYTE) || (c == NStr::C_FORMAT_SHORT) || (c == NStr::C_FORMAT_INT) || (c == NStr::C_FORMAT_INTEGER))
      {
        s = s.replace(i - 1, 2, CStr::intToStr(va_arg(args, int32)));
        replaced = true;
      }
      else if(c == NStr::C_FORMAT_LONG)
      {
        s = s.replace(i - 1, 2, CStr::intToStr(va_arg(args, int64)));
        replaced = true;
      }
      else if(c == NStr::C_FORMAT_HEX_INT)
      {
        s = s.replace(i - 1, 2, CStr::uintToHex(va_arg(args, uint32)));
        replaced = true;
      }
      else if(c == NStr::C_FORMAT_HEX_LONG)
      {
        s = s.replace(i - 1, 2, CStr::uintToHex(va_arg(args, uint64)));
        replaced = true;
      }
      else if(c == NStr::C_FORMAT_DOUBLE_FLOAT)
      {
        s = s.replace(i - 1, 2, CStr::doubleToStr(va_arg(args, double)));
        replaced = true;
      }
      else if(c == NStr::C_FORMAT_POINTER)
      {
        s = s.replace(i - 1, 2, CStr::pointToHex(va_arg(args, void *)));
        replaced = true;
      }
      else if(c == NStr::C_FORMAT_STRING)
      {
        s = s.replace(i - 1, 2, va_arg(args, char *));
        replaced = true;
      }
      else if((c == NStr::C_FORMAT_UNSIGNED) && (i < (s.size() - 1)))
      {
        lastC = c;
        i++;
        c = s[i];

        if((c == NStr::C_FORMAT_BYTE) || (c == NStr::C_FORMAT_SHORT) || (c == NStr::C_FORMAT_INT) || (c == NStr::C_FORMAT_INTEGER))
        {
          s = s.replace(i - 2, 3, CStr::uintToStr(va_arg(args, uint32)));
          replaced = true;
        }
        else if(c == NStr::C_FORMAT_LONG)
        {
          s = s.replace(i - 2, 3, CStr::uintToStr(va_arg(args, uint64)));
          replaced = true;
        }
        else if(c == NStr::C_FORMAT_HEX_INT)
        {
          s = s.replace(i - 2, 3, CStr::uintToHex(va_arg(args, uint32)));
          replaced = true;
        }
        else if(c == NStr::C_FORMAT_HEX_LONG)
        {
          s = s.replace(i - 2, 3, CStr::uintToHex(va_arg(args, uint64)));
          replaced = true;
        }
        else if(c == NStr::C_FORMAT_POINTER)
        {
          s = s.replace(i - 2, 3, CStr::pointToHex(va_arg(args, void *)));
          replaced = true;
        }

        if(replaced)
          i--;
      }

      if(replaced)
        i--;
    }
  }

  va_end(args);
}
//-----------------------------------------------------------------------------
inline CStr::~CStr()
{
}
//-----------------------------------------------------------------------------
inline CStr::operator std::string() const
{
  return s;
}
//-----------------------------------------------------------------------------
inline const std::string &CStr::str() const
{
  return s;
}
//-----------------------------------------------------------------------------
inline const char *CStr::c_str() const
{
  return s.c_str();
}
//-----------------------------------------------------------------------------
inline std::string CStr::intToStr(int64 number)
{
  std::stringstream ss;
  ss << number;
  return ss.str();
}
//-----------------------------------------------------------------------------
inline std::string CStr::uintToStr(uint64 number)
{
  std::stringstream ss;
  ss << number;
  return ss.str();
}
//-----------------------------------------------------------------------------
inline std::string CStr::floatToStr(float number)
{
  std::stringstream ss;
  ss << number;
  return ss.str();
}
//-----------------------------------------------------------------------------
inline std::string CStr::doubleToStr(double number)
{
  std::stringstream ss;
  ss << number;
  return ss.str();
}
//-----------------------------------------------------------------------------
inline std::string CStr::uintToHex(uint64 number)
{
  std::stringstream ss;
  ss << std::hex << NStr::STR_HEX_PREFIX << number << std::dec;
  return ss.str();
}
//-----------------------------------------------------------------------------
inline std::string CStr::pointToHex(const void *pointer)
{
  std::stringstream ss;
  ss << std::hex << pointer << std::dec;
  return ss.str();
}
//-----------------------------------------------------------------------------
inline int64 CStr::strToInt(const std::string &text)
{
  std::istringstream ss(text);
  int64 ret;
  ss >> ret;
  return ret;
}
//-----------------------------------------------------------------------------
inline float CStr::strToFloat(const std::string &text)
{
  std::istringstream ss(text);
  float ret;
  ss >> ret;
  return ret;
}
//-----------------------------------------------------------------------------
inline double CStr::strToDouble(const std::string &text)
{
  std::istringstream ss(text);
  double ret;
  ss >> ret;
  return ret;
}
//-----------------------------------------------------------------------------
inline std::string CStr::replaceAll(const std::string &src, const std::string &before, const std::string &after)
{
  std::string ret = src;
  for(auto pos = 0U; pos = ret.find(before, pos), pos != std::string::npos; pos += after.length())
    ret.replace(pos, before.length(), after);
  return ret;
}
//-----------------------------------------------------------------------------
inline std::string CStr::strToUp(const std::string &text)
{
  std::string ret;
  ret.resize(text.length());
  std::transform(text.begin(), text.end(), ret.begin(), ::toupper);
  return ret;
}
//-----------------------------------------------------------------------------
inline std::string CStr::strToLow(const std::string &text)
{
  std::string ret;
  ret.resize(text.length());
  std::transform(text.begin(), text.end(), ret.begin(), ::tolower);
  return ret;
}
//-----------------------------------------------------------------------------
inline std::string CStr::extPath(const std::string &text)
{ // return dir1/dir2/
  auto found = text.find_last_of(NStr::STR_PATH_SEPARATORS);
  if(found != std::string::npos)
    return text.substr(0, found + 1);
  return text;
}
//-----------------------------------------------------------------------------
inline std::string CStr::extPathFile(const std::string &text)
{ // return dir1/dir2/file
  auto found = text.find_last_of(NStr::STR_EXTENSION_SEPARATOR);
  if(found != std::string::npos)
    return text.substr(0, found);
  return text;
}
//-----------------------------------------------------------------------------
inline std::string CStr::extFile(const std::string &text)
{ // return file.abc
  auto found = text.find_last_of(NStr::STR_PATH_SEPARATORS);
  if(found != std::string::npos)
    return text.substr(found + 1);
  return text;
}
//-----------------------------------------------------------------------------
inline std::string CStr::extFile2(const std::string &text)
{ // return file
  auto found = text.find_last_of(NStr::STR_PATH_SEPARATORS);
  std::string text2 = text;
  if(found != std::string::npos)
    text2 = text.substr(found + 1);
  found = text2.find_last_of(NStr::STR_EXTENSION_SEPARATOR);
  if(found != std::string::npos)
    return text2.substr(0, found);
  return text2;
}
//-----------------------------------------------------------------------------
inline std::string CStr::extExt(const std::string &text)
{ // return .abc
  auto found = text.find_last_of(NStr::STR_EXTENSION_SEPARATOR);
  if(found != std::string::npos)
    return text.substr(found);
  return std::string();
}
//-----------------------------------------------------------------------------
inline std::string CStr::extExt2(const std::string &text)
{ // return abc
  auto found = text.find_last_of(NStr::STR_EXTENSION_SEPARATOR);
  if(found != std::string::npos)
    return text.substr(found + 1);
  return std::string();
}
//-----------------------------------------------------------------------------
inline std::string CStr::exe()
{
  std::string text;
  text.resize(NStr::MAX_PATH_LEN);
#if defined(_WIN32)
  GetModuleFileNameA(NULL, &text[0], NStr::MAX_PATH_LEN);
#elif defined(__linux__)
  readlink(CStr(NStr::STR_UNIX_EXE_PATH, getpid()).c_str(), &text[0], NStr::MAX_PATH_LEN);
#endif
  return text.c_str();
}
//-----------------------------------------------------------------------------
inline std::string CStr::exeFile()
{
  return extFile(exe());
}
//-----------------------------------------------------------------------------
inline std::string CStr::exePath()
{
  return extPath(exe());
}
//-----------------------------------------------------------------------------
inline std::string CStr::getSizes()
{
  return CStr(NStr::STR_TYPE_SIZES,
    sizeof(bool),
    sizeof(char),
    sizeof(unsigned char),
    sizeof(short),
    sizeof(unsigned short),
    sizeof(int),
    sizeof(unsigned int),
    sizeof(long),
    sizeof(unsigned long),
    sizeof(long long),
    sizeof(unsigned long long),
    sizeof(float),
    sizeof(void *),
    sizeof(int8),
    sizeof(uint8),
    sizeof(int16),
    sizeof(uint16),
    sizeof(int32),
    sizeof(uint32),
    sizeof(int64),
    sizeof(uint64));
}
//-----------------------------------------------------------------------------
#endif // STRING_H