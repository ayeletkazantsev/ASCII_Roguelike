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
    int attack();
    int takeDamage(int attack);
    //setters
    void setPosition(int x, int y);

    //getters
    void getPosition(int &x, int &y);
    string getName();

    //gets ai move command
    char getMove(int playerX, int playerY);
    char getTile();
private:
    //properties
    string _name;
    char _tile;
    int _level;
    int _attack;
    int _defense;
    int _health;
    int _experienceValue;

    //position
    int _x;
    int _y;
};


#endif //ASCII_ROUGUELIKE_ENEMY_H
