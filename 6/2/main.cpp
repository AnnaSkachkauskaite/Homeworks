#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "tree.h"

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
	char c = 0;
	fscanf(file, "%c", &c);
	Tree *tree = new Tree;
	fileToTree(file, &tree->root);
	printTreeInc(tree->root);
	getValue(tree->root);
	printf("\nResult:  ");
	printTreeInc(tree->root);
	freeTree(tree->root);
	delete tree;
	fclose(file);
	delete []fileAdress;
	gets(fileAdress);
}