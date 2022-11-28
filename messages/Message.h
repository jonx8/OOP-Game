#pragma once
#include <iostream>
#include <string>

class Message
{
public:
    enum MSG_TYPE
    {
        ERROR,
        GAME_STATUS,
        INFO,
    };
    Message(std::string text, MSG_TYPE type);
    friend std::ostream &operator<<(std::ostream &out, const Message &obj);
    [[nodiscard]] int getType() const;

protected:
    MSG_TYPE type;
    std::string text;
};
