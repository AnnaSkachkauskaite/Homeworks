#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "calculation.h"

class CalculatorTest : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorTest(QObject *parent = 0);

private slots:

    void calculationTest1()
    {
        QVERIFY(calculator.calculate(2, 3, QString("+")) == 5);
    }

    void calculationTest2()
    {
        QVERIFY(calculator.calculate(6, 5, QString("-")) == 1);
    }

    void calculationTest3()
    {
        QVERIFY(calculator.calculate(4, 2, QString("*")) == 8);
    }

    void calculationTest4()
    {
        QVERIFY(calculator.calculate(6, 3, QString("/")) == 2);
    }

private:
    Calculator calculator;

};


