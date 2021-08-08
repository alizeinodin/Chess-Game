#include "chessMan.h"
#include <stdexcept>
#ifndef _PAWNPROMOTION_H
#define _PAWNPROMOTION_H

class pawnpromotion : public std::runtime_error
{
public:
    ID id;
    ChessMan * attack = nullptr;
    pawnpromotion(ID i) : std::runtime_error("Choose piece type") , id(i) {}
};

#endif