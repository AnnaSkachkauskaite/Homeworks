#include <string.h>
#include <stdio.h>
#include "huffTree.h"

Symbol *huffTree (Symbol *symbs[], int numberOfSymbols)
{
	for (int i = 0; i < numberOfSymbols - 1; ++i)
		for (int j = i + 1; j < numberOfSymbols; ++j)
			if (symbs[i]->freq < symbs[j]->freq)
			{
				Symbol *buf = symbs[j];
				symbs[j] = symbs[i];
				symbs[i] = buf;
			}
	Symbol *tmp = new Symbol;
	tmp->freq = symbs[numberOfSymbols - 1]->freq + symbs[numberOfSymbols - 2]->freq;
	tmp->code[0] = 0;
	tmp->left = symbs[numberOfSymbols - 2];
	tmp->right = symbs[numberOfSymbols - 1];

	if (numberOfSymbols == 2)
		return tmp;
	else
	{
		symbs[numberOfSymbols - 2] = tmp;
		return huffTree(symbs, numberOfSymbols - 1);
	}
	delete tmp;
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

void addToArr (Symbol arr[], char symb, char* code)
{
	int count = 0;
	while (arr[count].sym != 0)
	{
		++count;
	}
	arr[count].sym = symb;
	strcpy(arr[count].code, code);
}

void makeCodeArr (Symbol *root, Symbol arr[])
{
	if(root->left != nullptr)
		makeCodeArr(root->left, arr);
	if (root->sym > 0)
		addToArr(arr, root->sym, root->code);
	if(root->right != nullptr)
		makeCodeArr(root->right, arr);
}

void freeTree(Symbol *root)
{
        if (root == nullptr) 
                return;
        if (root->left != nullptr)   
                freeTree(root->left); 
    if (root->right != nullptr)  
                freeTree(root->right);
	delete root;
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

void makeKey (Symbol arr[SIZE], int numberOfSymbols)
{
        FILE *fout;
        fout = fopen("key.txt", "w");
        for (int i = 0; i < numberOfSymbols; ++i)
        {
                fprintf(fout, "%c %s\n",arr[i].sym, arr[i].code);
        }
        fclose(fout);
}