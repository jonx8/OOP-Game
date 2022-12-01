#include "Cell.h"
#include "../events/Event.h"

Cell::Cell() : playerOnCell(false), type(Objects::GROUND), event(nullptr) {}

bool Cell::isPassable() const { return type != Objects::WALL; }

bool Cell::hasPlayer() const { return playerOnCell; }

void Cell::addPlayer() { playerOnCell = true; }

Event *Cell::getEvent() const { return event; }

Cell::Objects Cell::getType() const { return type; }

void Cell::removePlayer() { playerOnCell = false; }

void Cell::setEvent(Event *ev) { event = ev; }

void Cell::react(Player &player, Field &field) {
    if (event) {
        Event *oldEvent = event;
        event->interact(player, field);
        if (oldEvent == event) {
            event = nullptr;
        }
        delete oldEvent;
    }
}

void Cell::setType(Objects value) { type = value; }


