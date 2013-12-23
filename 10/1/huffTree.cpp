#include <string.h>
#include <stdio.h>
#include "huffTree.h"

Symbol *huffTree (Symbol *symbs[], int numb)
{
	for (int i = 0; i < numb - 1; ++i)
		for (int j = i + 1; j < numb; ++ j)
			if (symbs[i]->freq < symbs[j]->freq)
			{
				Symbol *buf = symbs[j];
				symbs[j] = symbs[i];
				symbs[i] = buf;
			}
	Symbol *tmp = new Symbol;
	tmp->freq = symbs[numb-1]->freq + symbs[numb-2]->freq;
    tmp->code[0] = 0;
    tmp->left = nullptr;
    tmp->right = nullptr;

    tmp->left = symbs[numb-2];
    tmp->right = symbs[numb-1];

    if(numb==2)
        return tmp;
	else
	{
		symbs[numb - 2] = tmp;
		return huffTree(symbs, numb - 1);
	}
}

void makeCodes(Symbol *root)
{
    if (root->left)
    {
        strcpy(root->left->code, root->code);
        strcat(root->left->code, "0");
        makeCodes(root->left);
    }
    if (root->right)
    {
        strcpy(root->right->code, root->code);
        strcat(root->right->code, "1");
        makeCodes(root->right);
    }
}

void printTreeInc (Symbol *root)
{
	if(root->left != nullptr)
		printTreeInc(root->left);
	if (root->sym > 0)
	printf("%c %s ", root->sym, root->code);
	if(root->right != nullptr)
		printTreeInc(root->right);
}

void freeTree(Symbol **root)
{
	if (*root == nullptr) 
		return;
	if ((*root)->left != nullptr)   
		freeTree(&(*root)->left); 
    if ((*root)->right != nullptr)  
		freeTree(&(*root)->right);
	(*root) = nullptr;
}


void makeCode (FILE *fin, char* fileAdress, Symbol arr[SIZE])
{
	FILE *fout;
	fout = fopen("code.txt", "w");
	fin = fopen(fileAdress, "r");
	char buf = 0;
	buf = fgetc(fin);
	while (buf != EOF)
	{
		bool isFind = false;
		int i = 0;
		while (!isFind)
		{
			if (arr[i].sym == buf)
			{
				fprintf(fout, "%s", arr[i].code);
				isFind = true;
			}
			++i;
		}
		buf = fgetc(fin);
	}
	fclose(fin);
	fclose(fout);
}

void makeKey (Symbol arr[SIZE], int count)
{
	FILE *fout;
	fout = fopen("key.txt", "w");
	for (int i = 0; i < count; ++i)
	{
		fprintf(fout, "%c %s\n",arr[i].sym, arr[i].code);
	}
	fclose(fout);
}