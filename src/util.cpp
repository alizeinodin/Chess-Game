#include "util.h"
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

bool iscell(string cell)
{
    char temp[2];
    temp[0] = cell.at(1);
    temp[1] = '\0';
    vector<string> alfa = {"A", "B", "C", "D", "E", "F", "G", "H"};
    int num = stoi(temp);
    temp[0] = cell.at(0);
    temp[1] = '\0';
    if (binary_search(alfa.cbegin(),alfa.cend(),temp))
    {
        if (num < 9 && num > 0)
        {
            return true;
        }
    }

    return false;
}