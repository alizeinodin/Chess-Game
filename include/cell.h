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
    bool isnull = false;
    COLOR color;
    ChessMan * Nut = nullptr;


    public:
    Cell(); // fill id, color in make
    Cell(ChessMan *); // fill id, color in make
    ID getId();
    COLOR getColor();
    bool getState();
};

#endif /* CELL_H */
