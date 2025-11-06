#include "datamanager.h"
#include "filetypes.h"
#include "shorts.h"

DataManager::DataManager(AppCore* acptr) {
    this->appCorePtr = acptr;

    acptr->getEventManager().subscribe("initialize", &DataManager::initialize, this);

    acptr->getEventManager().subscribe("ask_cache", &DataManager::tryToLoadCache, this);

    acptr->getEventManager().subscribe("engine_resolving_request", &DataManager::resolveFuncTable, this);

    acptr->getEventManager().subscribe("save", &DataManager::dummy, this);
    acptr->getEventManager().subscribe("new", &DataManager::dummy2, this);
}

void DataManager::initialize() {

    std::unordered_map<std::string, std::any> map = this->cacheManagerPtr->loadCache();
    // раздача данных - сообщение set_data (broadcast)
    appCorePtr->getEventManager().sendMessage(AppMessage("dataManager", "dm_ready", 0));
}

void DataManager::tryToLoadCache() {
    cacheMap map = cacheManagerPtr->loadCache();
    if (map.empty()) {
        appCorePtr->getEventManager().sendMessage(AppMessage(name, "cache_err", 0));
        return;
    }
    appCorePtr->getEventManager().sendMessage(AppMessage(name, "cache_ok", 0));
}

void DataManager::resolveFuncTable(std::string path) {
    funcMap map {};
    DynamicLibrary lib = DynamicLibrary(path);
    // логика запихивания методов в карту

    appCorePtr->getEventManager().sendMessage(AppMessage(name, "engine_resolving_respond", map));
}
