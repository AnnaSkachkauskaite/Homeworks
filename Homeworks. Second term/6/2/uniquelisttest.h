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
        list->addValue(3);
        list->deleteValue(3);
         QVERIFY(!list->isFind(3));
    }

    void addDuplicateElemTest()
    {
        list->addValue(4);
        try
        {
            list->addToUniqueList(4);
        }
        catch (const Exeption &ex)
        {
            QCOMPARE(ex.getExeption(), "This element is exist in tge list");
        }
    }

    void deleteNonexistentElemTest()
    {
        list->addValue(6);
        list->deleteValue(6);
        try
        {
            list->delFromUniqueList(6);
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

