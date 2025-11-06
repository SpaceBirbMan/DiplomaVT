
#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "appcore.h"
#include "modelmanager.h"
#include "cachemanager.h"
#include "crashreportmanager.h"
#include "dynamiclibrary.h"
#include <any>

class DataManager
{
public:
    DataManager(AppCore* acptr);

    void initialize();

    void dummy(int a) { std::cout << "a1" << std::endl;}
    void dummy2() { std::cout << "a2" << std::endl;}

private:

    std::string name = "DataManager"; // имя модуля, используется в методах с описанием отправителя/получаетля

    AppCore* appCorePtr = nullptr; // ядро

    /// Внутренние модули модуля
    ModelManager* modelManagerPtr;
    CacheManager* cacheManagerPtr;
    CrashReportManager* crashReportManagerPtr;

    void tryToLoadCache();

    void resolveFuncTable(std::string path);

};

#endif // DATAMANAGER_H
