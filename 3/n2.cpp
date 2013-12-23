#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main ()
{
	printf("Enter number  ");
	int n = 0;
	scanf("%d", &n);
	int arr[100][100];
	printf("Enter array\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	}
	printf("\n");
	printf("Array:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d   ", arr[i][j]);
		printf("\n");
	}
	int i = 0;
	int newArr [1000];
	for (int level = 0; level <= n / 2; level++)
	{
		for (int cols1 = level; cols1 < n - level; cols1++)
		{
			newArr[i] = arr[level][cols1];
			i++;
		}
		for (int rows1 = level + 1; rows1 < n - level; rows1++)
		{
			newArr[i] = arr[rows1][n - level - 1];
			i++;
		}
		for (int cols2 = n - level-2; cols2 >= level; cols2--)
		{
			newArr[i] = arr[n -level - 1][cols2];
			i++;
		}
		for (int rows2 = n - level - 2; rows2 > level; rows2--)
		{
			newArr[i] = arr[rows2][level];
			i++;
		}
	}
	printf("\n");
	for (int i = n * n - 1; i >= 0; i--)
	{
		printf("%d  ", newArr[i]);
	}
	scanf("%d", &n);
}

