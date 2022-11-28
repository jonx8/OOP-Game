#include "ConsoleLogger.h"
#include <iostream>

ConsoleLogger::ConsoleLogger()
{
    std::cout << "ConsoleLogger has been started" << std::endl;
}

void ConsoleLogger::log(const Message &msg)
{
    if (log_level >= msg.getType())
    {
        std::cout << msg << std::endl;
    }
}