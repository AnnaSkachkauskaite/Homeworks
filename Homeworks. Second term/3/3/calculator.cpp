#include "calculator.h"
#include "calc.h"

Calculator::Calculator()
{
}

int Calculator::calculate(QString str)
{
    PointerStack *opers = new PointerStack;
    char input[80], outstring[80];
    int k = 0;
    int point = 0;
    //printf("Enter task (with = in the end):\n");
    //gets(input);
    for(int i = 0; i < str.length(); ++i)
        input[i] = str.toStdString()[i];
    while ((input[k] != '\0') && (input[k] != '='))
    {
        if (input[k] == ')')
        {
            while ((opers->getTop()) != '(')
            {
                outstring[point++] = opers->pop();
            }
            opers->pop();
        }
        if (isNumb(input[k]))
        {
            outstring[point++] = input[k];
        }
        if (input[k] == '(')
        {
            opers->push('(');
        }
        if (isSighn(input[k]))
        {
            if (opers->isEmpty())
            {
                opers->push(input[k]);
            }
            else  if (priority(opers->getTop()) < priority(input[k]))
            {
                opers->push(input[k]);
            }
            else
            {
                while ((opers != nullptr) && (priority(opers->getTop()) >= priority(input[k])))
                {
                    outstring[point++] = opers->pop();
                }
                opers->push(input[k]);
            }
        }
        k++;
    }
    while (!(opers->isEmpty()))
    {
        outstring[point++] = opers->pop();
    }
    outstring[point] = '\n';
    //for (int i = 0; i <= point; ++i)
        //printf("%c", outstring[i]);
    delete(opers);


    PointerStack *numbers = new PointerStack;
    k = 0;
    while (outstring[k] != '\n')
    {
        if (isNumb(outstring[k]))
        {
            numbers->push(numb(outstring[k]));
        }
        if (isSighn(outstring[k]))
        {
            int a = numbers->pop();
            int b = numbers->pop();
            numbers->push(calc(b, a, outstring[k]));

        }
        ++k;
    }
    //printf("result: %d\n", numbers->pop());
    return numbers->pop();
    delete(numbers);
}
