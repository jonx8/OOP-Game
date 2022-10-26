#include "Observer.h"
#include <iostream>
Observer::Observer(const char *name) : name(name) {}
Observer::~Observer() {}
void Observer::update(const Message &msg)
{
    for (auto i : logList)
    {
        i->log(msg);
    }
}

void Observer::addLogger(Logger *logger)
{
    logList.emplace_back(logger);
}

void Observer::removeLogger(Logger *logger)
{
    for (size_t i = 0; i < logList.size(); i++)
    {
        if (logList[i] == logger)
        {
            logList.erase(logList.begin() + i);
            break;
        }
    }
}

std::string Observer::getName() const
{
    return name;
}