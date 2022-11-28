#include "Controller.h"
#include "../models/Player.h"
#include "../views/FieldView.h"
#include "../views/PlayerView.h"

Controller::Controller(FieldView &fieldView, PlayerView &playerStatus, Field &gamefield, Player *player) : fieldView(fieldView), playerStatus(playerStatus), gamefield(gamefield), player(player), running(false) {}

void Controller::showField() const
{
    // system("clear");
    fieldView.print();
}

void Controller::movePlayer(Field::Directions direction) const
{
    gamefield.movePlayer(direction);

    if (gamefield.playerInWater())
    {
        player->changeStamina(-player->getStaminaMax() / 10);
        if (player->getStamina() == 0)
        {
            player->setHealth(0);
        }
    }
    else
    {
        player->changeStamina(player->getStaminaMax() / 20);
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

void Controller::startGame()
{
    running = true;
    observer->update(Message("Game was started", Message::GAME_STATUS));
}

void Controller::resetGame()
{
    player->~Player();
    player = new Player();
    playerStatus = PlayerView(player);
    // gamefield = generator.getField();
    gamefield.setPlayer(player);
    gamefield.clearEvents();
    gamefield.setPlayerCoord(0, 0);
}

void Controller::exitGame()
{
    running = false;
    showField();
    observer->update(Message("Game was stopped", Message::GAME_STATUS));
    delete player;
}

void Controller::setObserver(Observer *obs)
{
    observer = obs;
}

bool Controller::isVictory() const { return player->isWin(); }
bool Controller::isDefeat() const { return player->isDead(); }
bool Controller::isRunning() const { return running; }