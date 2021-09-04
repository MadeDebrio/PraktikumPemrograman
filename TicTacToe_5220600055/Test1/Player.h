#pragma once
#include<iostream>
#include <string>
using namespace std;
class Player
{
private:
    /* data */
    string aUsername;
    int winCount;
    int matchCount;
public:
    Player();
    Player(string username, int win, int match);
    string getUsername();
    void setUsername(string uname);
    int getWinCount();
    void setWinCount(int win);
    int getMatchCount();
    void setMatchCount(int match);
};

