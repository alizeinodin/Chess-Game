#include <iostream>
#include "include/king.h"
#include "include/util.h"
#include "include/pawn.h"
#include "include/rook.h"
#include "include/bishop.h"
#include "include/knight.h"
#include <array>
using namespace std;


int main(int argc, char const *argv[])
{
    // std::array<std::array<Cell, 8>, 8> board;
    // knight k("#000000");
    // k.access("G8" , "G2" , board);
    string s = "KG3D5";
    cout << cut_str(s).first << endl;
    cout << cut_str(s).second << endl;
    
    return 0;
}
