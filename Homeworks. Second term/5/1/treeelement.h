#pragma once
#include <string>
using namespace std;

class TreeElement
{
public:
    virtual ~TreeElement()
    {
    }
    virtual int getResult() = 0;
    virtual string toString() = 0;
};


