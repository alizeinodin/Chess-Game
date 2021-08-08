#include "chessMan.h"
#ifndef _ENPASSANT_h
#define _ENPASSANT_h

class enpassantexcept
{
public:
    ChessMan * attack = nullptr;
    ID id;
    enpassantexcept(ChessMan * a, ID i) : attack(a) , id(i) {}
};




#endif