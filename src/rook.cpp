#include "rook.h"
#include "util.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

rook::rook(COLOR c) : ChessMan(c) 
{
    piecetype = ROOK;
}

void rook::movePiece(MOVE move, std::array<std::array<Cell, 8>, 8> &board)
{
    Cell cells[2];
    if (move.at(0) == 'R')
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

bool rook::access(string origin, string destination, array<array<Cell, 8>, 8> &board)
{
    threat_id.clear();
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
                    threat_id.push_back(temp);
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
                    threat_id.push_back(temp);
                    temp.clear();
                    break;
                }
            }
        }
        temp.clear();
        temp_num++;
    }
    char character[] = "a";
    get_char(origin, character);

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
                    threat_id.push_back(temp);
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
            if (iscell(temp))
            {
                celltemp = search_cell(temp, board);
                if (!celltemp.getState())
                {
                    if (temp == destination)
                        return true;
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
    }
    return false;
}

std::map<std::string, int> rook::threat(std::string cellid, array<array<Cell, 8>, 8> &board)
{
    bool kish;
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