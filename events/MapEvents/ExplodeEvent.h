#pragma once
#include "MapEvent.h"

class ExplodeEvent : public MapEvent
{
private:
    uint damage;
    void pushPlayer(uint distance, Field &field) const;
    void cellsTraversal(Field &field) override;

public:
    ExplodeEvent(uint damage, uint radius);
    ~ExplodeEvent();
    void interact(Player &player) override;
    void interact(Field &field) override;
    Event* clone() const override;
};
