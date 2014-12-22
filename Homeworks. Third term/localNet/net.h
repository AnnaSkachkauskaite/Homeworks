#ifndef NET_H
#define NET_H

#include "computer.h"
#include <QTime>

const int maxCompNumb = 100;

class Net
{
public:
    Net();
    ///Read all information about net
    void readData();
    void makeMove();
    ///Infects all net
    void infectSystem();
    void defaultSystem();
    ///Print infurmation about current infection
    void printList(QList<int> result);
    int numbOfInf();
    ///Number of computers inthe net
    int numbOfComputers();

    QList<int> getResult();

    void setTesting();
private:
    QList<int> result;
    Computer computers[maxCompNumb];
    int numbOfComp;
    int numbOfInfComp;
    int matrix[maxCompNumb][maxCompNumb];
    int infComputers[maxCompNumb];

    ///For making tests(without random)
    bool isTesting;

    bool isInfPossible(int probability);

};

#endif // NET_H
