#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <utility>

using namespace std;

class Player {
  int x, y;
  double hp;
  double atk;
  double def;
  char tile;
public:
  Player();
  void setPos(pair<int, int> newPos);
  pair<int, int> getPos();
  void setTile(char newTile);
  char getTile();
  ~Player();
};

#endif
