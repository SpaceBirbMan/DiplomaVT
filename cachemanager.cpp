#include "cachemanager.h"
#include "shorts.h"


CacheManager::CacheManager(): fileLoader(FileLoader()), fileSaver(FileSaver()) {}

void CacheManager::loadCache() {

    try {
        this->cache = fileLoader.loadJson(CACHE_FILE_PATH);
    } catch (...) {}

}

void CacheManager::saveCache() {

    try {
        fileSaver.saveJson(CACHE_FILE_PATH, this->cache);
    } catch (...) {}

}

void CacheManager::writeCache(nlohmann::json payload) {

    try {
        this->cache.push_back(payload);
    } catch (...) {}

}
