#pragma once

#include <functional>
#include <unordered_map>
#include <memory>
#include "../commands/StartGameCommand.h"
#include "../../observable/Observable.h"

class ICommand;

class CommandReader : public Observable {
protected:
    std::unordered_map<std::string, ICommand *, std::hash<std::string>> commands;

    bool commandKeyCheck(const std::string &key);

public:
    virtual ~CommandReader() = 0;

    virtual ICommand *readcmd() = 0;

    [[maybe_unused]] virtual std::pair<int, int> readFieldSize() = 0;

    virtual std::unique_ptr<StartGameCommand> readFieldType() = 0;

    virtual std::pair<int, int> readLogParams() = 0;

    void loadDefaultSettings();

    bool ImportFileConf(const char *filename);
};