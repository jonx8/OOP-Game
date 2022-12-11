#include "LoadCommand.h"
#include "../Controller.h"

void LoadCommand::execute(Controller &controller) {
    controller.loadGame();
}
