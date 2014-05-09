#pragma once
#include <QString>

///Class for functions for tic-tac-toe game
class TicTacToe
{
public:
    TicTacToe();
    QString getCellState(int x, int y);
    ///Returns result of a game (X or O wins)
    QString getResult();

    bool isWinX();
    bool isWinO();
    ///Has game finished
    bool isFinished();

    ///If user put X or O
    void makeMove(int x, int y);
    void changeState();
private:

    enum CellState
    {
        empty,
        X,
        O
    };

    enum GameState
    {
        inProgress,
        WinsX,
        WinsO
    };

    enum Move
    {
        moveX,
        moveO
    };

    CellState buttons[3][3];
    GameState currState;
    Move move;

    CellState update(Move move)
    {
        if (move == moveX)
            return X;
        return O;
    }


    Move nextMove()
    {
        if (move == moveX)
            return moveO;
        return moveX;

    }

};


