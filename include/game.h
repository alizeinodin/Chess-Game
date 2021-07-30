#ifndef _GAME_H
#define _GAME_H
#include "chessBoard.h"
#include "player.h"

using nameGame = std::string;

class Game
{
    enum Color {BLACK, WITHE};
    private:
    Game(Name);
    Name gamename;
    ChessBoard & gameBoard = ChessBoard::getInstance();
    Player * player1 = nullptr;
    Player * player2 = nullptr;
    bool Turn = true;


    public:
    Game & getInstance(Name);
    void startgame();
    void setPlayer(Color, std::string);
    Player getPlayer(COLOR);
    void order(MOVE);
};

#endif /* _GAME_H */
