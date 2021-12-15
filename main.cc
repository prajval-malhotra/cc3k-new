#include "game.h"
#include <iostream>
#include <sstream>
#include <memory>
#include <fstream>
#include <vector>
#include <utility>
#include "player.h"
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
  vector<shared_ptr<Game>> floors;
  shared_ptr<Player> player;
  player = make_shared<Player>();
  char buffer;
  int curFloor = 0;
  string input;
  string direction;
  if (argc == 2)
  {
    ifstream infile(argv[1]);
    string line;
    string floor[25];
    int lnumber = 0;
    while(getline(infile, line))
    {
      if (lnumber >= 25)
      {
        floors.push_back(make_shared<Game>(floor));
        lnumber = 0;
      }
      floor[lnumber++] = line;
    }
    floors.push_back(make_shared<Game>(floor));
  }
  else
  {
    for (int i = 0; i < 5; ++i)
    {
      floors.push_back(make_shared<Game>());
      floors[i]->generate();
    }
  }
  pair<int, int> playerpos = floors[curFloor]->getPlayerPos();
  player->setPos(playerpos);
  floors[curFloor]->displayMap();
  cout << "HP: " << player->getHP() << endl;
  cout << "ATK: " << player->getATK() << endl;
  cout << "DEF: " << player->getDEF() << endl;
  cout << "Enter your command: ";
  cin >> input;
  if (cin.eof())
    return 0;
  while(input != "q" && !floors[curFloor]->getNextFloor() && player->getHP() > 0)
  {
    floors[curFloor]->resetCombat();
    if (input == "u")
    {
      cin >> direction;
      pair<pair<int, int>, bool> itemCheck = floors[curFloor]->checkItem(direction, player->getPos());
      if (itemCheck.second)
      {
        for (int i = 0; i < floors[curFloor]->items.size(); ++i)
        {
          if (floors[curFloor]->items[i]->getPos() == itemCheck.first)
          {
            player->useItem(floors[curFloor]->items[i]);
            floors[curFloor]->items.erase(floors[curFloor]->items.begin() + i);
            floors[curFloor]->change(itemCheck.first, '.');
            break;
          }
        }
      }
    }
    else if (input == "a")
    {
      cin >> direction;
      pair<pair<int, int>, bool> enemyCheck = floors[curFloor]->checkEnemy(direction, player->getPos());
      if (enemyCheck.second)
      {
        for (int i = 0; i < floors[curFloor]->enemies.size(); ++i)
        {
          if (floors[curFloor]->enemies[i]->getPos() == enemyCheck.first)
          {
            int dmg = player->damage(floors[curFloor]->enemies[i]);
            floors[curFloor]->enemies[i]->setHP(floors[curFloor]->enemies[i]->getHP() - dmg);
            if(floors[curFloor]->enemies[i]->getHP() <= 0)
            {
              floors[curFloor]->enemies.erase(floors[curFloor]->enemies.begin() + i);
              floors[curFloor]->change(enemyCheck.first, '.');
              break;
            }
          }
        }
      }
    }
    else
    {
      pair<pair<int, int>, char> playerstuff = floors[curFloor]->movePlayer(input, player->getPos().first, player->getPos().second, player->getTile());
      player->setPos(playerstuff.first);
      player->setTile(playerstuff.second);
    }

    // all enemies should have a boolean called combat = false. if they engage in combat, they cannot move.

    int playerx = player->getPos().first;
    int playery = player->getPos().second;

    for (int i = 0; i < floors[curFloor]->enemies.size(); ++i)
    {
      int enemyx = floors[curFloor]->enemies[i]->getPos().first;
      int enemyy = floors[curFloor]->enemies[i]->getPos().second;
      if (abs(playerx - enemyx) <= 1 && abs(playery - enemyy) <= 1)
      {
        int dmg = floors[curFloor]->enemies[i]->damage(player);
        player->setHP(player->getHP() - dmg);
        floors[curFloor]->enemies[i]->setCombat(true);
      }
    }
    floors[curFloor]->moveEnemies();
    if (!floors[curFloor]->getNextFloor() && player->getHP() > 0)
    {
      cout << "\f";
      floors[curFloor]->displayMap();
      cout << "HP: " << player->getHP() << endl;
      cout << "ATK: " << player->getATK() << endl;
      cout << "DEF: " << player->getDEF() << endl;
      cout << "Enter your command: ";
      cin >> input;
    }
  }
}
