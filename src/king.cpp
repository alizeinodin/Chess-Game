#include "king.h"
#include "util.h"
#include <algorithm>
#include <vector>
using namespace std;

king::king(COLOR c) : ChessMan(c)
{
    piecetype = KING;
}

void king::movePiece(MOVE move, std::array<std::array<Cell, 8>, 8> &board)
{
    Cell cells[2];

    if (move.at(0) == 'K')
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

void king::access(std::string origin, std::array<std::array<Cell, 8>, 8> &board)
{
    threat_id.clear();
    char character[] = "a";
    get_char(origin, character);
    vector<string> alfa = {"A", "B", "C", "D", "E", "F", "G", "H"};
    int dx[] = {1, 1, 1, -1, -1, -1, 0, 0}; // all possible moves.
    int dy[] = {1, -1, 0, -1, 1, 0, -1, 1}; // all possible moves.
    auto it = find(alfa.cbegin(), alfa.cend(), character);
    string temp;
    Cell celltemp;
    int num = get_num(origin);
    for (size_t i = 0; i < 8; i++)
    {
        temp += (it + dx[i])->at(0);
        temp += to_string(num + dy[i]);
        if (it + dx[i] == alfa.cend())
        {
            continue;
        }
        if (num + dy[i] > 9)
        {
            continue;
        }
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

            temp.clear();
        }
    }
}

std::map<std::string, int> king::threat(std::string cellid, array<array<Cell, 8>, 8> &board)
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

void king::attack(std::string move, Cell & cell)
{
    attackpiece = cell.getPiece();
    cell.empty();
    cell.setPiece(this);
    switch (attackpiece->get_type())
    {
    case QUEEN:
        attackscore = 15;
        break;
    case POWN:
        attackscore = 3;
        break;
    case ROOK:
    case BISHOP:
    case KNIGHT:
        attackscore = 8;
    }
}