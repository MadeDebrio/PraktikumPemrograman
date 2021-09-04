#pragma once
#include<iostream>
using namespace std;

class Board
{
private:
    /* data */
    char aBoard[3][3];

public:
    Board();
    bool isFull();
    bool isEmpty();
    char getValueAtIndex(int x, int y);
    void setValueAtIndex(int x, int y, char value);
    char checkSimilarValueVertically();
    char checkSimilarValueHorizontally();
};
