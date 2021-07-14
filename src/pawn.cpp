#include "pawn.h"
#include "util.h"
#include <vector>
#include <algorithm>
using namespace std;

pawn::pawn(COLOR c) : ChessMan(c) {}


void pawn::movePiece(MOVE move)
{
    if (move.at(0) == 'P')
    {
        /* code */
    }
    
}

bool pawn::access(string acc)
{
    char temp2[2];
    temp2[0] = acc.at(1);
    temp2[1] = '\0';
    int num = stoi(temp2);
    vector<string> Optimal_mode;
    string temp;
    
    if (color == "#000000")
    {
        if (num == 7)
        {
            int dy[] = {-1,-2};
        for (size_t i = 0; i < 2; i++)
        {
            temp += acc.at(0);
            temp += to_string(num + dy[i]);
            if (iscell(temp))
            {
                Optimal_mode.push_back(temp);
            }
            temp.clear();
        }
        }
        else
        {
            temp += acc.at(0);
            temp += to_string(num - 1);
            if (iscell(temp))
            {
                Optimal_mode.push_back(temp);
            }
            temp.clear();
        }
    }
    else
    {
        if (num == 2)
        {
            int dy[] = {-1,-2};
        for (size_t i = 0; i < 2; i++)
        {
            temp += acc.at(0);
            temp += to_string(num + dy[i]);
            if (iscell(temp))
            {
                Optimal_mode.push_back(temp);
            }
            temp.clear();
        }
        }
        else
        {
            temp += acc.at(0);
            temp += to_string(num + 1);
            if (iscell(temp))
            {
                Optimal_mode.push_back(temp);
            }
            temp.clear();
        }
    }
        for (auto &i : Optimal_mode)
        {
            cout << i << endl;
        }
        return false;

}