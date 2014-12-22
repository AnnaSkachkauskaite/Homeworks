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
        system.setSize(3);

        system.setMatrixElement(0, 0, true);
        system.setMatrixElement(0, 1, true);
        system.setMatrixElement(0, 2, false);

        system.setMatrixElement(1, 0, true);
        system.setMatrixElement(1, 1, true);
        system.setMatrixElement(1, 2, true);

        system.setMatrixElement(2, 0, false);
        system.setMatrixElement(2, 1, true);
        system.setMatrixElement(2, 2, true);

        system.setRobot(0, true);
        system.setRobot(1, false);
        system.setRobot(2, true);

        QVERIFY(system.areAllRobotsDestroyed());
    }

    void secondTest()
    {
        system.setSize(4);

        system.setMatrixElement(0, 0, true);
        system.setMatrixElement(0, 1, false);
        system.setMatrixElement(0, 2, true);
        system.setMatrixElement(0, 3, false);

        system.setMatrixElement(1, 0, false);
        system.setMatrixElement(1, 1, true);
        system.setMatrixElement(1, 2, true);
        system.setMatrixElement(1, 3, false);

        system.setMatrixElement(2, 0, true);
        system.setMatrixElement(2, 1, true);
        system.setMatrixElement(2, 2, true);
        system.setMatrixElement(2, 3, true);

        system.setMatrixElement(3, 0, false);
        system.setMatrixElement(3, 1, false);
        system.setMatrixElement(3, 2, true);
        system.setMatrixElement(3, 3, true);

        system.setRobot(0, true);
        system.setRobot(1, true);
        system.setRobot(2, true);
        system.setRobot(3, false);

        QVERIFY(!system.areAllRobotsDestroyed());
    }

private:
    RobotsSystem system;
};

#endif // ROBOTTEST_H
