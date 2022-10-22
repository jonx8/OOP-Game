#pragma once
#include "MapEvent.h"
class EventsRegister;

class DoorOpenEvent : public MapEvent
{
private:
    EventsRegister *evReg;
    void cellsTraversal(Field &field) override;

public:
    DoorOpenEvent(EventsRegister *evReg);
    ~DoorOpenEvent();
    void interact(Player &player, Field &field) override;
    Event *clone() const override;
};
