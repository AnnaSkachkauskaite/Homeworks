#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include <iostream>
#include "uniquelist.h"
#include "exeption.h"

using namespace std;

class UniqueListTest : public QObject
{
    Q_OBJECT
public:
    explicit UniqueListTest(QObject *parent = 0);

private slots:

    void initTestCase()
    {
        list = new UniqueList();
    }

    void addElemTest()
    {
        list->addValue(1);
        list->addValue(2);
        QVERIFY(list->isFind(1) && list->isFind(2));
    }

    void delElemTest()
    {
        list->deleteValue(2);
         QVERIFY(!list->isFind(2));
    }

    void addDuplicateElemTest()
    {
        try
        {
            list->addToUniqueList(1);
        }
        catch (const Exeption &ex)
        {
            QCOMPARE(ex.getExeption(), "This element is exist in tge list");
        }
    }

    void deleteNonexistentElemTest()
    {
        try
        {
            list->delFromUniqueList(4);
        }
        catch (const Exeption &ex)
        {
            QCOMPARE(ex.getExeption(), "Can't delete, element dosen't find");
        }
    }

    void cleanupTestCase()
    {
        delete list;
    }

private:
    UniqueList *list;

};

