#include <stdio.h>
#include "huffTree.h"

int main ()
{
	printf("Enter file adress\n");
	char *fileAdress = new char[maxFileAdressLength];
	gets(fileAdress);
	FILE *file;
	file = fopen(fileAdress, "r");
	if (file != NULL)
	{
		char buf = 0;
		long numb = 0;
		long numberOfSymbols = 0;
		buf = fgetc(file);
		Symbol *syms[SIZE];
		Symbol arr[SIZE];
		for (int i = 0; i < SIZE; ++i)
			arr[i].sym = 0;
		while (buf != EOF)
		{
			bool isFind = false;
			for (int i = 0; i < numberOfSymbols; ++i)
			{
				if (syms[i]->sym == buf)
				{
					++syms[i]->count;
					isFind = true;
				}
			}
			if (isFind == false)
			{
				syms[numberOfSymbols] = new Symbol;
				syms[numberOfSymbols]->sym = buf;
				syms[numberOfSymbols]->count = 1;
				syms[numberOfSymbols]->left = nullptr;
				syms[numberOfSymbols]->right = nullptr;
				++numberOfSymbols;
			}
			buf = fgetc(file);
			++numb;
		}
		for (int i = 0; i < numberOfSymbols; ++i)
		{
			syms[i]->freq = (float) syms[i]->count / numb;
		}
		Symbol *root=huffTree(syms, numberOfSymbols);
		makeCodes(root);
		printTreeInc(root);
		fclose(file);
		makeCodeArr(root, arr);
		makeCode(file, fileAdress, arr);
		makeKey(arr, numberOfSymbols);
		freeTree(root);
		for (int i = 0; i < numberOfSymbols; ++i)
		{
			delete syms[i];
		}
	}
	else
		printf("File not found!\n");
	delete []fileAdress;
	gets(fileAdress);
}