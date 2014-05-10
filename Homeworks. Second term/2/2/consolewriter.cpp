#include "consolewriter.h"
#include <iostream>

void ConsoleWriter::printMatrix (int **arr, int size)
{
    int *spiralArr = makeSpiralArray(arr, size);
    for (int i = size * size - 1; i >= 0; i--)
    {
        std::cout << spiralArr[i] << " ";
    }
    std::cout << "\n";
    //delete spiralArr;
}
