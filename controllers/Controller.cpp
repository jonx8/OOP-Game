#include "Controller.h"
#include "../models/Player.h"
#include "../views/FieldView.h"
#include "../views/PlayerView.h"

Controller::Controller(FieldView &fieldView, PlayerView &playerStatus, Field &gamefield, Player &player) : fieldView(fieldView), playerStatus(playerStatus), gamefield(gamefield), player(player) {}

Controller::~Controller() {}

void Controller::showField() const
{
    fieldView.print();
}

void Controller::movePlayer(Field::Directions direction) const
{
    gamefield.movePlayer(direction);

    if (gamefield.playerInWater())
    {
        player.changeStamina(-player.getStaminaMax() / 10);
        if (player.getStamina() == 0)
        {
            player.setHealth(0);
        }
    }
    else
    {
        player.changeStamina(player.getStaminaMax() / 20);
    }

    gamefield.eventCheck();
}

void Controller::showPlayerStatus() const
{
    std::cout << "PlayerStatus: \n";
    playerStatus.showHealth();
    playerStatus.showStamina();
    playerStatus.showDamage();
    playerStatus.showArmor();
}

bool Controller::isVictory() const { return player.isWin(); }
bool Controller::isDefeat() const { return player.isDead(); }
