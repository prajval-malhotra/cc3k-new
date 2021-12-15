#include "player.h"
#include <cstdlib>
#include <cmath>

using namespace std;

Player::Player(): hp{125}, atk{25}, def{25}, baseHp{125}, baseAtk{25}, baseDef{25}, tile{'.'} {}

void Player::useItem(shared_ptr<Item> item) {
  double buff = item->getBuff();
  if(hp + buff >= 0) hp += buff;
  if(hp + buff >= getBaseHP()) hp = getBaseHP();
  if(atk + buff >= 0) atk += buff;
  if(def + buff >= 0) def += buff;
}

int Player::damage(shared_ptr<Enemy> enemy) {
  // Damage(Defender) = ceiling((100/(100 + Def(Defender))) ∗ Atk(Attacker))
  int new_damage = ceil((100/(100 + enemy->getDEF())) * atk);
  return new_damage;
}

void Player::setHP(int new_hp) {
  hp = new_hp;
}

void Player::setATK(double new_atk) {
  atk = new_atk;
}

void Player::setDEF(double new_def) {
  def = new_def;
}

int Player::getHP() {
  return hp;
}

double Player::getATK() {
  return atk;
}

double Player::getDEF() {
  return def;
}

double Player::getBaseHP() {
  return baseHp;
}

double Player::getBaseATK() {
  return baseAtk;
}

double Player::getBaseDEF() {
  return baseDef;
}

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
