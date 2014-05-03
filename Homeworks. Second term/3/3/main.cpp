#include "ubercalculator.h"
#include <QApplication>
#include "calculatortest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalculatorTest test;
    QTest::qExec(&test);
    UberCalculator w;
    w.show();

    return a.exec();
}
