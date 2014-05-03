#include "ubercalculator.h"
#include "ui_ubercalculator.h"
#include "pointstack.h"
#include "calculator.h"
#include "calc.h"
#include <QString>
#include <stdio.h>

UberCalculator::UberCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UberCalculator)
{
    ui->setupUi(this);
    signalMapper = new QSignalMapper(this);

        connect(ui->pushButton0, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(ui->pushButton0, "0");
        connect(ui->pushButton1, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(ui->pushButton1, "1");
        connect(ui->pushButton2, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(ui->pushButton2, "2");
        connect(ui->pushButton3, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(ui->pushButton3, "3");
        connect(ui->pushButton4, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(ui->pushButton4, "4");
        connect(ui->pushButton5, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(ui->pushButton5, "5");
        connect(ui->pushButton6, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(ui->pushButton6, "6");
        connect(ui->pushButton7, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(ui->pushButton7, "7");
        connect(ui->pushButton8, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(ui->pushButton8, "8");
        connect(ui->pushButton9, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(ui->pushButton9, "9");
        connect(ui->pushButtonPlus, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(ui->pushButtonPlus, "+");
        connect(ui->pushButtonMinus, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(ui->pushButtonMinus, "-");
        connect(ui->pushButtonMult, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(ui->pushButtonMult, "*");
        connect(ui->pushButtonDiv, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(ui->pushButtonDiv, "/");
        connect(ui->pushButtonEqual, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(ui->pushButtonEqual, "=");

        connect(signalMapper, SIGNAL(mapped(const QString&)), this, SLOT(addToLine(QString)));
        connect(ui->pushButtonEqual, SIGNAL(clicked()), this, SLOT(getResult()));
        connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clearLine()));
}

UberCalculator::~UberCalculator()
{
    delete ui;
}

void UberCalculator::addToLine(QString str)
{
    ui->lineEdit->setText(ui->lineEdit->text() + str);
}

void UberCalculator::getResult()
{
    Calculator calc;
    int result = calc.calculate(ui->lineEdit->text());
    ui->lineEdit->setText(QString::number(result));
}

void UberCalculator::clearLine()
{
    emit ui->lineEdit->setText("");
}
