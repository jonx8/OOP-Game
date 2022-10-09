#include <iostream>
#include "CommandReader.h"

CommandReader::CommandReader() : currentCmd(std::string("")) {}

void CommandReader::readcmd() { std::cin >> currentCmd; }

void CommandReader::readFieldSize()
{
    while (sizes.first < 5 && sizes.second < 5)
    {
        std::cout << "Enter height and width of the field: ";
        std::cin >> sizes.first >> sizes.second;
        std::cout << '\n';
    }
}

std::pair<int, int> CommandReader::getFieldSize() const
{
    return sizes;
}

std::string CommandReader::getCurrentCmd() const { return currentCmd; }
