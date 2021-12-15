#include "enemy.h"

using namespace std;

Enemy::Enemy(pair<int, int> pos): hp{140}, atk{20}, def{20}, pos{pos} {}

void Enemy::setPos(pair<int, int> newPos){
  pos = newPos;
}

pair<int, int> Enemy::getPos(){
  return pos;
}

Enemy::~Enemy() {}
