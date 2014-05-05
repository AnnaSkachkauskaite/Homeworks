#pragma once
#include "calc.h"
#include "pointstack.h"
#include <QString>

///Class for computing result
class Calculator
{
public:
    Calculator();
    int calculate(QString str);
};

