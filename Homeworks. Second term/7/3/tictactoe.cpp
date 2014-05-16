#include "tictactoe.h"

TicTacToe::TicTacToe()
{
    size = 3;
    winNumber = 3;
    buttons = new CellState *[size];
    for (int i = 0; i < size; ++i)
        buttons[i] = new CellState [size];
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            buttons[i][j] = empty;
    move = moveX;
    currState = inProgress;

}

TicTacToe::~TicTacToe()
{
    for (int i = 0; i < size; ++i)
        delete[] buttons[i];
    delete[] buttons;
}

TicTacToe::CellState TicTacToe::getCellState(int x, int y)
{
    return buttons[x][y];
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
    for (int i = 0; i < size - winNumber + 1; i++)
      for (int j = winNumber - 1; j < size; j++)
      {
        bool win = true;
        for (int k = 0; k < winNumber - 1; k++)
          if (buttons[i + k][j - k] == empty || buttons[i + k][j - k] != buttons[i + k + 1][j - k - 1])
          {
            win = false;
            break;
          }
        if (!win)
          continue;

        if (buttons[i][j] == X)
          currState = WinsX;
        else
          currState = WinsO;
      }
      for (int i = 0; i < size; i++)
      {
        for (int j = 0; j < size - winNumber + 1; j++)
        {
          bool win = true;
          for (int k = 0; k < winNumber - 1; k++)
            if (buttons[i][j + k] == empty || buttons[i][j + k] != buttons[i][j + k + 1])
            {
              win = false;
              break;
            }
          if (!win)
            continue;

          if (buttons[i][j] == X)
            currState = WinsX;
          else
            currState = WinsO;
          return;
        }
      }

      for (int i = 0; i < size; i++)
        for (int j = 0; j < size - winNumber + 1; j++)
        {
          bool win = true;
          for (int k = 0; k < winNumber - 1; k++)
            if (buttons[j + k][i] == empty || buttons[j + k][i] != buttons[j + k + 1][i])
            {
              win = false;
              break;
            }

          if (!win)
            continue;

          if (buttons[i][j] == X)
            currState = WinsX;
          else
            currState = WinsO;
          return;
      }

      for (int i = 0; i < size - winNumber + 1; i++)
        for (int j = 0; j < size - winNumber + 1; j++)
        {
          bool win = true;
          for (int k = 0; k < winNumber - 1; k++)
            if (buttons[i + k][j + k] == empty || buttons[i + k][j + k] != buttons[i + k + 1][j + k + 1])
            {
              win = false;
              break;
            }
          if (!win)
            continue;

          if (buttons[i][j] == X)
            currState = WinsX;
          else
            currState = WinsO;
          return;
        }

    }

void TicTacToe::changeFieldSize(int newSize)
{
    for (int i = 0; i < size; ++i)
        delete[] buttons[i];
    delete[] buttons;

    size = newSize;

    buttons = new CellState *[size];
    for (int i = 0; i < size; ++i)
        buttons[i] = new CellState [size];
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            buttons[i][j] = empty;
    winNumber = 5;
    move = moveX;
}

QString TicTacToe::getCellText(int x, int y)
{
    if (buttons[x][y] == empty)
            return " ";
        if (buttons[x][y] == X)
            return "X";
        return "O";
}
