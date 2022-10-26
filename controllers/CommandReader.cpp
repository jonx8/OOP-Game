#include "CommandReader.h"
#include <iostream>

CommandReader::CommandReader() : currentCmd(std::string("")) {}

void CommandReader::readcmd() { std::cin >> currentCmd; 
    if (currentCmd == "exit")
    {
        notify(Message("Exit command was entered", Message::CRITICAL));
    }
    
}

void CommandReader::readFieldSize()
{
    std::cout << "Enter height and width of the field: ";
    std::cin >> sizes.first >> sizes.second;
    std::cout << '\n';
    while (sizes.first < 20 && sizes.second < 20)
    {
        std::cout << "Enter height and width of the field: ";
        std::cin >> sizes.first >> sizes.second;
        std::cout << '\n';
        notify(Message("Incorrect size of field was entered", Message::CRITICAL));
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
