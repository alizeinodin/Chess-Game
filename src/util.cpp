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

int get_num(std::string str)
{
    char temp2[2];
    str.copy(temp2,1,1);
    temp2[1] = '\0';
    int num = stoi(temp2);
    return num;
}

char * get_char(std::string str)
{
    char  character[2];
    str.copy( character,1,0);
    character[2] = '\0';
    return character;
}