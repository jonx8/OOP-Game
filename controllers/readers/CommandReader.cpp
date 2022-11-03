#include <iostream>
#include <fstream>
#include "CommandReader.h"

CommandReader::~CommandReader() {}

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
            // split by = symb
            commands[curr_line.substr(delim_ind + 1, curr_line.length())] = curr_line.substr(0, delim_ind);
        }
    }

    conf_file.close();
    return true;
}