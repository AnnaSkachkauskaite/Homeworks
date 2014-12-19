#ifndef ROBOTTEST_H
#define ROBOTTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "robotssystem.h"

class RobotTest : public QObject
{
    Q_OBJECT
public:
    explicit RobotTest(QObject *parent = 0);

private slots:

    void firstTest()
    {
        system.smallSystem();
        QVERIFY(system.isRobotsDestr());
    }

    void secondTest()
    {
        system.largeSystem();
        QVERIFY(!system.isRobotsDestr());
    }

private:
    RobotsSystem system;

};

#endif // ROBOTTEST_H
