#include "eventmanager.h"


EventManager::eventmanager()
{

}

void EventManager::subscribe(const CallbackEntry callback) {
    callbacks.push_back(callback);
}

void EventManager::unsubscribe(const CallbackEntry callback) {
    for (CallbackEntry cb : callbacks) { // алгоритм - шляпа
        if (callback == cb) {
            callbacks.erase(std::remove(callbacks.begin(), callbacks.end(), cb), callbacks.end()); // без итератора не хавает
            return;
        }
    }
}

void EventManager::notifyModules() {
    for (CallbackEntry cb : callbacks) {
        cb.cb; // вызов коллбэк-функции
    }
}

void EventManager::test() {
    // todo: потом
}

void EventManager::sendMessage(AppMessage message) {
    messages.sendMessage(message);
}

EventQueue EventManager::getQueue() { return messages; }
