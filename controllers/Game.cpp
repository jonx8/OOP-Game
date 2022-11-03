#include "Game.h"
#include "../loggers/ConsoleLogger.h"
#include "../loggers/FileLogger.h"
Game::Game(Controller *controller, CommandReader *reader, Observer *obs) : controller(controller), reader(reader), observer(obs), running(false) {}

Game::~Game() {}

void Game::start()
{
    observer->update(Message("Game was started", Message::GAME_STATUS));
    running = true;
    while (running)
    {
        system("clear");
        controller->showField();
        controller->showPlayerStatus();
        std::string cmd = reader->readcmd();
        if (cmd == "up")
        {
            controller->movePlayer(Field::Directions::UP);
        }
        else if (cmd == "down")
        {
            controller->movePlayer(Field::Directions::DOWN);
        }
        else if (cmd == "right")
        {
            controller->movePlayer(Field::Directions::RIGHT);
        }
        else if (cmd == "left")
        {
            controller->movePlayer(Field::Directions::LEFT);
        }
        else if (cmd == "exit")
        {
            stop();
        }

        if (controller->isVictory())
        {
            stop();
            std::cout << "Victory!\n";
        }
        else if (controller->isDefeat())
        {
            stop();
            std::cout << " Defeat!\n";
        }
    }
}

void Game::stop()
{
    system("clear");
    observer->update(Message("Game was stopped", Message::GAME_STATUS));
    controller->showField();
    running = false;
}

void Game::setObserver(Observer *obs)
{
    observer = obs;
}