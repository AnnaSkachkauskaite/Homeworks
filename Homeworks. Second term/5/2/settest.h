#pragma once
#include "myset.h"
#include <QObject>
#include <QtTest/QtTest>

class SetTest : public QObject
{
    Q_OBJECT
public:
    explicit SetTest(QObject *parent = 0);


private slots:
    void initTestCase()
    {
         set = new MySet<int>();
    }

    void emptySetTest()
    {
        QVERIFY(set->getSize() == 0);
    }

    void addElemTest()
    {
        set->incert(1);
        QVERIFY(set->isFind(1));
    }

    void deleteElemTest()
    {
        set->del(1);
        QVERIFY(!(set->isFind(1)));
    }

    void addTwoElemTest()
    {
        set->incert(1);
        set->incert(4);
        QVERIFY(set->getSize() == 2);
    }


private:
    MySet<int> *set;

};


