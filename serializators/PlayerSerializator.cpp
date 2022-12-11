#include <fstream>
#include <iostream>
#include "PlayerSerializator.h"
#include "../models/Player.h"


bool PlayerSerializator::serialize(const std::string &filename, Player *player) {

    std::ofstream out;
    out.open(filename);
    if (out.is_open()) {
        player->clearObs();
        out.write(reinterpret_cast<char *>(player), sizeof(*player));
        out.close();
    } else {
        return false;
    }
    return true;
}

std::unique_ptr<Player> PlayerSerializator::deserialize(const std::string &filename) {
    Player player;
    std::ifstream in;
    in.open(filename);
    if (in.is_open()) {
        std::cout << sizeof(Player) << std::endl;
        in.read(reinterpret_cast<char *>(&player), sizeof(Player));
    } else {
        throw std::runtime_error("Cannot open file");
    }
    return std::make_unique<Player>(player);
}
