#pragma once

#include "ICommand.h"

class RestartCommand : public ICommand {
public:
    void execute(Controller &controller) override;
};
