#include "appcore.h"
#include "messageprocessor.h"
#include "eventmanager.h"

AppCore::AppCore() : eventManager() {
    eQueuePointer = &(this->eventManager.getQueue());
}
