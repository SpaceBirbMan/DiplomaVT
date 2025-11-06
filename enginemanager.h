#ifndef ENGINEMANAGER_H
#define ENGINEMANAGER_H

#include <vector>
#include "appcore.h"
#include "unordered_map"
#include "shorts.h"

class EngineManager
{
public:
    EngineManager(AppCore* acptr);



private:

    std::string name = "EngineManager";

    AppCore* acptr;

    std::unordered_map<std::string, std::string> enginesRegistry {}; // название | путь

    funcMap currentEngineFunctions; // указывает на функцию входа в код движка (main в движке)

    void initialize();

    void initializeCache(cacheMap map);

    void funcsTableResolvingRequest();

    void setActiveEngine(std::string ename);

    void setFuncs(funcMap map);

};

#endif // ENGINEMANAGER_H
