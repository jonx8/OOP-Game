#pragma once

#include "ICommand.h"
#include "../Controller.h"

class StartGameCommand : public ICommand {
private:
    FieldType map_template;
public:
    explicit StartGameCommand(FieldType type);

    ~StartGameCommand() override = default;

    void execute(Controller& controller) override;
};

