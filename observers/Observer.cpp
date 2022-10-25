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

void Observer::setName(const char *name) { this->name = name; }
std::string Observer::getName() const { return name; }