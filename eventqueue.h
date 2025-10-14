#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include <queue> // мб стоит юзать журнал, аки в apache kafka
#include <map>
#include <QString>
#include "appmessage.h"

using namespace std;

class EventQueue
{
public:

    EventQueue() = default;

    std::string logQueue() {
        std::string str = "";
        for (AppMessage am : eventQueue) {
            str.append(am.toString()+'\n');
        }
        return str;
    } // выводит всю очередь, полезно для определния, что там есть

    void sendMessage(const AppMessage message) {
        eventQueue.push_back(message);
        // оповещение?
    } // отправить сообщение в очередь

    AppMessage pollMessage(/*AppMessage message*/) {
        eventQueue.pop_front();
        AppMessage res = eventQueue.front();
        return res;
    } // достать сообщение из очереди

    void clearQueue() {
        eventQueue.empty();
    }


private:

    deque<AppMessage> eventQueue = deque<AppMessage>{}; // сюда попадают сообщения из блоков
    //todo: Есть подозрения, что у сообщений будет приоретизация, для этого нужно будет юзать дерево, как минимум

};

#endif // EVENTQUEUE_H
