#include <iostream>
#include <conio.h>
#include "GameSystem.h"
using namespace std;

int main() {
    GameSystem gameSystem("level1.txt");
    gameSystem.playGame();
    return 0;
}