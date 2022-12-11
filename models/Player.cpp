#include "Player.h"

Player::Player() : health(100), HEALTH_MAX(100), stamina(100), STAMINA_MAX(100), winner(false), armor(false) {}

Player::~Player() = default;

int Player::getHealth() const { return health; }

int Player::getHealthMax() const { return HEALTH_MAX; }

int Player::getStamina() const { return stamina; }

int Player::getStaminaMax() const { return STAMINA_MAX; }

bool Player::isDead() {
    if (health == 0) {
        notify(Message("Player defeat", Message::INFO));
    }
    return not health;
}

bool Player::isWin() const { return winner; }

bool Player::hasArmor() const { return armor; }

void Player::win() {
    notify(Message("Player wins", Message::INFO));
    winner = true;
}

void Player::setArmor(bool value) {
    armor = value;
    notify(Message("Player take armor", Message::INFO));
}

void Player::changeHealth(int value) {
    health += value;
    if (health < 0) {
        health = 0;
    }

    if (health > HEALTH_MAX) {
        health = HEALTH_MAX;
    }

    notify(Message("Player health was changed to " + std::to_string(health), Message::INFO));
}

void Player::setHealth(int value) {
    if (value >= 0 and value <= HEALTH_MAX) {
        health = value;
    }
}

void Player::changeStamina(int value) {
    stamina += value;
    if (stamina < 0) {
        stamina = 0;
    }

    if (stamina > STAMINA_MAX) {
        stamina = STAMINA_MAX;
    }

}


