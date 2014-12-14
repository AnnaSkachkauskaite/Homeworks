#include <QCoreApplication>
#include "nettest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    NetTest test;
    QTest::qExec(&test);

    return a.exec();
}
