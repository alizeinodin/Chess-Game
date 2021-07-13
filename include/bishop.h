#ifndef _BISHOP_H
#define _BISHOP_H
#include "chessBoard.h"
#include <iostream>
#include "using.h"

class bishop : public ChessBoard
{
public:
    virtual void movePiece(MOVE);
};

#endif /* _BISHOP_H */
