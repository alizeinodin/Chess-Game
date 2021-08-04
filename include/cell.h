#include "using.h"
#include "moving.h"
#include <array>
#include <vector>
#include <map>
#ifndef CELL_H
#define CELL_H


using ID = std::string;
using COLOR = std::string;
class ChessMan;
class Cell
{
    private:
    ID id;
    bool isnull = true; // the means of true is null
    COLOR color;
    ChessMan * piece = nullptr;


    public:
    Cell(); // fill id, color in make
    ~Cell();
    ID getId();
    COLOR getColor();
    bool getState();
    void setColor();
    void setPiece(ChessMan *);
    ChessMan * getPiece();
    void empty();
    bool operator==(Cell &);
    operator std::string();
};

#endif /* CELL_H */
