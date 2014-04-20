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



private:
    MySet<int> *set;

};


