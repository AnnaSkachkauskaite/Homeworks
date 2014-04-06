#pragma once
#include <QObject>


///Class for computing expression
class Calculator : public QObject
{
    Q_OBJECT

public:
    ///Takes two numbers, operation and calculates result
    int calculate(int arg1,int arg2, QString oper);
};

