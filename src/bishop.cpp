#include "bishop.h"
#include "util.h"
#include <vector>
#include <algorithm>
using namespace std;

bishop::bishop(COLOR c) : ChessMan(c)
{
    piecetype = BISHOP;
}

void bishop::move(MOVE move, std::array<std::array<Cell, 8>, 8> &board)
{
    Cell cells[2];
    if (move.at(0) == 'B')
    {
        auto cellsid = cut_str(move);
        this->access(cellsid.first, board);
        for (size_t i = 0; i < possible.size(); i++)
        {
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

void bishop::access(std::string origin, std::array<std::array<Cell, 8>, 8> &board)
{
    threat_id.clear();
    vector<string> alfa = {"A", "B", "C", "D", "E", "F", "G", "H"};
    Cell celltemp;
    int num = get_num(origin);
    string temp;
    int temp_num = num - 1;
    char character[] = "a";
    get_char(origin, character);
    auto it = (find(alfa.cbegin(), alfa.cend(), character) - 1);
    while ((it >= alfa.cbegin()) && (temp_num >= 0))
    {
        temp += (it)->at(0);
        temp += to_string(temp_num);
        if (iscell(temp))
        {
            celltemp = search_cell(temp, board);
            if (!celltemp.getState())
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
        it--;
        temp_num--;
    }

    temp_num = num + 1;
    it = (find(alfa.cbegin(), alfa.cend(), character) + 1);
    while ((it <= alfa.cend() - 1) && (temp_num <= 8))
    {
        temp += (it)->at(0);
        temp += to_string(temp_num);
        if (iscell(temp))
        {
            celltemp = search_cell(temp, board);
            if (!celltemp.getState())
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
        it++;
        temp_num++;
    }

    temp_num = num - 1;
    it = (find(alfa.cbegin(), alfa.cend(), character) + 1);
    while ((it <= alfa.cend() - 1) && (temp_num >= 0))
    {
        temp += (it)->at(0);
        temp += to_string(temp_num);
        if (iscell(temp))
        {
            celltemp = search_cell(temp, board);
            if (!celltemp.getState())
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
        it++;
        temp_num--;
    }

    temp_num = num + 1;
    it = (find(alfa.cbegin(), alfa.cend(), character) - 1);
    while ((it >= alfa.cbegin()) && (temp_num <= 8))
    {
        temp += (it)->at(0);
        temp += to_string(temp_num);
        if (iscell(temp))
        {
            celltemp = search_cell(temp, board);
            if (!celltemp.getState())
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
        it--;
        temp_num++;
    }
}

std::map<std::string, int> bishop::threat(std::string cellid, array<array<Cell, 8>, 8> &board)
{
    bool kish;
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

ChessMan  * bishop::attack(std::string move, Cell & cell)
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