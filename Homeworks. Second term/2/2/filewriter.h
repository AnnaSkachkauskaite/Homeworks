#pragma once
#include "writer.h"


/// Class which can print matrix to console using spiral bypass
class FileWriter : public Writer
{
public:

    /// Method which print an array to console
    void printMatrix (int **arr, int size);


};
