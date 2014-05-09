#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QMessageBox>
#include <QString>


GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    createButtons();
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::createButtons()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            QPushButton *button = new QPushButton;
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button->setText(" ");
            ui->gridLayout->addWidget( button, i, j);
            buttonsPosition[button] = qMakePair(i, j);
            connect(button, &QPushButton::clicked, this, &GameWindow::buttonClick);
        }
}

void GameWindow::buttonClick()
{
    if (tictactoe.isFinished())
        return;
    QPushButton *button = dynamic_cast<QPushButton *> (sender());
    int i = buttonsPosition[button].first;
    int j = buttonsPosition[button].second;
    tictactoe.makeMove(i, j);
    button->setText(tictactoe.getCellState(i, j));
    tictactoe.changeState();
    button->setEnabled(false);
    if (tictactoe.isFinished())
    {
        int ok = QMessageBox::information(this, "Game over!", tictactoe.getResult());
        if (ok == QMessageBox::Ok)
            qApp->quit();
    }
}

void GameWindow::resizeEvent(QResizeEvent *resized)
{
    QMainWindow::resizeEvent(resized);
    int size = std::min(geometry().height(), geometry().width());
    QFont buttonFont;
    buttonFont.setPixelSize(size * size / 3000);
    buttonFont.setBold(true);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            QPushButton *button = dynamic_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i, j)->widget());
            button->setFont(buttonFont);
            button->setText(tictactoe.getCellState(buttonsPosition[button].first, buttonsPosition[button].second));

        }

}
