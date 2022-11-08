#include "ExitCommand.h"
#include "../Controller.h"

ExitCommand::ExitCommand() {}

ExitCommand::~ExitCommand() {}

void ExitCommand::execute(Controller* controller)
{ 
    controller->exitGame();
}