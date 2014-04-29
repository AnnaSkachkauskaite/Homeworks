#include "div.h"

Div::Div(TreeElement *leftEl, TreeElement *rightEl) : left(leftEl), right(rightEl)
{
}

Div::~Div()
{
    delete left;
    delete right;
}

int Div::getResult()
{
    return (left->getResult() / right->getResult());
}

string Div::toString()
{
    return string("( / " + left->toString() + " " + right->toString() + " )");
}

