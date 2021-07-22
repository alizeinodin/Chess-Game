#include "chessMan.h"
#ifndef CELL_H
#define CELL_H


using ID = std::string;
using COLOR = std::string;

class Cell
{
    private:
    ID id;
    bool isnull = true; // the means of true is null
    COLOR color;
    ChessMan * piece = nullptr;


    public:
    Cell(); // fill id, color in make
    ID getId();
    COLOR getColor();
    bool getState();
    void setColor();
    void setPiece(ChessMan *);
    ChessMan * getPiece();
    void empty();
    bool operator==(Cell &);
};

#endif /* CELL_H */
