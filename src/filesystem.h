//---------------------------------------------------------------------------
#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>

#include "exceptions.h"
#include "headers/fileTypes.h"

//---------------------------------------------------------------------------
class CFile;
//---------------------------------------------------------------------------
class CFilesystem : public CEngineBase
{
  private:
  std::vector<SFile> files;
  std::vector<std::string> searchPathes;

  public:
  CFilesystem();
  CFilesystem(CContext *context);
  ~CFilesystem();

  CFile open(std::string path, NFile::EFileMode fileMode, uint32 *file = NULL, bool quietMode = false);
  void read(uint32 file, void *dest, uint32 bytes);
  void write(uint32 file, void *src, uint32 bytes);
  uint32 tell(uint32 file);
  void seek(uint32 file, int pos, NFile::EFileSeek way);
  uint32 size(uint32 file);
  void close(uint32 file, NFile::EFileMode normalClose = NFile::FILE_NORMAL_CLOSE);

  void addSearchPath(std::string path);
  bool removeSearchPath(std::string path);
  void clearSearchPathes();

  inline uint32 getFilesCount() const { return files.size(); }
  inline const SFile *getFile(uint32 file) const { if((!file) || (file > files.size())) return NULL; return &files[file - 1]; }
  inline const std::vector<std::string> *getSearchPathes() const { return &searchPathes; }

  std::string getStringList() const;
};
//---------------------------------------------------------------------------
class CFile : public CEngineBase
{
  private:
  uint32 file;

  public:
  inline CFile() : CEngineBase(), file(0) {}
  inline CFile(CContext *context) : CEngineBase(context), file(0) {}
  inline CFile(CContext *context, uint32 file) : CEngineBase(context), file(file) {}
  inline ~CFile() {}

  inline void read(void *dest, uint32 bytes) { context->getFilesystem()->read(file, dest, bytes); }
  inline void write(void *src, uint32 bytes) { context->getFilesystem()->write(file, src, bytes); }
  inline uint32 tell() { return context->getFilesystem()->tell(file); }
  inline void seek(int pos, NFile::EFileSeek way) { context->getFilesystem()->seek(file, pos, way); }
  inline uint32 size() { return context->getFilesystem()->size(file); }
  inline void close(NFile::EFileMode normalClose = NFile::FILE_NORMAL_CLOSE) { context->getFilesystem()->close(file, normalClose); }

  inline uint32 getFileID() const { return file; }
  inline const SFile *getFile() const { return context->getFilesystem()->getFile(file); }
};
//---------------------------------------------------------------------------
#endif // FILESYSTEM_H