#include "ExplodeEvent.h"

ExplodeEvent::ExplodeEvent(int damage, int radius, EventsRegister *evReg) : MapEvent::MapEvent(radius),
                                                                             damage(damage), evReg(evReg) {}

ExplodeEvent::ExplodeEvent(const ExplodeEvent &obj) : MapEvent(obj) {
    damage = obj.damage;
    evReg = obj.evReg;
}

void ExplodeEvent::pushPlayer(uint distance, Field &field) {
    int direction = rand() % 4; // direction of the push
    for (size_t i = 0; i < distance; i++) {
        field.movePlayer(static_cast<Directions>(direction));
    }
}

void ExplodeEvent::interact(Player &player, Field &field) {
    notify(Message("ExplodeEvent executed", Message::INFO));
    if (player.hasArmor()) {
        player.setArmor(false);
    } else {
        player.changeHealth(-damage);
    }
    cellsTraversal(field);
    pushPlayer(radius, field);
}

Event *ExplodeEvent::clone() const {
    return new ExplodeEvent(*this);
}

void ExplodeEvent::cellsTraversal(Field &field) {
    Point playerCoords{};
    playerCoords.x = static_cast<int>(field.getPlayerCoords().first);
    playerCoords.y = static_cast<int>(field.getPlayerCoords().second);
    int h = field.getHeight();
    int w = field.getWidth();
    int y0 = playerCoords.y - radius;
    int x0 = playerCoords.x - radius;
    field.getCell(playerCoords.y, playerCoords.x).setEvent(evReg->getEvent(HEAL_EVENT));
    for (int i = y0; i <= y0 + 2 * radius; i++) {
        for (int j = x0; j <= x0 + 2 * radius; j++) {
            if (round(distanceCompute(Point(j, i), playerCoords)) <= radius) {
                if (field.getCell((i + h) % h, (j + w) % w).getType() == Cell::Objects::WALL) {
                    field.getCell((i + h) % h, (j + w) % w).setType(Cell::Objects::GROUND);
                }
            }
        }
    }
}