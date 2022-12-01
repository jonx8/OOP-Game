#include "Controller.h"

Controller::Controller(Observer *obs) : gameCreator(GameCreator()), player(std::make_unique<Player>()),
                                        gamefield(nullptr), observer(obs), running(false) {}

void Controller::showField() const {
    system("clear");
    fieldView.print();
}

void Controller::movePlayer(Field::Directions direction) {
    gamefield->movePlayer(direction);

    if (gamefield->playerInWater()) {
        player->changeStamina(-player->getStaminaMax() / 10);
        if (player->getStamina() == 0) {
            player->setHealth(0);
        }
    } else {
        player->changeStamina(player->getStaminaMax() / 20);
    }

    gamefield->eventCheck();
}

void Controller::showPlayerStatus() const {
    std::cout << "PlayerStatus: \n";
    playerStatus.showHealth();
    playerStatus.showStamina();
    playerStatus.showArmor();
}

void Controller::startGame(FieldType type) {
    gameCreator.setMapTemplate(type);
    gamefield = gameCreator.generateField(player.get(), observer);
    fieldView.setField(gamefield);
    fieldView.setBorderChar('@');
    playerStatus.setPlayer(player.get());
    observer->update(Message("Game was started", Message::GAME_STATUS));
    running = true;
}

void Controller::resetGame() {
    *player = Player();
    gamefield = gameCreator.generateField(player.get(), observer);
    observer->update(Message("Game was restart", Message::GAME_STATUS));
}


void Controller::exitGame() {
    running = false;
    showField();
    observer->update(Message("Game was stopped", Message::GAME_STATUS));
}

void Controller::setObserver(Observer *obs) {
    observer = obs;
}

bool Controller::isVictory() const { return player->isWin(); }

bool Controller::isDefeat() { return player->isDead(); }

bool Controller::isRunning() const { return running; }