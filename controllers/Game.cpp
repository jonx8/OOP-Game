#include "Game.h"
#include "../loggers/ConsoleLogger.h"
#include "../loggers/FileLogger.h"
Game::Game(Controller *controller, CommandReader *reader, Observer *obs) : controller(controller), reader(reader), observer(obs), running(false)
{
}

Game::~Game()
{
}
void Game::start()
{
    observer->update(Message("Game was started", Message::GAME_STATUS));
    running = true;
    while (running)
    {
        controller->showField();
        controller->showPlayerStatus();
        reader->readcmd();
        if (reader->getCurrentCmd() == "8")
        {
            controller->movePlayer(Field::Directions::UP);
        }
        else if (reader->getCurrentCmd() == "2")
        {
            controller->movePlayer(Field::Directions::DOWN);
        }
        else if (reader->getCurrentCmd() == "6")
        {
            controller->movePlayer(Field::Directions::RIGHT);
        }
        else if (reader->getCurrentCmd() == "4")
        {
            controller->movePlayer(Field::Directions::LEFT);
        }
        else if (reader->getCurrentCmd() == "exit")
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