#include "sum.h"

Sum::Sum(TreeElement *leftEl, TreeElement *rightEl) : left(leftEl), right(rightEl)
{
}

Sum::~Sum()
{
    delete left;
    delete right;
}

int Sum::getResult()
{
    return (left->getResult() + right->getResult());
}

string Sum::toString()
{
    return string("( + " + left->toString() + " " + right->toString() + " )");
}
