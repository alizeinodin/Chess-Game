#ifndef _KING_H
#define _KING_H
#include "chessMan.h"
#include <iostream>
#include "using.h"

class king : public ChessMan
{
public:
    virtual void movePiece(MOVE);
};

#endif /* _KING_H */
