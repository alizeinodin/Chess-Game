#include <stdexcept>
#include <exception>
#ifndef _MATEXCEPT_H
#define _MATEXCEPT_H

class matexcept : public std::runtime_error
{
public:
    matexcept(std::string s);
};

matexcept::matexcept(std::string s) : std::runtime_error("you have mat" + s) {}

#endif