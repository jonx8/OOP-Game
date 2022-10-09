#include "VictoryEvent.h"

VictoryEvent::VictoryEvent(std::string msg, bool taken) : msg(msg), taken(taken) {}

void VictoryEvent::interact(Player &player)
{
    taken = true;
    player.win();
    std::cout << msg << std::endl;
}

bool VictoryEvent::isTaken() const { return taken; }

//VictoryEvent::GameOverEvent(std::string msg) : msg(msg) {}

void VictoryEvent::interact(Field *field) 
{
    field->setPlayerCoord(0, 0);
}