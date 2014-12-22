#ifndef ROBOTSSYSTEM_H
#define ROBOTSSYSTEM_H

const int maxNumber = 100;

class RobotsSystem
{
public:
    RobotsSystem();

    ///True if all robots can be destroyed
    bool areAllRobotsDestroyed();

    void setSize(int matrixSize);
    void setMatrixElement(int i, int j, bool value);
    void setRobot(int i, bool isRobot);


private:

    ///True if robot on the position cen be destroyed
    bool isRobotCanBeDestroyed(int position);
    ///Graph size
    int size;
    ///Number of robots in the system
    int numbRobots;
    ///Adjency matrix
    bool matrix[maxNumber][maxNumber];


    ///Element true if vertex contains robot
    bool robot[maxNumber];

    ///Element true if robot destroyed
    bool isRobotDestroyed[maxNumber];
};

#endif // ROBOTSSYSTEM_H
