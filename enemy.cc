#include "enemy.h"

using namespace std;

Enemy::Enemy(pair<int, int> pos): combat{false}, hp{140}, atk{20}, def{20}, pos{pos} {}

int Enemy::damage(shared_ptr<Player> player) {
  // Damage(Defender) = ceiling((100/(100 + Def(Defender))) ∗ Atk(Attacker))
  int new_damage = ceil((100/(100 + player->getDEF())) * atk);
  return new_damage;
}


void Enemy::setHP(int new_hp) {
  hp = new_hp;
}

void Enemy::setATK(double new_atk) {
  atk = new_atk;
}

void Enemy::setDEF(double new_def) {
  def = new_def;
}

int Enemy::getHP() {
  return hp;
}

double Enemy::getATK() {
  return atk;
}

double Enemy::getDEF() {
  return def;
}


bool Enemy::getCombat() {
  return combat;
}

void Enemy::setCombat(bool new_combat) {
  combat = new_combat;
}

void Enemy::setPos(pair<int, int> newPos){
  pos = newPos;
}

pair<int, int> Enemy::getPos(){
  return pos;
}

Enemy::~Enemy() {}
