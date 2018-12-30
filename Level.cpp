//
// Created by Ayelet on 12/29/2018.
//
#include <fstream>
#include <iostream>
#include <cstdio>
#include "Level.h"

Level::Level() {}

void Level::load(string fileName, Player &player, vector <Enemy>& enemies)
{
    //load the level
    ifstream file;
    file.open(fileName);
    if (file.fail())
    {
        perror(fileName.c_str());
        system("PAUSE");
        exit(1);
    }

    string line;

    while (getline(file, line))
    {
        _levelData.push_back(line);
    }
    file.close();

    //process the level
    char tile;
    for (int i=0; i< _levelData.size(); ++i)
    {
        for (int j=0; j<_levelData[i].size(); ++j)
        {
            tile = _levelData[i][j];

            switch (tile)
            {
                case '@' : //player
                    player.setPosition(j,i);
                    break;
                case 'S':  //snake
                     enemies.push_back(Enemy("Snake",tile,1,3,1,10,10));
                             break;
                case 'g': //goblin
                    enemies.push_back(Enemy("Goblin",tile,2,10,5,35,50));
                    break;
                case 'O': //ogre
                    enemies.push_back(Enemy("Ogre",tile,4,20,20,200,500));
                    break;
                case 'D': //dragon
                    enemies.push_back(Enemy("Dragon",tile,100,2000,2000,2000,5000000));
                    break;
                case 'B': //bandit
                    enemies.push_back(Enemy("Bandit",tile,3,15,10,100,250));
                    break;
            }
        }
    }
}

void Level::print() {
    cout << string(100,'\n');
    for (int i=0; i<_levelData.size(); ++i)
    {
        printf("%s\n",_levelData[i].c_str());
    }
    printf("\n");
}

void Level::movePlayer(char input, Player& player)
{
    int playerX, playerY;
    player.getPosition(playerX,playerY);

    switch (input)
    {
        case 'w': //up
        case 'W':
            processPlayerMove(player,playerX,playerY - 1);
            break;
        case 's': //down
        case 'S': processPlayerMove(player,playerX,playerY + 1);
            break;
        case 'a': //left
        case 'A': processPlayerMove(player,playerX - 1,playerY);
            break;
        case 'd': //right
        case 'D':processPlayerMove(player,playerX + 1,playerY);
            break;
        default:
            printf("INVALID INPUT!\n");
            break;
    }
}

char Level::getTile(int x, int y)
{
    return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile)
{
    _levelData[y][x] = tile;
}

void Level::processPlayerMove(Player& player, int targetX, int targetY)
{
    char moveTile = getTile(targetX,targetY);
    int playerX, playerY;
    player.getPosition(playerX,playerY);
    switch (moveTile) {
        case '.':
            player.setPosition(targetX,targetY);
            setTile(playerX,playerY,'.');
            setTile(targetX,targetY, '@');
            break;
    }
}