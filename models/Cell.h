#pragma once
#include "../events/Event.h"


class Cell
{
private:
    bool passable;
    bool playerOnCell;
    Event *event;

public:
    Cell();
    bool isPassable() const;
    bool hasPlayer() const;
    Event *getEvent() const;
    void react(Player &);
    void react(Field &field);
    void setEvent(Event *ev);
    void addPlayer();
    void removePlayer();
    void setPassable(bool value);
};
