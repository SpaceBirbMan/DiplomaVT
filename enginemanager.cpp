#include "enginemanager.h"

EngineManager::EngineManager(AppCore* acptr) {
    this->acptr = acptr;

    acptr->getEventManager().subscribe("plugin_main_respond", &EngineManager::setMainFunctuionPtr, this);
}

void EngineManager::setActiveEngine(std::string path_to_file) {
    for (const auto& [path, name] : enginesRegistry) {
        if (path == path_to_file) {
            acptr->getEventManager().sendMessage(AppMessage("EngineManager", "plugin_main_request", path));
        }
    }
}
