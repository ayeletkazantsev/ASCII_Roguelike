//
// Created by Ayelet on 12/30/2018.
//

#include "Enemy.h"

Enemy::Enemy(string name, char tile, int level, int attack, int defense, int health, int xp)
        : _name(name), _tile(tile), _level(level), _attack(attack), _health(health), __experienceValue(xp)
{}