#ifndef _KING_H
#define _KING_H
#include <iostream>
#include "chessBoard.h"

class king : public ChessBoard
{
    public:
        virtual Move();
};

#endif /* _KING_H */
