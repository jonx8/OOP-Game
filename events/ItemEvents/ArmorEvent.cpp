#include "ArmorEvent.h"

ArmorEvent::ArmorEvent() {}
ArmorEvent::~ArmorEvent() {}

void ArmorEvent::interact(Player &player) { player.setArmor(true); }
void ArmorEvent::interact(Field &field) {}
Event *ArmorEvent::clone() const
{
    return new ArmorEvent(*this);
}