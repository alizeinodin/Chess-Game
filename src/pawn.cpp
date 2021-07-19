#include "pawn.h"
#include "util.h"
#include "cell.h"
#include <vector>
#include <algorithm>
using namespace std;

pawn::pawn(COLOR c) : ChessMan(c) {}

void pawn::movePiece(MOVE move)
{
    if (move.at(0) == 'P')
    {
        /* code */
    }
}

bool pawn::access(std::string origin, std::string destination, std::array<std::array<Cell, 8>, 8> &board)
{
    Cell celltemp;
    int num = get_num(origin);
    string temp;
    if (color == "#000000")
    {
        if (num == 7)
        {
            int dy[] = {-1, -2};
            for (size_t i = 0; i < 2; i++)
            {
                temp += origin.at(0);
                temp += to_string(num + dy[i]);
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
            }
        }
        else
        {
            temp += origin.at(0);
            temp += to_string(num - 1);
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
                    }
                }
            }
            temp.clear();
        }
    }
    else
    {
        if (num == 2)
        {
            int dy[] = {-1, -2};
            for (size_t i = 0; i < 2; i++)
            {
                temp += origin.at(0);
                temp += to_string(num + dy[i]);
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
            }
        }
        else
        {
            temp += origin.at(0);
            temp += to_string(num + 1);
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
                    }
                }
            }
            temp.clear();
        }
    }
    return false;
}