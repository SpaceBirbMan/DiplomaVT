#ifndef FILELOADER_H
#define FILELOADER_H

#include "fileinstance.h"
#include <string>

class FileLoader
{
public:
    FileLoader();

    FileInstance loadFile(std::string path);
};

#endif // FILELOADER_H
