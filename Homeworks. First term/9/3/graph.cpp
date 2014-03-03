#include <stdio.h>
#include "graph.h"

void makeAdjMatrix (FILE *file, int arr[maxNumb][maxNumb], int n)
{
	for (int i = 0; i < maxNumb; ++i)
		for (int j = 0; j < maxNumb; ++j)
			arr[i][j] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			fscanf(file, "%d ", &arr[i][j]);
		}
	}
}

void printMatrix (int arr[maxNumb][maxNumb], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void makeTree (List *list, int arr[maxNumb][maxNumb], int n, int isVisited[maxNumb])
{
	int count = n;
	isVisited[0] = 1;
	addValue(list, 0, 0);
	--count;
	while (count > 0)
	{
		int minWay = maxWay;
		int minInd = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if ((arr[i][j] < minWay) && (isVisited[i] == 1) && (isVisited[j] == 0))
				{
					minWay = arr[i][j];
					minInd = j;
				}
			}
		}
		addValue(list, minInd, minWay);
		isVisited[minInd] = 1;
		--count;
	}
}