#include <iostream>
#include <set>
#include <fstream>
#include "CommandReader.h"
#include "../commands/MoveCommand.h"
#include "../commands/NewGameCommand.h"
#include "../commands/ExitCommand.h"

CommandReader::CommandReader() : is_default_settings(false) {}
CommandReader::~CommandReader()
{
    for (auto i : commands)
    {
        delete i.second;
    }
}

void CommandReader::loadDefaultSettings()
{
    std::cout << "Problem with control configuration file! Default settings were used" << std::endl;
    std::cin.get();
    std::cin.get();
    notify(Message("Control configuration file is corrupted. Default settings were used", Message::ERROR));
    for (auto i : commands)
    {
        delete i.second;
    }
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
    std::set<std::string> occupancy;
    const size_t FILE_LENGTH = 6;
    std::ifstream conf_file(filename);
    std::string curr_line;
    if (!conf_file)
    {
        notify(Message("Problem with opening control configuration file", Message::ERROR));
        return false;
    }
    for (size_t i = 1; !conf_file.eof(); i++)
    {
        std::getline(conf_file, curr_line);
        std::erase(curr_line, ' ');
        size_t delim_ind = curr_line.find('=');

        if (curr_line.substr(delim_ind + 1).length() != 0 && !commands.contains(curr_line.substr(delim_ind + 1)))
        {
            std::string command_name = curr_line.substr(0, delim_ind);
            if (command_name == "up")
            {
                if (occupancy.contains("up"))
                {
                    loadDefaultSettings();
                    break;
                }
                else
                {
                    occupancy.emplace("up");
                    commands[curr_line.substr(delim_ind + 1, curr_line.length())] = new MoveCommand(Field::Directions::UP);
                }
            }
            else if (command_name == "down")
            {
                if (occupancy.contains("down"))
                {
                    loadDefaultSettings();
                    break;
                }
                else
                {
                    occupancy.emplace("down");
                    commands[curr_line.substr(delim_ind + 1, curr_line.length())] = new MoveCommand(Field::Directions::DOWN);
                }
            }
            else if (command_name == "right")
            {
                if (occupancy.contains("right"))
                {
                    loadDefaultSettings();
                    break;
                }
                else
                {
                    occupancy.emplace("right");
                    commands[curr_line.substr(delim_ind + 1, curr_line.length())] = new MoveCommand(Field::Directions::RIGHT);
                }
            }
            else if (command_name == "left")
            {
                if (occupancy.contains("left"))
                {
                    loadDefaultSettings();
                    break;
                }
                else
                {
                    occupancy.emplace("left");
                    commands[curr_line.substr(delim_ind + 1, curr_line.length())] = new MoveCommand(Field::Directions::LEFT);
                }
            }
            else if (command_name == "exit")
            {
                if (occupancy.contains("exit"))
                {
                    loadDefaultSettings();
                    break;
                }
                else
                {
                    occupancy.emplace("exit");
                    commands[curr_line.substr(delim_ind + 1, curr_line.length())] = new ExitCommand;
                }
            }
            else if (command_name == "new_game")
            {
                if (occupancy.contains("new_game"))
                {
                    loadDefaultSettings();
                    break;
                }
                else
                {
                    occupancy.emplace("new_game");
                    commands[curr_line.substr(delim_ind + 1, curr_line.length())] = new NewGameCommand;
                }
            }
            // else
            // {
            //     loadDefaultSettings();
            //     break;
            // }
        }
        else
        {
            // Using default settings
            loadDefaultSettings();
            break;
        }
    }

    if (occupancy.size() != FILE_LENGTH)
    {
        loadDefaultSettings();
    }

    conf_file.close();
    return true;
}
