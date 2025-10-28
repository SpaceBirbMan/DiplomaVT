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

private:


    EventQueue *eQueuePointer = nullptr;

    EventManager eventManager;

    void dummyFunction() {
        std::cout<< eQueuePointer->logQueue() << std::endl;
    }

};

#endif // APPCORE_H
