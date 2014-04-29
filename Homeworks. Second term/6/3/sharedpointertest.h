#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "sharedpointer.h"

class SharedPointerTest : public QObject
{
    Q_OBJECT
public:
    explicit SharedPointerTest(QObject *parent = 0);

private slots:

    void initTestCase()
    {
        ptr = new SharedPointer<int>(new int(2));
    }

    void copyPointerTest()
    {
        SharedPointer<int> copy(*ptr);
        QVERIFY(ptr->getCount() == 2);
    }

    void assignmentPointerTest()
    {
        SharedPointer<int> tmp(new int(3));
        *ptr = tmp;
        QCOMPARE(ptr->getPointer(), tmp.getPointer());
    }

    void cleanupTestCase()
    {
        delete ptr;
    }

private:
    SharedPointer<int> *ptr;

};
