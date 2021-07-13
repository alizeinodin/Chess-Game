#ifndef _CELL_H
#define _CELL_H
#include <iostream>

using ID = std::string;
using COLOR = std::string;

class Cell
{
    private:
    ID id;
    bool isnull = false;
    COLOR color;

    public:
    Cell(); // fill id, color in make
    ID getId();
    COLOR getColor();
};

#endif /* _CELL_H */
