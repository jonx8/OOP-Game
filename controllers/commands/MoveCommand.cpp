#include "MoveCommand.h"

MoveCommand::MoveCommand(Field::Directions direction) : direction(direction) {}

void MoveCommand::execute(Controller &controller) {
    controller.movePlayer(direction);
}