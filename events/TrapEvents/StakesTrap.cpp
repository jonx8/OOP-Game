#include "StakesTrap.h"
#include "../../models/Player.h"

StakesTrap::~StakesTrap() {}
void StakesTrap::interact(Player &player, Field &field) { player.changeHealth(-damage); }

Event *StakesTrap::clone() const
{
    return new StakesTrap(*this);
}