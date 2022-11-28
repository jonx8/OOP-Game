#include "StakesTrap.h"
#include "../../models/Player.h"

void StakesTrap::interact(Player &player, Field &field)
{
    notify(Message("StakesTrap executed", Message::INFO));
    player.changeHealth(-damage);
}

Event *StakesTrap::clone() const
{
    return new StakesTrap(*this);
}