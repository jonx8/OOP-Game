#pragma once
#include "MapEvent.h"

class DoorOpenEvent : public MapEvent
{
private:
    void cellsTraversal(Field& field) override;
public:
    DoorOpenEvent();
    ~DoorOpenEvent();
    void interact(Player &player) override;
    void interact(Field &field) override;
    Event *clone() const override;
};
