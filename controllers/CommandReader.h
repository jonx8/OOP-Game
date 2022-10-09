#pragma once

class CommandReader
{
private:
    std::pair <int, int> sizes;
    std::string currentCmd;

public:
    CommandReader();
    void readcmd();
    void readFieldSize();
    std::pair <int, int> getFieldSize() const;
    std::string getCurrentCmd() const;
};