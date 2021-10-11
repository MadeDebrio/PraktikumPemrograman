#pragma once
#include <iostream>
#include <string>
#include <set>
#include <fstream>//Call file

using namespace std;

class Board
{
	string xBoard[9][9];
	string solutionBoard[9][9];
	string fileName;
	int rowCounter;

public :
	Board(); 
	Board(string fileName, string answerFile);
	bool NotInRow(string arr[][9], int row);// Checks whether there is any duplicate in current row or not
	bool NotInColumn(string arr[][9], int col);// Checks whether there is any duplicate in current column or not.
	bool NotInBox(string arr[][9], int startRow, int startCol);// Checks whether there is any duplicate in current 3x3 box or not.
	bool IsValid(string arr[][9], int row, int col);// Checks whether current row and current column and current 3x3 box is valid or not
	bool IsValidConfig();

	bool IsAvailableAtIndex(int x, int y); //fungsi ini memberikan return value true jika board pada koordinat x dan y masih belum terisi.
	bool IsEmpty();	//fungsi ini memberikan return value true jika board masih kosong. 
	bool IsFull();	//fungsi ini memberikan return value true jika board sudah penuh.
	void SetValueAtIndex(int x, int y, string value);//fungsi ini digunakan untuk mengisi board pada koordinat x, y dengan nilai yang ada	pada variabel value.
	string GetValueAtIndex(int x, int y);//fungsi ini digunakan untuk mengambil nilai board pada koordinat x, y
	void BoardLoader(string Board[][9],string fileName);//Fungsi ini digunakan untuk loading board dari sebuah file txt.
	void DisplayBoard();//Fungsi ini digunakan untuk mencetak isi board
	void PisahDataBaris(string Board[][9], string line);
	int CheckAnswer(int x, int y);
};

