#ifndef _ROOK_H
#define _ROOK_H
#include "chessBoard.h"
#include <iostream>
#include "using.h"

class rook : public ChessBoard
{
public:
    virtual void movePiece(MOVE);
};

#endif /* _ROOK_H */