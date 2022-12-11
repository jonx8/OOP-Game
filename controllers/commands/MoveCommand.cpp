#include "MoveCommand.h"

MoveCommand::MoveCommand(Directions direction) : direction(direction) {}

void MoveCommand::execute(Controller &controller) {
    controller.movePlayer(direction);
}