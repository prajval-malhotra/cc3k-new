#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <utility>

using namespace std;

class Player {
  double hp;
  double atk;
  double def;
  char tile;
  pair<int, int> pos;
public:
  Player();
  void setPos(pair<int, int> newPos);
  pair<int, int> getPos();
  void setTile(char newTile);
  char getTile();
  ~Player();
};

#endif
