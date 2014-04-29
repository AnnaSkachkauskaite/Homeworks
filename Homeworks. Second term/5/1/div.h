#pragma once
#include "treeelement.h"

///Node for division
class Div : public TreeElement
{
public:
    Div(TreeElement *leftEl, TreeElement *rightEl);
    ~Div();
    int getResult();
    string toString();
private:
    TreeElement *left;
    TreeElement *right;
};


