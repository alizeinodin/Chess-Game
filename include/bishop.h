#ifndef _BISHOP_H
#define _BISHOP_H
#include "chessMan.h"
#include <iostream>
#include "using.h"

class bishop : public ChessMan
{
public:
    virtual void movePiece(MOVE);
};

#endif /* _BISHOP_H */
