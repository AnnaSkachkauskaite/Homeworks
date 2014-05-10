#pragma once
#include "writer.h"
#include <iostream>
#include <QObject>
#include <QtTest/QtTest>
#include <QString>

using namespace std;

class WriterTest : public QObject
{
    Q_OBJECT
public:
    explicit WriterTest(QObject *parent = 0);

private slots:

    void wrterTest()
    {
        int** arr = new int*[3];
        arr[0] = new int[3] {1, 2, 3};
        arr[1] = new int[3] {4, 5, 6};
        arr[2] = new int[3] {7, 8, 9};
        string result = writer->makeString(arr, 3); //"5 4 7 8 9 6 3 2 1 ";
        cout << result << "\n";
        string out = "5 4 7 8 9 6 3 2 1 ";
        cout << out;
        for (int i = 0; i < out.size(); ++i)
            QCOMPARE(result[i], out[i]);

    }
private:
    Writer *writer;

};


