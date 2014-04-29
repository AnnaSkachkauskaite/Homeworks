#include "bag.h"

Bag::Bag() : size(0)
{
    set.clear();
}

Bag::~Bag()
{
    set.clear();
}

bool Bag::isFind(int value)
{
    return set[value] > 0;
}

void Bag::incert(int value)
{
    ++set[value];
    ++size;
}

void Bag::remove(int value)
{
    if (isFind(value))
    {
        --set[value];
        --size;
    }
}

int Bag::getSize()
{
    return size;
}
