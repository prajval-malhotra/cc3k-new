#ifndef ENEMY_H
#define ENEMY_H

#include <utility>
#include <cmath>
#include "player.h"

using namespace std;

class Player;

class Enemy {
  bool combat;
  double hp;
  double atk;
  double def;
  pair<int, int> pos;
public:
  Enemy(pair<int, int> pos);
  int damage(shared_ptr<Player>);

  void setHP(int);
  void setATK(double);
  void setDEF(double);
  int getHP();
  double getATK();
  double getDEF();

  bool getCombat();
  void setCombat(bool);
  void setPos(pair<int, int>);
  pair<int, int> getPos();
  ~Enemy();
};

#endif
