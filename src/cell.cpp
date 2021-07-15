#include "cell.h"
#include "id.h"

using namespace std;

Cell::Cell()
{
    id = CellID();
    setColor();
}

ID Cell::getId()
{
    return id;
}

COLOR Cell::getColor()
{
    return color;
}

void Cell::setColor()
{
    static unsigned int counter = 0, selectColor = 0;
    array <string, 2> colors = {"#000000", "#ffffff"};
    counter++;
    color = colors[counter % 8 == 0 ? selectColor % 2 : (selectColor++) % 2];
    // if counter == 8 and color was black in next line first element must be black in chess
}

void Cell::setPiece(ChessMan * myPiece)
{
    this->piece = myPiece;
}