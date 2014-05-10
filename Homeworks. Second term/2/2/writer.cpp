#include "writer.h"
using namespace std;

int* Writer::makeSpiralArray (int **arr, int size)
{
    int i = 0;
    int *newArr = new int[size * size - 1];
    for (int level = 0; level <= size / 2; level++)
    {
        for (int cols1 = level; cols1 < size - level; cols1++)
        {
            newArr[i] = arr[level][cols1];
            i++;
        }
        for (int rows1 = level + 1; rows1 < size - level; rows1++)
        {
            newArr[i] = arr[rows1][size - level - 1];
            i++;
        }
        for (int cols2 = size - level-2; cols2 >= level; cols2--)
        {
            newArr[i] = arr[size -level - 1][cols2];
            i++;
        }
        for (int rows2 = size - level - 2; rows2 > level; rows2--)
        {
            newArr[i] = arr[rows2][level];
            i++;
        }
    }
    for (int i = 0; i < size;++i)
        delete [] arr[i];
    delete [] arr;
    return newArr;
}

string Writer::makeString(int **arr, int size)
{
    string result= "";
    int *spiralArr = makeSpiralArray(arr, size);
    for (int i = size * size - 1; i >= 0; i--)
    {
        result = result + to_string(spiralArr[i]) + " ";
    }
    return result;
}
