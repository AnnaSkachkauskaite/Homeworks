#include <QCoreApplication>
#include "bagtest.h"

int main()
{
    BagTest test;
    QTest::qExec(&test);
}
