#ifndef _GAME_H
#define _GAME_H
#include "chessBoard.h"
#include "player.h"

class Game
{
    enum Color {BLACK, WITHE};
    private:
    Name gamename;
    ChessBoard gameBoard = ChessBoard::getInstance();
    Player * player1 = nullptr;
    Player * player2 = nullptr;
    bool Turn = true;
    std::vector<MOVE> moves;

    public:
    Game(Name);
    Game & getInstance(Name);
    void startgame();
    void setPlayer(Color, std::string);
    Player getPlayer(COLOR);
    void order(MOVE);
    void undo();
    void savegame();
};

#endif /* _GAME_H */
