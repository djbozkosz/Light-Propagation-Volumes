//---------------------------------------------------------------------------
#include "filesystem.h"

//---------------------------------------------------------------------------
CFile::CFile() : CEngineBase()
{
}
//---------------------------------------------------------------------------
CFile::CFile(CContext *context, const SFile &file) : CEngineBase(context), file(file)
{
}
//---------------------------------------------------------------------------
CFile::~CFile()
{
}
//---------------------------------------------------------------------------
void CFile::read(void *dest, uint32 bytes)
{
  if(file.mode == NFile::MODE_READ)
  {
    try { file.in->read(reinterpret_cast<char *>(dest), bytes); }
    catch(std::ifstream::failure)
    {
      memset(dest, 0, bytes);
      return;
    }
  }
}
//---------------------------------------------------------------------------
void CFile::write(const void *src, uint32 bytes)
{
  if(file.mode == NFile::MODE_WRITE)
    file.out->write(reinterpret_cast<const char *>(src), bytes);
}
//---------------------------------------------------------------------------
uint32 CFile::tell()
{
  if(file.mode == NFile::MODE_READ)
    return static_cast<uint32>(file.in->tellg());
  else if(file.mode == NFile::MODE_WRITE)
    return static_cast<uint32>(file.out->tellp());

  return 0;
}
//---------------------------------------------------------------------------
void CFile::seek(int32 pos, NFile::ESeek way)
{
  std::ios_base::seekdir way2;

  if(way == NFile::FSEEK_BEG)
    way2 = std::ios_base::beg;
  else if(way == NFile::FSEEK_CUR)
    way2 = std::ios_base::cur;
  else if(way == NFile::FSEEK_END)
    way2 = std::ios_base::end;
  else
    return;

  if(file.mode == NFile::MODE_READ)
    file.in->seekg(pos, way2);
  else if(file.mode == NFile::MODE_WRITE)
    file.out->seekp(pos, way2);
}
//---------------------------------------------------------------------------
uint32 CFile::size()
{
  uint32 pos;
  uint32 size;

  if(file.mode != NFile::MODE_READ)
    return 0;

  pos = tell();
  seek(0, NFile::FSEEK_END);
  size = tell();
  seek(pos, NFile::FSEEK_BEG);

  return size;
}
//---------------------------------------------------------------------------
void CFile::close()
{
  if(file.mode == NFile::MODE_READ)
  {
    file.in->close();
    delete file.in;
  }
  else if(file.mode == NFile::MODE_WRITE)
  {
    file.out->close();
    delete file.out;
  }
  file.mode = NFile::MODE_CLOSE;
}
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
CFile *CFilesystem::open(const SFile &file)
{
  SFile f(file);
  f.id = files.size();
  bool opened = false;

  if(f.mode == NFile::MODE_READ)
  {
    for(auto i = searchPathes.cbegin(); i != searchPathes.cend(); i++)
    {
      f.in = new std::ifstream();
      f.in->exceptions(std::ifstream::failbit | std::ifstream::badbit);

      try { f.in->open(i->first+f.path, std::ifstream::binary); }
      catch(std::ifstream::failure) { delete f.in; continue; }

      opened = true;
      f.prefix = i->first;

      break;
    }
  }
  else if(f.mode == NFile::MODE_WRITE)
  {
    for(auto i = searchPathes.cbegin(); i != searchPathes.cend(); i++)
    {
      f.out = new std::ofstream();
      f.out->exceptions(std::ofstream::failbit | std::ofstream::badbit);

      try { f.out->open(i->first+f.path, std::ofstream::binary); }
      catch(std::ofstream::failure) { delete f.out; continue; }

      opened = true;
      f.prefix = i->first;

      break;
    }
  }

  if(!opened)
  {
    context->error(CStr(NFile::STR_ERROR_UNABLE_OPEN, f.path.c_str()));
    return NULL;
  }

  files.push_back(CFile(context, f));

  return &files.back();
}
//---------------------------------------------------------------------------
inline std::vector<std::string> CFilesystem::getSearchPathes() const
{
  std::vector<std::string> keys;

  for(auto it = searchPathes.cbegin(); it != searchPathes.cend(); it++)
    keys.push_back(it->first);

  return keys;
}
//---------------------------------------------------------------------------
std::string CFilesystem::getStringList() const
{
  std::string text = "";

  uint32 i = 0;
  for(auto it = files.cbegin(); it != files.cend(); it++, i++)
    text = text+CStr(NFile::STR_FILES_LIST, i, it->getFile()->path.c_str()).str()+"\n";

  return text;
}
//---------------------------------------------------------------------------
