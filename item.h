#ifndef _ITEM_H_ 
#define _ITEM_H_

#include <utility> 

using namespace std;

class Item {
    double buff;
    pair<int, int> ItemPos;
    public:
    Item(double buff, pair<int, int> ItemPos);
    double getBuff();
    pair<int, int> getItemPos(); 
    ~Item();
};

#endif