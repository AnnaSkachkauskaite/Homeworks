#pragma once
#include "treeelement.h"

class Calculator
{
public:
    Calculator();
    TreeElement *calc(string input);
private:
    ///position in parsed string
    int pos;
};


