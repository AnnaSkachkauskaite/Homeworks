#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "graph.h"
#include "stringUnit.h"

int main ()
{
		printf("Enter file adress\n");
	char *fileAdress = new char[maxFileAdressLength];
	gets(fileAdress);
	FILE *file;
	file = fopen(fileAdress, "r");
	int adjMatrix[maxVertexNumber][maxVertexNumber];
	for (int i = 0; i < maxVertexNumber; ++i)
		for (int j = 0; j < maxVertexNumber; ++j)
			adjMatrix[i][j] = maxWay;
	int numb = 0;
	fscanf (file, "%d", &numb);
	int i = 0;
	int j = 0;
	int length = 0;
	while (!feof(file))
	{
		fscanf (file, "%d %d %d", &i, &j, &length);
		adjMatrix[i][j] = length;
		adjMatrix[j][i] = length;
	}
	int isVisited[maxVertexNumber];
	isVisited[1] = 1;
	for (int i = 2; i <= numb; ++i)
		isVisited[i] = 0;
	int minToFirst[maxVertexNumber];
	minToFirst[1] = 0;
	for (int i = 2; i <= numb; ++i)
		minToFirst[i] = maxWay;
	String *ways[maxVertexNumber];
	for (int i = 1; i <= numb; ++i)
		ways[i] = createString();
	addSymbol(ways[1], '1');
	capture(adjMatrix, isVisited, numb, minToFirst, ways);
	fclose(file);
	delete []fileAdress;
	for (int i = 1; i <= numb; ++i)
	{
		deleteString(ways[i]);
		ways[i] = nullptr;
	}
	scanf("%d", &i);
}