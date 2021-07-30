#include "include/chessMan.h"

ChessMan::ChessMan(COLOR c) : color(c) {}

COLOR ChessMan::get_color()
{
    return color;
}

piece ChessMan:: get_type()
{
    return piecetype;
}
