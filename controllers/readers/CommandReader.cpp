#include <iostream>
#include <set>
#include <fstream>
#include "CommandReader.h"
#include "../commands/MoveCommand.h"
#include "../commands/NewGameCommand.h"
#include "../commands/ExitCommand.h"


CommandReader::~CommandReader()
{
    for (const auto& i: commands)
        delete i.second;

}

bool CommandReader::commandKeyCheck(const std::string &key)
{
    if (!key.empty() && !commands.contains(key))
    {
        return true;
    }
    return false;
}

void CommandReader::loadDefaultSettings()
{
    std::cin.get();
    std::cin.get();
    notify(Message("Control configuration file is corrupted. Default settings were used", Message::ERROR));
    for (const auto &i: commands)
        delete i.second;

    commands.clear();
    commands["w"] = new MoveCommand(Field::Directions::UP);
    commands["s"] = new MoveCommand(Field::Directions::DOWN);
    commands["d"] = new MoveCommand(Field::Directions::RIGHT);
    commands["a"] = new MoveCommand(Field::Directions::LEFT);
    commands["start"] = new NewGameCommand;
    commands["exit"] = new ExitCommand;
}

bool CommandReader::ImportFileConf(const char *filename)
{
    std::ifstream conf_file(filename);
    std::string curr_line, cmd_name, cmd_key_name;
    std::unordered_map<std::string, bool, std::hash<std::string>> occupancy; // Required commands

    // key - cmd_name, second - equal true if cmd has been added else false.
    occupancy["up"] = false;
    occupancy["down"] = false;
    occupancy["right"] = false;
    occupancy["left"] = false;
    occupancy["exit"] = false;
    occupancy["new_game"] = false;

    if (!conf_file)
    {
        notify(Message("Problem with opening control configuration file", Message::ERROR));
        return false;
    }
    while (!conf_file.eof())
    {
        std::getline(conf_file, curr_line);
        std::erase(curr_line, ' ');
        size_t delim_index = curr_line.find_first_of('=', 1);

        if (delim_index != std::string::npos)
        {
            // Name of the command - left part in conf file
            cmd_name = curr_line.substr(0, delim_index);

            // Key of the command - right part
            cmd_key_name = curr_line.substr(delim_index + 1, curr_line.length());

            if (occupancy.contains(cmd_name) && commandKeyCheck(cmd_key_name))
            {
                if (cmd_name == "up")
                {
                    commands[cmd_key_name] = new MoveCommand(Field::Directions::UP);
                }
                else if (cmd_name == "down")
                {
                    commands[cmd_key_name] = new MoveCommand(Field::Directions::DOWN);
                }
                else if (cmd_name == "right")
                {
                    commands[cmd_key_name] = new MoveCommand(Field::Directions::RIGHT);
                }
                else if (cmd_name == "left")
                {
                    commands[cmd_key_name] = new MoveCommand(Field::Directions::LEFT);
                }
                else if (cmd_name == "new_game")
                {
                    commands[cmd_key_name] = new NewGameCommand;
                }
                else if (cmd_name == "exit")
                {
                    commands[cmd_key_name] = new ExitCommand;
                }

                if (occupancy[cmd_name])
                {
                    // If command has been repeat in conf file, break
                    occupancy[cmd_name] = false;
                    break;
                }
                occupancy[cmd_name] = true;
            }
        }
    }
    // Checking for errors
    for (const auto& i : occupancy)
    {
        if (!i.second)
        {
            // If for some command, the key is not unique, or it is incorrect
            std::cout << "Control configuration file is incomplete. Default settings have been used." << std::endl;
            loadDefaultSettings();
            break;
        }
    }

    conf_file.close();
    return true;
}
