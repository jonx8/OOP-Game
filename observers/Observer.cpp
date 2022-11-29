#include "Observer.h"

Observer::Observer(const char *name) : name(name) {}

Observer::~Observer() = default;


std::string Observer::getName() const {
    return name;
}