#include "Game.h"

Game::Game(Controller *controller, CommandReader *reader) : controller(controller), reader(reader), running(false) {}
Game::~Game() {}
void Game::start()
{
    running = true;
    while (running)
    {
        system("clear");
        controller->showField();
        controller->showPlayerStatus();
        reader->readcmd();
        if (reader->getCurrentCmd() == "8")
        {
            controller->movePlayer(Field::UP);
        }
        else if (reader->getCurrentCmd() == "2")
        {
            controller->movePlayer(Field::DOWN);
        }
        else if (reader->getCurrentCmd() == "6")
        {
            controller->movePlayer(Field::RIGHT);
        }
        else if (reader->getCurrentCmd() == "4")
        {
            controller->movePlayer(Field::LEFT);
        }
        else if (reader->getCurrentCmd() == "exit")
        {
            stop();
        }

        if (controller->isVictory())
        {
            controller->showField();
            controller->showPlayerStatus();
            stop();
        }
        else if (controller->isDefeat())
        {
            std::cout << " Defeat!!!\n";
            stop();
        }
    }
}

void Game::stop()
{
    std::cout << "-- EXIT --" << std::endl;
    running = false;
}