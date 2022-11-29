#include "ExitCommand.h"
#include "../Controller.h"

void ExitCommand::execute(Controller *controller) {
    controller->exitGame();
}