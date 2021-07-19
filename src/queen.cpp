#include "queen.h"
#include "util.h"
#include <vector>
#include <algorithm>
using namespace std;

queen::queen(COLOR c) : ChessMan(c) {}

void queen:: movePiece(MOVE m)
{

}


bool queen::access(std::string origin, std::string destination, std::array<std::array<Cell, 8>, 8> &board)
{
    Cell celltemp;
    vector<string> alfa = {"A", "B", "C", "D", "E", "F", "G", "H"};
    int num = get_num(origin);
    string temp;
    int temp_num = num - 1;
    while (temp_num >= 0)
    {
        temp += origin.at(0);
        temp += to_string(temp_num);
        if (temp == destination)
        {
            if (iscell(temp))
            {
                celltemp = search_cell(temp, board);
                if (!celltemp.getState())
                {
                    return true;
                }
                else
                {
                    temp.clear();
                    break;
                }
            }
        }
        temp.clear();
        temp_num--;
    }

    temp_num = num + 1;

    while (temp_num <= 8)
    {
        temp += origin.at(0);
        temp += to_string(temp_num);
        if (temp == destination)
        {
            if (iscell(temp))
            {
                celltemp = search_cell(temp, board);
                if (!celltemp.getState())
                {
                    return true;
                }
                else
                {
                    temp.clear();
                    break;
                }
            }
        }
        temp.clear();
        temp_num++;
    }
    char character[] = "a";
    get_char(origin , character);

    auto it = (find(alfa.cbegin(), alfa.cend(), character) - 1);

    while (it >= alfa.cbegin())
    {
        temp += (it)->at(0);
        temp += to_string(num);
        if (temp == destination)
        {
            if (iscell(temp))
            {
                celltemp = search_cell(temp, board);
                if (!celltemp.getState())
                {
                    return true;
                }
                else
                {
                    temp.clear();
                    break;
                }
            }
        }
        temp.clear();
        it--;
    }
    it = (find(alfa.cbegin(), alfa.cend(), character) + 1);

    while (it <= alfa.cend() - 1)
    {
        temp += (it)->at(0);
        temp += to_string(num);
        if (temp == destination)
        {
            if (iscell(temp))
            {
                celltemp = search_cell(temp, board);
                if (!celltemp.getState())
                {
                    return true;
                }
                else
                {
                    temp.clear();
                    break;
                }
            }
        }
        temp.clear();
        it++;
    }

    get_char(origin , character);
    it = (find(alfa.cbegin(), alfa.cend(), character) - 1);
    temp_num = num - 1;

    while ((it >= alfa.cbegin()) && (temp_num >= 0))
    {
        temp += (it)->at(0);
        temp += to_string(temp_num);
        if (temp == destination)
        {
            if (iscell(temp))
            {
                celltemp = search_cell(temp, board);
                if (!celltemp.getState())
                {
                    return true;
                }
                else
                {
                    temp.clear();
                    break;
                }
            }
        }
        temp.clear();
        it--;
        temp_num--;
    }

    temp_num = num + 1;
    it = (find(alfa.cbegin(), alfa.cend(), character) + 1);
    while ((it <= alfa.cend() - 1) && (temp_num <= 8))
    {
        temp += (it)->at(0);
        temp += to_string(temp_num);
        if (temp == destination)
        {
            if (iscell(temp))
            {
                celltemp = search_cell(temp, board);
                if (!celltemp.getState())
                {
                    return true;
                }
                else
                {
                    temp.clear();
                    break;
                }
            }
        }
        temp.clear();
        it++;
        temp_num++;
    }

    temp_num = num - 1;
    it = (find(alfa.cbegin(), alfa.cend(), character) + 1);
    while ((it <= alfa.cend() - 1) && (temp_num >= 0))
    {
        temp += (it)->at(0);
        temp += to_string(temp_num);
        if (temp == destination)
        {
            if (iscell(temp))
            {
                celltemp = search_cell(temp, board);
                if (!celltemp.getState())
                {
                    return true;
                }
                else
                {
                    temp.clear();
                    break;
                }
            }
        }
        temp.clear();
        it++;
        temp_num--;
    }

    temp_num = num + 1;
    it = (find(alfa.cbegin(), alfa.cend(), character) - 1);
    while ((it >= alfa.cbegin()) && (temp_num <= 8))
    {
        temp += (it)->at(0);
        temp += to_string(temp_num);
        if (temp == destination)
        {
            if (iscell(temp))
            {
                celltemp = search_cell(temp, board);
                if (!celltemp.getState())
                {
                    return true;
                }
                else
                {
                    temp.clear();
                    break;
                }
            }
        }
        temp.clear();
        it--;
        temp_num++;
    }
    return false;
}
