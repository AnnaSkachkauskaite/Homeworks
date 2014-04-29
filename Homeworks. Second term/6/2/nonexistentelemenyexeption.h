#pragma once
#include "exeption.h"

class NonexistentElemenyExeption : public Exeption
{
public:
    NonexistentElemenyExeption(const char *str);
};

