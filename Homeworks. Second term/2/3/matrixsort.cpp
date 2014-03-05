#include <iostream>
#include "matrixsort.h"
using namespace std;

void swapColumns (int i, int j, int **arr, int size)
{
	for (int k = 0; k < size; ++k)
		swap(arr[k][i], arr[k][j]);
}

void quickSort(int *a, int l, int r, int **arr, int size)
{
	int x = a[l + (r - l) / 2];
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (a[i] < x) 
		{
			i++;
		}
		while (a[j] > x)
		{
			j--;
		}
		if (i <= j)
		{
			swapColumns(i, j, arr, size);
			i++;
			j--;
		}
	}
	if (i < r)
	{
		quickSort(a, i, r, arr, size);
	}
	if (l < j)  
	{
		quickSort(a, l, j, arr, size);   
	}
}