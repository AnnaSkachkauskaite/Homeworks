#pragma once
#include "bubblesort.h"
#include "insertionsort.h"
#include "qsort.h"
#include <cstdio>
#include <ctime>

#include <QObject>
#include <QtTest/QtTest>

class SorterTest : public QObject
{
    Q_OBJECT
public:
    explicit SorterTest(QObject *parent = 0);

private slots:

    void bubbleSortTest()
    {
        BubbleSort sorter;
        int arr[10];
        srand(time(NULL));
        for (int i = 0; i < 10; ++i)
            arr[i] = rand() % 100;
        sorter.sort(arr, 10);
        QVERIFY(isSorted(arr, 10));
    }

    void quickSortTest()
    {
        QSort sorter;
        int arr[10];
        srand(time(NULL));
        for (int i = 0; i < 10; ++i)
            arr[i] = rand() % 100;
        sorter.sort(arr, 10);
        QVERIFY(isSorted(arr, 10));
    }

    void insertionSortTest()
    {
        InsertionSort sorter;
        int arr[10];
        srand(time(NULL));
        for (int i = 0; i < 10; ++i)
            arr[i] = rand() % 100;
        sorter.sort(arr, 10);
        QVERIFY(isSorted(arr, 10));
    }

private:
    bool isSorted(int arr[], int size)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if(arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

};


