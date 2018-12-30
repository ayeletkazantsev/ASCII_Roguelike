//
// Created by Ayelet on 12/29/2018.
//

#ifndef ASCII_ROUGUELIKE_GAMESYSTEM_H
#define ASCII_ROUGUELIKE_GAMESYSTEM_H

#include <string>
#include "Player.h"
#include "Level.h"
#include "Enemy.h"

class GameSystem {
public:
    GameSystem(string levelFileName);
    void playGame();
    void playerMove();
private:
    Level _level;
    Player _player;
    vector <Enemy> _enemies;
};


#endif //ASCII_ROUGUELIKE_GAMESYSTEM_H
