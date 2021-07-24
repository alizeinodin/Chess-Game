#ifndef _GAME_H
#define _GAME_H
#include "chessBoard.h"
#include "player.h"

class Game
{
    enum Color {BLACK, WITHE};
    private:
    ChessBoard gameBoard = ChessBoard::getInstance();
    Player * player1 = nullptr;
    Player * player2 = nullptr;
    bool Turn = false;

    public:
    ChessBoard & getBoard();
    void setPlayer(Color, std::string);
    Player getPlayer(COLOR);
};

#endif /* _GAME_H */
