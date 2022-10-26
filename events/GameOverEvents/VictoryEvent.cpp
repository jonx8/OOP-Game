#include "VictoryEvent.h"
#include <iostream>
#include <string>
#include "../../models/Player.h"
#include "../../models/Field.h"

VictoryEvent::VictoryEvent(std::string msg) : msg(msg) {}
VictoryEvent::~VictoryEvent() {}

void VictoryEvent::interact(Player &player, Field &field)
{
    notify(Message("VictoryEventExecute!", Message::INFO));
    player.win();
    field.setPlayerCoord(0, 0);
    std::cout << msg << std::endl;
}

Event *VictoryEvent::clone() const
{
    return new VictoryEvent(*this);
}

std::string VictoryEvent::getMSG() const
{
    return msg;
}