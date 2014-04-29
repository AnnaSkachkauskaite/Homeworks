#pragma once
#include "exeption.h"

class DuplicateExeption : public Exeption
{
public:
    DuplicateExeption(const char *str);
};

