#include "MoveCommand.h"

MoveCommand::MoveCommand(Field::Directions direction) : direction(direction) {}

MoveCommand::~MoveCommand() {}

void MoveCommand::execute(Controller *controller)
{
    controller->movePlayer(direction);
}