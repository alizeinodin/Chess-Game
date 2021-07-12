#ifndef _PAWN_H
#define _PAWN_H
#include <iostream>
#include "chessBoard.h"

class pawn : public ChessBoard
{
    public:
        virtual Move();
};

#endif /* _PAWN_H */
