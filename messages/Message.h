#pragma once
#include <string>

class Message
{
protected:
    std::string text;
public:
    Message(char const* text);
    ~Message();
    std::string getText() const;
};


