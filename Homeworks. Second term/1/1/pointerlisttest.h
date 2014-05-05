#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "pointlist.h"

class PointerListTest : public QObject
{
    Q_OBJECT
public:
    explicit PointerListTest(QObject *parent = 0);

private slots:
    void init()
    {
        list = new PoinerList();
    }

    void cleanup()
    {
        delete list;
    }

    void emptyPointerListTest()
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
    PoinerList *list;
};

