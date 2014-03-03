#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "qsort.h"
;
using namespace std;

int main()
{
	printf("enter number of elements ");
	int n;
	scanf("%d", &n);
	printf("enter array\n");
	int a[100];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	quickSort(a, 0, n - 1);
	bool numbFind = false;
	int i = n - 1;
	while ((!numbFind) && (i > 1))
	{
		if (a[i] == a[i - 1])
		{
			numbFind = true;
		}
		else
		{
			--i;
		}
	}
	if (numbFind)
	{
		printf("%d", a[i]);
	}
	else
	{
		printf("no duplicate items");
	}
	scanf("%d", &n);
    return 0;
}