#include <QCoreApplication>
#include "robottest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RobotTest test;
    QTest::qExec(&test);

    return a.exec();
}
