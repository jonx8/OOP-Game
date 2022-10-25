#include "Logger.h"

Logger::~Logger() {}

void Logger::setLevel(LEVELS level)
{
    LOG_LEVEL = level;
}
