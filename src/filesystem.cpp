//---------------------------------------------------------------------------
#include "filesystem.h"

//---------------------------------------------------------------------------
CFilesystem::CFilesystem() : CEngineBase()
{
  clearSearchPathes();
}
//---------------------------------------------------------------------------
CFilesystem::CFilesystem(CContext *context) : CEngineBase(context)
{
  clearSearchPathes();
}
//---------------------------------------------------------------------------
CFilesystem::~CFilesystem()
{
}
//---------------------------------------------------------------------------
CFile CFilesystem::open(std::string path, NFile::EFileMode fileMode, uint32 *file, bool quietMode)
{
  uint32 index = files.size();
  if(file) *file = index;

  files.push_back(SFile());
  files[index].mode = fileMode;
  files[index].path = path;
  files[index].quiet = quietMode;

  try
  {
    if(files[index].mode == NFile::FILE_READ)
    {
      files[index].prefix = NFile::STR_DEFAULT_SEARCH_PATH;
      for(auto i = searchPathes.cbegin(); i != searchPathes.cend(); i++)
      {
        std::ifstream ifs;
        ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try { ifs.open(*i+path, std::ifstream::binary); }
        catch(std::ifstream::failure) { continue; }
        ifs.close();
        files[index].prefix = *i;
        break;
      }

      files[index].in = new std::ifstream();
      files[index].in->exceptions(std::ifstream::failbit | std::ifstream::badbit);
      try { files[index].in->open(files[index].prefix+path, std::ifstream::binary); }
      catch(std::ifstream::failure)
      {
        close(index + 1, NFile::FILE_ABNORMAL_CLOSE);
        throw CException(NFile::STR_ERROR_UNABLE_OPEN, NException::EO_FILESYSTEM, std::string(), files[index].path);
      }
      return CFile(context, index + 1);
    }
    else if(files[index].mode == NFile::FILE_WRITE)
    {
      files[index].out = new std::ofstream();
      files[index].out->exceptions(std::ofstream::failbit | std::ofstream::badbit);
      try { files[index].out->open(path, std::ofstream::binary); }
      catch(std::ofstream::failure)
      {
        close(index + 1, NFile::FILE_ABNORMAL_CLOSE);
        throw CException(NFile::STR_ERROR_UNABLE_OPEN, NException::EO_FILESYSTEM, std::string(), files[index].path);
      }
      return CFile(context, index + 1);
    }
  }
  catch(CException &e)
  {
    if(!files[index].quiet)
      std::cerr << e.what() << "\n";
    throw e;
  }

  return CFile(context, index + 1);
}
//---------------------------------------------------------------------------
void CFilesystem::read(uint32 file, void *dest, uint32 bytes)
{
  if(files[file - 1].mode == NFile::FILE_READ)
  {
    try { files[file - 1].in->read(reinterpret_cast<char *>(dest), bytes); }
    catch(std::ifstream::failure)
    {
      if(!files[file - 1].quiet)
        std::cerr << CException::warning(NFile::STR_ERROR_READ_BEYOND, NException::EO_FILESYSTEM, std::string(), files[file - 1].path) << std::endl;
      memset(dest, 0, bytes);
      return;
    }
  }
}
//---------------------------------------------------------------------------
void CFilesystem::write(uint32 file, void *src, uint32 bytes)
{
  if(files[file - 1].mode == NFile::FILE_WRITE)
    files[file - 1].out->write(reinterpret_cast<char *>(src), bytes);
}
//---------------------------------------------------------------------------
uint32 CFilesystem::tell(uint32 file)
{
  if(files[file - 1].mode == NFile::FILE_READ)
    return static_cast<uint32>(files[file - 1].in->tellg());
  else if(files[file - 1].mode == NFile::FILE_WRITE)
    return static_cast<uint32>(files[file - 1].out->tellp());

  return 0;
}
//---------------------------------------------------------------------------
void CFilesystem::seek(uint32 file, int pos, NFile::EFileSeek way)
{
  std::ios_base::seekdir way2;
  if(way == NFile::FSEEK_BEG) way2 = std::ios_base::beg;
  else if(way == NFile::FSEEK_CUR) way2 = std::ios_base::cur;
  else if(way == NFile::FSEEK_END) way2 = std::ios_base::end;
  else return;

  if(files[file - 1].mode == NFile::FILE_READ)
    files[file - 1].in->seekg(pos, way2);
  else if(files[file - 1].mode == NFile::FILE_WRITE)
    files[file - 1].out->seekp(pos, way2);
}
//---------------------------------------------------------------------------
uint32 CFilesystem::size(uint32 file)
{
  uint32 pos;
  uint32 size;

  if(files[file - 1].mode == NFile::FILE_READ)
  {
    pos = tell(file);
    seek(file, 0, NFile::FSEEK_END);
    size = tell(file);
    seek(file, pos, NFile::FSEEK_BEG);
    return size;
  }

  return 0;
}
//---------------------------------------------------------------------------
void CFilesystem::close(uint32 file, NFile::EFileMode normalClose)
{
  if(files[file - 1].mode == NFile::FILE_READ)
  {
    if(normalClose == NFile::FILE_NORMAL_CLOSE)
      files[file - 1].in->close();
    delete files[file - 1].in;
  }
  else if(files[file - 1].mode == NFile::FILE_WRITE)
  {
    if(normalClose == NFile::FILE_NORMAL_CLOSE)
      files[file - 1].out->close();
    delete files[file - 1].out;
  }
  files[file - 1].mode = NFile::FILE_INACITVE;
}
//---------------------------------------------------------------------------
std::string CFilesystem::getStringList() const
{
  std::string text = "";

  for(uint32 i = 0; i < files.size(); i++)
    text = text+CStr(NFile::STR_FILES_LIST, i + 1, files[i].path.c_str()).str()+"\n";

  return text;
}
//---------------------------------------------------------------------------
void CFilesystem::addSearchPath(std::string path)
{
  searchPathes.push_back(path);
}
//---------------------------------------------------------------------------
bool CFilesystem::removeSearchPath(std::string path)
{
  for(auto i = searchPathes.begin(); i != searchPathes.end(); i++)
  {
    if(*i == path)
    {
      searchPathes.erase(i);
      return true;
    }
  }

  return false;
}
//---------------------------------------------------------------------------
void CFilesystem::clearSearchPathes()
{
  searchPathes.clear();
  searchPathes.push_back(NFile::STR_DEFAULT_SEARCH_PATH);
}
//---------------------------------------------------------------------------