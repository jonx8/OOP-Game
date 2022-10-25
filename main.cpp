#include "eventsRegister/EventsRegister.h"
#include "views/PlayerView.h"
#include "models/Field.h"
#include "views/FieldView.h"
#include "observers/Observer.h"
#include "controllers/Game.h"

int main()
{
    // Observers map initializing

    observers_map observers;
    observers[READER_OBS] = new Observer("ReaderObserver");
    observers[EVENTS_OBS] = new Observer("EventObserver");
    observers[FIELD_OBS] = new Observer("FieldObserver");
    observers[PLAYER_OBS] = new Observer("PlayerObserver");
    
    // Player initialization
    Player *player = new Player;
    player->addObserver(observers[PLAYER_OBS]);

    // Reader initialization
    CommandReader *reader = new CommandReader;
    reader->addObserver(observers[READER_OBS]);

    // Events Register initialization
    EventsRegister *evReg = new EventsRegister(observers[EVENTS_OBS]);

    // Field initializing
    reader->readFieldSize();
    Field field(reader->getFieldSize().first, reader->getFieldSize().second, player);
    field.setEventRegister(evReg);
    field.stdFieldGen();
    field.setPlayerCoord(0, 0);
    field.addObserver(observers[FIELD_OBS]);

    // Views initialization
    PlayerView playerStatus(player, 15);
    FieldView fieldViewer(field);
    fieldViewer.setBorderChar('@');

    Controller *controller = new Controller(fieldViewer, playerStatus, field, *player);
    Game game(controller, reader, observers);

    game.start();
    delete player;
    delete controller;
    delete reader;
    delete evReg;
    for (auto i: observers)
    {
        delete i.second;
    }
    return 0;
}
