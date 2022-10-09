#include "VictoryEventBuilder.h"
VictoryEventBuilder::VictoryEventBuilder(std::string msg) : msg(msg) {}
VictoryEventBuilder::~VictoryEventBuilder() {}
Event *VictoryEventBuilder::create() const { return new VictoryEvent(msg); }
void VictoryEventBuilder::setMessage(std::string msg) { this->msg = msg; }