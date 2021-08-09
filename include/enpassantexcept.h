#include "chessMan.h" 
#include <stdexcept>
#ifndef _ENPASSANT_h
#define _ENPASSANT_h

class enpassantexcept : public std::runtime_error
{
public:
    ChessMan * attack = nullptr;
    ID id;
    enpassantexcept(ChessMan * a, ID i) : attack(a) , id(i) , std::runtime_error("enpassant") {}
};




#endif