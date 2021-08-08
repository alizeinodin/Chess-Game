#ifndef EQUALITY_H
#define EQUALITY_H
#include <iostream>

class Equality : public std::runtime_error
{
public:
    Equality() : std::runtime_error(std::string("EQUAL")) {}
};



#endif // EQUALITY_H
