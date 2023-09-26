#pragma once

#include "../messages/Message.h"

class Logger {
protected:
    Message::MSG_TYPE log_level;

public:
    virtual ~Logger() = 0;

    virtual void log(const Message &msg) = 0;

    void setLevel(Message::MSG_TYPE log_level);
};
