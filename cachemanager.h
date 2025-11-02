#ifndef CACHEMANAGER_H
#define CACHEMANAGER_H

#include "filesaver.h"
#include "fileloader.h"
#include <any>
#include <unordered_map>


class CacheManager
{
public:
    CacheManager();

    FileLoader fileLoader;
    FileSaver fileSaver;

    std::unordered_map<std::string, std::any> loadCache();

    void saveCache(std::unordered_map<std::string, std::any> data);

private:

};

#endif // CACHEMANAGER_H
