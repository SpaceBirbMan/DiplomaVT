#include "enginemanager.h"

EngineManager::EngineManager(AppCore* acptr) {
    this->acptr = acptr;

    /*
     * Первый запрос на инициализацию требует ответ о готвонсти, затем
     * публикуется таблица данных из кеша, которую нужно "распарсить"
     * в конце инициализации таблица удаляется из оперативной памяти
     */

    // todo: А если данных в таблице инициализации будет очень много, насколько целесообразно копирование?

    // ответ на инициализацию
    acptr->getEventManager().subscribe("initialize", &EngineManager::initialize, this);
    // ответ на возврат ссылок плагина
    acptr->getEventManager().subscribe("engine_resolving_respond", &EngineManager::setActiveEngine, this);
    // ответ на получение кеша
    acptr->getEventManager().subscribe("set_data", &EngineManager::initializeCache, this);
    acptr->getEventManager().subscribe("general_init_ok", &EngineManager::setActiveEngine, this);
}


void EngineManager::setFuncs(funcMap map) {
    // todd: верефикация таблицы (maybe)
    this->currentEngineFunctions = map;
}

void EngineManager::initializeCache(cacheMap map) {
    // сначала надо взять словарь от своего модуля, потом
    // в нём перебирать переменные vvvv
    for (auto pair : map) {
        // скорее всего придётся руками городить рефлексию и юзать макросы
    }
}

void EngineManager::initialize() {
    acptr->getEventManager().sendMessage(AppMessage(name, "init_started", 0));
}

void EngineManager::setActiveEngine(std::string ename) {
    if (!enginesRegistry.empty()) {
        if (ename == "") {
            // резолв первой строки словаря
                auto pair = enginesRegistry.begin();
                acptr->getEventManager().sendMessage(AppMessage(name, "engine_resolving_request", pair->second));

        } else {
            // резолв по имени
            acptr->getEventManager().sendMessage(AppMessage(name, "engine_resolving_request", enginesRegistry.find(ename))); // возможна ошибка - направильный доступ к элементу
        }
    } else {
        // уведомление об ошибке
        acptr->getEventManager().sendMessage(AppMessage(name, "error", "Данные об ошибке"));
    }

}
