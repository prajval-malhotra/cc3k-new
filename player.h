#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <utility>
#include <memory>
#include "item.h"


using namespace std;

class Player {
    double hp;
    double atk;
    double def;
    double baseHp, baseAtk, baseDef;
    char tile;
    pair<int, int> pos;
  public:
    Player();

    void useItem(shared_ptr<Item>);
    
    void setPos(pair<int, int> newPos);

    void setHP(int);
    void setATK(double);
    void setDEF(double);
    int getHP();
    double getATK();
    double getDEF();
    double getBaseHP();
    double getBaseATK();
    double getBaseDEF();

    pair<int, int> getPos();
    void setTile(char newTile);
    char getTile();
    ~Player();
};

#endif
