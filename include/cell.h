#ifndef CELL_H
#define CELL_H
#include <iostream>
#include "chessMan.h"

using ID = std::string;
using COLOR = std::string;

class Cell
{
    private:
    ID id;
    bool isnull = false; // the means of false is null
    COLOR color;
    ChessMan * piece = nullptr;


    public:
    Cell(); // fill id, color in make
    //Cell(ChessMan *); // fill id, color in make
    ID getId();
    COLOR getColor();
    bool getState();
    void setColor();
    void setPiece(ChessMan *);
};

#endif /* CELL_H */
