#ifndef COMPUTER_H
#define COMPUTER_H

#include <QString>

///Computer in the net
class Computer
{
public:
    Computer();
    void setInfection(bool);
    void setProb(int);
    ///Returns probability of infection
    int getProb();
    ///True if computer infected
    bool inf();
//private:
    bool isInfected;
    int probability;
};

#endif // COMPUTER_H
