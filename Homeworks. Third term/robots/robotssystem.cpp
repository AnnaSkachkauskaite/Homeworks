#include "robotssystem.h"
#include <QQueue>

RobotsSystem::RobotsSystem()
{
}

bool RobotsSystem::areAllRobotsDestroyed()
{
    for (int i = 0; i < size; ++i)
        isRobotDestroyed[i] = false;
    for (int i = 0; i < size; ++i)
    {
        if (robot[i] && !isRobotDestroyed[i])
        {
            if (!isRobotCanBeDestroyed(i))
                return false;
        }
    }
    return true;
}

bool RobotsSystem::isRobotCanBeDestroyed(int position)
{
    bool isVisited[maxNumber];
    for (int i = 0; i < size; ++i)
        isVisited[i] = false;
   QQueue<int> queue;
   queue.enqueue(position);
   isVisited[position] = true;
   while (queue.count() != 0)
   {
       int currPos = queue.dequeue();
       if (robot[currPos] && currPos != position)
       {
           isRobotDestroyed[currPos] = true;
           isRobotDestroyed[position] = true;
           return true;
       }
       for (int i = 0; i < size; ++i)
       {
           if (matrix[currPos][i] && currPos != i)
           {
               for (int j = 0; j < size; ++j)
               {
                   if (matrix[j][i] && j != i && !isVisited[j])
                   {
                       queue.enqueue(j);
                       isVisited[j] = true;
                   }
               }
           }
       }
   }
   return false;
}


void RobotsSystem::setSize(int matrixSize)
{
    size = matrixSize;
}

void RobotsSystem::setRobot(int i, bool isRobot)
{
    robot[i] = isRobot;
}

void RobotsSystem::setMatrixElement(int i, int j, bool value)
{
    matrix[i][j] = value;
}

