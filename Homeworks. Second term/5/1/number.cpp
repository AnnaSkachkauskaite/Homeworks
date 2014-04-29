#include "number.h"

Number::Number(int num) : number(num)
{
}

int Number::getResult()
{
    return number;
}

string Number::toString()
{
    return (to_string(number));
}
