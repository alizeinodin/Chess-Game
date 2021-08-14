#include "chessMan.h" 
#include <stdexcept>
#ifndef _CASTLING_h
#define _CASTLING_h

class castlingundo
{
public:
    ID rookid;
    MOVE undomove;
    castlingundo(MOVE m,ID id) : rookid(id) , undomove(m) {}
};




#endif
