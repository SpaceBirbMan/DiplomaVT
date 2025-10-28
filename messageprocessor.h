#ifndef MESSAGEPROCESSOR_H
#define MESSAGEPROCESSOR_H

#include <thread>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <unordered_map>
#include <any>
#include <functional>

class EventQueue; // решение циклической зависимости

class MessageProcessor
{
public:
    explicit MessageProcessor(EventQueue& q, std::unordered_map<std::string, std::function<void(const std::any&)>>& s)
        :qPtr(q), stopFlag(false), subsTable(s)
    {
        proc_thread = std::thread(&MessageProcessor::process, this);
    }

    ~MessageProcessor() {
        {
            std::lock_guard<std::mutex> lock(mut);
            stopFlag = true;
        }
        cv.notify_one();
        if (proc_thread.joinable())
            proc_thread.join();
    }

    // вызывать при добавлении сообщения
    void notify() {
        cv.notify_one();
    }

private:
    std::thread proc_thread;
    std::mutex mut;
    std::condition_variable cv;
    std::atomic<bool> stopFlag;
    EventQueue& qPtr;
    std::unordered_map<std::string, std::function<void(const std::any&)>>& subsTable;

    void process();

    void handleMessage() {
        // обработка сообщения
    }
};

#endif // MESSAGEPROCESSOR_H
