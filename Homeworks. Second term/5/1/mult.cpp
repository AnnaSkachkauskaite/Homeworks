#include "mult.h"

Mult::Mult(TreeElement *leftEl, TreeElement *rightEl) : left(leftEl), right(rightEl)
{
}

Mult::~Mult()
{
    delete left;
    delete right;
}

int Mult::getResult()
{
    return (left->getResult() * right->getResult());
}

string Mult::toString()
{
    return string("( * " + left->toString() + " " + right->toString() + " )");
}

