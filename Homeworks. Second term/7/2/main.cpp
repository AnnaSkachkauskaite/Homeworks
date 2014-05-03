#include <QCoreApplication>
#include "vectortest.h"

int main()
{
    VectorTest test;
    QTest::qExec(&test);
}
