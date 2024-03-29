#include "HealEvent.h"

HealEvent::HealEvent(int value) : value(value) {}

HealEvent::HealEvent(const HealEvent &obj) : ItemEvent::ItemEvent(obj) {
    value = obj.value;
}

void HealEvent::interact(Player &player, Field &field) {
    notify(Message("VictoryEvent executed", Message::INFO));
    player.changeHealth(value);
}

Event *HealEvent::clone() const {
    return new HealEvent(*this);
}