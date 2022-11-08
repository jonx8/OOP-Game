#include "Game.h"
#include "commands/ICommand.h"

Game::Game(Controller *controller, CommandReader *reader) : controller(controller), reader(reader), current_cmd(nullptr), running(false) {}

Game::~Game() {}

void Game::start()
{
    running = true;
    controller->startGame();
    while (controller->isRunning())
    {
        controller->showField();
        controller->showPlayerStatus();
        current_cmd = reader->readcmd();
        if (current_cmd)
        {
            current_cmd->execute(controller);
        }
        if (controller->isVictory())
        {
            controller->exitGame();
            running = false;
            std::cout << "Victory!\n";
        }
        else if (controller->isDefeat())
        {
            controller->exitGame();
            running = false;
            std::cout << " Defeat!\n";
        }
        else if (!controller->isRunning())
        {
            running = false;
        }
    }
}
