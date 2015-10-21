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
class CFile : public CEngineBase
{
  private:
    SFile file;

  public:
    CFile();
    CFile(CContext *context, const SFile &file);
    ~CFile();

    void read(void *dest, uint32 bytes);
    void write(const void *src, uint32 bytes);
    uint32 tell();
    void seek(int32 pos, NFile::ESeek way);
    uint32 size();
    void close();

    inline const SFile *getFile() const { return &file; }
};
//---------------------------------------------------------------------------
class CFilesystem : public CEngineBase
{
  private:
    std::list<CFile> files;
    std::map<std::string, std::string> searchPathes;

  public:
    CFilesystem();
    CFilesystem(CContext *context);
    ~CFilesystem();

    CFile *open(const SFile &file);

    inline void addSearchPath(const std::string &path) { searchPathes[path] = path; }
    inline uint32 removeSearchPath(const std::string &path) { return searchPathes.erase(path); }
    inline void clearSearchPathes() { searchPathes.clear(); }

    inline uint32 getFilesCount() const { return files.size(); }
    inline CFile *getFile(uint32 id) { if(id > files.size()) return NULL; auto it = files.begin(); std::advance(it, id); return &(*it); }
    std::vector<std::string> getSearchPathes() const;

    std::string getStringList() const;
};
//---------------------------------------------------------------------------
#endif // FILESYSTEM_H
