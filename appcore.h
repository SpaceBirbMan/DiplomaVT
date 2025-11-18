#ifndef APPCORE_H
#define APPCORE_H

#include "eventmanager.h"
#include <iostream>

class AppCore
{
public:
    AppCore();

    EventManager& getEventManager() {
        return eventManager;
    }

    // вынести subscribe, send и прочее

private:

    std::string name = "Core";

    EventQueue *eQueuePointer = nullptr;

    EventManager eventManager;

    void dummyFunction() {
        std::cout<< eQueuePointer->logQueue() << std::endl;
    }

    void startInitialization();
    void discardStartUp();

    void askToReady() {
        eventManager.sendMessage(AppMessage(name, "ask_cache", 0));
    }

};

#endif // APPCORE_H
