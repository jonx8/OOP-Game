#include "StartGameCommand.h"

StartGameCommand::StartGameCommand(FieldType type) : map_template(type) {}

void StartGameCommand::execute(Controller &controller) {
    controller.startGame(map_template);
}
