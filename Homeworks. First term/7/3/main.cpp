#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list.h"
#include "stringUnit.h"
#include "hash.h"


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
	HashElem *hashArr[hashMax];
	createHashArr(hashArr);
	int length[hashMax];
	makeHashArr(hashArr, file, length);
	long numbWord = 0;
	int lengthMax = 0;
	int lengthMaxNumb = 0;
	int count = 0;
	for (int i = 0; i < hashMax; ++i)
	{
		if (!isEmpty(hashArr[i]->list))
		{
			numbWord = numbWord + length[i];
			++count;
			printList(hashArr[i]->list);
			if (length[i] > lengthMax)
			{
				lengthMax = length[i];
				lengthMaxNumb = i;
			}

		}
	}
	float loadFactor = (float) numbWord / hashMax;
	printf("number of words %ld load factor %lf\n", numbWord, loadFactor);
	printf("the average length %lf\n", (float)numbWord / count);
	printf("Number of empty cells %d\n", hashMax - count);
	printf("The longest chain has %d elements\n", lengthMax);
	printList(hashArr[lengthMaxNumb]->list);
	for (int i = 0; i < hashMax; ++i)
	{
		deleteList(hashArr[i]->list);
		delete hashArr[i];
	}
	fclose(file);
	gets(fileAdress);
	delete []fileAdress;
}