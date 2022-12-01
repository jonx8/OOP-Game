#pragma once

class Controller;

class ICommand {
public:
    virtual ~ICommand() = 0;

    virtual void execute(Controller &) = 0;
};
