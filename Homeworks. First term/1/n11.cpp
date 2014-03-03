#define _CRT_SECURE_NO_WARNINGS
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
int main()
{
	printf("enter number of elements ");
	int n;
	scanf("%d", &n);
	printf("enter array\n");
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int a[100];
	quickSort(a, 0, n - 1);
	printf("sorted array\n");
	for (int i = 0; i < n; i++)
	{
		printf("%3d", a[i]);
	}        
	scanf("%d", &n);
    return 0;
}