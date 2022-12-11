#include "Controller.h"
#include "../serializators/FieldSerializator.h"
#include "../serializators/PlayerSerializator.h"

Controller::Controller(Observer *obs) : levelCreator(LevelController()), player(std::make_unique<Player>()),
                                        gamefield(nullptr), observer(obs), running(false) {}

void Controller::showField() const {
    system("clear");
    fieldView.print();
}

void Controller::movePlayer(Directions direction) {
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
    levelCreator.setMapTemplate(type);
    gamefield = levelCreator.generateField(player.get(), observer);
    fieldView.setField(gamefield);
    fieldView.setBorderChar('@');
    playerStatus.setPlayer(player.get());
    observer->update(Message("Game was started", Message::GAME_STATUS));
    running = true;
}

void Controller::resetGame() {
    *player = Player();
    gamefield = levelCreator.generateField(player.get(), observer);
    observer->update(Message("Game was restart", Message::GAME_STATUS));
    fieldView.setField(gamefield);
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

void Controller::saveGame() const {
    std::cout << FieldSerializator::serialize("save1.bin", gamefield);
    std::cout << PlayerSerializator::serialize("save_player.bin", player.get());

}

void Controller::loadGame() {
    player = PlayerSerializator::deserialize("save_player.bin");
    *gamefield = FieldSerializator::deserialize("save1.bin");
    player->addObserver(observer);
    gamefield->addObserver(observer);
    gamefield->setPlayer(player.get());
    fieldView.setField(gamefield);
    playerStatus.setPlayer(player.get());
}
