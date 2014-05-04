#pragma once
#include "exeption.h"

///Exeption for trying to delete element which is not exist in the list
class DuplicateExeption : public Exeption
{
public:
    DuplicateExeption(const char *str);
};

