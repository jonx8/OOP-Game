#pragma once

#include "ICommand.h"
#include "../Controller.h"

class MoveCommand : public ICommand {
private:
    Directions direction;
public:
    MoveCommand(Directions direction);

    void execute(Controller & controller) override final;
};

