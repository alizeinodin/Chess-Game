#include "king.h"
#include "util.h"
#include <algorithm>
#include <vector>
using namespace std;

king::king(COLOR c) : ChessMan(c) {}

void king::movePiece(MOVE move)
{
    if (move.at(0) == 'K')
    {
    }
}

bool king::access(std::string origin, std::string destination, std::array<std::array<Cell, 8>, 8> &board)
{
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
            if (temp == destination)
            {
                celltemp = search_cell(temp, board);
                if (!celltemp.getState())
                {
                    return true;
                }
                else
                {
                    temp.clear();
                    break;
                }
            }
            temp.clear();
        }
    }
    return false;
}
