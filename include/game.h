#ifndef _GAME_H
#define _GAME_H
#include "chessBoard.h"
#include "player.h"

class Game
{
    private:
    ChessBoard gameBoard = ChessBoard::getInstance();
    Player * player1 = nullptr;
    Player * player2 = nullptr;
    bool Turn = false;

    public:
    ChessBoard & getBoard();
    void setPlayer(size_t, std::string);
    Player getPlayer();
};

#endif /* _GAME_H */
