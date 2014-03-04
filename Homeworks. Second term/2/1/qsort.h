#pragma once
#include "sort.h"

/// Class that allows to sort an array with arbitrary size using quick sort
class QSort : public Sort
{
public:

	/// Abbstract method which sort an array with some size using quick sort
	void sort(int arr[], int size);

};
