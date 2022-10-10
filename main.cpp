#include "views/PlayerView.h"
#include "models/Field.h"
#include "views/FieldView.h"
#include "controllers/Game.h"

int main()
{
    Player* player = new Player();
    PlayerView playerStatus(player, 15);
    CommandReader reader;

    reader.readFieldSize();
    Field field(reader.getFieldSize().first, reader.getFieldSize().second, player);
    FieldView fieldViewer(field);
    field.stdFieldGen();
    field.setPlayerCoord(0, 0);

    Controller controller(fieldViewer, playerStatus, field, *player);
    Game game(&controller, &reader);
    fieldViewer.setBorderChar('~');

    game.start();
    delete player;
    return 0;
}
