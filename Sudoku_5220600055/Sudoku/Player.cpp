#include "Player.h"

Player::Player(){
	exactness = 0 / 100;
	matchCount = 0;
	username = "";
	winCount = 0;
	winPercentage = 0;
}

Player::Player(string username, int MatchCount, int WinCount, float Exactness) {
	this->exactness = Exactness;
	this->matchCount = MatchCount;
	this->username = username; 
	this->winCount = WinCount;
	SetWinPercentage(MatchCount, WinCount);
}

void Player::SetExactness(int answer, int correct)
{
	exactness = correct / answer;
}

void Player::SetMatchCount(int match)
{
	matchCount = match;
}

void Player::SetUsername(string name)
{
	username = name;
}

void Player::SetWinCount(int winCount)
{
	this->winCount = winCount;
}

void Player::SetWinPercentage(int matchCount, int winCount)
{
	winPercentage = winCount / matchCount;
}

float Player::GetExactness()
{
	return exactness;
}

int Player::GetMatchCount()
{
	return matchCount;
}

string Player::GetUsername()
{
	return username;
}

int Player::GetWinCount()
{
	return winCount;
}

float Player::GetWinPercentage()
{
	return winPercentage;
}
