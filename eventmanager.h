#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "eventqueue.h"
#include <vector>
#include <functional>

using namespace std;

// template <typename... Args>
// using Callback = function<void(Args... args)>;

struct CallbackEntry {
    int id;
    std::shared_ptr<CallbackEntry> cb;

    bool operator==(const CallbackEntry& other) const {
        return id == other.id;
    }
};

class EventManager // занимается рассылкой и обработкой сообщений, создаёт очередь сообщений, даёт на неё ссылку
        // сюда же можно свалить задачу по загрузке данных в окна, программа запустилась - постепенно закидываются данные в окна
{
public:
    EventManager();

    void subscribe(const CallbackEntry callback);

    void unsubscribe(const CallbackEntry callback);

    EventQueue getQueue();

    void sendMessage(AppMessage message);

private:

    std::vector<CallbackEntry> callbacks; // хранит ссылки на вызываемые функции модулей
    int nextId = 0;
    EventQueue messages = EventQueue{}; // хранит сообщения

    void notifyModules();

    // тестирует всю систему на предмет ошибок, тесты поверхностные, глубже в модуле, выдающем ошибку
    void test();

};

#endif // EVENTMANAGER_H
