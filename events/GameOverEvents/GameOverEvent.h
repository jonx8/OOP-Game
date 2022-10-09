#pragma once
#include "../Event.h"
#include "../../models/Field.h"

class GameOverEvent : public Event
{
protected:
    std::string msg;

public:
    GameOverEvent(std::string msg);
    void interact(Field* field) override;
};