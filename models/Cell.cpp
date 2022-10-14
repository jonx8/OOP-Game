#include "Cell.h"
#include "../events/Event.h"

Cell::Cell() : passable(true), playerOnCell(false), type(Objects::GROUND), event(nullptr) {}
bool Cell::isPassable() const { return passable; }

bool Cell::hasPlayer() const { return playerOnCell; }

void Cell::addPlayer() { playerOnCell = true; }

Event *Cell::getEvent() const { return event; }

Cell::Objects Cell::getType() const { return type; }

void Cell::removePlayer() { playerOnCell = false; };

void Cell::setEvent(Event *ev) { event = ev; }

void Cell::react(Player &player)
{
    if (event)
    {
        event->interact(player);
    }
}

void Cell::react(Field &field)
{
    if (event)
    {
        event->interact(field);
        setEvent(nullptr);
    }
}
void Cell::setPassable(bool value) { passable = value; }

void Cell::setType(Objects value) { type = value; }
