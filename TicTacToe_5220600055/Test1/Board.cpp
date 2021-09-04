#include "Board.h"

Board::Board() {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            aBoard[i][j] = '0';
        }
    }
};
bool Board::isFull() {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (aBoard[i][j] == '0')
            {
                return false;
            }

        }
    }
    return true;
};

bool Board::isEmpty() {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (aBoard[i][j] != '0')
            {
                return false;
            }

        }
    }
    return true;
};

char Board::getValueAtIndex(int x, int y) {
    return aBoard[x][y];
};
void Board::setValueAtIndex(int x, int y, char value) {
    aBoard[x][y] = value;
};
char Board::checkSimilarValueVertically() {

    for (int i = 0; i < 3; i++)
    {
        if (aBoard[0][i] == aBoard[1][i] && aBoard[0][i] == aBoard[2][i] && aBoard[1][i] == aBoard[2][i] && aBoard[0][i] != '0')
        {
            return aBoard[0][i];
        }

    }
    return '0';
};
char Board::checkSimilarValueHorizontally() {
    for (int i = 0; i < 3; i++)
    {
        if (aBoard[i][0] == aBoard[i][1] && aBoard[i][0] == aBoard[i][2] && aBoard[i][1] == aBoard[i][2]&&aBoard[i][0]!='0')
        {
            return aBoard[i][0];
        }

    }
    return '0';
};