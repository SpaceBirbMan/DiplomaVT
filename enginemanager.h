#ifndef ENGINEMANAGER_H
#define ENGINEMANAGER_H

#include <vector>
#include <functional>
#include "appcore.h"
#include "unordered_map"

class EngineManager
{
public:
    EngineManager(AppCore* acptr);

    void setActiveEngine(std::string path_to_file);

private:

    AppCore* acptr;

    std::unordered_map<std::string, std::string> enginesRegistry {};

    std::function<void()> *currentEngineStarterPtr; // указывает на функцию входа в код движка (main в движке)

    void setMainFunctuionPtr(std::function<void()>* fn) {
        this->currentEngineStarterPtr = fn;
    }

};

#endif // ENGINEMANAGER_H
