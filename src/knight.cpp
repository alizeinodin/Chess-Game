#include "../include/knight.h"
#include "../include/util.h"
#include <vector>
#include <algorithm>
using namespace std;

knight::knight(COLOR c) : ChessMan(c)
{
    piecetype = KNIGHT;
}

void knight::access(std::string origin, std::array<std::array<Cell, 8>, 8> &board)
{
    if (origin.size() == 0)
    {
        throw invalid_argument("move command invalid");
    }
    threat_id.clear();
    possible.clear();
    char character[] = "a";
    get_char(origin, character);
    vector<string> alfa = {"A", "B", "C", "D", "E", "F", "G", "H"};
    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1}; // all possible moves.
    int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2}; // all possible moves.
    auto it = find(alfa.cbegin(), alfa.cend(), character);
    string temp;
    Cell *celltemp;
    int num = get_num(origin);
    for (size_t i = 0; i < 8; i++)
    {
        if (!(((num + dx[i]) > 9) && ((num + dx[i]) < 0)))
        {
            if (((it + dy[i]) < alfa.cend()) && ((it + dy[i]) >= alfa.cbegin()))
            {
                temp += (it + dy[i])->at(0);
                temp += to_string(num + dx[i]);
                //cout << temp << endl;
            }
        }
        if (iscell(temp))
        {
            celltemp = search_cell(temp, board);
            //cout << "get" << temp <<endl;
            if (celltemp->getState())
            {
                possible.push_back(temp);
                //cout << temp <<endl;
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

void knight::move(MOVE move, std::array<std::array<Cell, 8>, 8> &board)
{
    if (move.size() == 0)
    {
        throw invalid_argument("move command invalid");
    }
    Cell *cells[2];
    if (move.at(0) == 'H')
    {
        auto cellsid = cut_str(move);
        this->access(cellsid.first, board);
        for (size_t i = 0; i < possible.size(); i++)
        {
            //cout << possible.at(i).getId();
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

std::map<std::string, int> knight::threat(std::string cellid, array<array<Cell, 8>, 8> &board)
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
        throw kishexcept("H");
    }
    return temp;
}

ChessMan *knight::attack(std::string move, Cell **cell)
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
