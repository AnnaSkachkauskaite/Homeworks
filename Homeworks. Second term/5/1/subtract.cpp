#include "subtract.h"

Subtract::Subtract(TreeElement *leftEl, TreeElement *rightEl) : left(leftEl), right(rightEl)
{
}

Subtract::~Subtract()
{
    delete left;
    delete right;
}

int Subtract::getResult()
{
    return (left->getResult() - right->getResult());
}

string Subtract::toString()
{
    return string("( - " + left->toString() + " " + right->toString() + " )");
}

