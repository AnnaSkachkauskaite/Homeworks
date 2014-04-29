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
    void initTestCase()
    {
        calculator = new Calculator();
        result = calculator->calc("(* (+ 1 1) 2)");
    }

    void resultTest()
    {
        QVERIFY(result->getResult() == 4);
    }

    void stringTest()
    {
        QVERIFY(result->toString() == "( * ( + 1 1 ) 2 )");
    }

    void cleanupTestCase()
    {
        delete calculator;
        delete result;
    }

private:
    Calculator *calculator;
    TreeElement *result;
};


