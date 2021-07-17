#include "util.h"
#include <cstring>
#include <algorithm>
#include <vector>
<<<<<<< HEAD
#include <random>
=======
#include <array>
>>>>>>> b3f21c3291ecdfa927236d9ad219a03dee1ec222
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

Cell & search_cell(std::string str, std::array<std::array<Cell, 8>, 8> &board)
{
    auto it = find(board.at(0).begin(),board.at(0).end(), str);
    if (it != board.at(0).cend())
    {
        return *it;
    }
    for (size_t i = 1; i < 8; i++)
    {
        it = find(board.at(i).begin(),board.at(i).end(), str);
        if (it != board.at(i).cend())
        {
            return *it;
        }
        
    }
    
}