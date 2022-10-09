#include "VictoryEvent.h"

VictoryEvent::VictoryEvent(std::string msg) : msg(msg) {}

void VictoryEvent::interact(Player &player)
{
    player.win();
    std::cout << msg << std::endl;
}

void VictoryEvent::interact(Field &field)
{
    field.setPlayerCoord(0, 0);
}

std::string VictoryEvent::getMSG() const
{
    return msg;
}