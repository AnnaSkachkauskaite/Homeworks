#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "matrixsort.h"

#include <iostream>
using namespace std;

class MatrixSortTest : public QObject
{
    Q_OBJECT
public:
    explicit MatrixSortTest(QObject *parent = 0);

private slots:

    void sortTest()
    {
        int size = 4;
        int** arr = new int*[4];
        arr[0] = new int[4] {8, 2, 17, 1};
        arr[1] = new int[4] {1, 48, 34, 9};
        arr[2] = new int[4] {76, 23, 84, 12};
        arr[3] = new int[4] {2, 4, 5, 6};
        int *firstLine = new int[4];
        for (int i = 0; i < size; ++i)
            firstLine[i] = arr[0][i];
        quickSort(firstLine, 0, size - 1, arr, size);
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
                cout << arr[i][j] << " ";
            cout << "\n";
        }
        QVERIFY(isSorted(arr, size));
        for (int i = 0; i < size; ++i)
            delete[] arr[i];
        delete[] arr;
        delete[] firstLine;
    }

private:
    bool isSorted(int** arr, int size)
    {
        for (int i = 0; i < size - 1; i++)
            if(arr[0][i] > arr[0][i + 1])
                return false;
        return true;
    }

};


