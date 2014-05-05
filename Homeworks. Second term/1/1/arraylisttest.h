#pragma once
#include "arrlist.h"

#include <QObject>
#include <QtTest/QtTest>

class ArrayListTest : public QObject
{
    Q_OBJECT
public:
    explicit ArrayListTest(QObject *parent = 0);

private slots:
    void init()
    {
        list = new ArrayList();
    }

    void cleanup()
    {
        delete list;
    }

    void emptyArrayListTest()
    {
        QVERIFY(list->getSize() == 0);
    }

    void addElementTest()
    {
        list->addValue(1);
        QVERIFY(list->isFind(1));
    }

    void deleteElementTest()
    {
        list->addValue(1);
        list->addValue(2);
        list->deleteValue(2);
        QVERIFY(!list->isFind(2));
        QVERIFY(list->isFind(1));
    }

private:
    ArrayList *list;

};


