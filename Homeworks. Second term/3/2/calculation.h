#pragma once
#include <QObject>

class Calculator : public QObject
{
    Q_OBJECT

public:
    int calculate(int arg1,int arg2, QString oper);
};

