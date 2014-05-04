#pragma once
#include <string>
using namespace std;

///Class for element of calcualtor tree
class TreeElement
{
public:
    virtual ~TreeElement()
    {
    }
    virtual int getResult() = 0;
    ///Output hierarchica tree expression
    virtual string toString() = 0;
};


