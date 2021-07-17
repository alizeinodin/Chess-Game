#include "util.h"
#include <cstring>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

std::string makeID()
{
    
}

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