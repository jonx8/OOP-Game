#include "CommandReader.h"
#include <iostream>

CommandReader::CommandReader() : currentCmd(std::string("")) {}

void CommandReader::readcmd()
{
    std::cin >> currentCmd;
    if (currentCmd == "exit")
    {
        notify(Message("Exit command entered", Message::INFO));
    }
}

std::pair<int, int> CommandReader::readLogParams() const
{
    int log_method = 0, log_level = 0;

    do
    {
        system("clear");
        std::cout << "Enter the method of logging: \n";
        std::cout << "1) No logging\n";
        std::cout << "2) Console logging\n";
        std::cout << "3) File logging\n";
        std::cout << "4) File and console logging" << std::endl;
        std::cin >> log_method;
    } while (log_method > 5 || log_method < 1);
    if (log_method != 1)
    {
        do
        {
            system("clear");
            std::cout << "Enter the level of logging: \n";
            std::cout << "1) ERROR\n2) GAME STATUS\n3) INFO" << std::endl;
            std::cin >> log_level;
        } while (log_level > 3 || log_level < 1);
    }

    switch (log_level)
    {
    case 1:
        log_level = Message::ERROR;
        break;
    case 2:
        log_level = Message::GAME_STATUS;
        break;
    case 3:
        log_level = Message::INFO;
        break;
    }

    return std::pair<int, int>(log_method, log_level);
}

void CommandReader::readFieldSize()
{
    std::cout << "Enter height and width of the field: ";
    std::cin >> sizes.first >> sizes.second;
    std::cout << '\n';
    while (sizes.first < 20 || sizes.second < 20)
    {
        notify(Message("Incorrect size of field was entered", Message::ERROR));
        std::cout << "Enter height and width of the field: ";
        std::cin >> sizes.first >> sizes.second;
        std::cout << '\n';
    }
}

std::pair<int, int> CommandReader::getFieldSize() const
{
    return sizes;
}

std::string CommandReader::getCurrentCmd()
{
    return currentCmd;
}
