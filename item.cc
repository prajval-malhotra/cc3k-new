#include "item.h"

using namespace std;

Item::Item(double buff, pair<int, int> ItemPos): buff{buff}, ItemPos{ItemPos} {}

double Item::getBuff(){
    return buff;
}

pair<int, int> Item::getPos() {
    return ItemPos;
}

Item::~Item() {}
