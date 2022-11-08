#include <iostream>
#include <fstream>
#include "CommandReader.h"
#include "../commands/MoveCommand.h"
#include "../commands/NewGameCommand.h"
#include "../commands/ExitCommand.h"

CommandReader::~CommandReader()
{
    for (auto i : commands)
    {
        delete i.second;
    }
}

bool CommandReader::ImportFileConf(const char *filename)
{
    const size_t MAX_FILE_LENGTH = 50;
    std::ifstream conf_file(filename);
    std::string curr_line;
    if (!conf_file)
    {
        notify(Message("Error opening control configuration file", Message::ERROR));
        return false;
    }
    for (size_t i = 1; !conf_file.eof(); i++)
    {
        if (i > MAX_FILE_LENGTH)
        {
            notify(Message("Control configuration file is too long. Max lenght of configuration file: " + std::to_string(MAX_FILE_LENGTH), Message::ERROR));
            return false;
        }
        std::getline(conf_file, curr_line);
        std::erase(curr_line, ' ');

        if (size_t delim_ind = curr_line.find('='))
        {
            if (curr_line.substr(0, delim_ind) == "up")
            {
                commands[curr_line.substr(delim_ind + 1, curr_line.length())] = new MoveCommand(Field::Directions::UP);
            }
            else if (curr_line.substr(0, delim_ind) == "down")
            {
                commands[curr_line.substr(delim_ind + 1, curr_line.length())] = new MoveCommand(Field::Directions::DOWN);
            }
            else if (curr_line.substr(0, delim_ind) == "right")
            {
                commands[curr_line.substr(delim_ind + 1, curr_line.length())] = new MoveCommand(Field::Directions::RIGHT);
            }
            else if (curr_line.substr(0, delim_ind) == "left")
            {
                commands[curr_line.substr(delim_ind + 1, curr_line.length())] = new MoveCommand(Field::Directions::LEFT);
            }
            else if (curr_line.substr(0, delim_ind) == "exit")
            {
                commands[curr_line.substr(delim_ind + 1, curr_line.length())] = new ExitCommand;
            }
            else if (curr_line.substr(0, delim_ind) == "new_game")
            {
                commands[curr_line.substr(delim_ind + 1, curr_line.length())] = new NewGameCommand;
            }
        }
    }
    conf_file.close();
    return true;
}