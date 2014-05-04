#pragma once
#include "treeelement.h"
using namespace std;

///Class for computing value of expression from input string
class Calculator
{
public:
    Calculator();
    TreeElement *calc(string input);
private:
    ///position in parsed string
    int pos;
};


