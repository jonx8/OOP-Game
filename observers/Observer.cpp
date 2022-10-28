#include "Observer.h"
#include <iostream>
Observer::Observer(const char *name) : name(name) {}

Observer::~Observer() {}



std::string Observer::getName() const
{
    return name;
}