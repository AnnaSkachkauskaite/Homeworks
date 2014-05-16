#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QMessageBox>
#include <QString>


GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    size(3),
    isSmallField(true),
    tictactoe()
{
    ui->setupUi(this);
    createButtons();
    connect(ui->generateButton, &QPushButton::clicked, this, &GameWindow::createButtons);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::createButtons()
{
    if (!isSmallField)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                delete ui->gridLayout->itemAtPosition(i, j)->widget();
            }
        }
    size = ui->sizeSpinBox->value();
    tictactoe.changeFieldSize(size);
    }

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
        {
            QPushButton *button = new QPushButton;
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button->setText(" ");
            ui->gridLayout->addWidget( button, i, j);
            buttonsPosition[button] = qMakePair(i, j);
            connect(button, &QPushButton::clicked, this, &GameWindow::buttonClick);
        }
    isSmallField = false;
}

void GameWindow::buttonClick()
{
    if (tictactoe.isFinished())
        return;
    QPushButton *button = dynamic_cast<QPushButton *> (sender());
    int i = buttonsPosition[button].first;
    int j = buttonsPosition[button].second;
    tictactoe.makeMove(i, j);
    button->setText(tictactoe.getCellText(i, j));
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
    int sizeWind = std::min(geometry().height(), geometry().width());
    QFont buttonFont;
    buttonFont.setPixelSize(sizeWind * sizeWind / (1000 * size));
    buttonFont.setBold(true);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
        {
            QPushButton *button = dynamic_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i, j)->widget());
            button->setFont(buttonFont);
            button->setText(tictactoe.getCellText(i, j));

        }

}
