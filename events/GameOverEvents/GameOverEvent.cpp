#include "GameOverEvent.h"
//void Field::setPlayerCoord(uint, uint);

GameOverEvent::GameOverEvent(std::string msg) : msg(msg) {}

void GameOverEvent::interact(Field *field) 
{
    field->setPlayerCoord(10, 10);
}