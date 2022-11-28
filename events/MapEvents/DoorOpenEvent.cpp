#include "DoorOpenEvent.h"
#include "../../eventsRegister/EventsRegister.h"

DoorOpenEvent::DoorOpenEvent(EventsRegister *evReg) : evReg(evReg) {}
DoorOpenEvent::DoorOpenEvent(const DoorOpenEvent &obj) : MapEvent(obj)
{
    evReg = obj.evReg;
}

void DoorOpenEvent::cellsTraversal(Field &field)
{
    double h = field.getHeight() * 5 / 12;
    for (size_t i = h - 1; i <= h + 1; i++)
    {
        field.getCell(i, 7).setType(Cell::Objects::GROUND);
        field.getCell(i, 7).setPassable(true);
        field.getCell(i, 7).setEvent(evReg->getEvent(STAKES_EVENT));
        field.getCell(i, 8).setType(Cell::Objects::GROUND);
        field.getCell(i, 8).setPassable(true);
    }
}

void DoorOpenEvent::interact(Player &player, Field &field)
{
    notify(Message("DoorOpenEvent executed", Message::INFO));
    cellsTraversal(field);
}

Event *DoorOpenEvent::clone() const
{
    return new DoorOpenEvent(*this);
}