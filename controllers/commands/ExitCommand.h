#pragma once
#include "ICommand.h"

class ExitCommand : public ICommand
{
public:
    ExitCommand();
    ~ExitCommand();
    void execute(Controller *controller) override;
};
