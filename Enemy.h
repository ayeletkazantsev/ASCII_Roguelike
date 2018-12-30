//
// Created by Ayelet on 12/30/2018.
//

#ifndef ASCII_ROUGUELIKE_ENEMY_H
#define ASCII_ROUGUELIKE_ENEMY_H

#include <string>
using namespace std;

class Enemy {
public:
    Enemy(string name, char tile, int level, int attack, int defense, int health, int xp);
private:
    string _name;
    char _tile;
    int _level;
    int _attack;
    int _defense;
    int _health;
    int _experienceValue;
};


#endif //ASCII_ROUGUELIKE_ENEMY_H
