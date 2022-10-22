#pragma once

typedef unsigned int uint;
class Player;
class Field;

class Event
{
public:
    virtual void interact(Player &player, Field &field) = 0;
    virtual Event *clone() const = 0;
    virtual ~Event() = 0;
};
