#ifndef _NME_H_
#define _NME_H_

#include <utility>

using namespace std;

class Enemy {
  int x, y;
  double hp;
  double atk;
  double def;
public:
  Enemy(pair<int, int> pos);
  void setPos(pair<int, int>);
  pair<int, int> getPos();
  ~Enemy();
};

#endif
