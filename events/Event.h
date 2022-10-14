#pragma once

typedef unsigned int uint;
class Player;
class Field;

class Event
{
public:
    virtual void interact(Player &player) = 0;
    virtual void interact(Field &field) = 0;
    virtual Event *clone() const = 0;
    virtual ~Event() = 0;
};
