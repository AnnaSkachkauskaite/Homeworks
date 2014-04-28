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

    void emptySetTest()
    {
        QVERIFY(set.getSize() == 0);
    }

    void addElemTest()
    {
        set.incert(1);
        QVERIFY(set.isFind(1));
    }

    void deleteElemTest()
    {
        set.del(1);
        QVERIFY(!(set.isFind(1)));
    }

    void addTwoElemTest()
    {
        set.incert(1);
        set.incert(4);
        QVERIFY(set.getSize() == 2);
    }

    void unificationTwoSetsTest()
    {
        MySet<int> newSet;
        newSet.incert(5);
        newSet.incert(7);
        set = set.unification(newSet);
        QVERIFY(set.isFind(5));
    }

     void intersectionTwoSetsTest()
     {
         MySet<int> newSet;
         newSet.incert(8);
         newSet.incert(3);
         set = set.intersection(newSet);
         QVERIFY(set.isEmpty());
     }

private:
    MySet<int> set;

};


