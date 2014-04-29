#include "calculator.h"
#include "sum.h"
#include "subtract.h"
#include "mult.h"
#include "div.h"
#include "number.h"

bool isNumb(char a)
{
    return ((a >= '0') && (a <= '9'));
}

bool isPlus(char a)
{
    return a == '+';
}

bool isMinus(char a)
{
    return a == '-';
}

bool isMul(char a)
{
    return a == '*';
}

bool isDiv(char a)
{
    return a == '/';
}

int numb(char a)
{
    return a - '0';
}

Calculator::Calculator() : pos(0)
{
}

TreeElement* Calculator::calc(string input)
{
    while (input[pos] == '(' || input[pos] == ')' || input[pos] == ' ')
    {
        pos++;
    }
    if (isNumb(input[pos]))
    {
        int result = 0;
        while (isNumb(input[pos]))
        {
            result = numb(input[pos]) + result * 10;
            ++pos;
        }
        return (new Number(result));
    }

    TreeElement *left;
    TreeElement *right;

    if (isPlus(input[pos]))
    {
        ++pos;
        left = calc(input);
        right = calc(input);
        return (new Sum(left, right));
    }

    if (isMul(input[pos]))
    {
        ++pos;
        left = calc(input);
        right = calc(input);
        return (new Mult(left, right));
    }

    if (isDiv(input[pos]))
    {
        ++pos;
        left = calc(input);
        right = calc(input);
        return (new Div(left, right));
    }

    if (isMinus(input[pos]))
    {
        ++pos;
        left = calc(input);
        right = calc(input);
        return (new Subtract(left, right));
    }

    return (new Number(-999));
}
