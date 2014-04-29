#include "exeption.h"

Exeption::Exeption(const char *str) : message(str)
{
}

const char* Exeption::getExeption() const
{
    return message;
}
