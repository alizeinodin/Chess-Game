#ifndef _GAME_H
#define _GAME_H
#include "chessBoard.h"
#include "player.h"

using nameGame = std::string;

class Game
{
    private:
    Game();
    nameGame name;
    ChessBoard & gameBoard = ChessBoard::getInstance();
    Player * player1 = nullptr;
    Player * player2 = nullptr;
    bool Turn = false;


    public:
    static Game & getInstance();
    ChessBoard & getBoard();
    void setPlayer(size_t, std::string);
    Player getPlayer();


};

#endif /* _GAME_H */
