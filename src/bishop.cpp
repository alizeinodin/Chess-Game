#include "bishop.h"
#include "util.h"
#include <vector>
#include <algorithm>
using namespace std;


bishop::bishop(COLOR c) : ChessMan(c) {}

void bishop::movePiece(MOVE)
{

}

bool bishop::access(std::string acc)
{
    vector<string> alfa = {"A", "B", "C", "D", "E", "F", "G", "H"};
    
    int num = get_num(acc);
    vector<string> Optimal_mode;
    string temp;
    int temp_num = num - 1;
    char  * character = get_char(acc);
    auto it = (find(alfa.cbegin(),alfa.cend(), character) - 1);
    while ((it >= alfa.cbegin()) && (temp_num >= 0))
    {
        temp += (it)->at(0);
        temp += to_string(temp_num);
        if (iscell(temp))
        {
            Optimal_mode.push_back(temp);
        }
        temp.clear();
        it--;
        temp_num--;
    }

    temp_num = num + 1;
    it = (find(alfa.cbegin(),alfa.cend(),character) + 1);
    while ((it <= alfa.cend() - 1) && (temp_num <= 8))
    {
        temp += (it)->at(0);
        temp += to_string(temp_num);
        if (iscell(temp))
        {
            Optimal_mode.push_back(temp);
        }
        temp.clear();
        it++;
        temp_num++;
    }

    temp_num = num - 1;
    it = (find(alfa.cbegin(),alfa.cend(),character) + 1);
    while ((it <= alfa.cend() - 1) && (temp_num >= 0))
    {
        temp += (it)->at(0);
        temp += to_string(temp_num);
        if (iscell(temp))
        {
            Optimal_mode.push_back(temp);
        }
        temp.clear();
        it++;
        temp_num--;
    }

    temp_num = num + 1;
    it = (find(alfa.cbegin(),alfa.cend(), character) - 1);
    while ((it >= alfa.cbegin()) && (temp_num <= 8))
    {
        temp += (it)->at(0);
        temp += to_string(temp_num);
        if (iscell(temp))
        {
            Optimal_mode.push_back(temp);
        }
        temp.clear();
        it--;
        temp_num++;
    }
    for (auto &i : Optimal_mode)
    {
        cout << i << endl;
    }

    

    
}
