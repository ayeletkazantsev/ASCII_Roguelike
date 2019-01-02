//
// Created by Ayelet on 12/29/2018.
//
#include <string>
#include <iostream>
#include <conio.h>
#include "GameSystem.h"

using namespace std;
//constructor sets up the game
GameSystem::GameSystem(string levelFileName) {
    _player.init(1,100,10,10,0);
    _level.load(levelFileName,_player);

    //system("PAUSE");
}

void GameSystem::playGame()
{
    bool isDone = false;

    while (isDone == false)
    {
        _level.print();
        playerMove();
        _level.updateMonsters(_player);
    }
}

void GameSystem::playerMove()
{
    char input;
    cout << "Enter a move command (w/s/a/d): ";
    input = _getch();

    _level.movePlayer(input,_player);
}