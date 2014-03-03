#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list.h"
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
	int arr[maxNumb][maxNumb];
	int n = 0;
	fscanf(file, "%d", &n);
	makeAdjMatrix(file, arr, n);
	printf("This matrix\n");
	List *list = createList();
	int isVisited[maxNumb];
	for(int i = 0; i < n; ++i)
		isVisited[i] = 0;
	printMatrix(arr, n);
	makeTree(list, arr, n, isVisited);
	printList(list);
	deleteList(list);
	delete list;
	fclose(file);
	gets(fileAdress);
	delete []fileAdress;
}