#include "../include/bishop.h"
#include "../include/util.h"
#include <vector>
#include <algorithm>
using namespace std;

bishop::bishop(COLOR c) : ChessMan(c)
{
    piecetype = BISHOP;
}

void bishop::move(MOVE move, std::array<std::array<Cell, 8>, 8> &board)
{
    Cell *cells[2];
    if (move.size() == 0)
    {
        throw invalid_argument("move command invalid");
    }
    if (move.at(0) == 'B')
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

void bishop::access(std::string origin, std::array<std::array<Cell, 8>, 8> &board)
{
    if (origin.size() == 0)
    {
        throw invalid_argument("move command invalid");
    }
    threat_id.clear();
    possible.clear();
    vector<string> alfa = {"A", "B", "C", "D", "E", "F", "G", "H"};
    Cell *celltemp;
    int num = get_num(origin);
    string temp;
    int temp_num = num - 1;
    char character[] = "a";
    get_char(origin, character);
    auto it = (find(alfa.cbegin(), alfa.cend(), character) - 1);
    ID id;
    while ((it >= alfa.cbegin()) && (temp_num > 0))
    {
        temp += (it)->at(0);
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
                    kish.insert(kish.begin(), possible.begin(), possible.end());
                    t = dynamic_cast<king *> (celltemp->getPiece());
                    t->insert(kish);
                    t->kishr = origin;
                }
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
    if (possible.size() != 0)
    {
        id = possible.back();
    }
    while ((it < alfa.cend()) && (temp_num <= 8))
    {
        temp += (it)->at(0);
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
                    auto itfind = find(possible.begin(), possible.end(), id);
                    if (itfind != possible.cend())
                    {
                        itfind++;
                    }
                    kish.insert(kish.begin(), itfind, possible.end());                    
                    t = dynamic_cast<king *> (celltemp->getPiece());
                    t->insert(kish);
                    t->kishr = origin;
                }
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
    if (possible.size() != 0)
    {
        id = possible.back();
    }
    while ((it < alfa.cend()) && (temp_num > 0))
    {
        temp += (it)->at(0);
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
                    auto itfind = find(possible.begin(), possible.end(), id);
                    if (itfind != possible.cend())
                    {
                        itfind++;
                    }
                    kish.insert(kish.begin(), itfind, possible.end());
                    t = dynamic_cast<king *> (celltemp->getPiece());
                    t->insert(kish);
                    t->kishr = origin;
                }
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
    if (possible.size() != 0)
    {
        id = possible.back();
    }
    while ((it >= alfa.cbegin()) && (temp_num <= 8))
    {
        temp += (it)->at(0);
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
                    auto itfind = find(possible.begin(), possible.end(), id);
                    if (itfind != possible.cend())
                    {
                        itfind++;
                    }
                    kish.insert(kish.begin(), itfind, possible.end());
                    t = dynamic_cast<king *> (celltemp->getPiece());
                    t->insert(kish);
                    t->kishr = origin;
                }
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
        throw kishexcept("B");
    }
    return temp;
}

ChessMan *bishop::attack(std::string move, Cell **cell)
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

ID bishop::get_random(ID origin)
{
    if (origin.size() == 0)
    {
        throw invalid_argument("move command invalid");
    }
    threat_id.clear();
    possible.clear();
    vector<string> alfa = {"A", "B", "C", "D", "E", "F", "G", "H"};
    Cell *celltemp;
    int num = get_num(origin);
    string temp;
    int temp_num = num - 1;
    char character[] = "a";
    get_char(origin, character);
    auto it = (find(alfa.cbegin(), alfa.cend(), character) - 1);
    ID id;
    while ((it >= alfa.cbegin()) && (temp_num > 0))
    {
        temp += (it)->at(0);
        temp += to_string(temp_num);
        if (iscell(temp))
        {
            possible.push_back(temp);
        }

        temp.clear();
        it--;
        temp_num--;
    }

    temp_num = num + 1;
    it = (find(alfa.cbegin(), alfa.cend(), character) + 1);
    while ((it < alfa.cend()) && (temp_num <= 8))
    {
        temp += (it)->at(0);
        temp += to_string(temp_num);
        if (iscell(temp))
        {
            possible.push_back(temp);
        }

        temp.clear();
        it++;
        temp_num++;
    }

    temp_num = num - 1;
    it = (find(alfa.cbegin(), alfa.cend(), character) + 1);
    while ((it < alfa.cend()) && (temp_num > 0))
    {
        temp += (it)->at(0);
        temp += to_string(temp_num);
        if (iscell(temp))
        {
            possible.push_back(temp);
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
            possible.push_back(temp);
        }
        temp.clear();
        it--;
        temp_num++;
    }
    string rand = possible.at(randomNoGenerator(possible.size()- 1));
    possible.clear();
    return rand;
}