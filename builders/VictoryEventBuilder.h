#pragma once
#include <string>
#include "EventBuilder.h"

class VictoryEventBuilder : public EventBuilder
{
private:
    std::string msg;

public:
    VictoryEventBuilder(std::string msg = "");
    ~VictoryEventBuilder();
    void reset() override;
    void setMessage(std::string msg);
    Event  *create() const override;
};
