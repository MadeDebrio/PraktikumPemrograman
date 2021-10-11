#include "GameManager.h"

GameManager::GameManager()
{
	correctAns=0;
	turn=0;
    baris = 0;
    kolom = 0;
}

GameManager::GameManager(Player p1, Board b1)
{
	mainBoard=b1;
	player1=p1;
	correctAns = 0;
	turn = 0;
}

void GameManager::setAttemps(int attemp)
{
	turn = attemp;
}

int GameManager::getAttemps()
{
	return turn;
}

void GameManager::play()
{
		
    if (player1.GetUsername() == "") {
        cout << "Masukkan Nama Pemain : ";
        cin >> nama1;
        player1.SetUsername(nama1);
    }

    while (!checkWin())
    {
        system("cls");
        mainBoard.DisplayBoard();//cetak board
        
        cout << endl<< endl;
        cout << "Masukkan baris : ";
        cin >> baris;
        cout << "Masukkan kolom : ";
        cin >> kolom;
        cout << "Masukkan Nilai : ";
        cin >> value;

        mainBoard.SetValueAtIndex(baris-1, kolom-1, value);
        correctAns += mainBoard.CheckAnswer(baris, kolom);

        turn++;
        
    }
        system("cls");
        mainBoard.DisplayBoard();//cetak board

        cout << "\nSelamat anda berhasil menyelesaikan teka teki sudoku.";

        player1.SetWinCount(player1.GetWinCount() + 1);
        player1.SetMatchCount(player1.GetMatchCount() + 1);
        player1.SetExactness(turn,correctAns);
        player1.SetWinPercentage(player1.GetMatchCount(), player1.GetWinCount());

    cout << "\n\nStat  Player\n\n";

    cout << player1.GetUsername() << endl;
    cout << "Total Match      : " << player1.GetMatchCount() << endl;
    cout << "Total Kemenangan : " << player1.GetWinCount() << endl << endl;
    cout << "Persentase Kemenangan : " << player1.GetWinPercentage() << endl << endl;
    cout << "Ketepatan jawaban : " << player1.GetExactness() << endl << endl;
}

bool GameManager::checkWin()
{
	
	if (mainBoard.IsValidConfig()&&mainBoard.IsFull()) {
		return true;
	}
	return false;
}
