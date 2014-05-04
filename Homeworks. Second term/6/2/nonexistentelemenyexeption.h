#pragma once
#include "exeption.h"

///Exeption for trying to add element which is already exist in the list
class NonexistentElemenyExeption : public Exeption
{
public:
    NonexistentElemenyExeption(const char *str);
};

