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

void knight::movePiece(MOVE m)
{
}