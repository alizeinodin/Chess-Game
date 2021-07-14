#ifndef _CHESSMAN_H
#define _CHESSMAN_H
#include <iostream>
#include "using.h"
#include "moving.h"
#include <map>

class ChessMan
{
protected:
    State CurrentState;
    State TypeMove;
    COLOR color;
    

public:
    ChessMan(COLOR);
// <<<<<<< HEAD
//     virtual bool access(std::string); // cheking access for cell's
//     virtual void attack(std::string);
//     virtual void movePiece(std::string);
//     virtual ~ChessMan() = 0;
// =======
    //virtual bool access(std::string) = 0; // cheking access for cell's
    //virtual std::map<std::string, int> threat(std::string) = 0; // threat with cell ID and score
    //virtual void attack(std::string) = 0;
    virtual void movePiece(std::string) = 0;
// >>>>>>> 233d1494294eac9c8bf65f7e6de05ab5f6cf6c16
};

#endif /* _CHESSMAN_H */
