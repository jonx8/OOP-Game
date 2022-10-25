#include "Game.h"
#include "../loggers/ConsoleLogger.h"
Game::Game(Controller *controller, CommandReader *reader, observers_map &obs) : controller(controller), reader(reader), observers(obs), running(false)
{
    logger = new ConsoleLogger;
    logger->setLevel(Logger::INFO);
    for (auto i : observers)
    {
        i.second->addLogger(logger);
    }
}

Game::~Game() {}
void Game::start()
{
    running = true;
    while (running)
    {
        // system("clear");
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
    controller->showField();
    running = false;
    delete logger;
}
