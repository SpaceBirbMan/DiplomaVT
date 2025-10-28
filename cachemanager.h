#ifndef CACHEMANAGER_H
#define CACHEMANAGER_H

#include "filesaver.h"
#include "fileloader.h"

class CacheManager
{
public:
    CacheManager();

    FileLoader fileLoader;
    FileSaver fileSaver;

private:

};

#endif // CACHEMANAGER_H
