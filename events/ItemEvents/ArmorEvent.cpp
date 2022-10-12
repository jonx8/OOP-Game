#include "ArmorEvent.h"

ArmorEvent::ArmorEvent() {}
ArmorEvent::~ArmorEvent() {}

void ArmorEvent::interact(Player &player) { player.setArmor(true); }