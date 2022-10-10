#include "TrapEvent.h"
#include "../../models/Player.h"

TrapEvent::TrapEvent(uint damage) : damage(damage) {}
TrapEvent::~TrapEvent() {}
void TrapEvent::interact(Player &player)
{
    player.changeHealth(-damage);
}
void TrapEvent::interact(Field &field) {}
