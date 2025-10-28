#include "eventmanager.h"

// todo: Возможно стоит добалять функции списком а не только по одному

void EventManager::test() {
    // todo: потом
}

void EventManager::sendMessage(AppMessage message) {
    messages.sendMessage(message); //?
}

EventQueue& EventManager::getQueue() { return messages; }
