#include "util.h"
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

bool iscell(string cell)
{
    char temp[2];
    cell.copy(temp,1,1);
    temp[1] = '\0';
    vector<string> alfa = {"A", "B", "C", "D", "E", "F", "G", "H"};
    int num = stoi(temp);
    cell.copy(temp,1,0);
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