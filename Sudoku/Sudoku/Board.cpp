#include "Board.h"

Board::Board()
{
    fileName = "SoalSudoku_1.txt";
    BoardLoader(xBoard,fileName);
    fileName = "JawabanSoalSudoku_1.txt";
    BoardLoader(solutionBoard,fileName);

}

Board::Board(string fileName, string answerFile)
{
    BoardLoader(xBoard, fileName);
    BoardLoader(solutionBoard, answerFile);
}


bool Board::NotInRow(string arr[][9], int row)
{
    // Set to store characters seen so far.
    set<string> st;

    for (int i = 0; i < 9; i++) {

        // If already encountered before, return false
        if (st.find(arr[row][i]) != st.end())
            return false;

        // If it is not an empty cell, insert value
        // at the current cell in the set
        if (arr[row][i] != "-")
            st.insert(arr[row][i]);
    }
    return true;
}

bool Board::NotInColumn(string arr[][9], int col)
{
    set<string> st;

    for (int i = 0; i < 9; i++) {

        // If already encountered before, return false
        if (st.find(arr[i][col]) != st.end())
            return false;

        // If it is not an empty cell,
        // insert value at the current cell in the set
        if (arr[i][col] != "-")
            st.insert(arr[i][col]);
    }
    return true;
}

bool Board::NotInBox(string arr[][9], int startRow, int startCol)
{
    set<string> st;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            string curr = arr[row + startRow][col + startCol];

            // If already encountered before, return false
            if (st.find(curr) != st.end())
                return false;

            // If it is not an empty cell,
            // insert value at current cell in set
            if (curr != "-")
                st.insert(curr);
        }
    }
    return true;
}

bool Board::IsValid(string arr[][9], int row, int col)
{
    return NotInRow(arr, row) && NotInColumn(arr, col) &&
        NotInBox(arr, row - row % 3, col - col % 3);
}

bool Board::IsValidConfig()
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            // If current row or current column or
            // current 3x3 box is not valid, return false
            if (!IsValid(xBoard, i, j))
                return false;
        }
    }
    return true;
}

bool Board::IsAvailableAtIndex(int x, int y)
{
    if (xBoard[x][y] == "-") {
        return true;
    }
    return false;
}

bool Board::IsEmpty()
{
    bool checker = true;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!IsAvailableAtIndex(i, j)) {
                checker = false;
            }
        }
    }
    return checker;
}

bool Board::IsFull()
{
    bool checker = true;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (IsAvailableAtIndex(i, j)) {
                checker = false;
            }
        }
    }
    return checker;
}

void Board::SetValueAtIndex(int x, int y, string value)
{
    xBoard[x][y] = value;
}

string Board::GetValueAtIndex(int x, int y)
{
	return xBoard[x][y];
}

void Board::BoardLoader(string Board[][9],string fileName)
{
    ifstream ReadBoard(fileName);
    string line;
    if (ReadBoard.is_open()) {


        for (rowCounter = 0; getline(ReadBoard, line); rowCounter++) {
            PisahDataBaris(Board, line);
        }
       
        ReadBoard.close();
    }
    else {
        cout << "Unable to open file";
    }
}

void Board::DisplayBoard()
{
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << "\t";
            }
            cout << xBoard[i][j];
        }
        cout << endl;
    }
}

void Board::PisahDataBaris(string Board[][9],string line)
{
    size_t found;//unsigned integral datatype
    for (int i = 0; i < 9; i++) {

            found = line.find_first_of(" ");

            Board[rowCounter][i].assign(line, 0, found);

            line.erase(0, found+1);
    }
}

int Board::CheckAnswer(int x, int y)
{
    if (xBoard[x][y] == solutionBoard[x][y]) {
        return 1;
    }
    return 0;
}
