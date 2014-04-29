#pragma once
#include "treeelement.h"

///Node for multiplication
class Mult : public TreeElement
{
public:
    Mult(TreeElement *leftEl, TreeElement *rightEl);
    ~Mult();
    int getResult();
    string toString();
private:
    TreeElement *left;
    TreeElement *right;
};

