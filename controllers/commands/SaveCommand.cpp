#include "SaveCommand.h"
#include "../Controller.h"

void SaveCommand::execute(Controller &controller) {
    controller.saveGame();
}
