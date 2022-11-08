#pragma once
#include "ICommand.h"

class NewGameCommand : public ICommand
{
public:
    NewGameCommand();
    ~NewGameCommand();
    void execute(Controller *controller) override;
};
