#include "FileLogger.h"
#include <iostream>

FileLogger::FileLogger(const char *filename) : filename(filename)
{
    logfile.open(filename);
    if (!logfile)
    {
        throw std::runtime_error("Log file open failure!");
    }
    else
    {
        logfile << "File logger started\n";
    }
}
FileLogger::~FileLogger()
{
    logfile.close();
}

void FileLogger::log(const Message &msg)
{
    if (log_level >= msg.getType())
    {
        logfile << msg << '\n';
    }
}