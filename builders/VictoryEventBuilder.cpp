#include "VictoryEventBuilder.h"
#include "../events/GameOverEvents/VictoryEvent.h"

VictoryEventBuilder::VictoryEventBuilder(std::string msg) : msg(msg) {}
VictoryEventBuilder::~VictoryEventBuilder() {}
void VictoryEventBuilder::reset() { setMessage(""); }
void VictoryEventBuilder::setMessage(std::string msg) { this->msg = msg; }
Event *VictoryEventBuilder::create() const { return new VictoryEvent(msg); }
