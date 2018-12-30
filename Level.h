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

    void load(string fileName, Player &player, vector <Enemy>& enemies);
    void print();

    void movePlayer(char input, Player& player);
    char getTile(int x, int y);
    void setTile(int x, int y, char tile);
private:
    vector<string> _levelData;

    void processPlayerMove(Player& player, int targetX, int targetY);
};


#endif //ASCII_ROUGUELIKE_LEVEL_H
