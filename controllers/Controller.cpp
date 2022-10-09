#include "Controller.h"

Controller::Controller(FieldView &fieldView, PlayerView &playerStatus, Field &gamefield, Player &player) : fieldView(fieldView), playerStatus(playerStatus), gamefield(gamefield), player(player) {}

Controller::~Controller() {}

void Controller::showField() const
{
    fieldView.print();
}

void Controller::movePlayer(Field::directions direction) const
{
    gamefield.movePlayer(direction);
}

void Controller::showPlayerStatus() const
{
    std::cout << "PlayerStatus: \n";
    playerStatus.showHealth();
    playerStatus.showStamina();
    playerStatus.showDamage();
}

bool Controller::isVictory() const { return player.isWin(); }
bool Controller::isDefeat() const { return player.isDead(); }