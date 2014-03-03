#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap (int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void screening (int arr[1000], int k, int numb)
{
	if (numb == 0)
	{
		return;
	}
	int tmp = arr[k];
	while (k < numb / 2)
	{
		int childPos = 2 * k + 1;
		if ((childPos < numb) && (arr[childPos] < arr[childPos + 1]))
		{
			++childPos;
		}
		if(tmp >= arr[childPos]) 
		{
			break;
		}
		arr[k] = arr[childPos];
		k = childPos;
		//swap(arr[k], arr[childPos]);
		//k = childPos;
	}
	arr[k] = tmp;
}


int main ()
{
	printf("enter number of elements ");
	int numb;
	scanf("%d", &numb);
	printf("enter array\n");
	int arr[1000];
	for (int i = 0; i < numb; ++i)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = numb / 2 - 1; i >= 0; --i)
	{
		screening(arr, i, numb-1);
	}
	for (int i = numb - 1; i > 0; --i)
	{
		swap(arr[0], arr[i]);
		screening(arr, 0, i - 1);
	}
	printf("sorted array\n");
	for (int i = 0; i < numb; ++i)
	{
		printf("%d  ", arr[i]);
	}
	scanf("%d", &numb);
}


