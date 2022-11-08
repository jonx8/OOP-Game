#include "NewGameCommand.h"
#include "../Controller.h"

NewGameCommand::NewGameCommand() {}

NewGameCommand::~NewGameCommand() {}

void NewGameCommand::execute(Controller* controller)
{ 
    controller->resetGame();
}