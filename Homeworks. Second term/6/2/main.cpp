#include <QCoreApplication>
#include "uniquelisttest.h"

int main()
{
   UniqueListTest test;
   QTest::qExec(&test);
}
