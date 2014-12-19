#include "robotssystem.h"
#include <QQueue>

RobotsSystem::RobotsSystem()
{
}

bool RobotsSystem::isRobotsDestr()
{
    for (int i = 0; i < size; ++i)
        isRobotDestr[i] = false;
    for (int i = 0; i < size; ++i)
    {
        if (robot[i] && !isRobotDestr[i])
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
           isRobotDestr[currPos] = true;
           isRobotDestr[position] = true;
           return true;
       }
       for (int i = 0; i < size; ++i)
       {
           if(matrix[currPos][i] && currPos != i)
           {
               for (int j = 0; j < size; ++j)
               {
                   if(matrix[j][i] && j != i && !isVisited[j])
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
void RobotsSystem::smallSystem()
{
    size = 3;

    matrix[0][0] = true;
    matrix[0][1] = true;
    matrix[0][2] = false;

    matrix[1][0] = true;
    matrix[1][1] = true;
    matrix[1][2] = true;

    matrix[2][0] = false;
    matrix[2][1] = true;
    matrix[2][2] = true;

    robot[0] = true;
    robot[1] = false;
    robot[2] = true;

}

void RobotsSystem::largeSystem()
{
    size = 4;


    matrix[0][0] = true;
    matrix[0][1] = false;
    matrix[0][2] = true;
    matrix[0][3] = false;

    matrix[1][0] = false;
    matrix[1][1] = true;
    matrix[1][2] = true;
    matrix[1][3] = false;

    matrix[2][0] = true;
    matrix[2][1] = true;
    matrix[2][2] = true;
    matrix[2][3] = true;

    matrix[3][0] = false;
    matrix[3][1] = false;
    matrix[3][2] = true;
    matrix[3][3] = true;


    robot[0] = true;
    robot[1] = true;
    robot[2] = true;
    robot[3] = false;
}
