#include <stdio.h>
#include "huffTree.h"

int main ()
{
	printf("Enter key file adress\n");
	char *fileAdress = new char[maxFileAdressLength];
	gets(fileAdress);
	FILE *file;
	file = fopen(fileAdress, "r");
	Tree *tree = new Tree;
	tree->root = new TreeNode;
	tree->root->left = nullptr;
	tree->root->right = nullptr;
	if (file != NULL)
	{
		char symb;
		char* code = new char[SIZE];
		while (!feof(file))
		{
			fscanf(file, "%c ", &symb);
			fgets(code ,SIZE ,file);
			addToTree(symb, code, &tree->root);
		}
		delete []code;
		//printTreeInc(tree->root);
	}
	else
		printf("File not found!\n");
	printf("Enter code file adress\n");
	gets(fileAdress);
	FILE *fileCode;
	fileCode = fopen(fileAdress, "r");
	if (fileCode != NULL)
	{
		decode(fileCode, tree);
		fclose(fileCode);
	}
	else
		printf("File not found!\n");
	freeTree(tree->root);
	delete tree;
	gets(fileAdress);
	delete []fileAdress;
}