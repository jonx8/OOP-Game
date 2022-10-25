#pragma once
#include "../messages/Message.h"

class Logger
{
public:
    enum LEVELS
    {
        INFO,
        GAME_STATUS,
        ERROR,
    };
    virtual ~Logger() = 0;
    virtual void log(const Message &msg) = 0;
    void setLevel(LEVELS LOG_LEVEL);

protected:
    LEVELS LOG_LEVEL;
};
