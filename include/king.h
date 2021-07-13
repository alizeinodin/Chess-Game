#ifndef _KING_H
#define _KING_H
#include "chessBoard.h"
#include <iostream>
#include "using.h"

class king : public ChessBoard
{
public:
    virtual void movePiece(MOVE);
};

#endif /* _KING_H */
