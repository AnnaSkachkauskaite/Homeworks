#pragma once
#include "treeelement.h"

///Node for addition
class Sum : public TreeElement
{
public:
    Sum(TreeElement *leftEl, TreeElement *rightEl);
    ~Sum();
    int getResult();
    string toString();
private:
    TreeElement *left;
    TreeElement *right;
};


