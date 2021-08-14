#include "chessMan.h"
#include <stdexcept>
#include <QString>
#include "undoattack.h"
#ifndef _PAWNPROMOTIONUNDO_H
#define _PAWNPROMOTIONUNDO_H

class promotionundo : public std::runtime_error
{

public:
    QString id;
    bool attackUndo = false;
    undoattack *e;
    promotionundo(QString i) : id(i) , std::runtime_error("promotionundo") {}
    
};



#endif