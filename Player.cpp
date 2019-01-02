//
// Created by Ayelet on 12/29/2018.
//
#include <random>
#include <ctime>
#include "Player.h"

using namespace std;

Player::Player() : _x(0),_y(0) {}

void Player::init(int level, int health, int attack, int defense, int experience)
{
    _level=level;
    _health=health;
    _attack=attack;
    _defense=defense;
    _experience=experience;
}

int Player::attack()
{
    static default_random_engine randomEngine(time(NULL));
    uniform_int_distribution<int> attackRoll(_attack/2,_attack);

    return attackRoll(randomEngine);
}

int Player::takeDamage(int attack)
{
    attack -= _defense;
    //check if attack does damage
    if (attack > 0)
    {
        _health -= attack;
        //check if monster died
        if (_health <=0 )
        {
            return 1;
        }
    }
    return 0;
}

void Player::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

void Player::addExperience(int experience)
{
    _experience += experience;

    //level up
    while (_experience > 50)
    {
        printf("Leveled up!\n");
        _experience -= 50;
        _attack += 10;
        _defense += 5;
        _health += 10;
        _level++;
        system("PAUSE");
    }
}

void Player::getPosition(int &x, int &y)
{
    x = _x;
    y = _y;
}