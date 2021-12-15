#include "player.h"

using namespace std;

Player::Player(): hp{125}, atk{25}, def{25}, tile{'.'} {}

void Player::setPos(pair<int, int> newPos){
  pos = newPos;
}

pair<int, int> Player::getPos(){
  return pos;
}

void Player::setTile(char newTile) {
  tile = newTile;
}

char Player::getTile(){
  return tile;
}

Player::~Player() {}
