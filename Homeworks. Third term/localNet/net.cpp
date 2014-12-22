#include "net.h"
#include <QFile>
#include <QTextStream>
#include <QList>
#include <iostream>
#include <stdio.h>
#include <iostream>

using namespace std;


Net::Net()
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    isTesting = false;
}

void Net::setTesting()
{
    isTesting = true;
}

void Net::readData()
{
//    cout << "Enter number of computers  ";
//    cin << numbOfComp;
//    cout << "Enter number of computers  " << endl;
//    for (int i = 0; i < numbOfComp; ++i)
//        for (int j = 0; j < numbOfComp; ++j)
//            cin << matrix[i][j];

//    cout << "Enter probability of infection of computers  "<< endl;
//    int tmp = 0;
//    for (int i = 0; i < numbOfComp; ++i)
//    {
//        cout << i << "computer  ";
//        cin << tmp;
//        computers[i].setProb(tmp);
//        computers[i].setInf(false);

//    }


//    cout << "Enter number of infected computers  ";
//    cin << numbOfInfComp;
//    cout << "Enter numbers of infected computers  ";
//    for (int i = 0; i < numbOfInfComp; ++i)
//    {

//        cin << tmp;
//        computers[tmp].setInf(true);
//    }


}

bool Net::isInfPossible(int probability)
{
    if (isTesting)
        return true;
    return rand() % 100 > probability;
}


void Net::makeMove()
{
    if (numbOfInfComp == 0)
    {
        for (int i = 0; i < numbOfComp; ++i)
            if (isInfPossible(computers[i].getProb()))
            {
                computers[i].setInfection(true);
                result.append(i + 1);
                ++numbOfInfComp;
                return;
            }
        return;
    }
    for (int i = 0; i < numbOfComp; ++i)
        if (computers[i].isInfected)
            for (int j = 0; j < numbOfComp; ++j)
                if (!computers[j].isInfected && matrix[i][j] == 1 && isInfPossible(computers[j].getProb()))
                {
                    computers[j].setInfection(true);
                    result.append(j + 1);
                    ++numbOfInfComp;
                    return;
                }



}
void Net::printList(QList<int> result)
{
    std::cout << "Current state\n";
    if (result.isEmpty())
        std::cout << "No infected computers";
    else
        std::cout << "Infected computers ";

    for (int i = 0; i < result.size(); ++i)
        std::cout << result[i] << " ";
    std::cout << "\n";

}

void Net::infectSystem()
{
    for (int i = 0; i < numbOfComp; ++i)
        if (computers[i].isInfected && !result.contains(i+1))
            result.append(i + 1);
    while (numbOfComp != numbOfInfComp)
    {
        printList(result);
        makeMove();

    }
     printList(result);

}

void Net::defaultSystem()
{
    numbOfComp = 4;

    matrix[0][0] = 0;
    matrix[0][1] = 1;
    matrix[0][2] = 0;
    matrix[0][3] = 1;

    matrix[1][0] = 1;
    matrix[1][1] = 0;
    matrix[1][2] = 1;
    matrix[1][3] = 1;

    matrix[2][0] = 0;
    matrix[2][1] = 1;
    matrix[2][2] = 0;
    matrix[2][3] = 1;

    matrix[3][0] = 1;
    matrix[3][1] = 1;
    matrix[3][2] = 1;
    matrix[3][3] = 0;

    computers[1].setProb(50);
    computers[2].setProb(22);
    computers[3].setProb(37);
    computers[4].setProb(22);

    for (int i = 0; i < numbOfComp; ++i)
        computers[i].setInfection(false);
}

int Net::numbOfInf()
{
    return result.size();
}

int Net::numbOfComputers()
{
    return numbOfComp;
}

QList<int> Net::getResult()
{
    return result;
}

