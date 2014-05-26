#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QMap>
#include <QPair>

#include "tictactoe.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

private slots:
    ///Slot for generating buttons
    void createButtons();
    ///Slot for processing pushed button
    void buttonClick();


private:
    Ui::GameWindow *ui;
    QMap <QPushButton *, QPair<int, int>> buttonsPosition;
    TicTacToe tictactoe;
    ///Resize text on buttons
    void resizeEvent(QResizeEvent *resized);
    int size;
    bool isSmallField;
};


