#pragma once

#include "CommandReader.h"

class ConsoleReader : public CommandReader {
public:
    ICommand *readcmd() override;

    std::unique_ptr<StartGameCommand> readFieldType() override;

    [[deprecated]] std::pair<int, int> readFieldSize() override;

    std::pair<int, int> readLogParams() override;
};