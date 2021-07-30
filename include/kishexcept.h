#ifndef _KISHEXCEPT_H
#define _KISHEXCEPT_H
#include <stdexcept>
#include <exception>

class kishexcept : public std::runtime_error
{
public:
    kishexcept();
    ~kishexcept();
};

kishexcept::kishexcept() : std::runtime_error("you have a kish") {}
kishexcept::~kishexcept(){}

#endif