#include "Logger.h"
Logger::Logger() {}
Logger::~Logger() {}

void Logger::setLevel(Message::MSG_TYPE level)
{
    log_level = level;
}
