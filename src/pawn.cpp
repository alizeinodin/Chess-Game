#include "../include/pawn.h"
#include "include/util.h"
#include "include/cell.h"
#include "include/kishexcept.h"
#include <vector>
#include <algorithm>
using namespace std;

pawn::pawn(COLOR c) : ChessMan(c)
{
    piecetype = POWN;
}

void pawn::move(MOVE move, std::array<std::array<Cell, 8>, 8> &board)
{
    Cell cells[2];

    if (move.at(0) == 'P')
    {
        cout << move.at(0) << endl;
        auto cellsid = cut_str(move);
        //cout << cellsid.first << endl;
        //cout << cellsid.second << endl;
        this->access(cellsid.first, board);
        cout << boolalpha << possible.empty() << endl;
        for (size_t i = 0; i < possible.size(); i++)
        {
            //cout << possible.at(i).getId() << "\t" << cellsid.second <<endl;
            if (possible.at(i).getId() == cellsid.second)
            {
                cells[0] = search_cell(cellsid.first, board);
                cells[0].empty();
                cells[1] = search_cell(cellsid.second, board);
                cells[1].setPiece(this);
                return;
            }
            else
            {
                cells[0] = search_cell(cellsid.first, board);
                cells[1] = search_cell(cellsid.second, board);
                if (!cells[1].getState())
                {
                    cells[0].empty();
                    this->attack(move, cells[1]);
                    return;
                }
                throw invalid_argument("can not move!!!");
            }
        }
    }
    throw invalid_argument("piece is not true");
}

void pawn::access(std::string origin, std::array<std::array<Cell, 8>, 8> &board)
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
                if (iscell(temp))
                {
                    celltemp = search_cell(temp, board);
                    //cout << celltemp.getState();
                    if (celltemp.getState())
                    {
                        possible.push_back(celltemp);
                    }
                    else
                    {
                        threat_id.push_back(temp);
                        temp.clear();
                        break;
                    }
                }

                temp.clear();
            }
        }
        else
        {
            temp += origin.at(0);
            temp += to_string(num - 1);

            if (iscell(temp))
            {
                celltemp = search_cell(temp, board);
                //cout << celltemp.getState();
                if (celltemp.getState())
                {
                    possible.push_back(celltemp);
                }
                else
                {
                    threat_id.push_back(temp);
                    temp.clear();
                }
            }

            temp.clear();
        }
    }
    else
    {
        cout << num << endl;
        if (num == 2)
        {
            int dy[] = {1, 2};
            for (size_t i = 0; i < 2; i++)
            {
                temp += origin.at(0);
                temp += to_string(num + dy[i]);
                //cout << "temp" << temp << endl;
                //cout << "get" << iscell(temp);
                if (iscell(temp))
                {

                    celltemp = search_cell(temp, board);
                    cout << "get" << celltemp.getState();
                    if (celltemp.getState())
                    {
                        possible.push_back(celltemp);
                    }
                    else
                    {
                        threat_id.push_back(temp);
                        temp.clear();
                        break;
                    }
                }

                temp.clear();
            }
        }
        else
        {
            temp += origin.at(0);
            temp += to_string(num + 1);
            cout << temp << endl;
            if (iscell(temp))
            {
                celltemp = search_cell(temp, board);
                //cout << "get" << celltemp.getState();
                if (celltemp.getState())
                {
                    possible.push_back(celltemp);
                }
                else
                {
                    threat_id.push_back(temp);
                    temp.clear();
                }
            }
            temp.clear();
        }
    }
}

std::map<std::string, int> pawn::threat(std::string cellid, array<array<Cell, 8>, 8> &board)
{
    bool kish = false;
    map<string, int> temp;
    this->access(cellid, board);
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
            case KING:
                kish = true;
                break;
            }
        }
    }
    if (kish)
    {
        throw kishexcept();
    }
    return temp;
}

ChessMan  * pawn:: attack(std::string move, Cell & cell)
{
    ChessMan *attackpiece = cell.getPiece();
    auto temp = cut_str(move);
    if (!(attackpiece->get_color() == color) || !(attackpiece->get_color() == color))
    {
        if (binary_search(threat_id.cbegin(), threat_id.cend(), temp.second))
        {
            cell.empty();
            cell.setPiece(this);
            return attackpiece;
        }
    }
    throw invalid_argument("can not move!!!");
    return attackpiece;
}
