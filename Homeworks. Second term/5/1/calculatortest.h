#pragma once
#include "calculator.h"
#include <QObject>
#include <QtTest/QtTest>

class CalculatorTest : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorTest(QObject *parent = 0);

private slots:
    void init()
    {
        calculator = new Calculator();
    }

    void calculatorTest1()
    {
        TreeElement *result = calculator->calc("(* (+ 1 1) 2)");
        QVERIFY(result->getResult() == 4);
        QVERIFY(result->toString() == "( * ( + 1 1 ) 2 )");
        delete result;
    }

    void calculatorTest2()
    {
        TreeElement *result = calculator->calc("(/ (* 3 4) 2)");
        QVERIFY(result->getResult() == 6);
        QVERIFY(result->toString() == "( / ( * 3 4 ) 2 )");
        delete result;
    }

    void calculatorTest3()
    {
        TreeElement *result = calculator->calc("(- (* 10 3) 2)");
        QVERIFY(result->getResult() == 28);
        QVERIFY(result->toString() == "( - ( * 10 3 ) 2 )");
        delete result;
    }

    void cleanup()
    {
        delete calculator;
    }

private:
    Calculator *calculator;
};


