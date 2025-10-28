#include "messageprocessor.h"
#include "eventqueue.h"
#include <iostream>

void MessageProcessor::process() {
    std::unique_lock<std::mutex> lock(mut);

    while (!stopFlag) { // выяснить, почему метод работает на while
        // ждём сигнал либо новые данные
        cv.wait(lock, [&]() {
            return stopFlag || !qPtr.is_empty();
        });

        if (stopFlag) break;

        // обрабатываем все сообщения, пока они есть
        while (!qPtr.is_empty()) {
            auto msg = qPtr.pollMessage();
            lock.unlock(); // выяснить, нахрена тут мьютекс отпускать
            for (const auto& subscriber_pair : subsTable) {
                const std::string& key = subscriber_pair.first;
                const auto& callback = subscriber_pair.second;
                if (msg.getMessage() == key) {
                    callback(msg.getData());
                }
            }
            std::cout << "Обработано" << std::endl;
            lock.lock();
        }
    }
}
