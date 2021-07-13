#ifndef _ROOK_H
#define _ROOK_H
#include "chessMan.h"
#include <iostream>
#include "using.h"

class rook : public ChessMan
{
public:
    virtual void movePiece(MOVE);
};

#endif /* _ROOK_H */