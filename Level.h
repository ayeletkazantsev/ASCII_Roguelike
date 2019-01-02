//
// Created by Ayelet on 12/29/2018.
//

#ifndef ASCII_ROUGUELIKE_LEVEL_H
#define ASCII_ROUGUELIKE_LEVEL_H

#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Level {
public:
    Level();

    void load(string fileName, Player &player);
    void print();
    void movePlayer(char input, Player& player);
    void updateMonsters(Player& player);
    char getTile(int x, int y);
    void setTile(int x, int y, char tile);
private:
    vector<string> _levelData;
    vector <Enemy> _enemies;
    void processPlayerMove(Player& player, int targetX, int targetY);
    void processEnemyMove(Player& player, Enemy& enemy, int targetX, int targetY);
    void battleMonster(Player& player, int targetX, int targetY);
};


#endif //ASCII_ROUGUELIKE_LEVEL_H
