#pragma once
#include "CommandReader.h"

class ConsoleReader : public CommandReader
{
public:
    ConsoleReader();
    ~ConsoleReader();
    ICommand *readcmd() override;
    std::pair<int, int> readFieldSize() override;
    std::pair<int, int> readLogParams() override;
};