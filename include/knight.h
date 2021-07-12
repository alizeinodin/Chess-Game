#ifndef _KNIGHT_H
#define _KNIGHT_H
#include <iostream>
#include "chessBoard.h"

class knight : public ChessBoard
{
    public:
        virtual Move();
};

#endif /* _KNIGHT_H */
