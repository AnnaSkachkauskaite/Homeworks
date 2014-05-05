#pragma once
#include "pointstack.h"
#include <QtTest/QtTest>
#include <QObject>

class PointStackTest : public QObject
{
    Q_OBJECT
public:
    explicit PointStackTest(QObject *parent = 0);

private slots:

    void init()
    {
        stack = new PointerStack();
    }

    void cleanup()
    {
        delete stack;
    }

    void emptyPointerStackTest()
    {
        QVERIFY(stack->isEmpty());
    }

    void pushTest()
    {
        stack->push(0);
        QVERIFY(stack->getTop() == 0);
    }

    void popTest()
    {
        stack->push(1);
        char a = stack->pop();
        QVERIFY(stack->isEmpty());
        QVERIFY(a == 1);
    }

private:
    PointerStack *stack;

};

