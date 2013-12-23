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
	int startVertex = 0;
	fscanf (file, "%d", &startVertex);
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
	char arrLetters[maxVertexNumber];
	for (int i = 0; i <= numb; ++i)
		arrLetters[i] = 0;
	char letters[maxVertexNumber];
	for (int i = 0; i <= numb; ++i)
		letters[i] = 65 + i;
	int count = 0;
	dfs(adjMatrix, startVertex, arrLetters, numb, letters, count);
	for (int i = 0; i <= numb; ++i)
		printf("%d %c\n", i, arrLetters[i]);
	fclose(file);
	gets(fileAdress);
	delete []fileAdress;
}