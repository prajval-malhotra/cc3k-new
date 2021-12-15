#include "player.h"

using namespace std;

Player::Player(): hp{125}, atk{25}, def{25}, tile{'.'}, x{0}, y{0} {}

void Player::setPos(pair<int, int> newPos){
  x = newPos.first;
  y = newPos.second;
}

pair<int, int> Player::getPos(){
  return make_pair(x, y);
}

void Player::setTile(char newTile) {
  tile = newTile;
}

char Player::getTile(){
  return tile;
}

Player::~Player() {}
