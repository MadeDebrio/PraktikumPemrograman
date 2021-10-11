#pragma once
#include <iostream>
#include <string>

using namespace std;

class Player
{
	int matchCount;
	int winCount;
	float exactness;
	float winPercentage;
	string username;
	

public :
	Player();
	Player(string username, int MatchCount, int WinCount, float Exactness);
	void SetExactness(int answer, int correct);
	void SetMatchCount(int match);
	void SetUsername(string name);
	void SetWinCount(int winCount);
	void SetWinPercentage(int matchCount, int winCount);
	float GetExactness();
	int GetMatchCount();
	string GetUsername();
	int GetWinCount();
	float GetWinPercentage();
};

