#include "ArmorEvent.h"

ArmorEvent::ArmorEvent(const ArmorEvent &obj) : ItemEvent::ItemEvent(obj) {}

void ArmorEvent::interact(Player &player, Field &field) {
    notify(Message("ArmorEvent executed", Message::INFO));
    player.setArmor(true);
}

Event *ArmorEvent::clone() const {
    return new ArmorEvent(*this);
}