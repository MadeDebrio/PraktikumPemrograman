#include "GameManager.h"

GameManager::GameManager() {
    Player1.setMatchCount(Player1.getMatchCount() + 1);
    Player2.setMatchCount(Player2.getMatchCount() + 1);
    sym1 = ' ';
    sym2 = ' ';
};
GameManager::GameManager(Player p1, Player p2, char symbol1, char symbol2) {
    Player1 = p1;
    Player2 = p2;
    Player1.setMatchCount(Player1.getMatchCount() + 1);
    Player2.setMatchCount(Player2.getMatchCount() + 1);
    sym1 = symbol1;
    sym2 = symbol2;
};
void GameManager::turn(char sym) {
    cout << "Masukkan indeks baris : ";
    cin >> baris;
    cout << "Masukkan indeks kolom : ";
    cin >> kolom;

    TicTacToe.setValueAtIndex(baris,kolom,sym);
};
void GameManager::play() {

    if (Player1.getUsername() == "") {
        cout << "Masukkan Nama Player1 : ";
        cin >> nama1;
        cout << "Masukkan Nama Player2 : ";
        cin >> nama2;

        Player1.setUsername(nama1);
        Player2.setUsername(nama2);
        sym1 = nama1[0];
        sym2 = nama2[0];
    }

    playerTurn = 1;

    while (checkWin() == '0')
    {
        system("cls");
        //cetak board
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << TicTacToe.getValueAtIndex(i, j) << "\t";
            }
            cout << endl;
        }

        if (playerTurn == 1) {
            cout << "Giliran " << sym1 << " untuk menentukan kotak. " << endl << endl;
            turn(sym1);
        }
        else {
            cout << "Giliran " << sym2 << " untuk menentukan kotak. " << endl << endl;
            turn(sym2);
        }

        if (TicTacToe.isFull() && checkWin() == '0') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    TicTacToe.setValueAtIndex(i, j, '0');
                }
            }
        }

        //mengubah giliran pemain
        if (playerTurn == 1) {
            playerTurn = 2;
        }
        else {
            playerTurn = 1;
        }
    }

    if (checkWin() == sym1)
    {
        system("cls");
        //cetak board
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << TicTacToe.getValueAtIndex(i, j) << "\t";
            }
            cout << endl;
        }
        cout << "\nPemenang dari game ini adalah : " << Player1.getUsername();

        Player1.setWinCount(Player1.getWinCount() + 1);
    }
    else {
        system("cls");
        //cetak board
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << TicTacToe.getValueAtIndex(i, j) << "\t";
            }
            cout << endl;
        }
        cout << "\nPemenang dari game ini adalah : " << Player2.getUsername();

        Player2.setWinCount(Player2.getWinCount() + 1);
    }
    Player1.setMatchCount(Player1.getMatchCount() + 1);
    Player2.setMatchCount(Player2.getMatchCount() + 1);

    cout << "\n\nStat Kedua Player\n\n ";

    cout << Player1.getUsername() << endl;
    cout << "Total Match      : " << Player1.getMatchCount() << endl;
    cout << "Total Kemenangan : " << Player1.getWinCount() << endl << endl;

    cout << Player2.getUsername() << endl;
    cout << "Total Match      : " << Player2.getMatchCount() << endl;
    cout << "Total Kemenangan : " << Player2.getWinCount() << endl;
}
char GameManager::checkWin() {
    if (TicTacToe.checkSimilarValueVertically() != '0')
    {
        return TicTacToe.checkSimilarValueVertically();
    }
    else if (TicTacToe.checkSimilarValueHorizontally() != '0')
    {
        return TicTacToe.checkSimilarValueHorizontally();
    }
    else {
        return '0';
    }
};