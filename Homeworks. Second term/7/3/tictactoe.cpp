#include "tictactoe.h"

TicTacToe::TicTacToe()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            buttons[i][j] = empty;
    move = moveX;
    currState = inProgress;

}

QString TicTacToe::getCellState(int x, int y)
{
    if (buttons[x][y] == empty)
        return " ";
    if (buttons[x][y] == X)
        return "X";
    return "O";
}

bool TicTacToe::isWinO()
{
    return currState == WinsO;
}

bool TicTacToe::isWinX()
{
    return currState == WinsX;
}

bool TicTacToe::isFinished()
{
    if (isWinX() || isWinO())
        return true;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (buttons[i][j] == empty)
                return false;
    return true;
}

QString TicTacToe::getResult()
{
    if (isWinX())
        return QString("X wins!");
    if (isWinO())
        return QString("O wins!");
    return QString("Draw!");

}

void TicTacToe::makeMove(int x, int y)
{
    if (isFinished())
        return;
    buttons[x][y] = update(move);
    changeState();
    move = nextMove();

}

void TicTacToe::changeState()
{
    if (currState != inProgress)
        return;
    if (buttons[0][0] == buttons[1][1] && buttons[1][1] == buttons[2][2] && buttons[2][2] != empty)
    {
        if (buttons[2][2] == X)
            currState = WinsX;
        else
            currState = WinsO;
    }

    if (buttons[0][2] == buttons[1][1] && buttons[1][1] == buttons[2][0] && buttons[2][0] != empty)
    {
        if (buttons[2][0] == X)
            currState = WinsX;
        else
            currState = WinsO;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (buttons[i][0] == buttons[i][1] && buttons[i][1] == buttons[i][2] && buttons[i][2] != empty)
        {
            if (buttons[i][2] == X)
                currState = WinsX;
            else
                currState = WinsO;
            return;
        }

        if (buttons[0][i] == buttons[1][i] && buttons[1][i] == buttons[2][i] && buttons[2][i] != empty)
        {
            if (buttons[2][i] == X)
                currState = WinsX;
            else
                currState = WinsO;
            return;
        }
    }
}
