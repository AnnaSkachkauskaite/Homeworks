#pragma once

/// Class that allows to sort an array with arbitrary size using specific algorithms
class Sort
{
public:
    /// Abbstract method which sort an array with some size using specific algorithm
    virtual void sort(int arr[], int size) = 0;
};

