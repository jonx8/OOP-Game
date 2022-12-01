#include "RestartCommand.h"
#include "../Controller.h"


void RestartCommand::execute(Controller &controller) {
    controller.resetGame();
}