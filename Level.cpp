//
// Created by Ayelet on 12/29/2018.
//
#include <fstream>
#include <iostream>
#include <cstdio>
#include "Level.h"

Level::Level() = default;

void Level::load(string fileName, Player &player)
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
                     _enemies.push_back(Enemy("Snake", tile, 1, 3, 1, 10, 10));
                    _enemies.back().setPosition(j,i);
                             break;
                case 'g': //goblin
                    _enemies.push_back(Enemy("Goblin", tile, 1, 1, 1, 5, 50));
                    _enemies.back().setPosition(j,i);
                    break;
                case 'O': //ogre
                    _enemies.push_back(Enemy("Ogre", tile, 4, 20, 20, 200, 500));
                    _enemies.back().setPosition(j,i);
                    break;
                case 'D': //dragon
                    _enemies.push_back(Enemy("Dragon", tile, 100, 2000, 2000, 2000, 5000000));
                    _enemies.back().setPosition(j,i);
                    break;
                case 'B': //bandit
                    _enemies.push_back(Enemy("Bandit", tile, 3, 15, 10, 100, 250));
                    _enemies.back().setPosition(j,i);
                    break;
            }
        }
    }
}

void Level::print() {
    //cout << string(100,'\n');
    system("CLS");
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

void Level::updateMonsters(Player& player)
{
    char aiMove;
    int playerX, playerY;
    player.getPosition(playerX,playerY);
    for (int i=0; i<_enemies.size(); ++i)
    {
        Enemy& enemy = _enemies[i];
        int enemyX, enemyY;
        enemy.getPosition(enemyX,enemyY);
        aiMove = enemy.getMove(playerX,playerY);
        switch (aiMove)
        {
            case 'w': //up
                processEnemyMove(player,enemy,enemyX,enemyY - 1);
                break;
            case 's': //down
                processEnemyMove(player,enemy,enemyX,enemyY + 1);
                break;
            case 'a': //left
                processEnemyMove(player,enemy,enemyX - 1,enemyY);
                break;
            case 'd': //right
                processEnemyMove(player,enemy,enemyX + 1,enemyY);
                break;
            default:
                break;
        }
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
        case '#':
            break;
        default:
            battleMonster(player, targetX, targetY);
            break;
    }
}

void Level::processEnemyMove(Player& player, Enemy& enemy, int targetX, int targetY)
{
    char moveTile = getTile(targetX,targetY);
    int enemyX, enemyY;
    enemy.getPosition(enemyX,enemyY);
    switch (moveTile) {
        case '.':
            enemy.setPosition(targetX,targetY);
            setTile(enemyX,enemyY,'.');
            setTile(targetX,targetY, enemy.getTile());
            break;
        case '@':
            battleMonster(player, enemyX, enemyY);
            break;
        case '#':
            break;
    }
}

void Level::battleMonster(Player& player, int targetX, int targetY)
{
    int enemyX, enemyY;
    int playerX,playerY;
    int attackRoll, attackResult;
    string enemyName;

    player.getPosition(playerX,playerY);

    for (int i=0; i<_enemies.size(); ++i)
    {
        _enemies[i].getPosition(enemyX,enemyY);
        enemyName = _enemies[i].getName();
        if (targetX == enemyX && targetY == enemyY)
        {
            //battle!
            //player turn
            attackRoll = player.attack();
            printf("Player attacked %s with a roll of %d\n", enemyName.c_str(),attackRoll);
            system("PAUSE");
            attackResult = _enemies[i].takeDamage(attackRoll);
            if (attackResult != 0)
            {
                setTile(playerX,playerY,'.');
                setTile(targetX,targetY,'@');
                player.setPosition(targetX,targetY);
                print();
                printf("Monster died!\n");
                _enemies.erase(_enemies.begin() + i);
                i--;
                //system("PAUSE");
                player.addExperience(attackResult);
                return;
            }
            //monster turn
            attackRoll = _enemies[i].attack();
            printf ("%s attacked you with a roll of %d\n",enemyName.c_str(),attackRoll);
            attackResult = player.takeDamage(attackRoll);
            if (attackResult != 0)
            {
                setTile(playerX,playerY,'x');
                print();
                printf("You died!\n");
                system("PAUSE");
                exit(0);
            }
            //system("PAUSE");
            return;
        }
    }
}