#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <utility>
#include "player.h"
#include "enemy.h"
#include <memory>
#include <vector>
#include "item.h"

using namespace std;

class Game
{
  string map[25] =
  {"|-----------------------------------------------------------------------------|",
   "|                                                                             |",
   "| |--------------------------|        |-----------------------|               |",
   "| |..........................|        |.......................|               |",
   "| |..........................+########+.......................|-------|       |",
   "| |..........................|   #    |...............................|--|    |",
   "| |..........................|   #    |..................................|--| |",
   "| |----------+---------------|   #    |----+----------------|...............| |",
   "|            #                 #############                |...............| |",
   "|            #                 #     |-----+------|         |...............| |",
   "|            #                 #     |............|         |...............| |",
   "|            ###################     |............|   ######+...............| |",
   "|            #                 #     |............|   #     |...............| |",
   "|            #                 #     |-----+------|   #     |--------+------| |",
   "|  |---------+-----------|     #           #          #              #        |",
   "|  |.....................|     #           #          #         |----+------| |",
   "|  |.....................|     ########################         |...........| |",
   "|  |.....................|     #           #                    |...........| |",
   "|  |.....................|     #    |------+--------------------|...........| |",
   "|  |.....................|     #    |.......................................| |",
   "|  |.....................+##########+.......................................| |",
   "|  |.....................|          |.......................................| |",
   "|  |---------------------|          |---------------------------------------| |",
   "|                                                                             |",
   "|-----------------------------------------------------------------------------|"};
   pair<int, int> generatePosition(int chamber);
   bool checkPlayerMove(int x, int y);
   bool checkEnemyMove(int x, int y);
   bool nextFloor;
   pair<int, int> chooseMove(pair<int, int> enemypos);
   pair<int, int> ppos;
   int seed;
 public:
   vector<shared_ptr<Enemy>> enemies;
   vector<shared_ptr<Item>> items;
   bool inputFloor;
   void displayMap();
   void generate();
   Game();
   Game(string temp[25]);
   void resetMap();
   bool getNextFloor();
   pair<pair<int, int>, char> movePlayer (string command, int playerx, int playery, char playerTile);
   void moveEnemies();
   pair<int, int> getPlayerPos();
   char at(int x, int y);
   void change(int x, int y, char ch);
   pair<pair<int, int>, bool> checkItem(string direction, pair<int, int> playerpos);
};

#endif
