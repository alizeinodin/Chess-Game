#include <QString>
#ifndef _GAME_H
#define _GAME_H
#include "chessBoard.h"
#include "player.h"

class Game
{
    private:
    Name gamename;
    ChessBoard gameBoard = ChessBoard::getInstance();
    Player * player1 = nullptr;
    Player * player2 = nullptr;
    bool Turn = true;
    std::vector<MOVE> moves;

    public:
    enum Color {BLACK, WHITE};
    //Game & getInstance(Name);
    Game(Name);
    void startgame();
    void setPlayer(Color, std::string);
    Player getPlayer(COLOR);
    void order(MOVE);
    void undo();
};

#endif /* _GAME_H */
