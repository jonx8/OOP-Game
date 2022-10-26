#include "loggers/FileLogger.h"
#include "loggers/ConsoleLogger.h"
#include "eventsRegister/EventsRegister.h"
#include "views/PlayerView.h"
#include "models/Field.h"
#include "views/FieldView.h"
#include "observers/Observer.h"
#include "controllers/Game.h"

int main()
{
    Observer *obs = new Observer("GameObs");
    Logger *fileLog = new FileLogger("gamelogs.log");
    Logger *logger = new ConsoleLogger();
    obs->addLogger(fileLog);
    //obs->addLogger(logger);

    // Player initialization
    Player *player = new Player;
    player->addObserver(obs);

    // Reader initialization
    CommandReader *reader = new CommandReader;
    reader->addObserver(obs);

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
    delete fileLog;
    delete logger;
    return 0;
}
