#ifndef _PAWN_H
#define _PAWN_H
#include "chessMan.h"
#include "using.h"
#include "moving.h"
#include <iostream>

class pawn : public ChessMan
{
public:
    virtual void movePiece(MOVE);
};

#endif /* _PAWN_H */
