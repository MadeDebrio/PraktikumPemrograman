#include "Player.h"

Player::Player() {
    aUsername = "";
    winCount = 0;
    matchCount = 0;
};
Player::Player(string username, int win, int match) {
    aUsername = username;
    winCount = win;
    matchCount = match;
};
string Player::getUsername() {
    return aUsername;
};
void Player::setUsername(string uname) {
    aUsername = uname;
};
int Player::getWinCount() {
    return winCount;
};
void Player::setWinCount(int win) {
    winCount = win;
};
int Player::getMatchCount() {
    return matchCount;
};
void Player::setMatchCount(int match) {
    matchCount = match;
};