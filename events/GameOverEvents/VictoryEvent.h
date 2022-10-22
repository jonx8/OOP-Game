#pragma once
#include <iostream>
#include "../Event.h"

class VictoryEvent : public Event
{
private:
    std::string msg;

public:
    explicit VictoryEvent(std::string msg);
    ~VictoryEvent();
    void interact(Player &player, Field &field) override;
    Event *clone() const override;
    std::string getMSG() const;
};