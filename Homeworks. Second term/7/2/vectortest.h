#pragma once
#include "vector.h"

#include <QObject>
#include <QtTest/QtTest>

class VectorTest : public QObject
{
    Q_OBJECT
public:
    explicit VectorTest(QObject *parent = 0);

private slots:

    void zeroVectorTest()
    {
        Vector<int, 3> vector;
        QVERIFY(vector.isZeroVector());
    }

    void initVaectorTest()
    {
        int arr[3] = {2, 7, 4};
        Vector<int, 3> vector(arr);
        QVERIFY(!vector.isZeroVector());
    }

    void vectorAdditionTest()
    {
        int arr1[3] = {2, 7, 4};
        Vector<int, 3> vector1(arr1);
        int arr2[3] = {3, 6, 9};
        Vector<int, 3> vector2(arr2);
        Vector<int, 3> sum = vector1 + vector2;
        int arr3[3] = {5, 13, 13};
        Vector<int, 3> vector3(arr3);
        QVERIFY(vector3.areEqual(sum));
    }

    void vectorSubtractionTest()
    {
        int arr1[3] = {2, 7, 4};
        Vector<int, 3> vector1(arr1);
        int arr2[3] = {3, 6, 9};
        Vector<int, 3> vector2(arr2);
        Vector<int, 3> diff = vector1 - vector2;
        int arr3[3] = {-1, 1, -5};
        Vector<int, 3> vector3(arr3);
        QVERIFY(vector3.areEqual(diff));
    }

    void vectorMultiplicationTest()
    {
        int arr1[3] = {1, 2, 3};
        Vector<int, 3> vector1(arr1);
        int arr2[3] = {4, 7, 1};
        Vector<int, 3> vector2(arr2);
        int prod = vector1 * vector2;
        QVERIFY(prod == 21);
    }

};

