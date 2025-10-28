#ifndef APPMESSAGE_H
#define APPMESSAGE_H

#include <any>

using messageType = std::string;
using senderType = std::string;

class AppMessage
{
public:
    AppMessage(senderType sender, messageType message, std::any data) {
        this->message = message;
        this->sender = sender;
        this->data = data;
    }

    messageType getMessage() {
        return this->message;
    }

    senderType getSender() {
        return this->sender;
    }

    std::any getData() {
        return this->data;
    }

    std::string toString() {
        // return std::to_string(sender) + " " + std::to_string(message);
        return sender + " " + message;
    }

private:
    senderType sender; //мб стоит использовать что-то полегче, чем строки, если надо, юзать псевдонимы (возможны проблемы с безопасностью)
    messageType message;
    std::any data;
};

#endif // APPMESSAGE_H
