#ifndef APPMESSAGE_H
#define APPMESSAGE_H

using messageType = std::string;
using senderType = std::string;

class AppMessage
{
public:
    AppMessage(senderType sender, messageType message) {
        this->message = message;
        this->sender = sender;
    }

    messageType getMessage() {
        return this->message;
    }

    senderType getSender() {
        return this->sender;
    }

    std::string toString() {
        // return std::to_string(sender) + " " + std::to_string(message);
        return sender + " " + message;
    }

private:
    senderType sender; //мб стоит использовать что-то полегче, чем строки, если надо, юзать псевдонимы
    messageType message;
};

#endif // APPMESSAGE_H
