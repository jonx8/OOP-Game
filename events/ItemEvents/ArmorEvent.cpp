#include "ArmorEvent.h"

ArmorEvent::ArmorEvent() {}
ArmorEvent::ArmorEvent(const ArmorEvent &obj) : ItemEvent::ItemEvent(obj) {}
ArmorEvent::~ArmorEvent() {}

void ArmorEvent::interact(Player &player, Field &field) { player.setArmor(true); }
Event *ArmorEvent::clone() const
{
    return new ArmorEvent(*this);
}