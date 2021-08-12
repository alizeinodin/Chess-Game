#include "chessMan.h"
#include <stdexcept>
#include <QString>
#ifndef _PAWNPROMOTIONUNDO_H
#define _PAWNPROMOTIONUNDO_H

class promotionundo : public std::runtime_error
{

public:
    QString id;
    promotionundo(QString i) : id(i) , std::runtime_error("promotionundo") {}
    
};



#endif