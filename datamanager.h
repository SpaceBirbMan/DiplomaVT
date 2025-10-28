
#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "appcore.h"
#include "modelmanager.h"
#include "cachemanager.h"
#include "crashreportmanager.h"

class DataManager
{
public:
    DataManager(AppCore* acptr);

    void dummy() { std::cout << "a1" << std::endl;}
    void dummy2() { std::cout << "a2" << std::endl;}

private:

    AppCore* appCorePtr = nullptr;
    ModelManager* modelManagerPtr;
    CacheManager* CacheManagerPtr;
    CrashReportManager* crashReportManagerPtr;

};

#endif // DATAMANAGER_H
