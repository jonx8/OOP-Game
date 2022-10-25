#include "Message.h"

Message::Message(const char* text) : text(text)
{
}

Message::~Message()
{
}

std::string Message::getText() const
{
    return text;
}
