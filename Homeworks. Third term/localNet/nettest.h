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
    void Systemtest()
    {
        net.defaultSystem();
        net.infSystem();
        QVERIFY(net.numbOfInf() == net.numbOfComputers());
    }

private:
    Net net;

};

#endif // NETTEST_H

