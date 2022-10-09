#pragma once
#include "../models/Player.h"

class Field;

class Event
{
public:
    virtual void interact(Player&) = 0;
    virtual void interact(Field& field) = 0;
    virtual ~Event() = 0;
};
