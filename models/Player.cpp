#include "Player.h"

Player::Player() : health(100), HEALTH_MAX(100), damage(15), stamina(10), STAMINA_MAX(10), winner(false)
{
    setCoords(0, 0);
}

Player::Player(int healthMax, int damage, int staminaMax) : health(healthMax), HEALTH_MAX(healthMax), damage(damage), stamina(staminaMax), STAMINA_MAX(staminaMax), winner(false)
{
}

Player::~Player() {}

int Player::getHealth() const { return health; }
int Player::getHealthMax() const { return HEALTH_MAX; }
int Player::getDamage() const { return damage; }
int Player::getStamina() const { return stamina; }
int Player::getStaminaMax() const { return STAMINA_MAX; }
std::pair<uint, uint> Player::getCoords() const { return coords; }
bool Player::isDead() const { return !health; }
bool Player::isWin() const { return winner; }

void Player::setCoords(uint x, uint y)
{
    coords.first = x;
    coords.second = y;
}

void Player::setStamina(int stamina) { this->stamina = stamina; }
void Player::setDamage(int damage) { this->damage = damage; }
void Player::win() { winner = true; }
void Player::changeHealth(int value)
{
    // if the value of the parameter is incorrect, return false
    health += value;
    if (health < 0)
    {
        health = 0;
    }

    if (health > HEALTH_MAX)
    {
        health = HEALTH_MAX;
    }
}

void Player::setHealth(int health)
{
    // if the value of the parameter is incorrect, return false
    if (health >= 0 && health <= HEALTH_MAX)
    {
        this->health = health;
    }
}
