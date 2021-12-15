#include "enemy.h"

using namespace std;

Enemy::Enemy(pair<int, int> pos): hp{140}, atk{20}, def{20}, x{pos.first}, y{pos.second} {}

void Enemy::setPos(pair<int, int> newPos){
  x = newPos.first;
  y = newPos.second;
}

pair<int, int> Enemy::getPos(){
  return make_pair(x, y);
}

Enemy::~Enemy() {}
