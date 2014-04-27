#include "ubercalculator.h"
#include "ui_ubercalculator.h"
#include "pointstack.h"
#include "calculator.h"
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
    PointerStack *opers = new PointerStack;
    std::string input = new char[100];
    input = ui->lineEdit->text().toStdString();
    char *outstring = new char[100];
    int k = 0;
    int point = 0;
    while ((input[k] != '\0') && (input[k] != '='))
    {
        if (input[k] == ')')
        {
            while ((opers->getTop()) != '(')
            {
                outstring[point++] = opers->pop();
            }
            opers->pop();
        }
        if (isNumb(input[k]))
        {
            outstring[point++] = input[k];
        }
        if (input[k] == '(')
        {
            opers->push('(');
        }
        if (isSighn(input[k]))
        {
            if (opers->isEmpty())
            {
                opers->push(input[k]);
            }
            else  if (priority(opers->getTop()) < priority(input[k]))
            {
                opers->push(input[k]);
            }
            else
            {
                while ((opers != nullptr) && (priority(opers->getTop()) >= priority(input[k])))
                {
                    outstring[point++] = opers->pop();
                }
                opers->push(input[k]);
            }
        }
        k++;
    }
    while (!(opers->isEmpty()))
    {
        outstring[point++] = opers->pop();
    }
    outstring[point] = '\n';


    PointerStack *numbers = new PointerStack;
    k = 0;
    while (outstring[k] != '\n')
    {
        if (isNumb(outstring[k]))
        {
            numbers->push(numb(outstring[k]));
        }
        if (isSighn(outstring[k]))
        {
            int a = numbers->pop();
            int b = numbers->pop();
            numbers->push(calculate(a, b, outstring[k]));

        }
        ++k;
    }
    int result = numbers->pop();
    emit ui->lineEdit->setText(QString::number(result));
    delete numbers;
}
