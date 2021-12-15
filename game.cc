#include "game.h"
#include <vector>
#include <cstdlib>
#include "PRNG.h"
#include <ctime>

using namespace std;

Game :: Game() : inputFloor{false}, nextFloor{false}, seed{1024}  {}

Game :: Game(string temp[25]) : inputFloor{true}, nextFloor{false}, seed{1024}
{
  for (int i = 0; i < 25; ++i)
  {
    map[i] = temp[i];
  }
}

void Game::displayMap()
{
  for(int i = 0; i < 25; ++i)
  {
    cout << map[i] << endl;
  }
}

void Game::resetMap()
{
  string temp[25] =
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
   "| |---------+-----------|      #           #          #              #        |",
   "| |.....................|      #           #          #         |----+------| |",
   "| |.....................|      ########################         |...........| |",
   "| |.....................|      #           #                    |...........| |",
   "| |.....................|      #    |------+--------------------|...........| |",
   "| |.....................|      #    |.......................................| |",
   "| |.....................+###########+.......................................| |",
   "| |.....................|           |.......................................| |",
   "| |---------------------|           |---------------------------------------| |",
   "|                                                                             |",
   "|-----------------------------------------------------------------------------|"};
   for (int i = 0; i < 25; ++i)
   {
     map[i] = temp[i];
   }
}

pair<int, int> Game::generatePosition(int chamber)
{
  srand(time(NULL));
  PRNG prng(rand() % RAND_MAX);
  PRNG prng1(prng());
  int x, y, index, rect, i, j;
  vector<pair<int, int>> positions;
  switch(chamber)
  {
    case 1:
      for(i = 3; i <= 6; ++i)
      {
        for(j = 3; j <= 28; ++j)
        {
          if (map[i][j] == '.')
            positions.push_back(make_pair(i, j));
        }
      }
      index = prng(positions.size() - 1);
      return positions[index];

    case 2:
      srand(seed++);
      rect = (rand() % 4) + 1;
      switch(rect)
      {
        case 1 :
          for(i = 3; i <= 4; ++i)
          {
            for(j = 39; j <= 61; ++j)
            {
              if (map[i][j] == '.')
                positions.push_back(make_pair(i, j));
            }
          }
          index = prng(positions.size() - 1);
          return positions[index];

        case 2:
          for(i = 39; i <= 69; ++i)
          {
            if (map[5][i] == '.')
              positions.push_back(make_pair(5, i));
          }
          index = prng(positions.size() - 1);
          return positions[index];

        case 3:
          for(i = 39; i <= 72; ++i)
          {
            if (map[6][i] == '.')
              positions.push_back(make_pair(6, i));
          }
          index = prng(positions.size() - 1);
          return positions[index];

        case 4:
          for(i = 7; i <= 12; ++i)
          {
            for(j = 61; j <= 75; ++j)
            {
              if (map[i][j] == '.')
                positions.push_back(make_pair(i, j));
            }
          }
          index = prng(positions.size() - 1);
          return positions[index];

        default:
          return make_pair(0, 0);
      }

      case 3:
        for(i = 10; i <= 12; ++i)
        {
          for(j = 38; j <= 49; ++j)
          {
            if (map[i][j] == '.')
              positions.push_back(make_pair(i, j));
          }
        }
        index = prng(positions.size() - 1);
        return positions[index];

      case 4:
        for(i = 15; i <= 21; ++i)
        {
          for(j = 4; j <= 24; ++j)
          {
            if (map[i][j] == '.')
              positions.push_back(make_pair(i, j));
          }
        }
        index = prng(positions.size() - 1);
        return positions[index];

      case 5:
      srand(seed++);
      rect = (rand() % 2) + 1;
        switch(rect)
        {
          case 1 :
            for(i = 16; i <= 18; ++i)
            {
              for(j = 65; j <= 75; ++j)
              {
                if (map[i][j] == '.')
                  positions.push_back(make_pair(i, j));
              }
            }
            index = prng(positions.size() - 1);
            return positions[index];

          case 2:
            for(i = 19; i <= 21; ++i)
            {
              for(j = 37; j <= 75; ++j)
              {
                if (map[i][j] == '.')
                  positions.push_back(make_pair(i, j));
              }
            }
            index = prng(positions.size() - 1);
            return positions[index];

          default:
            return make_pair(0, 0);
        }

      default:
        return make_pair(0, 0);
  }
}

void Game :: generate()
{
  srand(time(NULL));
  PRNG prng(rand() % RAND_MAX);
  int i;
  // generate player first - @.
  int pchamber = prng(1, 5);
  ppos = generatePosition(pchamber);
  map[ppos.first][ppos.second] = '@';

  // then stairway location - \.
  vector<int> chambers;

  for (i = 1; i <= 5; ++i)
  {
    if (i != pchamber)
    {
      chambers.push_back(i);
    }
  }
  int stchamber = chambers[prng(3)];
  pair<int, int> stairpos = generatePosition(stchamber);
  map[stairpos.first][stairpos.second] = '\\';

  // then items - I.
  int itemchamber;
  pair<int, int> itempos;
  for(i = 0; i < 10; ++i)
  {
    itemchamber = prng(1, 5);
    itempos = generatePosition(itemchamber);
    map[itempos.first][itempos.second] = 'I';
    int buff = prng(1, 20);
    items.push_back(make_shared<Item>(buff, itempos));
  }

  // then enemies - E.
  int echamber;
  pair<int, int> enemypos;
  for(i = 0; i < 20; ++i)
  {
    echamber = prng(1, 5);
    enemypos = generatePosition(echamber);
    map[enemypos.first][enemypos.second] = 'E';
    enemies.push_back(make_shared<Enemy>(enemypos));
  }
}

bool Game :: checkPlayerMove(int x, int y)
{
  switch(map[x][y])
  {
    case '.':
    case '+':
    case '#':
      return true;
    case '\\':
      nextFloor = true;
      return true;
    default:
      return false;
  }
}

bool Game :: checkEnemyMove(int x, int y)
{
  switch (map[x][y])
  {
      case '.':
        return true;
      default:
        return false;
  }
}

bool Game :: getNextFloor ()
{
  return nextFloor;
}

pair<pair<int, int>, char> Game :: movePlayer (string command, int playerx, int playery, char playerTile)
{
  if (command == "no")
  {
    if (checkPlayerMove(playerx - 1, playery))
    {
      map[playerx--][playery] = playerTile;
      playerTile = map[playerx][playery];
      map[playerx][playery] = '@';
      return make_pair(make_pair(playerx, playery), playerTile);
    }
    else
    {
      cout << "no.\n";
      return make_pair(make_pair(playerx, playery), playerTile);
    }
  }
  else if (command == "nw")
  {
    if (checkPlayerMove(playerx - 1, playery - 1))
    {
      map[playerx--][playery--] = playerTile;
      playerTile = map[playerx][playery];
      map[playerx][playery] = '@';
      return make_pair(make_pair(playerx, playery), playerTile);
    }
    else
    {
      cout << "no.\n";
      return make_pair(make_pair(playerx, playery), playerTile);
    }
  }
  else if (command == "ne")
  {
    if (checkPlayerMove(playerx - 1, playery + 1))
    {
      map[playerx--][playery++] = playerTile;
      playerTile = map[playerx][playery];
      map[playerx][playery] = '@';
      return make_pair(make_pair(playerx, playery), playerTile);
    }
    else
    {
      cout << "no.\n";
      return make_pair(make_pair(playerx, playery), playerTile);
    }
  }
  else if (command == "w")
  {
    if (checkPlayerMove(playerx, playery - 1))
    {
      map[playerx][playery--] = playerTile;
      playerTile = map[playerx][playery];
      map[playerx][playery] = '@';
      return make_pair(make_pair(playerx, playery), playerTile);
    }
    else
    {
      cout << "no.\n";
      return make_pair(make_pair(playerx, playery), playerTile);
    }
  }
  else if (command == "e")
  {
    if (checkPlayerMove(playerx, playery + 1))
    {
      map[playerx][playery++] = playerTile;
      playerTile = map[playerx][playery];
      map[playerx][playery] = '@';
      return make_pair(make_pair(playerx, playery), playerTile);
    }
    else
    {
      cout << "no.\n";
      return make_pair(make_pair(playerx, playery), playerTile);
    }
  }
  else if (command == "so")
  {
    if (checkPlayerMove(playerx + 1, playery))
    {
      map[playerx++][playery] = playerTile;
      playerTile = map[playerx][playery];
      map[playerx][playery] = '@';
      return make_pair(make_pair(playerx, playery), playerTile);
    }
    else
    {
      cout << "no.\n";
      return make_pair(make_pair(playerx, playery), playerTile);
    }
  }
  else if (command == "sw")
  {
    if (checkPlayerMove(playerx + 1, playery - 1))
    {
      map[playerx++][playery--] = playerTile;
      playerTile = map[playerx][playery];
      map[playerx][playery] = '@';
      return make_pair(make_pair(playerx, playery), playerTile);
    }
    else
    {
      cout << "no.\n";
      return make_pair(make_pair(playerx, playery), playerTile);
    }
  }
  else if (command == "se")
  {
    if (checkPlayerMove(playerx + 1, playery + 1))
    {
      map[playerx++][playery++] = playerTile;
      playerTile = map[playerx][playery];
      map[playerx][playery] = '@';
      return make_pair(make_pair(playerx, playery), playerTile);
    }
    else
    {
      cout << "no.\n";
      return make_pair(make_pair(playerx, playery), playerTile);
    }
  }
  else
  {
    cout << "how?\n";
    return make_pair(make_pair(playerx, playery), playerTile);
  }
}

pair<int, int> Game :: getPlayerPos()
{
  return ppos;
}

pair<int, int> Game :: chooseMove(pair<int, int> enemypos)
{
  vector<pair<int, int>> possibleMoves;
  for (int i = -1; i <= 1; ++i)
  {
    for (int j = -1; j <= 1; ++j)
    {
      if (i == 0 && j == 0)
        continue;
      else
      {
        if (checkEnemyMove(enemypos.first + i, enemypos.second + j))
        {
          possibleMoves.push_back(make_pair(enemypos.first + i, enemypos.second + j));
        }
      }
    }
  }
  if (possibleMoves.size() != 0)
  {
    return possibleMoves[rand() % possibleMoves.size()];
  }
  else
    return make_pair(0, 0);
}

void Game :: moveEnemies()
{
  for (int i = 0; i < enemies.size(); ++i)
  {
    pair<int, int> newPos = chooseMove(enemies[i]->getPos());
    if (newPos.first == 0 && newPos.second == 0)
    {}
    else
    {
      map[enemies[i]->getPos().first][enemies[i]->getPos().second] = '.';
      map[newPos.first][newPos.second] = 'E';
      enemies[i]->setPos(newPos);
    }
  }
}

char Game :: at(int x, int y)
{
  return map[x][y];
}

pair<pair<int, int>, bool> Game :: checkItem(string direction, pair<int, int> playerpos)
{
  pair<int, int> location = make_pair(0, 0);
  if (direction == "no")
  {
    location.first = playerpos.first - 1;
    location.second = playerpos.second;
    if(at(playerpos.first - 1, playerpos.second) == 'I')
      return make_pair(location, true);
    else
      return make_pair(location, false);
  }
  else if (direction == "nw")
  {
    location.first = playerpos.first - 1;
    location.second = playerpos.second - 1;
    if(at(playerpos.first - 1, playerpos.second - 1) == 'I')
      return make_pair(location, true);
    else
      return make_pair(location, false);
  }
  else if (direction == "ne")
  {
    location.first = playerpos.first - 1;
    location.second = playerpos.second + 1;
    if(at(playerpos.first - 1, playerpos.second + 1) == 'I')
      return make_pair(location, true);
    else
      return make_pair(location, false);
  }
  else if (direction == "w")
  {
    location.first = playerpos.first;
    location.second = playerpos.second - 1;
    if(at(playerpos.first, playerpos.second - 1) == 'I')
      return make_pair(location, true);
    else
      return make_pair(location, false);
  }
  else if (direction == "e")
  {
    location.first = playerpos.first;
    location.second = playerpos.second + 1;
    if(at(playerpos.first, playerpos.second + 1) == 'I')
      return make_pair(location, true);
    else
      return make_pair(location, false);
  }
  else if (direction == "so")
  {
    location.first = playerpos.first + 1;
    location.second = playerpos.second;
    if(at(playerpos.first + 1, playerpos.second) == 'I')
      return make_pair(location, true);
    else
      return make_pair(location, false);
  }
  else if (direction == "sw")
  {
    location.first = playerpos.first + 1;
    location.second = playerpos.second - 1;
    if(at(playerpos.first + 1, playerpos.second - 1) == 'I')
      return make_pair(location, true);
    else
      return make_pair(location, false);
  }
  else if (direction == "se")
  {
    location.first = playerpos.first + 1;
    location.second = playerpos.second + 1;
    if(at(playerpos.first + 1, playerpos.second + 1) == 'I')
      return make_pair(location, true);
    else
      return make_pair(location, false);
  }
  else
  {
    return make_pair(location, false);
  }
}

void Game :: change(int x, int y, char ch)
{
  map[x][y] = ch;
}
