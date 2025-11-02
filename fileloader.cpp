#include "fileloader.h"
#include "fstream"
#include "fileinstance.h"
#include <iostream>

FileLoader::FileLoader() {}

FileInstance FileLoader::loadFile(std::string path) {

    std::ifstream file(path, std::ios::binary);

    if (!file) {
        std::cout << "File does not exists" << std::endl;
        return FileInstance();
    }

    FileInstance instance;

    file.read(reinterpret_cast<char*>(&instance), sizeof(instance));

    return instance;
}
