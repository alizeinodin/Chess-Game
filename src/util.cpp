//#include "util.h"
#include "include/cell.h"
#include "include/chessMan.h"
#include <cstring>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <random>
#include <array>
//#include <random>
using namespace std;

// std::string makeID()
// {

// }

bool iscell(string cell)
{
    char temp[2];
    cell.copy(temp, 1, 1);
    temp[1] = '\0';
    vector<string> alfa = {"A", "B", "C", "D", "E", "F", "G", "H"};
    int num = stoi(temp);
    cell.copy(temp, 1, 0);
    temp[1] = '\0';

    if (binary_search(alfa.cbegin(), alfa.cend(), temp))
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
    str.copy(temp2, 1, 1);
//    cout << "get_num str: " << str << endl;
//    cout << "get_num Y: " << temp2[0] << endl;
    temp2[1] = '\0';
    int num = stoi(temp2);
    return num;
}

void get_char(std::string str, char character[])
{

    str.copy(character, 1, 0);
    character[2] = '\0';
}

bool celltostr(Cell &cell, string &str)
{
    return (cell.getId() == str);
}

Cell &search_cell(string str, array<array<Cell, 8>, 8> &board)
{
    char *character;
    get_char(str, character);
    string temp = "ABCDEFGH";
    int x = temp.find(temp);
    int y = get_num(str);
    if (board.at(x).at(y).getId() == str)
    {
        return board.at(x).at(y);
    }

    throw out_of_range("cell not exist");
}

std::pair<std::string, std::string> cut_str(MOVE &move)
{
    char temp1[3];
    char temp2[3];
    move.copy(temp1, 2, 1);
    temp1[2] = '\0';
    move.copy(temp2, 2, 3);
    temp2[2] = '\0';
    return make_pair(temp1, temp2);
}

vector<ID> possible_move_king(COLOR color, std::array<std::array<Cell, 8>, 8> &board)
{
    vector<ID> temp;
    for (auto &i : board)
    {
        for (auto &j : i)
        {
            if (j.getPiece()->get_color() != color)
            {
                temp.insert(temp.end(), j.getPiece()->get_possiblemoves().begin(), j.getPiece()->get_possiblemoves().end());
            }
        }
    }
    return temp;
}


int randomNoGenerator(int set)
{
    static unsigned int rndm = 2;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1);
    unsigned int temp = dis(gen) * rndm;
    rndm++;
    temp = temp % set;
    return temp;
}
