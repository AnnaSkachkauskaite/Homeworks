#include <QCoreApplication>
#include "calculatortest.h"
#include "calculator.h"


int main()
{
    CalculatorTest test;
    QTest::qExec(&test);
}
