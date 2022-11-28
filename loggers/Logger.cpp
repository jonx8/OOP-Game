#include "Logger.h"
Logger::~Logger() = default;

void Logger::setLevel(Message::MSG_TYPE level)
{
    log_level = level;
}
