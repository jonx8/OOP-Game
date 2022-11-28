#include "NewGameCommand.h"
#include "../Controller.h"


void NewGameCommand::execute(Controller* controller)
{ 
    controller->resetGame();
}