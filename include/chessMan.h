#ifndef _CHESSMAN_H
#define _CHESSMAN_H
#include <iostream>

using State = std::string;
using COLOR = std::string;

class ChessMan
{
protected:
    State CurrentState;
    State TypeMove;
    COLOR color;

public:
    ChessMan(COLOR);
    virtual State Move();
    virtual ~ChessMan() = 0;
};

#endif /* _CHESSMAN_H */
