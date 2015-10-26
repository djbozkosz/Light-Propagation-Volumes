//---------------------------------------------------------------------------
#ifndef FILETYPES_H
#define FILETYPES_H

#include <string>
#include <fstream>
#include <vector>
#include <memory>

#include "types.h"

//---------------------------------------------------------------------------
namespace NFile
{
  static const uint8 SIGNATURE_LENGTH = 3;
  static const uint8 SIGNATURE_LENGTH_LONG = 4;

  static const uint32 SEARCH_PATHES_COUNT = 5;

  static const char STR_DATA_MAPS[] = "maps/";
  static const char STR_DATA_MODELS[] = "models/";
  static const char STR_DATA_SHADERS[] = "shaders/";
  static const char STR_DATA_SETTINGS[] = "settings.ini";

  static const char STR_ERROR_UNABLE_OPEN[] = "Unable to open file: \"%s\"";
  static const char STR_ERROR_READ_BEYOND[] = "Read beyond end of file";

  static const char STR_FILES_LIST[] = "%ud, %s";

  static const char *const STR_SEARCH_PATHES[] = { "", "bin/", "data/", "../bin/", "../data/" };

  enum EMode
  {
    MODE_INACITVE = 0,
    MODE_READ,
    MODE_WRITE,
    MODE_CLOSE
  };

  enum ESeek
  {
    FSEEK_BEG = 0,
    FSEEK_CUR,
    FSEEK_END
  };
}
//---------------------------------------------------------------------------
struct SFile
{
  NFile::EMode mode;
  int32 id;
  std::string prefix;
  std::string path;
  std::ifstream *in;
  std::ofstream *out;

  inline SFile() : mode(NFile::MODE_INACITVE), id(-1), in(NULL), out(NULL) {}
  inline SFile(const std::string &path, NFile::EMode mode = NFile::MODE_READ) : mode(mode), id(-1), path(path), in(NULL), out(NULL) {}
};
//---------------------------------------------------------------------------
#endif // FILETYPES_H