#include "datamanager.h"
#include "filetypes.h"
#include "shorts.h"

DataManager::DataManager(AppCore* acptr) {
    this->appCorePtr = acptr;

    acptr->getEventManager().subscribe("initialize", &DataManager::initialize, this);

    acptr->getEventManager().subscribe("ask_cache", &DataManager::tryToLoadCache, this);

    acptr->getEventManager().subscribe("engine_resolving_request", &DataManager::resolveFuncTable, this);

    acptr->getEventManager().subscribe("model_markdown_request", &DataManager::loadModel, this);

    acptr->getEventManager().subscribe("sub_to_cache", &CacheManager::cacheSubscribe, &this->cacheManager);

    acptr->getEventManager().subscribe("save", &DataManager::saveFiles, this);
    acptr->getEventManager().subscribe("new", &DataManager::dummy2, this);

    acptr->getEventManager().subscribe("save_cache", &CacheManager::pickCache, &this->cacheManager);

}

void DataManager::initialize() {


    appCorePtr->getEventManager().sendMessage(AppMessage("dataManager", "dm_ready", 0));

    //appCorePtr->getEventManager().sendMessage(AppMessage(name, "set_data", &cache));
}

void DataManager::tryToLoadCache() {
    // cacheManager.loadCache();
    // if () {
    //     appCorePtr->getEventManager().sendMessage(AppMessage(name, "cache_err", 0));
    //     return;
    // }
    // appCorePtr->getEventManager().sendMessage(AppMessage(name, "cache_ok", 0));
}

void DataManager::resolveFuncTable(std::string path) {
    funcMap map {};
    DynamicLibrary lib = DynamicLibrary(path);
    // логика запихивания методов в карту

    appCorePtr->getEventManager().sendMessage(AppMessage(name, "engine_resolving_respond", map));
}

void DataManager::loadModel(std::vector<std::string> exts) {

    // верификация...

    // FileInstance instance = FileInstance();
    // for (std::string ext : exts) {
    //     instance = this->modelManager.getLoader().load(""+ext);
    // }

    //appCorePtr->getEventManager().sendMessage(AppMessage(name, "model_markdown_respond", instance.getData()));
}

void DataManager::saveFiles(std::any data) {

}
