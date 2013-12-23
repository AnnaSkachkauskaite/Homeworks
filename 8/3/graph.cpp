#include "graph.h"
#include <stdio.h>

void dfs (int adjMatrix[maxVertexNumber][maxVertexNumber], int startVertex, int isVisited[maxVertexNumber], int numb, int &count)
{
	isVisited[startVertex] = 1;
	printf("%d", startVertex);
	++count;
	for (int i = 1; i <= numb; ++i)
		if ((adjMatrix[i][startVertex] == 1) && (isVisited[i] == 0))
			dfs(adjMatrix, i, isVisited, numb, count);
}