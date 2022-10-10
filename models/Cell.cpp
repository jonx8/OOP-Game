#include "Cell.h"
#include "../events/Event.h"

Cell::Cell() : passable(true), playerOnCell(false), event(nullptr){};

bool Cell::isPassable() const { return passable; };

bool Cell::hasPlayer() const { return playerOnCell; }

void Cell::addPlayer() { playerOnCell = true; }

Event *Cell::getEvent() const { return event; }

void Cell::removePlayer() { playerOnCell = false; };

void Cell::setEvent(Event *ev) { event = ev; }

void Cell::react(Player &player)
{
    if (event)
    {
        event->interact(player);
        //setEvent(nullptr);
    }
}

void Cell::react(Field& field)
{
    if (event)
    {
        event->interact(field);
        setEvent(nullptr);
    }
}
void Cell::setPassable(bool value) { passable = value; }