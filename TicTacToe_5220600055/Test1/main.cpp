#include "GameManager.h"
#include <iostream>
using namespace std;

int main()
{

    Player Satu("Jono",0,0);
    Player dua("Joni",0,0);
    GameManager Game(Satu ,dua,'s','p');

    //GameManager Game;
    Game.play();
    return 0;
}
