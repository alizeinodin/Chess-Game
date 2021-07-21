#include "pawn.h"
#include "util.h"
#include "cell.h"
#include <vector>
#include <algorithm>
using namespace std;

pawn::pawn(COLOR c) : ChessMan(c)
{
    piecetype = POWN;
}

void pawn::movePiece(MOVE move, std::array<std::array<Cell, 8>, 8> &board)
{
    Cell cells[2];
    if (move.at(0) == 'P')
    {
        auto cellsid = cut_str(move);
        if (this->access(cellsid.first, cellsid.second, board))
        {
            cells[0] = search_cell(cellsid.first, board);
            cells[0].empty();
            cells[1] = search_cell(cellsid.second, board);
            cells[1].setPiece(this);
        }
        else
        {
            if (!cells[1].getState())
            {
                attack(move, cells[1]);
            }
            throw invalid_argument("can not move!!!");
        }
    }
    throw invalid_argument("piece is not true");
}

bool pawn::access(std::string origin, std::string destination, std::array<std::array<Cell, 8>, 8> &board)
{
    threat_id.clear();
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
                            threat_id.push_back(temp);
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
                        threat_id.push_back(temp);
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
                            threat_id.push_back(temp);
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
                        threat_id.push_back(temp);
                        temp.clear();
                    }
                }
            }
            temp.clear();
        }
    }
    return false;
}

std::map<std::string, int> pawn::threat(std::string cellid, array<array<Cell, 8>, 8> &board)
{
    map<string, int> temp;
    this->access(cellid, "F5", board);
    for (size_t i = 0; i < threat_id.size(); i++)
    {
        if (threat_id.at(i) != this->get_color())
        {
            switch (search_cell(threat_id.at(i), board).getPiece()->get_type())
            {
            case QUEEN:
                temp.insert(make_pair(threat_id.at(i), 5));
                break;
            case ROOK:
            case BISHOP:
            case KNIGHT:
                temp.insert(make_pair(threat_id.at(i), 2));
                break;
            case POWN:
                temp.insert(make_pair(threat_id.at(i), 1));
                break;
            }
        }
    }
}