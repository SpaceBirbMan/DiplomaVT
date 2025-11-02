#include "datamanager.h"
#include "filetypes.h"
#include "shorts.h"

DataManager::DataManager(AppCore* acptr) {
    this->appCorePtr = acptr;

    acptr->getEventManager().subscribe("initialize", &DataManager::initialize, this);

    acptr->getEventManager().subscribe("ask_cache", &DataManager::tryToLoadCache, this);

    acptr->getEventManager().subscribe("save", &DataManager::dummy, this);
    acptr->getEventManager().subscribe("new", &DataManager::dummy2, this);
    acptr->getEventManager().subscribe("plugin_main_request", &DataManager::pluginMainRequest, this);
}

void DataManager::initialize() {

    std::unordered_map<std::string, std::any> map = this->cacheManagerPtr->loadCache();



    appCorePtr->getEventManager().sendMessage(AppMessage("dataManager", "dm_ready", 0));
}

void DataManager::pluginMainRequest(std::string path) {
    auto mainptr = 0;
    appCorePtr->getEventManager().sendMessage(AppMessage("dataManager", "plugin_main_respond", mainptr));
}

void DataManager::tryToLoadCache() {
    cacheMap map = cacheManagerPtr->loadCache();
    if (map.empty()) {
        appCorePtr->getEventManager().sendMessage(AppMessage(name, "cache_err", 0));
        return;
    }
    appCorePtr->getEventManager().sendMessage(AppMessage(name, "cache_ok", 0));
}
