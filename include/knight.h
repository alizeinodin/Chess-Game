#ifndef _KNIGHT_H
#define _KNIGHT_H
#include "chessMan.h"
#include <iostream>
#include "using.h"

class knight : public ChessMan
{
public:
    virtual void movePiece(MOVE);
};

#endif /* _KNIGHT_H */
