#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "bag.h"

class BagTest : public QObject
{
    Q_OBJECT
public:
    explicit BagTest(QObject *parent = 0);

private slots:

    void initTestCase()
    {
        bag = new Bag();
    }

    void addElmemTest()
    {
        bag->incert(1);
        bag->incert(2);
        QVERIFY(bag->getSize() == 2);
        QVERIFY(bag->isFind(1));
        QVERIFY(bag->isFind(2));
    }

    void addDuplicateElemTest()
    {
        bag->incert(1);
        QVERIFY(bag->getSize() == 3);
    }

    void removeElemTest()
    {
        bag->remove(2);
        QVERIFY(bag->getSize() == 2);
        QVERIFY(!bag->isFind(2));
    }

    void cleanupTestCase()
    {
        delete bag;
    }

private:
    Bag *bag;

};

