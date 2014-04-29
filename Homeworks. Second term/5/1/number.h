#pragma once
#include "treeelement.h"

///Node for number
class Number : public TreeElement
{
public:
    Number(int num);
    int getResult();
    string toString();
private:
    int number;
};


