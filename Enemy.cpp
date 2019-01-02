//
// Created by Ayelet on 12/30/2018.
//

#include <ctime>
#include <random>
#include "Enemy.h"

Enemy::Enemy(string name, char tile, int level, int attack, int defense, int health, int xp)
        : _name(name), _tile(tile), _level(level), _attack(attack), _health(health), _experienceValue(xp)
{}

int Enemy::attack()
{

}

int Enemy::takeDamage(int attack)
{
    attack -= _defense;
    //check if attack does damage
    if (attack > 0)
    {
        _health -= attack;
        //check if monster died
        if (_health <=0 )
        {
            return _experienceValue;
        }
    }
    return 0;
}

void Enemy::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

void Enemy::getPosition(int &x, int &y)
{
    x = _x;
    y = _y;
}

string Enemy::getName()
{
    return _name;
}

char Enemy::getMove(int playerX, int playerY)
{
    static default_random_engine randEngine (time(NULL));
    uniform_int_distribution<int> moveRoll(0,6);
    int distance;
    int dx = _x-playerX,dy=_y - playerY;
    int adx = abs(dx), ady = abs(dy);
    distance = adx + ady;
    if (distance <= 5)
    {
        //distance on X axis is smaller than distance on Y axis, so we move along X axis towards player
        if (adx > ady)
        {
            if (dx > 0)
            {
                return 'a';
            }
            return 'd';
        } else // move along Y axis towards player
        {
            if (dy > 0)
            {
                return 'w';
            }
            return 's';
        }
    }

    int randomMove = moveRoll(randEngine);
    switch (randomMove)
    {
        case 0: return 'a';
        case 1: return 'w';
        case 2: return 's';
        case 3: return 'd';
        default: return '.';
    }
}

char Enemy::getTile()
{
    return _tile;
}