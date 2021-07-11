#ifndef _CHECK_H
#define _CHECK_H
#include <iostream>

using ID = std::string;
using COLOR = std::string;

class Check
{
    private:
    ID id;
    bool isnull = false;
    COLOR color;

    public:
    Check(); // fill id, color in make
    ID getId();
    COLOR getColor();
};

#endif /* _CHECK_H */
