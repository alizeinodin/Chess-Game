#ifndef _QUEEN_H
#define _QUEEN_H
#include "chessBoard.h"
#include <iostream>
#include "using.h"

class queen : public ChessBoard
{
public:
    virtual void movePiece(MOVE);
};

#endif /* _QUEEN_H */
