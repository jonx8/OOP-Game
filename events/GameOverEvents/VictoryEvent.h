#pragma once
#include "../../models/Field.h"

class VictoryEvent : public Event
{
private:
    std::string msg;

public:
    VictoryEvent(std::string msg);
    void interact(Player &player) override;
    void interact(Field &field) override;
    std::string getMSG() const;
};