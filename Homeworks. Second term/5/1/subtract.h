#pragma once
#include "treeelement.h"

///Node for subtractoin
class Subtract : public TreeElement
{
public:
    Subtract(TreeElement *leftEl, TreeElement *rightEl);
    ~Subtract();
    int getResult();
    string toString();
private:
    TreeElement *left;
    TreeElement *right;
};


