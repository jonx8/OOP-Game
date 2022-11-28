#pragma once
#include "MapEvent.h"
class EventsRegister;

class DoorOpenEvent : public MapEvent
{
private:
    EventsRegister *evReg;
    void cellsTraversal(Field &field) override;

public:
    explicit DoorOpenEvent(EventsRegister *evReg);
    DoorOpenEvent(const DoorOpenEvent& obj);
    void interact(Player &player, Field &field) override;
    [[nodiscard]] Event *clone() const override;
};
