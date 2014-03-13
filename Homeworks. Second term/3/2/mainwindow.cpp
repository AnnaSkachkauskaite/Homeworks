#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->operation->addItem("+");
    ui->operation->addItem("-");
    ui->operation->addItem("*");
    ui->operation->addItem("/");

    connect(ui->arg1, SIGNAL(valueChanged(int)), this, SLOT(getResult()));
    connect(ui->operation, SIGNAL(currentTextChanged(QString)), this, SLOT(getResult()));
    connect(ui->arg2, SIGNAL(valueChanged(int)), this, SLOT(getResult()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getResult()
{
    if ((ui->operation->currentText() == "/") && (ui->arg2->value() == 0))
            ui->result->setText("division by zero!");
    else
        ui->result->setText(QString::number(calculator.calculate(ui->arg1->value(), ui->arg2->value(), ui->operation->currentText())));
}
