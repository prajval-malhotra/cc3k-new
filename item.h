#ifndef ITEM_H
#define ITEM_H

#include <utility>

using namespace std;

class Item {
    double buff;
    pair<int, int> ItemPos;
    public:
    Item(double buff, pair<int, int> ItemPos);
    double getBuff();
    pair<int, int> getPos();
    ~Item();
};

#endif
