#include "loggers/FileLogger.h"
#include "loggers/ConsoleLogger.h"
#include "eventsRegister/EventsRegister.h"
#include "views/PlayerView.h"
#include "models/Field.h"
#include "views/FieldView.h"
#include "observers/LogObserver.h"
#include "controllers/Game.h"

int main()
{

    LogObserver *obs = new LogObserver("GameObs");

    // Player initialization
    Player *player = new Player;
    player->addObserver(obs);

    // Reader initialization
    CommandReader *reader = new CommandReader;
    reader->addObserver(obs);

    // Loggers initialization
    enum logMethod
    {
        NO_LOG = 1,
        CONSOLE_LOG,
        FILE_LOG,
        CONSOLE_FILE_LOG,
    };
    // First - method of logging, second - level of logging
    std::pair<int, int> log_params = reader->readLogParams();

    // Console logger initialization
    if (log_params.first == CONSOLE_LOG || log_params.first == CONSOLE_FILE_LOG)
    {
        ConsoleLogger *console_logger = new ConsoleLogger;
        console_logger->setLevel(static_cast<Message::MSG_TYPE>(log_params.second));
        obs->addLogger(console_logger);
    }

    // File logger initialization
    if (log_params.first == FILE_LOG || log_params.first == CONSOLE_FILE_LOG)
    {
        FileLogger *file_logger = new FileLogger("gamelogs.log");
        file_logger->setLevel(static_cast<Message::MSG_TYPE>(log_params.second));
        obs->addLogger(file_logger);
    }

    // Events Register initialization
    EventsRegister *evReg = new EventsRegister(obs);

    // Field initializing
    reader->readFieldSize();
    Field field(reader->getFieldSize().first, reader->getFieldSize().second, player);
    field.setEventRegister(evReg);
    field.stdFieldGen();
    field.setPlayerCoord(0, 0);
    field.addObserver(obs);

    // Views initialization
    PlayerView playerStatus(player, 15);
    FieldView fieldViewer(field);
    fieldViewer.setBorderChar('@');

    Controller *controller = new Controller(fieldViewer, playerStatus, field, *player);
    Game game(controller, reader, obs);

    game.start();
    delete player;
    delete controller;
    delete reader;
    delete evReg;
    delete obs;
    return 0;
}
