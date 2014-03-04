#pragma once
#include "sort.h"

/// Class that allows to sort an array with arbitrary size using bubble sort
class BubbleSort : public Sort
{
public:

	/// Abbstract method which sort an array with some size using bubble sort
	void sort(int arr[], int size);

};
