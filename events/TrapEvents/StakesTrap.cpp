#include "StakesTrap.h"
#include "../../models/Player.h"

StakesTrap::~StakesTrap() {}
void StakesTrap::interact(Player &player) { player.changeHealth(-damage); }
void StakesTrap::interact(Field &field) {}


Event *StakesTrap::clone() const
{
    return new StakesTrap(*this);
}