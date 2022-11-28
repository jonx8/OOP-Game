#include "Message.h"

#include <utility>
Message::Message(std::string text, MSG_TYPE type) : type(type), text(std::move(text))
{
}

std::ostream &operator<<(std::ostream &out, const Message &obj)
{
    switch (obj.type)
    {
    case Message::INFO:
        out << "INFO: ";
        break;
    case Message::ERROR:
        out << "ERROR: ";
        break;
    case Message::GAME_STATUS:
        out << "GAME STATUS: ";
        break;
    default:
        return out;
    }
    out << obj.text;
    return out;
}

int Message::getType() const
{
    return type;
}
