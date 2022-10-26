#include "ConsoleLogger.h"
#include <iostream>

ConsoleLogger::ConsoleLogger()
{
}

ConsoleLogger::~ConsoleLogger()
{
}

void ConsoleLogger::log(const Message& msg)
{
    std::cout << msg << std::endl;
}