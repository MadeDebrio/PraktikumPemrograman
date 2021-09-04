#pragma once
#include<iostream>
#include "Player.h"
#include "Board.h"
using namespace std;

class GameManager
{
private:
    /* data */
    Board TicTacToe;
    Player Player1;
    Player Player2;
    char sym1;
    char sym2;
    string nama1;//berfungsi untuk menyimpan nama player, jika pemain tidak memasukkan player saat deklarasi objek;
    string nama2;//berfungsi untuk menyimpan nama player, jika pemain tidak memasukkan player saat deklarasi objek;
    int playerTurn;//berfungsi untuk menyimpan informasi giliran pemain.
    int kolom;//menyimpan data kolom sebagai input pemain
    int baris;//menyimpan data baris sebagai input pemain


public:
    GameManager();
    GameManager(Player p1, Player p2, char symbol1, char symbol2);
    void turn(char sym);
    void play();
    char checkWin();
};

