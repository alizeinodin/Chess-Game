<<<<<<< HEAD
#ifndef _KISHEXCEPT_H
#define _KISHEXCEPT_H
#include <stdexcept>
#include <exception>
=======
#include <stdexcept>
#include <exception>
#ifndef _KISHEXCEPT_H
#define _KISHEXCEPT_H
>>>>>>> 87196fc2639f971ed2f33db757835bb516348ed2

class kishexcept : public std::runtime_error
{
public:
    kishexcept();
<<<<<<< HEAD
    ~kishexcept();
};

kishexcept::kishexcept() : std::runtime_error("you have a kish") {}
kishexcept::~kishexcept(){}
=======
};

kishexcept::kishexcept() : std::runtime_error("you have a kish") {}
>>>>>>> 87196fc2639f971ed2f33db757835bb516348ed2

#endif