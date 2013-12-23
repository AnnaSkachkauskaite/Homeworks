#include <stdio.h>
#include <iostream>
using namespace std;

void quickSort(int a[100], int l, int r)
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
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i < r)
	{
		quickSort(a, i, r);
	}
	if (l < j)  
	{
		quickSort(a, l, j);   
	}
}