#ifndef _QUEEN_H
#define _QUEEN_H
#include <iostream>
#include "chessBoard.h"

class queen : public ChessBoard
{
    public:
        virtual Move();
};

#endif /* _QUEEN_H */
