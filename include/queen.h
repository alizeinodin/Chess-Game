#ifndef _QUEEN_H
#define _QUEEN_H
#include "chessMan.h"
#include <iostream>
#include "using.h"

class queen : public ChessMan
{
public:
    virtual void movePiece(MOVE);
};

#endif /* _QUEEN_H */
