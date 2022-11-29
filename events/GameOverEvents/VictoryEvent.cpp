#include "VictoryEvent.h"
#include <iostream>
#include <string>
#include "../../models/Player.h"
#include "../../models/Field.h"

VictoryEvent::VictoryEvent(std::string msg) : msg(msg) {}

void VictoryEvent::interact(Player &player, Field &field) {
    notify(Message("VictoryEvent executed", Message::INFO));
    player.win();
    field.setPlayerCoord(0, 0);
}

Event *VictoryEvent::clone() const {
    return new VictoryEvent(*this);
}

std::string VictoryEvent::getMSG() const {
    return msg;
}