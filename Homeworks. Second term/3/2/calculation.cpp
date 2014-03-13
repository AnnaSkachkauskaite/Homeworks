#include "calculation.h"

int Calculator::calculate(int arg1, int arg2, QString oper)
{
    switch (static_cast<char>(oper.toStdString()[0]))
    {
    case '+':
        return arg1 + arg2;
        break;
    case '-':
        return arg1 - arg2;
        break;
    case '*':
        return arg1 * arg2;
        break;
    case '/':
        return arg1 / arg2;
        break;
    }
    return 0;
}
