#ifndef _PAWN_H
#define _PAWN_H
#include "chessBoard.h"
#include "using.h"
#include "moving.h"
#include <iostream>

class pawn : public ChessBoard
{
public:
    virtual void movePiece(MOVE);
};

#endif /* _PAWN_H */
