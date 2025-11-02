#include "cachemanager.h"
#include "shorts.h"
#include "fileinstance.h"

CacheManager::CacheManager(): fileLoader(FileLoader()), fileSaver(FileSaver()) {}

std::unordered_map<std::string, std::any> CacheManager::loadCache() {
    FileInstance instance = this->fileLoader.loadFile("cache.cah");
    if (instance.getFlags().empty()) {
        return cacheMap();
    }
    // ...
    std::unordered_map<std::string, std::any> map = std::any_cast<std::unordered_map<std::string, std::any>>(instance.getData());;
    // ...

    return map;
}

void CacheManager::saveCache(std::unordered_map<std::string, std::any> data) {

}
