#include <QString>
#include "chessBoard.h"
#include "player.h"
#include "fileConnect.h"
#include "equality.h"
#ifndef _GAME_H
#define _GAME_H

class Game
{
    private:
    Name gamename;
    ChessBoard gameBoard = ChessBoard::getInstance();
    Player * player1 = nullptr;
    Player * player2 = nullptr;
    bool Turn = true;
    std::vector<MOVE> moves;
    ChessMan *attackpiece = nullptr;
    std::string Special_mode;
    FileConnect file;

    public:
    enum Color {BLACK, WHITE};
    //Game & getInstance(Name);
    Game(Name);
    void startgame();
    void setPlayer(Color, QString);
    Player getPlayer(COLOR);
    void order(MOVE);
    QString undo(bool isreview);
    std::vector<MOVE> movesUndo();
    void restart();
    void update_score();
    Player &compareScore();
    std::string random_move();
    void promotion(ID pawncell, piece);
    void twomove();
    bool getTurn();
    void savegame();
    std::vector<QString> get_gamelist();
    QString redo();
    void select_game(QString name);
    bool checkColorOfPiece(std::string);
    void addScore(size_t, int);

    
};

#endif /* _GAME_H */
