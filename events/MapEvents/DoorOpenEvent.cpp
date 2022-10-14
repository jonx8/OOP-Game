#include "DoorOpenEvent.h"

DoorOpenEvent::DoorOpenEvent() {}

DoorOpenEvent::~DoorOpenEvent() {}

void DoorOpenEvent::cellsTraversal(Field &field)
{
    double h = field.getHeight() * 5 / 12;

    field.getCell(h - 1, 7).setType(Cell::Objects::GROUND);
    field.getCell(h - 1, 7).setPassable(true);
    field.getCell(h - 1, 7).setEvent(field.eventGenerate(STAKES_EVENT));
    field.getCell(h - 1, 8).setType(Cell::Objects::GROUND);
    field.getCell(h - 1, 8).setPassable(true);

    field.getCell(h, 7).setType(Cell::Objects::GROUND);
    field.getCell(h, 7).setPassable(true);
    field.getCell(h, 7).setEvent(field.eventGenerate(STAKES_EVENT));
    field.getCell(h, 8).setType(Cell::Objects::GROUND);
    field.getCell(h, 8).setPassable(true);

    field.getCell(h + 1, 7).setType(Cell::Objects::GROUND);
    field.getCell(h + 1, 7).setPassable(true);
    field.getCell(h + 1, 7).setEvent(field.eventGenerate(STAKES_EVENT));
    field.getCell(h + 1, 8).setType(Cell::Objects::GROUND);
    field.getCell(h + 1, 8).setPassable(true);
}

void DoorOpenEvent::interact(Player &player) {}
void DoorOpenEvent::interact(Field &field)
{
    cellsTraversal(field);
}

Event *DoorOpenEvent::clone() const
{
    return new DoorOpenEvent(*this);
}