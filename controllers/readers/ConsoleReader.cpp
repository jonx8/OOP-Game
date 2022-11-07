#include "ConsoleReader.h"

ConsoleReader::ConsoleReader() {}
ConsoleReader::~ConsoleReader() {}
std::string ConsoleReader::readcmd()
{
    std::string currentCmd;
    std::cin >> currentCmd;
    
    if (commands[currentCmd.c_str()] == "exit")
    {
        notify(Message("Exit command entered", Message::INFO));
    }
    else if (commands[currentCmd.c_str()] == "new_game")
    {
        /* code */
    }
    
    return commands[currentCmd];
}

std::pair<int, int> ConsoleReader::readLogParams()
{
    int log_method = 0, log_level = 0;

    do
    {
        system("clear");
        std::cout << "Enter the method of logging: \n";
        std::cout << "1) No logging\n";
        std::cout << "2) Console logging\n";
        std::cout << "3) File logging\n";
        std::cout << "4) File and console logging" << std::endl;
        std::cin >> log_method;
    } while (log_method > 5 || log_method < 1);
    if (log_method != 1)
    {
        do
        {
            system("clear");
            std::cout << "Enter the level of logging: \n";
            std::cout << "1) ERROR\n2) GAME STATUS\n3) INFO" << std::endl;
            std::cin >> log_level;
        } while (log_level > 3 || log_level < 1);
    }

    switch (log_level)
    {
    case 1:
        log_level = Message::ERROR;
        break;
    case 2:
        log_level = Message::GAME_STATUS;
        break;
    case 3:
        log_level = Message::INFO;
        break;
    }

    return std::pair<int, int>(log_method, log_level);
}

std::pair<int, int> ConsoleReader::readFieldSize()
{
    std::pair<int, int> sizes;
    std::cout << "Enter height and width of the field: ";
    std::cin >> sizes.first >> sizes.second;
    std::cout << '\n';
    while (sizes.first < 20 || sizes.second < 20)
    {
        notify(Message("Incorrect size of field was entered", Message::ERROR));
        std::cout << "Enter height and width of the field: ";
        std::cin >> sizes.first >> sizes.second;
        std::cout << std::endl;
    }
    return sizes;
}
