#include <stdio.h>
#include "list.h"

FILE *openFile ()
{
	FILE *file;
	file = NULL;
	printf("Enter file adress\n");
	char *fileAdress = new char[maxFileAdressLength];
	while (file == NULL)
	{
		scanf("%s", fileAdress);
		file = fopen(fileAdress, "r");
		if (file == NULL)
			printf("File not found!\n");
	}
	delete []fileAdress;
	return file;
}

enum State
{
	exit,
	areEqual,
	findValue,
	findSum
};

int main ()
{
	printf ("Choose option:\n1 - Test for equality\n2 - Find value\n3 - Calculation of the sum\n0 - exit\n");
	State state;
	scanf("%d", &state);
	while (state != exit)
	{
		if (state == areEqual)
		{
			FILE *file = openFile();
			List *polynomal1 = createList();
			makeList(file, polynomal1);
			fclose(file);
			file = openFile();
			List *polynomal2 = createList();
			makeList(file, polynomal2);
			fclose(file);
			if (equals(polynomal1, polynomal2))
				printf("polynomals are equal\n");
			else
				printf("polynomals are not equal\n");
			deleteList(polynomal1);
			delete polynomal1;
			deleteList(polynomal2);
			delete polynomal2;

		}

		if (state == findValue)
		{
			FILE *file = openFile();
			List *polynomal1 = createList();
			makeList(file, polynomal1);
			fclose(file);
			printf("Enter value ");
			int numb = 0;
			scanf("%d", &numb);
			printf("Result = %d\n", value(polynomal1, numb));
			deleteList(polynomal1);
			delete polynomal1;
		}

		if (state == findSum)
		{
			FILE *file = openFile();
			List *polynomal1 = createList();
			makeList(file, polynomal1);
			fclose(file);
			file = openFile();
			List *polynomal2 = createList();
			makeList(file, polynomal2);
			fclose(file);
			List *result = add(polynomal1, polynomal2);
			printList(result);
			deleteList(result);
			delete result;
			deleteList(polynomal1);
			delete polynomal1;
			deleteList(polynomal2);
			delete polynomal2;
		}
		scanf("%d", &state);
	}
}