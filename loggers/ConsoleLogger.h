#include "Logger.h"


class ConsoleLogger : public Logger
{
public:
    ConsoleLogger();
    ~ConsoleLogger() = default;
    void log(const Message &msg) override;
};
