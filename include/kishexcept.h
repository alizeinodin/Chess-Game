#include <stdexcept>
#include <exception>
#ifndef _KISHEXCEPT_H
#define _KISHEXCEPT_H

class kishexcept : public std::runtime_error
{
public:
    kishexcept();
};

kishexcept::kishexcept() : std::runtime_error("you have a kish") {}

#endif