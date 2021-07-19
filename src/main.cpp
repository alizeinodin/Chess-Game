#include <iostream>
#include "king.h"
#include "util.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include <array>
using namespace std;


int main(int argc, char const *argv[])
{
    std::array<std::array<Cell, 8>, 8> board;
    knight k("#000000");
    k.access("G8" , "G2" , board);
    
    return 0;
}
