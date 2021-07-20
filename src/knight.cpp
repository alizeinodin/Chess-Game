#include "knight.h"
#include "util.h"
#include <vector>
#include <algorithm>
using namespace std;

knight::knight(COLOR c) : ChessMan(c) {}

bool knight::access(std::string origin, std::string destination, std::array<std::array<Cell, 8>, 8> &board)
{
    char character[] = "a";
    get_char(origin, character);
    vector<string> alfa = {"A", "B", "C", "D", "E", "F", "G", "H"};
    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1}; // all possible moves.
    int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2}; // all possible moves.
    auto it = find(alfa.cbegin(), alfa.cend(), character);
    string temp;
    Cell celltemp;
    int num = get_num(origin);
    for (size_t i = 0; i < 8; i++)
    {
        if (it + dx[i] == alfa.cend())
        {
            continue;
        }
        if (num + dy[i] > 9)
        {
            continue;
        }
        temp += (it + dx[i])->at(0);
        temp += to_string(num + dy[i]);
        //cout << temp <<endl;
        if (iscell(temp))
        {
            celltemp = search_cell(temp, board);
            if (!celltemp.getState())
            {
                return true;
                //cout << temp <<endl;
            }
            else
            {
                temp.clear(); 
                break;
            }
        }
        temp.clear();
    }

    return false;
}

void knight::movePiece(MOVE move, std::array<std::array<Cell, 8>, 8> &board)
{
    Cell cells[2];
    if (move.at(0) == 'H')
    {
        auto cellsid = cut_str(move);
        if (this->access(cellsid.first, cellsid.second, board))
        {
            cells[0] = search_cell(cellsid.first, board);
            cells[0].empty();
            cells[1] = search_cell(cellsid.second , board);
            cells[1].setPiece(this);
        }
        else
        {
            if(!cells[1].getState())
            {
                attack(move, cells[1]);
            }
            throw invalid_argument("can not move!!!");
        }
        
        
    }
    throw invalid_argument("piece is not true");
}