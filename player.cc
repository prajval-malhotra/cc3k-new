#include "player.h"

using namespace std;

Player::Player(): hp{125}, atk{25}, def{25}, baseHp{125}, baseAtk{25}, baseDef{25}, tile{'.'} {}

void Player::useItem(shared_ptr<Item> item) {
  double buff = item->getBuff();
  if(hp + buff >= 0) hp += buff;
  if(hp + buff >= getBaseHp()) hp = getBaseHp();
  if(atk + buff >= 0) atk += buff;
  if(def + buff >= 0) def += buff;
}

void Player::setHp(int new_hp) {
  hp = new_hp;
}

void Player::setAtk(double new_atk) {
  atk = new_atk;
}

void Player::setDef(double new_def) {
  def = new_def;
}

int Player::getHp() {
  return hp;
}

double Player::getAtk() {
  return atk;
}

double Player::getDef() {
  return def;
}

double Player::getBaseHp() {
  return baseHp;
}

double Player::getBaseAtk() {
  return baseAtk;
}

double Player::getBaseDef() {
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
