#include "../include/rook.h"
#include "../include/util.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

rook::rook(COLOR c) : ChessMan(c)
{
    piecetype = ROOK;
}

void rook::move(MOVE move, std::array<std::array<Cell, 8>, 8> &board)
{
    Cell *cells[2];
    if (move.at(0) == 'R')
    {
        auto cellsid = cut_str(move);
        this->access(cellsid.first, board);
        for (size_t i = 0; i < possible.size(); i++)
        {
            if (possible.at(i) == cellsid.second)
            {
                cells[0] = search_cell(cellsid.first, board);
                cells[1] = search_cell(cellsid.second, board);
                cells[1]->setPiece(cells[0]->getPiece());
                cells[0]->empty();
                return;
            }
        }
        throw invalid_argument("can not move!!!");
    }
    throw invalid_argument("piece is not true");
}

void rook::access(string origin, array<array<Cell, 8>, 8> &board)
{
    threat_id.clear();
    possible.clear();
    Cell *celltemp;
    vector<string> alfa = {"A", "B", "C", "D", "E", "F", "G", "H"};
    auto itkish = possible.begin();
    int num = get_num(origin);
    string temp;
    int temp_num = num - 1;
    while (temp_num > 0)
    {
        temp += origin.at(0);
        temp += to_string(temp_num);
        if (iscell(temp))
        {
            celltemp = search_cell(temp, board);
            if (celltemp->getState())
            {
                possible.push_back(temp);
            }
            else
            {
                threat_id.push_back(temp);
                vector<ID> kish;
                king * t;
                if (celltemp->getPiece()->get_type() == KING && celltemp->getPiece()->get_color() != this->color)
                {
                    kish.insert(kish.begin(), itkish, possible.end());
                    t = dynamic_cast<king *> (celltemp->getPiece());
                    t->insert(kish);
                }
                temp.clear();
                break;
            }
        }

        temp.clear();
        temp_num--;
    }

    temp_num = num + 1;
    itkish = possible.end() - 1;
    while (temp_num <= 8)
    {
        temp += origin.at(0);
        temp += to_string(temp_num);
        if (iscell(temp))
        {
            celltemp = search_cell(temp, board);
            if (celltemp->getState())
            {
                possible.push_back(temp);
            }
            else
            {
                threat_id.push_back(temp);
                vector<ID> kish;
                king * t;
                if (celltemp->getPiece()->get_type() == KING && celltemp->getPiece()->get_color() != this->color)
                {
                    kish.insert(kish.begin(), itkish, possible.end());
                    t = dynamic_cast<king *> (celltemp->getPiece());
                    t->insert(kish);
                }
                temp.clear();
                break;
            }
        }

        temp.clear();
        temp_num++;
    }
    char character[] = "a";
    get_char(origin, character);

    auto it = (find(alfa.cbegin(), alfa.cend(), character) - 1);
    itkish = possible.end() - 1;
    while (it >= alfa.cbegin())
    {
        temp += (it)->at(0);
        temp += to_string(num);
        if (iscell(temp))
        {
            celltemp = search_cell(temp, board);
            if (celltemp->getState())
            {
                possible.push_back(temp);
            }
            else
            {
                threat_id.push_back(temp);
                vector<ID> kish;
                king * t;
                if (celltemp->getPiece()->get_type() == KING && celltemp->getPiece()->get_color() != this->color)
                {
                    kish.insert(kish.begin(), itkish, possible.end());
                    t = dynamic_cast<king *> (celltemp->getPiece());
                    t->insert(kish);
                }
                temp.clear();
                break;
            }
        }

        temp.clear();
        it--;
    }
    it = (find(alfa.cbegin(), alfa.cend(), character) + 1);
    itkish = possible.end() - 1;
    while (it <= alfa.cend() - 1)
    {
        temp += (it)->at(0);
        temp += to_string(num);
        if (iscell(temp))
        {
            celltemp = search_cell(temp, board);
            if (celltemp->getState())
            {
                possible.push_back(temp);
            }
            else
            {
                threat_id.push_back(temp);
                vector<ID> kish;
                king * t;
                auto ittemp = (find(alfa.cbegin(), alfa.cend(), character) - 1);
                if (celltemp->getPiece()->get_type() == KING && celltemp->getPiece()->get_color() != this->color)
                {
                    kish.insert(kish.begin(), itkish, possible.end());
                    t = dynamic_cast<king *> (celltemp->getPiece());
                    t->insert(kish);
                }
                temp.clear();
                break;
            }
        }
        temp.clear();
        it++;
    }
}

std::map<std::string, int> rook::threat(std::string cellid, array<array<Cell, 8>, 8> &board)
{
    bool kish = false;
    map<string, int> temp;
    this->access(cellid, board);
    for (size_t i = 0; i < threat_id.size(); i++)
    {
        if (search_cell(threat_id.at(i), board)->getPiece() != nullptr)
        {
            if (search_cell(threat_id.at(i), board)->getPiece()->get_color() != this->get_color())
            {
                switch (search_cell(threat_id.at(i), board)->getPiece()->get_type())
                {
                case QUEEN:
                    temp.insert(make_pair(threat_id.at(i), 5));
                    break;
                case ROOK:
                case BISHOP:
                case KNIGHT:
                    temp.insert(make_pair(threat_id.at(i), 2));
                    break;
                case PAWN:
                    temp.insert(make_pair(threat_id.at(i), 1));
                    break;
                case KING:
                    kish = true;
                    break;
                }
            }
        }
    }
    if (kish)
    {
        throw kishexcept("R");
    }
    return temp;
}

ChessMan *rook::attack(std::string move, Cell **cell)
{
    ChessMan *attackpiece = cell[1]->getPiece();
    auto temp = cut_str(move);
    if (!(attackpiece->get_color() == color) || !(attackpiece->get_color() == color))
    {
        sort(threat_id.begin(),threat_id.end());
        if (binary_search(threat_id.cbegin(), threat_id.cend(), temp.second))
        {
            cell[1]->empty();
            cell[1]->setPiece(cell[0]->getPiece());
            cell[0]->empty();
            return attackpiece;
        }
    }
    throw invalid_argument("can not move!!!");
    return attackpiece;
}