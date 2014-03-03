#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "graph.h"

int main ()
{ 
	FILE *file;
	file = NULL;
	printf("Enter file adress\n");
	char *fileAdress = new char[maxFileAdressLength];
	while (file == NULL)
	{
	gets(fileAdress);
	file = fopen(fileAdress, "r");
	if (file == NULL)
		printf("File not found!\n");
	}
	int adjMatrix[maxVertexNumber][maxVertexNumber];
	for (int i = 0; i < maxVertexNumber; ++i)
		for (int j = 0; j < maxVertexNumber; ++j)
			adjMatrix[i][j] = 0;
	int i = 0;
	int j = 0;
	int numb = 0;
	while (!feof(file))
	{
		fscanf (file, "%d %d", &i, &j);
		adjMatrix[i][j] = 1;
		adjMatrix[j][i] = 1;
		if (i > numb)
			numb = i;
		if (j > numb)
			numb = j;
	}
	int isVisited[maxVertexNumber];
	isVisited[0] =12;
	for (int i = 1; i <= numb; ++i)
		isVisited[i] = 0;
	int count = 0;
	while (count < numb)
	{
		int startVertex = 0;
		while (isVisited[startVertex] != 0)
			++startVertex;
		dfs(adjMatrix, startVertex, isVisited, numb, count);
		printf("\n");
	}
	fclose(file);
	gets(fileAdress);
	delete []fileAdress;
}