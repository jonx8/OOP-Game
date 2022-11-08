#pragma once
#include "ICommand.h"
#include "../Controller.h"

class MoveCommand : public ICommand
{
private:
    Field::Directions direction;
public:
    MoveCommand(Field::Directions direction);
    ~MoveCommand();
    void execute(Controller*) override;
};

