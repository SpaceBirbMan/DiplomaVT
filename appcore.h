#ifndef APPCORE_H
#define APPCORE_H

#include "eventmanager.h"

class AppCore
{
public:
    AppCore();
private:

    EventQueue *eQueuePointer = nullptr;


    EventManager eventManager = nullptr;

};

#endif // APPCORE_H
