#include "graph.h"

void dfs (int adjMatrix[maxVertexNumber][maxVertexNumber], int startVertex, char arrLetters[maxVertexNumber], int numb, char letters[maxVertexNumber], int count)
{
	arrLetters[startVertex] = letters[count];
	count++;
	for (int i = 0; i <= numb; ++i)
		if ((adjMatrix[i][startVertex] == 1) && (arrLetters[i] == 0))
			dfs(adjMatrix, i, arrLetters, numb, letters, count);
}