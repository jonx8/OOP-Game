#pragma once

#include "ICommand.h"

class ExitCommand : public ICommand {
public:
    void execute(Controller *controller) override;
};
