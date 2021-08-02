#include <stdexcept>
#ifndef _KISHEXCEPT_H
#define _KISHEXCEPT_H

class kishexcept : public std::runtime_error
{
public:
    kishexcept(std::string s) : std::runtime_error("you have a kish" + s) {}
};


#endif
