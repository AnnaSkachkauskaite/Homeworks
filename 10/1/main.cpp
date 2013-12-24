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
		while (buf != EOF)
		{
			bool isFind = false;
			for (int i = 0; i < numberOfSymbols; ++i)
			{
				if (arr[i].sym == buf)
				{
					++arr[i].count;
					isFind = true;
				}
			}
			if (isFind == false)
			{
				arr[numberOfSymbols].sym = buf;
				arr[numberOfSymbols].count = 1;
				arr[numberOfSymbols].left = nullptr;
				arr[numberOfSymbols].right = nullptr;
				++numberOfSymbols;
			}
			buf = fgetc(file);
			++numb;
		}
		for (int i = 0; i < numberOfSymbols; ++i)
		{
			arr[i].freq = (float) arr[i].count / numb;
			syms[i] = &arr[i];
		}
		Symbol *root=huffTree(syms, numberOfSymbols);
		makeCodes(root);
		printTreeInc(root);
		freeTree(root);
		for (int i = 0; i < numberOfSymbols; ++i)
			syms[i] = nullptr;
		delete root;
		fclose(file);
		makeCode(file, fileAdress, arr);
		makeKey(arr, numberOfSymbols);
	}
	else
		printf("File not found!\n");
	delete []fileAdress;
	gets(fileAdress);
}