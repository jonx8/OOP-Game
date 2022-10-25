#include "CommandReader.h"
#include <iostream>

CommandReader::CommandReader() : currentCmd(std::string("")) {}

void CommandReader::readcmd() { std::cin >> currentCmd; }

void CommandReader::readFieldSize()
{
    while (sizes.first < 16 && sizes.second < 16)
    {
        std::cout << "Enter height and width of the field: ";
        std::cin >> sizes.first >> sizes.second;
        std::cout << '\n';
        notify(Message("Incorrect size field"));
    }
}

std::pair<int, int> CommandReader::getFieldSize() const
{   
    return sizes;
}

std::string CommandReader::getCurrentCmd() 
{
    if (currentCmd == "exit")
    {
        notify(Message("Game Exit"));
    } 
    return currentCmd; 
}

