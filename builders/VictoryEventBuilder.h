#pragma once
#include "EventBuilder.h"
#include "../events/GameOverEvents/VictoryEvent.h"

class VictoryEventBuilder : public EventBuilder
{
private:
    std::string msg;

public:
    VictoryEventBuilder(std::string msg = "");
    ~VictoryEventBuilder();
    void reset() override;
    void setMessage(std::string msg);
    Event *create() const override;
};
