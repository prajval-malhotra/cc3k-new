#include "player.h"

using namespace std;

Player::Player(): hp{125}, atk{25}, def{25}, tile{'.'}, pos{make_pair(0, 0)} {}

void Player::setPos(pair<int, int> newPos){
  pos = make_pair(newPos.first, newPos.second);
}

pair<int, int> Player::getPos(){
  return make_pair(pos.first, pos.second);
}

void Player::setTile(char newTile) {
  tile = newTile;
}

char Player::getTile(){
  return tile;
}

Player::~Player() {}
