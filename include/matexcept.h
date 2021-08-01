#include <stdexcept>
#include <exception>
#ifndef _MATEXCEPT_H
#define _MATEXCEPT_H

class matexcept : public std::runtime_error
{
public:
    matexcept();
};

matexcept::matexcept() : std::runtime_error("you hgave mat") {}

#endif