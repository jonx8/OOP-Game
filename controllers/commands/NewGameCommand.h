#pragma once

#include "ICommand.h"

class NewGameCommand : public ICommand {
public:
    void execute(Controller *controller) override;
};
