#include <QCoreApplication>
#include "sharedpointertest.h"

int main()
{
    SharedPointerTest test;
    QTest::qExec(&test);
}
