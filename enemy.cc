#include "enemy.h"

using namespace std;

Enemy::Enemy(pair<int, int> pos): hp{140}, atk{20}, def{20}, pos{pos} {}

void Enemy::setPos(pair<int, int> newPos){
  pos = make_pair(newPos.first, newPos.second);
}

pair<int, int> Enemy::getPos(){
  return make_pair(pos.first, pos.second);
}

Enemy::~Enemy() {}
