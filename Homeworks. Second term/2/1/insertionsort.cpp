#include "insertionsort.h"
#include <iostream>
using namespace std;

void InsertionSort::sort(int arr[], int size)
{
	for (int i = 1; i < size; i++) 
	{
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j]) 
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}