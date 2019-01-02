//
// Created by Ayelet on 12/29/2018.
//

#ifndef ASCII_ROUGUELIKE_PLAYER_H
#define ASCII_ROUGUELIKE_PLAYER_H


class Player {
public:
    Player();
    void init(int level, int health, int attack, int defense, int experience);

    int attack();
    int takeDamage(int attack);
    //setters
    void setPosition(int x, int y);
    void addExperience(int experience);

    //getters
    void getPosition(int &x, int &y);

private:
    int _level;
    int _health;
    int _attack;
    int _defense;
    int _experience;
    int _x;
    int _y;
};


#endif //ASCII_ROUGUELIKE_PLAYER_H
