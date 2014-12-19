#ifndef ROBOTSSYSTEM_H
#define ROBOTSSYSTEM_H

const int maxNumber = 100;

class RobotsSystem
{
public:
    RobotsSystem();

    ///True if all robots can be destroyed
    bool isRobotsDestr();


    ///For testing small system
    void smallSystem();

    ///For testing large system
    void largeSystem();
private:

    ///True if robot on the position cen be destroyed
    bool isRobotCanBeDestroyed(int position);
    int size;
    int numbRobots;
    bool matrix[maxNumber][maxNumber];


    bool robot[maxNumber];
    bool isRobotDestr[maxNumber];
};

#endif // ROBOTSSYSTEM_H
