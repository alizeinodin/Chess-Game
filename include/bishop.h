#ifndef _BISHOP_H
#define _BISHOP_H
#include <iostream>
#include "chessBoard.h"

class bishop : public ChessBoard
{
    public:
        virtual Move();
};

#endif /* _BISHOP_H */
