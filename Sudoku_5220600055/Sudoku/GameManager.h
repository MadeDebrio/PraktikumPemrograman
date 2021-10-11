#pragma once
#include "Board.h";
#include "Player.h";

class GameManager
{
	Board mainBoard;
	Player player1;
	int correctAns;
	int turn;
	string nama1;//berfungsi untuk menyimpan nama player, jika pemain tidak memasukkan player saat deklarasi objek;
	int baris;//berfungsi untuk menyimpan baris tujuan
	int kolom;//berfungsi untuk menyimpan kolom tujuan
	string value;//berfungsi untuk menyimpan nilai board

public:
	GameManager();
	GameManager(Player p1, Board b1);
	void setAttemps(int attemp);
	int getAttemps();
	void play();
	bool checkWin();
};

