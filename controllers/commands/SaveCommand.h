#pragma once

#include "ICommand.h"

class SaveCommand : public ICommand {
public:
    void execute(Controller &controller) override final;
};

