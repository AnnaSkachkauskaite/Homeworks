#ifndef NETTEST_H
#define NETTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "net.h"

class NetTest : public QObject
{
    Q_OBJECT
public:
    explicit NetTest(QObject *parent = 0);

signals:

private slots:
    void FirstTest()
    {
        net.defaultSystem();
        net.setTesting();
        net.infectSystem();
        result = net.getResult();
        QVERIFY(result[0] == 1);
        QVERIFY(result[1] == 2);
        QVERIFY(result[2] == 4);
        QVERIFY(result[3] == 3);
    }

private:
    Net net;
    QList<int> result;

};

#endif // NETTEST_H

