#include <stdio.h>
#include "graph.h"
#include "stringUnit.h"

/*int minimum (int a, int b)
{
	if (a > b)
		return b;
	return a;
}*/

void capture (int adjMatrix[maxVertexNumber][maxVertexNumber], int isVisited[maxVertexNumber], int numb, int minToFirst[maxVertexNumber], String *ways[maxVertexNumber])
{
	for (int k = 1; k < numb; ++k)
	{
		int min = maxWay;
		int start = 0;
		int newVisited = 0;
		int minimum = maxWay;
		for (int i = 1; i <= numb; ++i)
			if (isVisited[i] == 1)
				for (int j = 1; j <= numb; ++j)
				{
					if (adjMatrix[1][j] < (minToFirst[i] + adjMatrix[i][j]))
						minimum = adjMatrix[1][j];
					else
						minimum = minToFirst[i] + adjMatrix[i][j];
					if ((isVisited[j] == 0) && (minimum < min))
					{
						min = minimum;
						start = i;
						newVisited = j;
					}
				}
		isVisited[newVisited] = 1;
		minToFirst[newVisited] = min;
		ways[newVisited] = clone(ways[start]);
		addSymbol(ways[newVisited], '0' + newVisited);
		printString(ways[newVisited]);
		printf(" %d\n", min);
	}
}