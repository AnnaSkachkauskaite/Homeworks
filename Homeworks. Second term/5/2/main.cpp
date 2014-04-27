#include <QCoreApplication>
#include "settest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SetTest intsettests;
    QTest::qExec(&intsettests);

    return a.exec();
}
