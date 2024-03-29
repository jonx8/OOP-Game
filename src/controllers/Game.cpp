#include "Game.h"

Game::Game(Controller &controller, CommandReader &reader) : controller(controller), reader(reader),
                                                            current_cmd(nullptr) {}

void Game::start() {
    reader.readLevelType()->execute(controller);
    controller.saveGame();
    while (controller.isRunning()) {
        controller.showField();
        controller.showPlayerStatus();
        current_cmd = reader.readcmd();
        if (current_cmd) {
            current_cmd->execute(controller);
        }

        if (controller.isVictory()) {
            controller.exitGame();
            std::cout << "Victory!\n";
        } else if (controller.isDefeat()) {
            controller.exitGame();
            std::cout << "Defeat!\n";
        }
    }
}
