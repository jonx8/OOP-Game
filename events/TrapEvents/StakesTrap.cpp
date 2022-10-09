#include "StakesTrap.h"
StakesTrap::~StakesTrap() {}
void StakesTrap::interact(Player &player)
{
    player.changeHealth(-damage);
}