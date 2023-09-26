#include <iostream>
#include <set>
#include <fstream>
#include "CommandReader.h"
#include "../commands/MoveCommand.h"
#include "../commands/RestartCommand.h"
#include "../commands/ExitCommand.h"
#include "../commands/LoadCommand.h"
#include "../commands/SaveCommand.h"

CommandReader::~CommandReader() {
    for (const auto &i: commands)
        delete i.second;

}

bool CommandReader::commandKeyCheck(const std::string &key) {
    if (!key.empty() && !commands.contains(key)) {
        return true;
    }
    return false;
}

void CommandReader::loadDefaultSettings() {
    std::cin.get();
    std::cin.get();
    notify(Message("Control configuration file is corrupted. Default settings were used", Message::ERROR));
    for (const auto &i: commands)
        delete i.second;

    commands.clear();
    commands["w"] = new MoveCommand(Directions::UP);
    commands["s"] = new MoveCommand(Directions::DOWN);
    commands["d"] = new MoveCommand(Directions::RIGHT);
    commands["a"] = new MoveCommand(Directions::LEFT);
    commands["restart"] = new RestartCommand;
    commands["exit"] = new ExitCommand;
    commands["load"] = new LoadCommand;
    commands["save"] = new SaveCommand;
}

bool CommandReader::ImportFileConf(const char *filename) {
    std::ifstream conf_file(filename);
    std::string curr_line, cmd_name, cmd_key_name;
    std::unordered_map<std::string, bool, std::hash<std::string>> occupancy; // Required commands

    // key - cmd_name, second - equal true if cmd has been added else false.
    occupancy["up"] = false;
    occupancy["down"] = false;
    occupancy["right"] = false;
    occupancy["left"] = false;
    occupancy["exit"] = false;
    occupancy["restart"] = false;
    occupancy["save"] = false;
    occupancy["load"] = false;

    if (!conf_file) {
        notify(Message("Problem with opening control configuration file", Message::ERROR));
        return false;
    }
    while (!conf_file.eof()) {
        std::getline(conf_file, curr_line);
        std::erase(curr_line, ' ');
        size_t delim_index = curr_line.find_first_of('=', 1);

        if (delim_index != std::string::npos) {
            // Name of the command - left part in conf file
            cmd_name = curr_line.substr(0, delim_index);

            // Key of the command - right part
            cmd_key_name = curr_line.substr(delim_index + 1, curr_line.length());

            if (occupancy.contains(cmd_name) and commandKeyCheck(cmd_key_name)) {
                if (cmd_name == "up") {
                    commands[cmd_key_name] = new MoveCommand(Directions::UP);
                } else if (cmd_name == "down") {
                    commands[cmd_key_name] = new MoveCommand(Directions::DOWN);
                } else if (cmd_name == "right") {
                    commands[cmd_key_name] = new MoveCommand(Directions::RIGHT);
                } else if (cmd_name == "left") {
                    commands[cmd_key_name] = new MoveCommand(Directions::LEFT);
                } else if (cmd_name == "restart") {
                    commands[cmd_key_name] = new RestartCommand;
                } else if (cmd_name == "exit") {
                    commands[cmd_key_name] = new ExitCommand;
                } else if (cmd_name == "save") {
                    commands[cmd_key_name] = new SaveCommand;
                } else if (cmd_name == "load") {
                    commands[cmd_key_name] = new LoadCommand;
                }

                if (occupancy[cmd_name]) {
                    // If command has been repeat in config file, break
                    occupancy[cmd_name] = false;
                    break;
                }
                occupancy[cmd_name] = true;
            }
        }
    }
    // Checking for errors
    for (const auto &i: occupancy) {
        if (!i.second) {
            // If for some command, the key is not unique, or it is incorrect
            std::cout << "Control configuration file is incomplete. Default settings have been used." << std::endl;
            loadDefaultSettings();
            break;
        }
    }

    conf_file.close();
    return true;
}
