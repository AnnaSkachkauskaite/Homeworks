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
        MySet<int> set;
        QVERIFY(set.getSize() == 0);
    }

    void addElemTest()
    {
        MySet<int> set;
        set.insert(1);
        QVERIFY(set.isFind(1));
    }

    void deleteElemTest()
    {
        MySet<int> set;
        set.insert(2);
        set.del(2);
        QVERIFY(!(set.isFind(2)));
    }

    void addTwoElemTest()
    {
        MySet<int> set;
        set.insert(1);
        set.insert(4);
        QVERIFY(set.getSize() == 2);
    }

    void unificationTwoSetsTest()
    {
        MySet<int> set;
        set.insert(1);
        set.insert(4);
        MySet<int> newSet;
        newSet.insert(5);
        newSet.insert(7);
        set = set.unification(newSet);
        QVERIFY(set.isFind(5));
    }

     void intersectionTwoSetsTest()
     {
         MySet<int> set;
         set.insert(1);
         set.insert(4);
         MySet<int> newSet;
         newSet.insert(8);
         newSet.insert(3);
         set = set.intersection(newSet);
         QVERIFY(set.isEmpty());
     }


};


