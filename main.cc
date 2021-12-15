#include "game.h"
#include <iostream>
#include <sstream>
#include <memory>
#include <fstream>
#include <vector>
#include <utility>
#include "player.h"

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
  cout << "Enter your command: ";
  cin >> input;
  if (cin.eof())
    return 0;
  while(input != "q" && !floors[curFloor]->getNextFloor())
  {
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
            floors[curFloor]->items.erase(i);
            break;
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
    floors[curFloor]->moveEnemies();
    if (!floors[curFloor]->getNextFloor())
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
