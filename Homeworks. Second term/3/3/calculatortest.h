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
    void clacTest1()
    {
        int result = calc.calculate(QString("3*6-2"));
        QVERIFY(result == 16);
    }

    void calcTest2()
    {
        int result = calc.calculate(QString("7+2*5"));
        QVERIFY(result == 17);
    }

    void calcTest3()
    {
        int result = calc.calculate(QString("6/2-3"));
        QVERIFY(result == 0);
    }

private:
    Calculator calc;

};


