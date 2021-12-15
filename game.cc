#include "game.h"
#include <vector>
#include <cstdlib>

using namespace std;

Game :: Game() : inputFloor{false}, nextFloor{false}, ppos{make_pair(0, 0)} {}

Game :: Game(string temp[25]) : inputFloor{true}, nextFloor{false}, ppos{make_pair(0, 0)}
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
      index = rand() % positions.size();
      return positions[index];

    case 2:
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
          index = rand() % positions.size();
          return positions[index];

        case 2:
          for(i = 39; i <= 69; ++i)
          {
            if (map[5][i] == '.')
              positions.push_back(make_pair(5, i));
          }
          index = rand() % positions.size();
          return positions[index];

        case 3:
          for(i = 39; i <= 72; ++i)
          {
            if (map[6][i] == '.')
              positions.push_back(make_pair(6, i));
          }
          index = rand() % positions.size();
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
          index = rand() % positions.size();
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
        index = rand() % positions.size();
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
        index = rand() % positions.size();
        return positions[index];

      case 5:
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
            index = rand() % positions.size();
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
            index = rand() % positions.size();
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
  int i;
  // generate player first - @.
  int pchamber = (rand() % 5) + 1;
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
  int stchamber = chambers[rand() % 4];
  pair<int, int> stairpos = generatePosition(stchamber);
  map[stairpos.first][stairpos.second] = '\\';

  // then items - I.
  int itemchamber;
  pair<int, int> itempos;
  for(i = 0; i < 10; ++i)
  {
    itemchamber = (rand() % 5) + 1;
    itempos = generatePosition(itemchamber);
    map[itempos.first][itempos.second] = 'I';
  }

  // then enemies - E.
  int echamber;
  pair<int, int> enemypos;
  for(i = 0; i < 20; ++i)
  {
    echamber = (rand() % 5) + 1;
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
  return possibleMoves[rand() % possibleMoves.size()];
}

void Game :: moveEnemies()
{
  for (int i = 0; i < enemies.size(); ++i)
  {
    pair<int, int> newPos = chooseMove(enemies[i]->getPos());
    map[enemies[i]->getPos().first][enemies[i]->getPos().second] = '.';
    map[newPos.first][newPos.second] = 'E';
    enemies[i]->setPos(chooseMove(enemies[i]->getPos()));
  }
}
