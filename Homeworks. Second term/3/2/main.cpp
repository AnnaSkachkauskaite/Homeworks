#include "mainwindow.h"
#include "calculatortest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    CalculatorTest test;
    QTest::qExec(&test);
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(w.size());
    w.show();

    return a.exec();
}
