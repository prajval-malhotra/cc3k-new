#ifndef _NME_H_
#define _NME_H_

#include <utility>

using namespace std;

class Enemy {
  double hp;
  double atk;
  double def;
  pair<int, int> pos;
public:
  Enemy(pair<int, int> pos);
  void setPos(pair<int, int>);
  pair<int, int> getPos();
  ~Enemy();
};

#endif
