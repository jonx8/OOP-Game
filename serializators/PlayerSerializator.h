#pragma once

#include <string>
#include <memory>

class Player;

class PlayerSerializator {
public:
    static bool serialize(const std::string &filename, Player player);

    static std::unique_ptr<Player> deserialize(const std::string &filename);

};

