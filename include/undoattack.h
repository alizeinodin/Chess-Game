#include <string>
#ifndef _UNDOATTACK_H
#define _UNDOATTACK_H

class undoattack
{
public:
    std::string id;
    std::string color;
    undoattack(std::string i, std::string c) : id(i) , color(c) {}
};

#endif