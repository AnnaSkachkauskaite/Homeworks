#pragma once
#include "sort.h"

/// Class that allows to sort an array with arbitrary size using insertion sort
class InsertionSort : public Sort
{
public:

	/// Abbstract method which sort an array with some size using insertion sort
	void sort(int arr[], int size);

};
