#ifndef _KNIGHT_H
#define _KNIGHT_H
#include "chessBoard.h"
#include <iostream>
#include "using.h"

class knight : public ChessBoard
{
public:
    virtual void movePiece(MOVE);
};

#endif /* _KNIGHT_H */
