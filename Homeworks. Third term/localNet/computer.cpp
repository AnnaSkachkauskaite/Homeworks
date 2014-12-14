#include "computer.h"

Computer::Computer()
{
    this->isInfected = false;
}

void Computer::setInf(bool inf)
{
    this->isInfected = inf;
}

void Computer::setProb(int prob)
{
    this->probability = prob;
}

int Computer::getProb()
{
    return this->probability;
}

bool Computer::inf()
{
    return this->probability;
}
